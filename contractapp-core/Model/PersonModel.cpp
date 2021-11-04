#include "PersonModel.h"

PersonModel::PersonModel(const QString& view, QObject *parent) :
    QAbstractTableModel(parent),
    mDb(DatabaseManager::instance()),
    mPersons(mDb.mPersonDao.persons(view))
{

}

QModelIndex PersonModel::addPerson(const Person &person)
{
    int rowIndex = rowCount();
    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    std::unique_ptr<Person> newPerson(new Person(person));
    mDb.mPersonDao.addPerson(*newPerson);
    mPersons->push_back(std::move(newPerson));
    endInsertRows();
    return index(rowIndex, 0);
}

int PersonModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mPersons->size();
}

int PersonModel::columnCount(const QModelIndex &paernt) const
{
    return 5;
}

QVariant PersonModel::data(const QModelIndex &index, int role) const
{
    if(!isIndexValid(index))
    {
        return {};
    }

    Person& person = *mPersons->at(index.row());

    switch (role) {
    case Roles::ID_ROLE:
        return QVariant::fromValue(person);
    case Roles::FIRST_NAME_ROLE:
        return person.firstName();
    case Roles::LAST_NAME_ROLE:
        return person.lastName();
    case Roles::EMAIL_ROLE:
        return person.email();
    case Roles::CITY_ROLE:
        return person.city();
    case Qt::DisplayRole:
        switch(index.column())
        {
        case ColumnName::ID: return person.id();
        case ColumnName::FIRST_NAME: return person.firstName();
        case ColumnName::LAST_NAME: return person.lastName();
        case ColumnName::EMAIL: return person.email();
        case ColumnName::CITY: return person.city();
        }
    default:
        return {};
    }

}

bool PersonModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!isIndexValid(index) || role != Roles::ID_ROLE)
    {
        return false;
    }

    auto personTemp = qvariant_cast<Person>(value);

    Person& person = *mPersons->at(index.row());
    person.setFirstName(personTemp.firstName());
    person.setLastName(personTemp.lastName());
    person.setCity(personTemp.city());
    person.setEmail(personTemp.email());
    person.setPrincipal(personTemp.isPrincipal());
    mDb.mPersonDao.updatePerson(person);
    emit dataChanged(index, index);
    return true;
}

bool PersonModel::removeRows(int row, int count, const QModelIndex &parent)
{
    if(row < 0 || row >= rowCount() || count < 0 || (row + count) > rowCount())
    {
        return false;
    }

    beginRemoveRows(parent, row, row+ count - 1);
    int countLeft = count;

    while(countLeft--)
    {
        const Person& person = *mPersons->at(row + countLeft);
        mDb.mPersonDao.removePerson(person.id());
    }
    endRemoveRows();
    return true;
}

QHash<int, QByteArray> PersonModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Roles::ID_ROLE] = "id";
    roles[Roles::FIRST_NAME_ROLE] = "name";

    return roles;
}

bool PersonModel::isIndexValid(const QModelIndex &index) const
{
    return index.isValid() && index.row() < rowCount();
}

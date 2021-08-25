#include "PersonModel.h"

PersonModel::PersonModel(QObject *parent) :
    QAbstractTableModel(parent),
    mDb(DatabaseManager::instance()),
    mPersons(mDb.m_persondao.persons())
{

}

QModelIndex PersonModel::addPerson(const Person &peron)
{
    int rowIndex = rowCount();
    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    std::unique_ptr<Person> newPeron(new Person(peron));
    mDb.m_persondao.addPerson(*newPeron);
    mPersons->push_back(std::move(newPeron));
    endInsertRows();
    return index(rowIndex, 0);
}

int PersonModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mPersons->size();
}

int PersonModel::columnCount(const QModelIndex &parent) const
{
    return 5;
}

QVariant PersonModel::data(const QModelIndex &index, int role) const
{
    if(!isIndexValid(index))
    {
        return {};
    }

    const Person& person = *mPersons->at(index.row());

    switch (role) {
    case Roles::ID_ROLE:
        return person.id();
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
    if(!isIndexValid(index) || role != Roles::FIRST_NAME_ROLE)
    {
        return false;
    }

    Person& person = *mPersons->at(index.row());
    person.setFirstName(value.toString());
    mDb.m_persondao.updatePerson(person);
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
        mDb.m_persondao.removePerson(person.id());
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



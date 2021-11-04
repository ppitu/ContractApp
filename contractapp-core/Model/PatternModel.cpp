#include "PatternModel.h"

PatternModel::PatternModel(QObject *parent) :
    QAbstractTableModel(parent),
    mDb(DatabaseManager::instance()),
    mPatterns(mDb.mPatternDao.patterns())
{

}

QModelIndex PatternModel::addPattern(const Pattern &pattern)
{
    int rowIndex = rowCount();
    beginInsertRows(QModelIndex(), rowIndex, rowIndex);
    std::unique_ptr<Pattern> newPattern(new Pattern(pattern));
    mDb.mPatternDao.addPattern(*newPattern);
    mPatterns->push_back(std::move(newPattern));
    endInsertRows();
    return index(rowIndex, 0);
}

int PatternModel::rowCount(const QModelIndex &parent) const {
    Q_UNUSED(parent);
    return mPatterns->size();
}

int PatternModel::columnCount(const QModelIndex &parent) const {
    return 2;
}

QVariant PatternModel::data(const QModelIndex &index, int role) const {
    if(!isIndexValid(index))
    {
        return {};
    }

    Pattern& pattern = *mPatterns->at(index.row());

    switch (role) {
    case Roles::ID_ROLE:
        return QVariant::fromValue(pattern);
    case Qt::DisplayRole:
        switch (index.column()) {
        case ColumnName::ID: return pattern.getId();
        case ColumnName::NAME: return pattern.getName();
        case ColumnName::T1: return pattern.getTitle(0);
        case ColumnName::T2: return pattern.getTitle(1);
        case ColumnName::T3: return pattern.getTitle(2);
        case ColumnName::T4: return pattern.getTitle(3);
        case ColumnName::T5: return pattern.getTitle(4);
        case ColumnName::T6: return pattern.getTitle(5);
        case ColumnName::T7: return pattern.getTitle(6);
        case ColumnName::T8: return pattern.getTitle(7);
        case ColumnName::T9: return pattern.getTitle(8);
        case ColumnName::T10: return pattern.getTitle(9);
        case ColumnName::T11: return pattern.getTitle(10);
        case ColumnName::T12: return pattern.getTitle(11);
        case ColumnName::P1: return pattern.getParagraph(0);
        case ColumnName::P2: return pattern.getParagraph(1);
        case ColumnName::P3: return pattern.getParagraph(2);
        case ColumnName::P4: return pattern.getParagraph(3);
        case ColumnName::P5: return pattern.getParagraph(4);
        case ColumnName::P6: return pattern.getParagraph(5);
        case ColumnName::P7: return pattern.getParagraph(6);
        case ColumnName::P8: return pattern.getParagraph(7);
        case ColumnName::P9: return pattern.getParagraph(8);
        case ColumnName::P10: return pattern.getParagraph(9);
        case ColumnName::P11: return pattern.getParagraph(10);
        case ColumnName::P12: return pattern.getParagraph(11);
        }
    default:
        return {};
    }
}

bool PatternModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if(!isIndexValid(index) || role != Roles::ID_ROLE)
        return false;

    auto patternTemp = qvariant_cast<Pattern>(value);

    Pattern& pattern = *mPatterns->at(index.row());
    pattern.setId(patternTemp.getId());
    pattern.setName(patternTemp.getName());
    for(int i = 0; i < 12; ++i)
    {
        pattern.getTitle(i) = patternTemp.getTitle(i);
        pattern.getParagraph(i) = patternTemp.getParagraph(i);
    }

    mDb.mPatternDao.updatePattern(pattern);
    emit dataChanged(index, index);
    return true;
}

bool PatternModel::removeRows(int row, int count, const QModelIndex &parent) {
    if(row < 0 || row >= rowCount() || count < 0 || (row + count) > rowCount())
    {
        return false;
    }

    beginRemoveRows(parent, row, row + count - 1);
    int countLeft = count;

    while (countLeft--)
    {
        const Pattern& pattern = *mPatterns->at(row + countLeft);
        mDb.mPatternDao.removePattern(pattern.getId());
    }
    endRemoveRows();

    return true;
}

QHash<int, QByteArray> PatternModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[Roles::ID_ROLE] = "id";

    return roles;
}

bool PatternModel::isIndexValid(const QModelIndex &index) const {
    return index.isValid() && index.row() < rowCount();
}

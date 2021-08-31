//
// Created by ppitu on 29.08.2021.
//

#include "PatternModel.h"

PatternModel::PatternModel(QObject *parent) :
    QAbstractTableModel(parent),
    mDb(DatabaseManager::instance()),
    mPatterns(mDb.mPatternDao.patterns())
{

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
                case ColumnName::T1: return pattern.mTitles[0];
                case ColumnName::T2: return pattern.mTitles[1];
                case ColumnName::T3: return pattern.mTitles[2];
                case ColumnName::T4: return pattern.mTitles[3];
                case ColumnName::T5: return pattern.mTitles[4];
                case ColumnName::T6: return pattern.mTitles[5];
                case ColumnName::T7: return pattern.mTitles[6];
                case ColumnName::T8: return pattern.mTitles[7];
                case ColumnName::T9: return pattern.mTitles[8];
                case ColumnName::T10: return pattern.mTitles[9];
                case ColumnName::T11: return pattern.mTitles[10];
                case ColumnName::T12: return pattern.mTitles[11];
                case ColumnName::P1: return pattern.mParagraphs[0];
                case ColumnName::P2: return pattern.mParagraphs[1];
                case ColumnName::P3: return pattern.mParagraphs[2];
                case ColumnName::P4: return pattern.mParagraphs[3];
                case ColumnName::P5: return pattern.mParagraphs[4];
                case ColumnName::P6: return pattern.mParagraphs[5];
                case ColumnName::P7: return pattern.mParagraphs[6];
                case ColumnName::P8: return pattern.mParagraphs[7];
                case ColumnName::P9: return pattern.mParagraphs[8];
                case ColumnName::P10: return pattern.mParagraphs[9];
                case ColumnName::P11: return pattern.mParagraphs[10];
                case ColumnName::P12: return pattern.mParagraphs[11];
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
        pattern.mTitles[i] = patternTemp.mTitles[i];
        pattern.mParagraphs[i] = patternTemp.mParagraphs[i];
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

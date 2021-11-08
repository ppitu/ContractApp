#ifndef PATTERNMODEL_H
#define PATTERNMODEL_H

#include <QAbstractTableModel>
#include <QHash>
#include <vector>
#include <memory>

#include "Class/Pattern.h"
#include "Database/DatabaseManager.h"

#include "../contractapp-core_global.h"

class CONTRACTAPPCORE_EXPORT PatternModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    enum ColumnName {
        ID = 0,
        NAME, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12
    };

    enum Roles {
        ID_ROLE = Qt::UserRole + 1
    };

    PatternModel(QObject* parent = nullptr);

    QModelIndex addPattern(const Pattern& pattern);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role) override;
    bool removeRows(int row, int count, const QModelIndex& parent) override;
    QHash<int, QByteArray> roleNames() const override;

private:
    bool isIndexValid(const QModelIndex& index) const;

private:
    DatabaseManager& mDb;
    std::unique_ptr<std::vector<std::unique_ptr<Pattern>>> mPatterns;
};

#endif // PATTERNMODEL_H

#ifndef PERSONMODEL_H
#define PERSONMODEL_H

#include <QAbstractTableModel>
#include <QHash>
#include <vector>
#include <memory>

#include "Class/Person.h"
#include "Database/DatabaseManager.h"

class PersonModel : public QAbstractTableModel
{
    Q_OBJECT
public:

    enum Roles {
        ID_ROLE = Qt::UserRole + 1,
        FIRST_NAME_ROLE,
        LAST_NAME_ROLE,
        EMAIL_ROLE,
        CITY_ROLE
    };

    enum ColumnName {
        ID = 0,
        FIRST_NAME,
        LAST_NAME,
        EMAIL,
        CITY
    };

    PersonModel(const QString& view, QObject* parent = 0);

    QModelIndex addPerson(const Person& person);

    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    int columnCount(const QModelIndex& paernt = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role) override;
    bool removeRows(int row, int count, const QModelIndex& parent) override;
    QHash<int, QByteArray> roleNames() const override;

private:
    bool isIndexValid(const QModelIndex& index) const;

private:
    DatabaseManager& mDb;
    std::unique_ptr<std::vector<std::unique_ptr<Person>>> mPersons;

};

#endif // PERSONMODEL_H

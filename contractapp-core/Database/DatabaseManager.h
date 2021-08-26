#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <memory>

#include <QString>

#include "DatabaseClass/PersonDao.h"

class QSqlDatabase;
class QSqlQuery;

const QString DATABASE_FILENAME = "contractapp.db";

class DatabaseManager
{
public:
    static void debugQuery(const QSqlQuery& query);

    static DatabaseManager &instance();
    ~DatabaseManager();

protected:
    DatabaseManager(const QString& path = DATABASE_FILENAME);
    DatabaseManager& operator=(const DatabaseManager& rhs);

private:
    std::unique_ptr<QSqlDatabase> m_database;

public:
    const PersonDao m_persondao;
};

#endif // DATABASEMANAGER_H

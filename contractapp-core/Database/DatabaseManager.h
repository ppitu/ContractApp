#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QString>
#include <memory>

#include "DatabaseClass/PersonDao.h"
#include "DatabaseClass/PatternDao.h"

class QSqlDatabase;
class QSqlQuery;

const QString DATABASE_FILENAME = "contractapp.db";

class DatabaseManager {
public:
    static void debugQuery(const QSqlQuery &query);

    static DatabaseManager &instance();
    ~DatabaseManager();

protected:
    DatabaseManager(const QString &path = DATABASE_FILENAME);

private:
    std::unique_ptr<QSqlDatabase> mDatabase;

public:
    const PersonDao mPersonDao;
    const PatternDao mPatternDao;
};

#endif // DATABASEMANAGER_H

#include "DatabaseManager.h"

#include <QSqlDatabase>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

void DatabaseManager::debugQuery(const QSqlQuery &query)
{
    if(query.lastError().type() == QSqlError::ErrorType::NoError) {
        qDebug() << "Query OK: " << query.lastQuery();
    } else {
        qWarning() << "Query KO: " << query.lastError().text();
        qWarning() << "Query text: " << query.lastQuery();
    }
}

DatabaseManager &DatabaseManager::instance()
{
    static DatabaseManager singleton;
    return singleton;
}

DatabaseManager::~DatabaseManager()
{
    m_database->close();
}

DatabaseManager::DatabaseManager(const QString &path) :
    m_database(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE"))),
    m_persondao(*m_database)
{
    m_database->setDatabaseName(path);
    bool openStatus = m_database->open();

    qDebug() << "Database connection: " << (openStatus ? "OK" : "Error");

    m_persondao.init();
}

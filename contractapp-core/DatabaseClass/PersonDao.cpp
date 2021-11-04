#include "PersonDao.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>

#include "Database/DatabaseManager.h"

#include "Class/Person.h"

PersonDao::PersonDao(QSqlDatabase &database) : mDatabase(database)
{

}

void PersonDao::init() const
{
    if(!mDatabase.tables().contains("person"))
    {
        QSqlQuery query(mDatabase);
        query.exec("CREATE TABLE person (id INTEGER PRIMARY KEY AUTOINCREMENT, first_name VARCHAR(50), last_name VARCHAR(50), email VARCHAR(50), city VARCHAR(50), principal INTEGER NOT NULL)");
    }

    if(!mDatabase.tables().contains("v_contractor"))
    {
        QSqlQuery query(mDatabase);
        query.exec("CREATE VIEW v_contractor AS SELECT * FROM person WHERE principal = 0;");
    }

    if(!mDatabase.tables().contains("v_principal"))
    {
        QSqlQuery query(mDatabase);
        query.exec("CREATE VIEW v_principal AS SELECT * FROM person WHERE principal = 1;");
    }
}

void PersonDao::addPerson(Person &person) const
{
    QSqlQuery query(mDatabase);
    query.prepare("INSERT INTO person (first_name, last_name, email, city, principal) VALUES (:first_name, :last_name, :email, :city, :principal)");
    query.bindValue(":first_name", person.firstName());
    query.bindValue(":last_name", person.lastName());
    query.bindValue(":email", person.email());
    query.bindValue(":city", person.city());
    query.bindValue(":principal", person.isPrincipal());
    query.exec();
    person.setId(query.lastInsertId().toInt());
    DatabaseManager::debugQuery(query);
}

void PersonDao::updatePerson(const Person &person) const
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE person SET first_name = (:first_name), last_name = (:last_name), email = (:email), city = (:city), principal = (:principal) WHERE id = (:id)");
    query.bindValue(":first_name", person.firstName());
    query.bindValue(":last_name", person.lastName());
    query.bindValue(":email", person.email());
    query.bindValue(":city", person.city());
    query.bindValue(":id", person.id());
    query.bindValue(":principal", person.isPrincipal());
    query.exec();
    DatabaseManager::debugQuery(query);
}

void PersonDao::removePerson(int id) const
{
    QSqlQuery query(mDatabase);
    query.prepare("DELETE FROM person WHERE id = (:id)");
    query.bindValue(":id", id);
    query.exec();
    DatabaseManager::debugQuery(query);
}

std::unique_ptr<std::vector<std::unique_ptr<Person>>> PersonDao::persons(const QString& view) const
{
    QSqlQuery query("SELECT * FROM " + view, mDatabase);
    query.exec();
    DatabaseManager::debugQuery(query);
    std::unique_ptr<std::vector<std::unique_ptr<Person>>> list(new std::vector<std::unique_ptr<Person>>());
    while(query.next())
    {
        std::unique_ptr<Person> person(new Person());
        person->setId(query.value("id").toInt());
        person->setFirstName(query.value("first_name").toString());
        person->setLastName(query.value("last_name").toString());
        person->setEmail(query.value("email").toString());
        person->setCity(query.value("city").toString());
        person->setPrincipal(query.value("principal").toInt());
        list->push_back(std::move(person));
    }

    return list;
}

PersonDao::~PersonDao() = default;

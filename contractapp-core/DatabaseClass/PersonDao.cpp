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
        query.exec("CREATE TABLE person (id INTEGER PRIMARY KEY AUTOINCREMENT, first_name VARCHAR(50), last_name VARCHAR(50), " \
                   "email VARCHAR(50), city VARCHAR(50), nip VARCHAR(9), date_of_birth VARCHAR(20), pesel VARCHAR(11), " \
                   "street VARCHAR(50), house_number VARCHAR(10), flat_number VARCHAR(10), post_code VARCHAR(20), " \
                   "municipality VARCHAR(30), county VARCHAR(30), country VARCHAR(30), province VARCHAR(30), phone VARCHAR(20), principal INTEGER NOT NULL)");
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
    query.prepare("INSERT INTO person (first_name, last_name, email, city, nip, date_of_birth, pesel, street, house_number, flat_number, post_code, "
                  "municipality, county, country, province, phone,  principal) VALUES (:first_name, :last_name, :email, :city, :nip, :date_of_birth, :pesel, :street, "
                  ":house_number, :flat_number, :post_code, :municipality, :county, :country, :province, :phone, :principal)");
    query.bindValue(":first_name", person.firstName());
    query.bindValue(":last_name", person.lastName());
    query.bindValue(":email", person.email());
    query.bindValue(":city", person.city());
    query.bindValue(":principal", person.isPrincipal());
    query.bindValue(":nip", person.nip());
    query.bindValue(":pesel", person.pesel());
    query.bindValue(":date_of_birth", person.dataOfBirth());
    query.bindValue(":street", person.street());
    query.bindValue(":house_number", person.houseNumber());
    query.bindValue(":flat_number", person.flatNumber());
    query.bindValue(":post_code", person.postCode());
    query.bindValue(":municipality", person.municipality());
    query.bindValue(":county", person.county());
    query.bindValue(":country", person.country());
    query.bindValue(":province", person.province());
    query.bindValue(":phone", person.phone());
    query.exec();
    person.setId(query.lastInsertId().toInt());
    DatabaseManager::debugQuery(query);
}

void PersonDao::updatePerson(const Person &person) const
{
    QSqlQuery query(mDatabase);
    query.prepare("UPDATE person SET first_name = (:first_name), last_name = (:last_name), email = (:email), city = (:city), nip = (:nip), pesel = (:pesel), "
                  "date_of_birth = (:date_of_birth), street = (:street), house_number = (:house_number), flat_number = (:flat_number), post_code = (:post_code), "
                  "municipality = (:municipality), county = (:county), country = (:country), province = (:province), phone = (:phone),  principal = (:principal) WHERE id = (:id)");
    query.bindValue(":first_name", person.firstName());
    query.bindValue(":last_name", person.lastName());
    query.bindValue(":email", person.email());
    query.bindValue(":city", person.city());
    query.bindValue(":id", person.id());
    query.bindValue(":principal", person.isPrincipal());
    query.bindValue(":nip", person.nip());
    query.bindValue(":pesel", person.pesel());
    query.bindValue(":date_of_birth", person.dataOfBirth());
    query.bindValue(":street", person.street());
    query.bindValue(":house_number", person.houseNumber());
    query.bindValue(":flat_number", person.flatNumber());
    query.bindValue(":post_code", person.postCode());
    query.bindValue(":municipality", person.municipality());
    query.bindValue(":county", person.county());
    query.bindValue(":country", person.country());
    query.bindValue(":province", person.province());
    query.bindValue(":phone", person.phone());
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
        person->setIsPrincipal(query.value("principal").toInt());
        person->setNIP(query.value("nip").toString());
        person->setPESEL(query.value("pesel").toString());
        person->setCountry(query.value("country").toString());
        person->setCounty(query.value("county").toString());
        person->setDataOfBirth(query.value("date_of_birth").toString());
        person->setFlatNumber(query.value("flat_number").toString());
        person->setHouseNumber(query.value("house_number").toString());
        person->setMunicipality(query.value("municipality").toString());
        person->setPostCode(query.value("post_code").toString());
        person->setProvince(query.value("provice").toString());
        person->setStreet(query.value("street").toString());
        person->setPhone(query.value("phone").toString());
        list->push_back(std::move(person));
    }

    return list;
}

PersonDao::~PersonDao() = default;

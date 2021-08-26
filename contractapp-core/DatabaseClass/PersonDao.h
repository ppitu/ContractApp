#ifndef PERSONDAO_H
#define PERSONDAO_H

#include <QVector>
#include <memory>
#include <vector>

class QSqlDatabase;
class Person;

class PersonDao
{
public:
    PersonDao(QSqlDatabase &database);
    void init() const;
    void addPerson(Person& person) const;
    void updatePerson(const Person& person) const;
    void removePerson(int id) const;
    std::unique_ptr<std::vector<std::unique_ptr<Person>>> persons() const;

private:
    QSqlDatabase& m_database;
};

#endif // PERSONDAO_H

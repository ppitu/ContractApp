#ifndef PERSONDAO_H
#define PERSONDAO_H

#include <QString>
#include <memory>
#include <vector>

class QSqlDatabase;
class Person;

class PersonDao {
public:
    explicit PersonDao(QSqlDatabase &database);
    void init() const;
    void addPerson(Person &person) const;
    void updatePerson(const Person &person) const;
    void removePerson(int id) const;
    [[nodiscard]] std::unique_ptr<std::vector<std::unique_ptr<Person>>>
    persons(const QString &view) const;
    virtual ~PersonDao();

private:
    QSqlDatabase &mDatabase;
};

#endif // PERSONDAO_H

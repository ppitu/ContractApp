#ifndef PERSON_H
#define PERSON_H

#include "contractapp-core_global.h"

#include <QString>

class CONTRACTAPPCORE_EXPORT Person
{
public:
    explicit Person(const QString& firstName = "", const QString& lastName = "", const QString& email = "", const QString& city = "");

    int id() const;
    void setId(int id);
    QString firstName() const;
    void setFirstName(const QString& name);
    QString lastName() const;
    void setLastName(const QString& name);
    QString email() const;
    void setEmail(const QString& mail);
    QString city() const;
    void setCity(const QString& city);

private:
    int mId;
    QString mFirstName;
    QString mLastName;
    QString mEmail;
    QString mCity;

};

#endif // PERSON_H

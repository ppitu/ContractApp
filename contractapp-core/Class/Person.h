#ifndef PERSON_H
#define PERSON_H

#include "contractapp-core_global.h"

#include <QMetaType>
#include <QString>

class CONTRACTAPPCORE_EXPORT Person {
public:
    Person(const QString &firstName = "", const QString &lastName = "",
           const QString &email = "", const QString &city = "",
           bool Principal = false);
    Person(const Person& person);
    int id() const;
    void setId(int id);
    QString firstName() const;
    void setFirstName(const QString &name);
    QString lastName() const;
    void setLastName(const QString &name);
    QString email() const;
    void setEmail(const QString &mail);
    QString city() const;
    void setCity(const QString &city);
    void setPrincipal(int principal);
    int isPrincipal() const;

private:
    int mId{};
    QString mFirstName;
    QString mLastName;
    QString mEmail;
    QString mCity;
    int mIsPrincipal;
};

Q_DECLARE_METATYPE(Person);

#endif // PERSON_H

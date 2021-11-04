#include "Person.h"

Person::Person(const QString &firstName, const QString &lastName,
               const QString &email, const QString &city, bool principal)
    : mId(-1), mFirstName(firstName), mLastName(lastName), mEmail(email),
      mCity(city), mIsPrincipal(principal) {}

Person::Person(const Person &person)
{
    mId = person.mId;
    mFirstName = person.mFirstName;
    mLastName = person.mLastName;
    mEmail = person.mEmail;
    mCity = person.mCity;
    mIsPrincipal = person.mIsPrincipal;
}

int Person::id() const { return mId; }

void Person::setId(int id) { mId = id; }

QString Person::firstName() const { return mFirstName; }

void Person::setFirstName(const QString &name) { mFirstName = name; }

QString Person::lastName() const { return mLastName; }

void Person::setLastName(const QString &name) { mLastName = name; }

QString Person::email() const { return mEmail; }

void Person::setEmail(const QString &mail) { mEmail = mail; }

QString Person::city() const { return mCity; }

void Person::setCity(const QString &city) { mCity = city; }

void Person::setPrincipal(int principal) { mIsPrincipal = principal; }

int Person::isPrincipal() const { return mIsPrincipal; }

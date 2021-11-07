#include "Person.h"

Person::Person()
{

}

Person::Person(const Person &person)
{
    mId = person.mId;
    mFirstName = person.mFirstName;
    mLastName = person.mLastName;
    mEmail = person.mEmail;
    mCity = person.mCity;
    mIsPrincipal = person.mIsPrincipal;
}

const QString &Person::nip() const
{
    return mNIP;
}

void Person::setNIP(const QString &newNIP)
{
    mNIP = newNIP;
}

const QString &Person::pesel() const
{
    return mPESEL;
}

void Person::setPESEL(const QString &newPESEL)
{
    mPESEL = newPESEL;
}

const QString &Person::dataOfBirth() const
{
    return mDataOfBirth;
}

void Person::setDataOfBirth(const QString &newDataOfBirth)
{
    mDataOfBirth = newDataOfBirth;
}

const QString &Person::street() const
{
    return mStreet;
}

void Person::setStreet(const QString &newStreet)
{
    mStreet = newStreet;
}

const QString &Person::houseNumber() const
{
    return mHouseNumber;
}

void Person::setHouseNumber(const QString &newHouseNumber)
{
    mHouseNumber = newHouseNumber;
}

const QString &Person::flatNumber() const
{
    return mFlatNumber;
}

void Person::setFlatNumber(const QString &newFlatNumber)
{
    mFlatNumber = newFlatNumber;
}

const QString &Person::postCode() const
{
    return mPostCode;
}

void Person::setPostCode(const QString &newPostCode)
{
    mPostCode = newPostCode;
}

const QString &Person::municipality() const
{
    return mMunicipality;
}

void Person::setMunicipality(const QString &newMunicipality)
{
    mMunicipality = newMunicipality;
}

const QString &Person::county() const
{
    return mCounty;
}

void Person::setCounty(const QString &newCounty)
{
    mCounty = newCounty;
}

const QString &Person::country() const
{
    return mCountry;
}

void Person::setCountry(const QString &newCountry)
{
    mCountry = newCountry;
}

const QString &Person::privince() const
{
    return mPrivince;
}

void Person::setProvince(const QString &newPrivince)
{
    mPrivince = newPrivince;
}

void Person::setIsPrincipal(int newIsPrincipal)
{
    mIsPrincipal = newIsPrincipal;
}

int Person::id() const
{
    return mId;
}

void Person::setId(int newId)
{
    mId = newId;
}

const QString &Person::firstName() const
{
    return mFirstName;
}

void Person::setFirstName(const QString &newFirstName)
{
    mFirstName = newFirstName;
}

const QString &Person::lastName() const
{
    return mLastName;
}

void Person::setLastName(const QString &newLastName)
{
    mLastName = newLastName;
}

const QString &Person::email() const
{
    return mEmail;
}

void Person::setEmail(const QString &newEmail)
{
    mEmail = newEmail;
}

const QString &Person::city() const
{
    return mCity;
}

void Person::setCity(const QString &newCity)
{
    mCity = newCity;
}

int Person::isPrincipal() const
{
    return mIsPrincipal;
}

Person::Person(const QString &firstName, const QString &lastName, const QString &email, const QString &city, const QString &nIP, const QString &pESEL,
               const QString &dataOfBirth, const QString &street, const QString &houseNumber, const QString &flatNumber, const QString &postCode,
               const QString &municipality, const QString &county, const QString &country, const QString &privince, int isPrincipal)
    : mId(-1),
    mFirstName(firstName),
    mLastName(lastName),
    mEmail(email),
    mCity(city),
    mNIP(nIP),
    mPESEL(pESEL),
    mDataOfBirth(dataOfBirth),
    mStreet(street),
    mHouseNumber(houseNumber),
    mFlatNumber(flatNumber),
    mPostCode(postCode),
    mMunicipality(municipality),
    mCounty(county),
    mCountry(country),
    mPrivince(privince),
    mIsPrincipal(isPrincipal)
{}

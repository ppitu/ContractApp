#ifndef PERSON_H
#define PERSON_H

#include "contractapp-core_global.h"

#include <QMetaType>
#include <QString>

class CONTRACTAPPCORE_EXPORT Person {
public:

    Person(const QString &firstName, const QString &lastName, const QString &email, const QString &city,
           const QString &nIP, const QString &pESEL, const QString &dataOfBirth, const QString &street,
           const QString &houseNumber, const QString &flatNumber, const QString &postCode, const QString &municipality,
           const QString &county, const QString &country, const QString &privince, const QString& phone, int isPrincipal);
    Person();
    Person(const Person& person);

    const QString &nip() const;
    void setNIP(const QString &newNIP);
    const QString &pesel() const;
    void setPESEL(const QString &newPESEL);
    const QString &dataOfBirth() const;
    void setDataOfBirth(const QString &newDataOfBirth);
    const QString &street() const;
    void setStreet(const QString &newStreet);
    const QString &houseNumber() const;
    void setHouseNumber(const QString &newHouseNumber);
    const QString &flatNumber() const;
    void setFlatNumber(const QString &newFlatNumber);
    const QString &postCode() const;
    void setPostCode(const QString &newPostCode);
    const QString &municipality() const;
    void setMunicipality(const QString &newMunicipality);
    const QString &county() const;
    void setCounty(const QString &newCounty);
    const QString &country() const;
    void setCountry(const QString &newCountry);
    const QString &province() const;
    void setProvince(const QString &newPrivince);
    void setIsPrincipal(int newIsPrincipal);
    int id() const;
    void setId(int newId);
    const QString &firstName() const;
    void setFirstName(const QString &newFirstName);
    const QString &lastName() const;
    void setLastName(const QString &newLastName);
    const QString &email() const;
    void setEmail(const QString &newEmail);
    const QString &city() const;
    void setCity(const QString &newCity);
    int isPrincipal() const;

    const QString &phone() const;
    void setPhone(const QString &newPhone);

private:
    int mId{};
    QString mFirstName{};
    QString mLastName{};
    QString mEmail{};
    QString mCity{};
    QString mNIP{};
    QString mPESEL{};
    QString mDataOfBirth{};
    QString mStreet{};
    QString mHouseNumber{};
    QString mFlatNumber{};
    QString mPostCode{};
    QString mMunicipality{};
    QString mCounty{};
    QString mCountry{};
    QString mProvince{};
    QString mPhone{};
    int mIsPrincipal{};
};

Q_DECLARE_METATYPE(Person);

#endif // PERSON_H

#include "PersonDialog.h"
#include "ui_PersonDialog.h"

#include "Class/Person.h"

PersonDialog::PersonDialog(Person& person, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonDialog),
    mPerson(person)
{
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &PersonDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &PersonDialog::reject);

    ui->elEmail->setText(mPerson.email());
    ui->elCity->setText(mPerson.city());
    ui->elFirstName->setText(mPerson.firstName());
    ui->elLastName->setText(mPerson.lastName());
    ui->elCountry->setText(mPerson.country());
    ui->elCounty->setText(mPerson.county());
    ui->elFlatNumber->setText(mPerson.flatNumber());
    ui->elHouseNumber->setText(mPerson.houseNumber());
    ui->elMunicipality->setText(mPerson.municipality());
    ui->elNip->setText(mPerson.nip());
    ui->elPesel->setText(mPerson.pesel());
    ui->elPostCode->setText(mPerson.postCode());
    ui->elProvince->setText(mPerson.province());
    ui->elStreet->setText(mPerson.street());
    ui->elPhone->setText(mPerson.phone());
}

PersonDialog::~PersonDialog()
{
    delete ui;
}

void PersonDialog::accept()
{
    mPerson.setCity(ui->elCity->text());
    mPerson.setFirstName(ui->elFirstName->text());
    mPerson.setLastName(ui->elLastName->text());
    mPerson.setEmail(ui->elEmail->text());
    mPerson.setCountry(ui->elCountry->text());
    mPerson.setCounty(ui->elCounty->text());
    mPerson.setDataOfBirth(ui->deDateOfBirth->date().toString());
    mPerson.setFlatNumber(ui->elFlatNumber->text());
    mPerson.setHouseNumber(ui->elHouseNumber->text());
    mPerson.setMunicipality(ui->elMunicipality->text());
    mPerson.setNIP(ui->elNip->text());
    mPerson.setPESEL(ui->elPesel->text());
    mPerson.setPostCode(ui->elPostCode->text());
    mPerson.setProvince(ui->elProvince->text());
    mPerson.setStreet(ui->elStreet->text());
    mPerson.setPhone(ui->elPhone->text());

    QDialog::accept();
}

void PersonDialog::reject()
{
    QDialog::reject();
}

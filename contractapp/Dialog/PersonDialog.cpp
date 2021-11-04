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

    QDialog::accept();
}

void PersonDialog::reject()
{
    QDialog::reject();
}

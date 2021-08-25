#include "PersonDialog.h"
#include "ui_PersonDialog.h"

PersonDialog::PersonDialog(Person& person, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonDialog),
    mPerson(person)
{
    ui->setupUi(this);

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &PersonDialog::accept);
}

PersonDialog::~PersonDialog()
{
    delete ui;
}

void PersonDialog::accept() {
    mPerson.setFirstName(ui->elFirstName->text());
    mPerson.setLastName(ui->elLastName->text());
    mPerson.setEmail(ui->elEMail->text());
    mPerson.setCity(ui->elCity->text());

    QDialog::accept();
}

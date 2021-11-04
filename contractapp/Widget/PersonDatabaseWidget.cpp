#include "PersonDatabaseWidget.h"
#include "ui_PersonDatabaseWidget.h"
#include "PersonWidget.h"
#include "Model/PersonModel.h"

PersonDatabaseWidget::PersonDatabaseWidget(PersonModel* principalModel, PersonModel* contractorModel, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonDatabaseWidget),
    mPrincipalModel(principalModel),
    mContractorModel(contractorModel),
    mPrincipalWidget(new PersonWidget(1, this)),
    mContractorWidget(new PersonWidget(0, this))
{
    ui->setupUi(this);

    mPrincipalWidget->setModel(mPrincipalModel);
    mContractorWidget->setModel(mContractorModel);

    ui->tbPerson->clear();
    ui->tbPerson->addTab(mPrincipalWidget, "Principal");
    ui->tbPerson->addTab(mContractorWidget, "contractor");
}

PersonDatabaseWidget::~PersonDatabaseWidget()
{
    delete ui;
}

//
// Created by ppitu on 26.08.2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ContractWidget.h" resolved

#include "ContractWidget.h"
#include "ui_ContractWidget.h"

#include "Model/PersonModel.h"

ContractWidget::ContractWidget(PersonModel* principalModel, PersonModel* contractorModel, QWidget *parent) :
        QWidget(parent),
        ui(new Ui::ContractWidget),
        mPrincipalModel(principalModel),
        mContractorModel(contractorModel)
{
    ui->setupUi(this);
    ui->cbPrincipal->setModel(mPrincipalModel);
    ui->cbPrincipal->setModelColumn(1);
    ui->cbContractor->setModel(mContractorModel);
    ui->cbContractor->setModelColumn(1);
}

ContractWidget::~ContractWidget() {
    delete ui;
}



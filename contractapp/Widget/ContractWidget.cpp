//
// Created by ppitu on 26.08.2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ContractWidget.h" resolved

#include "ContractWidget.h"
#include "ui_ContractWidget.h"


ContractWidget::ContractWidget(QWidget *parent) :
        QWidget(parent), ui(new Ui::ContractWidget) {
    ui->setupUi(this);
}

ContractWidget::~ContractWidget() {
    delete ui;
}


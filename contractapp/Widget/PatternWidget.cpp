//
// Created by ppitu on 31.08.2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PatternWidget.h" resolved

#include "PatternWidget.h"
#include "ui_PatternWidget.h"
#include "Model/PatternModel.h"

PatternWidget::PatternWidget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::PatternWidget){
    ui->setupUi(this);
}

PatternWidget::~PatternWidget() {
    delete ui;
}

void PatternWidget::setModel(PatternModel *model) {
    mPatternModel = model;
    ui->grdPattern->setModel(model);
}


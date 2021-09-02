//
// Created by ppitu on 31.08.2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PatternWidget.h" resolved

#include "PatternWidget.h"
#include "ui_PatternWidget.h"
#include "Model/PatternModel.h"

PatternWidget::PatternWidget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::PatternWidget),
        indexOfLast(0)
{
    ui->setupUi(this);

    connect(ui->edit, &QPushButton::clicked, this, &PatternWidget::edit);
}

PatternWidget::~PatternWidget() {
    delete ui;
}

void PatternWidget::setModel(PatternModel *model) {
    mPatternModel = model;
    ui->grdPattern->setModel(model);
}

void PatternWidget::edit() {
    if(ui->grdPattern->selectionModel()->selectedIndexes().isEmpty())
    {
        return;
    }

    QModelIndex currentPatternIndex = ui->grdPattern->selectionModel()->selectedIndexes().first();

    mPattern = qvariant_cast<Pattern>(mPatternModel->data(currentPatternIndex, PatternModel::Roles::ID_ROLE));

    QLayoutItem* item;

    while((item = ui->horizontalLayout->layout()->takeAt(0)) != nullptr)
    {
        delete item->widget();
        delete item;
    }

    for(auto & mTitle : mPattern.mTitles)
    {
        auto btn = new QPushButton(mTitle);
        connect(btn, &QPushButton::clicked, this, [this, btn] () {
            mPattern.mParagraphs[indexOfLast] = ui->plainTextEdit->toPlainText();
            ui->plainTextEdit->setPlainText(mPattern.mParagraphs[ui->horizontalLayout->indexOf(btn)]);
            indexOfLast = ui->horizontalLayout->indexOf(btn);
        });

        ui->horizontalLayout->addWidget(btn);
    }

    ui->plainTextEdit->setPlainText(mPattern.mParagraphs[0]);
}


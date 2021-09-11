//
// Created by ppitu on 31.08.2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_PatternWidget.h" resolved

#include <QMessageBox>
#include "PatternWidget.h"
#include "ui_PatternWidget.h"
#include "Model/PatternModel.h"

PatternWidget::PatternWidget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::PatternWidget),
        indexOfLast(0),
        isEdit(false)
{
    ui->setupUi(this);
    ui->plainTextEdit->setEnabled(false);
    ui->btnCancel->setVisible(false);
    connect(ui->grdPattern, &QTableView::clicked, this, &PatternWidget::loadPattern);
    connect(ui->btnEditSave, &QPushButton::clicked, this, &PatternWidget::edit);
}

PatternWidget::~PatternWidget() {
    delete ui;
}

void PatternWidget::setModel(PatternModel *model) {
    mPatternModel = model;
    ui->grdPattern->setModel(model);
}

void PatternWidget::loadPattern() {
    if(ui->grdPattern->selectionModel()->selectedIndexes().isEmpty())
    {
        return;
    }

    if(isEdit)
    {
        QMessageBox msgBox;
        msgBox.setText("Uwaga edycja");
        msgBox.exec();
        save();
    }

    currentPatternIndex = ui->grdPattern->selectionModel()->selectedIndexes().first();

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

void PatternWidget::edit() {
    if(isEdit)
    {
        save();
        ui->plainTextEdit->setEnabled(false);
        ui->btnEditSave->setText("Edytuj");
        ui->btnCancel->setVisible(false);
        isEdit = false;
    } else
    {
        ui->plainTextEdit->setEnabled(true);
        ui->btnEditSave->setText("Zapisz");
        ui->btnCancel->setVisible(true);
        isEdit = true;
    }
}

void PatternWidget::save() {
    mPattern.mParagraphs[indexOfLast] = ui->plainTextEdit->toPlainText();
    mPatternModel->setData(currentPatternIndex, QVariant::fromValue(mPattern), PatternModel::Roles::ID_ROLE);
}


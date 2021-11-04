#include "PatternWidget.h"
#include "ui_PatternWidget.h"

#include "Model/PatternModel.h"

#include <QMessageBox>

PatternWidget::PatternWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatternWidget),
    isEdit(false),
    isNew(false)
{
    ui->setupUi(this);
    ui->plainTextEdit->setEnabled(false);
    ui->btnCancel->setVisible(false);
    connect(ui->grdPattern, &QTableView::clicked, this, &PatternWidget::loadPattern);
    connect(ui->btnEditSave, &QPushButton::clicked, this, &PatternWidget::editPattern);
    connect(ui->btnNewPattern, &QPushButton::clicked, this, &PatternWidget::newPattern);
    connect(ui->btnNewParagraph, &QPushButton::clicked, this, &PatternWidget::addParagraph);
    connect(ui->btnRemovePattern, &QPushButton::clicked, this, &PatternWidget::removePattern);
    connect(ui->btnRemoveParagraph, &QPushButton::clicked, this, &PatternWidget::removeParagraph);
}

PatternWidget::~PatternWidget()
{
    delete ui;
}

void PatternWidget::setModel(PatternModel *model)
{
    mPatternModel = model;
    ui->grdPattern->setModel(model);
}

void PatternWidget::loadPattern()
{
    if(ui->grdPattern->selectionModel()->selectedIndexes().isEmpty())
    {
        return;
    }

    if(isEdit)
    {
        QMessageBox msgBox;
        msgBox.setText("Uwaga edycja!");
        msgBox.exec();
        save();
    }

    currentPatternIndex = ui->grdPattern->selectionModel()->selectedIndexes().first();

    mPattern = qvariant_cast<Pattern>(mPatternModel->data(currentPatternIndex, PatternModel::Roles::ID_ROLE));

    clearPatternButtons();

    for(int i = 0; i < mPattern.getTitlesSize(); i++)
    {
        if(mPattern.getTitle(i) == "")
        {
            break;
        }

        auto btn = new QPushButton(mPattern.getTitle(i));
        connect(btn, &QPushButton::clicked, this, [this, btn]() {
            if(indexOfLast.has_value())
            {
                mPattern.setParagraph(indexOfLast.value(), ui->plainTextEdit->toPlainText());
            }
            ui->plainTextEdit->setPlainText(mPattern.getParagraph(ui->hlPatternButton->indexOf(btn)));
            indexOfLast = ui->hlPatternButton->indexOf(btn);
        });

        ui->hlPatternButton->addWidget(btn);
    }

    ui->plainTextEdit->setPlainText(mPattern.getParagraph(0));
}

void PatternWidget::editPattern()
{
    if(isEdit)
    {
        if(!validate())
        {
            return;
        }

        save();
        ui->plainTextEdit->setEnabled(false);
        ui->btnEditSave->setText("Edutyj");
        ui->btnCancel->setVisible(false);
        ui->btnNewParagraph->setVisible(false);
        ui->btnRemoveParagraph->setVisible(false);
        isNew = false;
        isEdit = false;
    } else {
        ui->plainTextEdit->setEnabled(true);
        ui->btnEditSave->setText("Zapisz");
        ui->btnCancel->setVisible(true);
        ui->btnNewParagraph->setVisible(true);
        ui->btnRemoveParagraph->setVisible(true);
        isEdit = true;
    }
}

void PatternWidget::newPattern()
{
    clearPatternButtons();
        mPattern.clear();
        isNew = true;
        editPattern();
        ui->btnNewParagraph->setVisible(true);
        addParagraph();
}

void PatternWidget::addParagraph()
{
    mPattern.addTitle("T" + QString::number(mPattern.getTitlesSize() + 1));
        mPattern.addParagraph("Tresc nowego paragrafu");

        auto btn = new QPushButton(mPattern.getTitle(mPattern.getTitlesSize() - 1));
        connect(btn, &QPushButton::clicked, this, [this, btn] () {
            if(indexOfLast.has_value())
            {
                mPattern.getParagraph(indexOfLast.value()) = ui->plainTextEdit->toPlainText();
                ui->plainTextEdit->setPlainText(mPattern.getParagraph(ui->hlPatternButton->indexOf(btn)));
            }
            indexOfLast = ui->hlPatternButton->indexOf(btn);
        });

        ui->hlPatternButton->addWidget(btn);
}

void PatternWidget::removeParagraph()
{
    if(ui->grdPattern->selectionModel()->selectedIndexes().isEmpty())
            return;

        int row = ui->grdPattern->selectionModel()->currentIndex().row();
        mPatternModel->removeRow(row);
}

void PatternWidget::removePattern()
{
    if(mPattern.getTitlesSize() > 1)
        {
            mPattern.removeParagraph();
            mPattern.removeTitle();
            auto item = ui->hlPatternButton->layout()->takeAt(ui->hlPatternButton->count() - 1);
            delete item->widget();
            delete item;
        } else
        {
            QMessageBox msgBox;
            msgBox.setText("Liczba paragrafów nie może być mniejsza niż 1");
            msgBox.exec();
        }
}

void PatternWidget::save()
{
    if(indexOfLast.has_value())
    {
        mPattern.setParagraph(indexOfLast.value(), ui->plainTextEdit->toPlainText());
    }

    mPattern.setName(ui->edtPatternName->text());

    if(isNew)
    {
        QModelIndex createdIndex = mPatternModel->addPattern(mPattern);
        ui->grdPattern->setCurrentIndex(createdIndex);
    } else
    {
        mPatternModel->setData(currentPatternIndex, QVariant::fromValue(mPattern), PatternModel::Roles::ID_ROLE);
    }
}

void PatternWidget::clearPatternButtons()
{
    ui->edtPatternName->setText("");
        ui->plainTextEdit->setPlainText("");

        QLayoutItem *item;

        while((item = ui->hlPatternButton->layout()->takeAt(0)) != nullptr)
        {
            delete item->widget();
            delete item;
        }
}

bool PatternWidget::validate()
{
    if(ui->edtPatternName->text().isEmpty())
        {
            return false;
        }

        for(int i = 0; i < mPattern.getTitlesSize(); ++i)
        {
            if(mPattern.getTitle(i) == "" || mPattern.getParagraph(i) == "")
            {
                return false;
            }
        }

        return true;
}



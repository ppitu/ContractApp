#include "PersonWidget.h"
#include "ui_PersonWidget.h"

#include <QInputDialog>

#include "PersonModel.h"
#include "PersonDialog.h"

PersonWidget::PersonWidget(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::PersonWidget)
{
    ui->setupUi(this);

    connect(ui->createPerson, &QPushButton::clicked, this, &PersonWidget::createPerson);
}

PersonWidget::~PersonWidget()
{
    delete ui;
}

void PersonWidget::setModel(PersonModel *model)
{
    mPersonModel = model;
    ui->personTable->setModel(mPersonModel);
}

void PersonWidget::createPerson()
{
    Person person;

    auto *dialog = new PersonDialog(person);

    dialog->exec();


    QModelIndex createdIndex = mPersonModel->addPerson(person);
    ui->personTable->setCurrentIndex(createdIndex);

    delete dialog;
}

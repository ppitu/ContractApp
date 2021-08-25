#include "PersonWidget.h"
#include "ui_PersonWidget.h"

#include <QInputDialog>

#include "PersonModel.h"
#include "PersonDialog.h"

PersonWidget::PersonWidget(QWidget *parent) :
    QWizardPage(parent),
    ui(new Ui::PersonWidget),
    mPersonSelectionModel(nullptr),
    mPersonModel(nullptr)
{
    ui->setupUi(this);

    connect(ui->createPerson, &QPushButton::clicked, this, &PersonWidget::createPerson);
    connect(ui->removePerson, &QPushButton::clicked, this, &PersonWidget::removePerson);
    connect(ui->editPerson, &QPushButton::clicked, this, &PersonWidget::editPerson);
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

void PersonWidget::setPersonSelectionModel(QItemSelectionModel *personSelectionModel) {

}

void PersonWidget::removePerson() {
    int row = ui->personTable->selectionModel()->currentIndex().row();
    mPersonModel->removeRow(row);
}

void PersonWidget::editPerson() {
    QModelIndex currentPersonIndex = ui->personTable->selectionModel()->selectedIndexes().first();

    auto person = qvariant_cast<Person>(mPersonModel->data(currentPersonIndex, PersonModel::Roles::ID_ROLE));

    auto *dialog = new PersonDialog(person, this);

    dialog->exec();

    mPersonModel->setData(currentPersonIndex, QVariant::fromValue(person), PersonModel::Roles::ID_ROLE);

    delete dialog;
}

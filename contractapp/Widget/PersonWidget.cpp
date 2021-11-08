#include "PersonWidget.h"
#include "ui_PersonWidget.h"

#include "Model/PersonModel.h"
#include "Dialog/PersonDialog.h"

PersonWidget::PersonWidget(int principal, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PersonWidget),
    isPrincipal(principal),
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

void PersonWidget::setPersonSelectionModel(QItemSelectionModel *personSelectionModel)
{

}

int PersonWidget::getPrincipal() const
{
    return isPrincipal;
}

void PersonWidget::createPerson()
{
    Person person;

    auto *dialog = new PersonDialog(person);

    auto dialogCode = dialog->exec();

    if(dialogCode == QDialog::Accepted)
    {
        person.setIsPrincipal(isPrincipal);
        QModelIndex createdIndex = mPersonModel->addPerson(person);
        ui->personTable->setCurrentIndex(createdIndex);
    }

    delete dialog;

}

void PersonWidget::removePerson()
{
    if(ui->personTable->selectionModel()->selectedIndexes().isEmpty())
        return;

    int row = ui->personTable->selectionModel()->currentIndex().row();
    mPersonModel->removeRow(row);
}

void PersonWidget::editPerson()
{
    if(ui->personTable->selectionModel()->selectedIndexes().isEmpty())
        return;

    QModelIndex currentPersonIndex = ui->personTable->selectionModel()->selectedIndexes().first();

    auto person = qvariant_cast<Person>(mPersonModel->data(currentPersonIndex, PersonModel::Roles::ID_ROLE));

    auto *dialog = new PersonDialog(person, this);

    dialog->exec();

    mPersonModel->setData(currentPersonIndex, QVariant::fromValue(person), PersonModel::Roles::ID_ROLE);

    delete dialog;
}

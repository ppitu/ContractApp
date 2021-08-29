#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "Widget/PersonDatabaseWidget.h"
#include "Widget/ContractWidget.h"
#include "Model/PersonModel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mPersonDatabaseWidget(nullptr)
    , mContractWidget(nullptr)
    , mTabWidget(new QTabWidget(this))
{
    ui->setupUi(this);

    auto* principalModel = new PersonModel("v_principal", this);
    auto* contractorModel = new PersonModel("v_contractor", this);

    mPersonDatabaseWidget = new PersonDatabaseWidget(principalModel, contractorModel, this);
    mContractWidget = new ContractWidget(principalModel, contractorModel, this);

    mTabWidget->addTab(mContractWidget, "Umowy");
    mTabWidget->addTab(mPersonDatabaseWidget, "Baza Osob");

    setCentralWidget(mTabWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}


#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "Model/PersonModel.h"
#include "Widget/PersonWidget.h"
#include "Widget/ContractWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mPersonWidget(new PersonWidget(this))
    , mContractWidget(new ContractWidget(this))
    , mTabWidget(new QTabWidget(this))
{
    ui->setupUi(this);

    auto* personModel = new PersonModel(this);
    mPersonWidget->setModel(personModel);

    mTabWidget->addTab(mPersonWidget, "Baza osób");
    mTabWidget->addTab(mContractWidget, "Umowy");

    setCentralWidget(mTabWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}


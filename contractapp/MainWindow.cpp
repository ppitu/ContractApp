#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "Widget/PersonDatabaseWidget.h"
#include "Widget/PatternWidget.h"
#include "Model/PersonModel.h"
#include "Model/PatternModel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mPersonDatabaseWidget(nullptr)
    , mPatternWidget(nullptr)
    , mTabWidget(new QTabWidget(this))
{
    ui->setupUi(this);

    auto* principalModel = new PersonModel("v_principal", this);
    auto* contractorModel = new PersonModel("v_contractor", this);
    auto* patternModel = new PatternModel(this);

    mPersonDatabaseWidget = new PersonDatabaseWidget(principalModel, contractorModel, this);
    mPatternWidget = new PatternWidget(this);

    mPatternWidget->setModel(patternModel);

    mTabWidget->addTab(mPersonDatabaseWidget, "Baza Osob");
    mTabWidget->addTab(mPatternWidget, "Szablony umów");

    setCentralWidget(mTabWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}


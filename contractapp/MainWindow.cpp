#include "MainWindow.h"
#include "./ui_MainWindow.h"

#include "PersonModel.h"
#include "PersonWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mPersonWidget(new PersonWidget(this))
{
    ui->setupUi(this);

    PersonModel* personModel = new PersonModel(this);
    mPersonWidget->setModel(personModel);

    setCentralWidget(mPersonWidget);

}

MainWindow::~MainWindow()
{
    delete ui;
}


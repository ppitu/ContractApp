//
// Created by ppitu on 26.08.2021.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ContractWidget.h" resolved

#include "ContractWidget.h"
#include "ui_ContractWidget.h"

#include <QPrinter>

#include "Model/PersonModel.h"

ContractWidget::ContractWidget(PersonModel* principalModel, PersonModel* contractorModel, QWidget *parent) :
        QWidget(parent),
        ui(new Ui::ContractWidget),
        mPrincipalModel(principalModel),
        mContractorModel(contractorModel)
{
    ui->setupUi(this);

    connect(ui->btnPreview, &QPushButton::clicked, this, &ContractWidget::preview);

    ui->cbPrincipal->setModel(mPrincipalModel);
    ui->cbPrincipal->setModelColumn(1);
    ui->cbContractor->setModel(mContractorModel);
    ui->cbContractor->setModelColumn(1);
}

ContractWidget::~ContractWidget() {
    delete ui;
}

void ContractWidget::preview() {
    QString html =
            "<div align=right>"
            "City, 11/11/2015"
            "</div>"
            "<div align=left>"
            "Sender Name"
            "Test"
            "street 34/56A<br>"
            "121-43 city"
            "</div>"
            "<h1 align=center>DOCUMENT TITLE</h1>"
            "<p align=justify>"
            "document content document content document content document content document content document content document content document content document content document content "
            "document content document content document content document content document content document content document content document content document content document content "
            "</p>"
            "<div align=right>sincerly</div>";

    QTextDocument document;
    document.setHtml(html);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    //printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName("test.pdf");
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    document.print(&printer);
}



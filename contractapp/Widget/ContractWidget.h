//
// Created by ppitu on 26.08.2021.
//

#ifndef CONTRACTAPP_CONTRACTWIDGET_H
#define CONTRACTAPP_CONTRACTWIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class ContractWidget; }
QT_END_NAMESPACE

class PersonModel;

class ContractWidget : public QWidget {
Q_OBJECT

public:
    explicit ContractWidget(PersonModel* principalMode, PersonModel* contractorModel, QWidget *parent = nullptr);

    ~ContractWidget() override;


private:
    Ui::ContractWidget *ui;
    PersonModel* mPrincipalModel;
    PersonModel* mContractorModel;
};


#endif //CONTRACTAPP_CONTRACTWIDGET_H

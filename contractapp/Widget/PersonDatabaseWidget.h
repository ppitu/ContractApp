//
// Created by ppitu on 29.08.2021.
//

#ifndef CONTRACTAPP_PERSONDATABASEWIDGET_H
#define CONTRACTAPP_PERSONDATABASEWIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class PersonDatabaseWidget; }
QT_END_NAMESPACE

class PersonWidget;
class PersonModel;

class PersonDatabaseWidget : public QWidget {
Q_OBJECT

public:
    explicit PersonDatabaseWidget(PersonModel* principalModel, PersonModel* contractorModel, QWidget *parent = nullptr);

    ~PersonDatabaseWidget() override;

private:
    Ui::PersonDatabaseWidget *ui;
    PersonWidget* mPrincipalWidget;
    PersonWidget* mContractorWidget;
    PersonModel* mPrincipalModel;
    PersonModel* mContractorModel;
};


#endif //CONTRACTAPP_PERSONDATABASEWIDGET_H

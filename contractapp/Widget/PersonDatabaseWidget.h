#ifndef PERSONDATABASEWIDGET_H
#define PERSONDATABASEWIDGET_H

#include <QWidget>

namespace Ui {
class PersonDatabaseWidget;
}

class PersonWidget;
class PersonModel;

class PersonDatabaseWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PersonDatabaseWidget(PersonModel* principalModel, PersonModel* contractorModel, QWidget *parent = nullptr);
    ~PersonDatabaseWidget();

private:
    Ui::PersonDatabaseWidget *ui;
    PersonWidget* mPrincipalWidget;
    PersonWidget* mContractorWidget;
    PersonModel* mPrincipalModel;
    PersonModel* mContractorModel;
};

#endif // PERSONDATABASEWIDGET_H

#ifndef PERSONWINDOW_H
#define PERSONWINDOW_H

#include <QDialog>

#include "Class/Person.h"

namespace Ui {
class PersonDialog;
}

class PersonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PersonDialog(Person& person, QWidget *parent = nullptr);
    ~PersonDialog() override;

private slots:
    void accept();
    void reject();

private:
    Ui::PersonDialog *ui;
    Person& mPerson;
};

#endif // PERSONWINDOW_H

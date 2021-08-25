#ifndef PERSONWIDGET_H
#define PERSONWIDGET_H

#include <QWizardPage>

namespace Ui {
class PersonWidget;
}

class PersonModel;

class PersonWidget : public QWizardPage
{
    Q_OBJECT

public:
    explicit PersonWidget(QWidget *parent = nullptr);
    ~PersonWidget();

    void setModel(PersonModel *model);

private slots:
    void createPerson();

private:
    Ui::PersonWidget *ui;
    PersonModel* mPersonModel;
};

#endif // PERSONWIDGET_H

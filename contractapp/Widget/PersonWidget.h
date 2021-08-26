#ifndef PERSONWIDGET_H
#define PERSONWIDGET_H

#include <QWizardPage>
#include <QModelIndex>

namespace Ui {
class PersonWidget;
}

class PersonModel;
class QItemSelectionModel;

class PersonWidget : public QWizardPage
{
    Q_OBJECT

public:
    explicit PersonWidget(QWidget *parent = nullptr);
    ~PersonWidget();

    void setModel(PersonModel *model);
    void setPersonSelectionModel(QItemSelectionModel* personSelectionModel);

private slots:
    void createPerson();
    void removePerson();
    void editPerson();

private:
    Ui::PersonWidget *ui;
    PersonModel* mPersonModel;

    QItemSelectionModel* mPersonSelectionModel;
};

#endif // PERSONWIDGET_H

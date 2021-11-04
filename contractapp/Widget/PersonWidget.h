#ifndef PERSONWIDGET_H
#define PERSONWIDGET_H

#include <QWidget>
#include <QModelIndex>

namespace Ui {
class PersonWidget;
}

class PersonModel;
class QItemSelectionModel;

class PersonWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PersonWidget(int principal, QWidget *parent = nullptr);
    ~PersonWidget();

    void setModel(PersonModel* model);
    void setPersonSelectionModel(QItemSelectionModel* personSelectionModel);
    int getPrincipal() const;

private slots:
    void createPerson();
    void removePerson();
    void editPerson();

private:
    Ui::PersonWidget *ui;

    PersonModel* mPersonModel;
    int isPrincipal;

    QItemSelectionModel* mPersonSelectionModel;
};

#endif // PERSONWIDGET_H

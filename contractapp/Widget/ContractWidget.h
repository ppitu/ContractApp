//
// Created by ppitu on 26.08.2021.
//

#ifndef CONTRACTAPP_CONTRACTWIDGET_H
#define CONTRACTAPP_CONTRACTWIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class ContractWidget; }
QT_END_NAMESPACE

class ContractWidget : public QWidget {
Q_OBJECT

public:
    explicit ContractWidget(QWidget *parent = nullptr);

    ~ContractWidget() override;

private:
    Ui::ContractWidget *ui;
};


#endif //CONTRACTAPP_CONTRACTWIDGET_H

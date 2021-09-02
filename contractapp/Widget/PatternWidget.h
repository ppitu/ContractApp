//
// Created by ppitu on 31.08.2021.
//

#ifndef CONTRACTAPP_PATTERNWIDGET_H
#define CONTRACTAPP_PATTERNWIDGET_H

#include <QWidget>

#include "Class/Pattern.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PatternWidget; }
QT_END_NAMESPACE

class PatternModel;
//class Pattern;

class PatternWidget : public QWidget {
Q_OBJECT

public:
    explicit PatternWidget(QWidget *parent = nullptr);

    void setModel(PatternModel *model);
    ~PatternWidget() override;

private slots:
    void edit();

private:
    Ui::PatternWidget *ui;
    class PatternModel *mPatternModel;
    int indexOfLast;
    Pattern mPattern;
};


#endif //CONTRACTAPP_PATTERNWIDGET_H

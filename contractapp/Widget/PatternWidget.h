//
// Created by ppitu on 31.08.2021.
//

#ifndef CONTRACTAPP_PATTERNWIDGET_H
#define CONTRACTAPP_PATTERNWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class PatternWidget; }
QT_END_NAMESPACE

class PatternModel;

class PatternWidget : public QWidget {
Q_OBJECT

public:
    explicit PatternWidget(QWidget *parent = nullptr);

    void setModel(PatternModel *model);
    ~PatternWidget() override;

private:
    Ui::PatternWidget *ui;
    class PatternModel *mPatternModel;
};


#endif //CONTRACTAPP_PATTERNWIDGET_H

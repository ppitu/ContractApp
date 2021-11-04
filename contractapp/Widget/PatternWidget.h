#ifndef PATTERNWIDGET_H
#define PATTERNWIDGET_H

#include <QWidget>
#include <QModelIndex>

#include <optional>

#include "Class/Pattern.h"

namespace Ui {
class PatternWidget;
}

class PatternModel;

class PatternWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PatternWidget(QWidget *parent = nullptr);
    ~PatternWidget() override;

    void setModel(PatternModel* model);

private slots:
    void loadPattern();
    void editPattern();
    void newPattern();
    void addParagraph();
    void removeParagraph();
    void removePattern();

private:
    Ui::PatternWidget *ui;
    class PatternModel *mPatternModel;
    std::optional<int> indexOfLast;
    Pattern mPattern;
    bool isEdit;
    bool isNew;
    QModelIndex currentPatternIndex;
    void save();

    void clearPatternButtons();
    bool validate();
};

#endif // PATTERNWIDGET_H

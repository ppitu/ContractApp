#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>

#include "Class/Person.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class PersonDatabaseWidget;
class PatternWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    PersonDatabaseWidget* mPersonDatabaseWidget;
    QTabWidget* mTabWidget;
    PatternWidget* mPatternWidget;
};
#endif // MAINWINDOW_H

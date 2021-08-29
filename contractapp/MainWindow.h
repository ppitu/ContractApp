#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTabWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class PersonDatabaseWidget;
class ContractWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    PersonDatabaseWidget* mPersonDatabaseWidget;
    ContractWidget* mContractWidget;
    QTabWidget* mTabWidget;
};
#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qlabel.h"
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_signButton_clicked();

private:
    Ui::MainWindow *ui;
    QString names[10]={"eman","merna","youssef","mohammed","ali","menna","jana","ahmed","mostafa","john"};
    QString passwords[10]={"eman123","merna123","youssef123","mohammed123","ali123","menna123","jana123","ahmed123","mostafa123","john123"};
    QString* purchasedItems;
    QString* prices;
    int total;
    QString accBalance[10]={"1000","911","720","475","300","123","800","50","120000","250"};
    QString chikOptions[10]={};
    QString meatOptions[10]={};
    QString chickenPrices[10]={};
    QString meatPrices[10]={};
    int counter=0;
    int signcount=0;
    std::vector <QString> cart;
};
#endif // MAINWINDOW_H

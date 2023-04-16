#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"window2.h"
#include<QTimer>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_signButton_clicked()
{
    int i;
    for(i=0;i<10;i++)
    {
        if(ui->nameEnt->text()==names[i])
        {
            if(ui->paswordEnt->text()==passwords[i])
            {
                ui->signStatus->setText("Signed in Successfully");
                ui->balanceDisplay->setText(accBalance[i]);
                signcount=i;
                QTimer timer;//  THIS PART WAS TAKEN FROM CHATGPT
                    timer.start(1500);     //Start the timer with a 5-second interval


                    QObject::connect(&timer, &QTimer::timeout, []()// Connect a lambda function to the timer's timeout signal
                    {
                        qDebug();
                    });
                    QEventLoop loop;   // Wait for the timer to finish
                    QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);
                    loop.exec();


                this->hide();
                Window2 window2(signcount,accBalance);
                window2.setModal(true);
                window2.exec();
                break;
            }
            else
            {
               ui->signStatus->setText("Name is correct but Password is wrong \n please re-enter the password");
               ui->paswordEnt->setText("");
             break;
            }
        }

    }
    if(i==10)
    {
        ui->signStatus->setText("Name does not exist");
        ui->nameEnt->setText("");
        ui->paswordEnt->setText("");
    }


}


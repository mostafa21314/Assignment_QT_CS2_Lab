#include "window3.h"
#include "qlistwidget.h"
#include "qtimer.h"
#include "ui_window3.h"

Window3::Window3(int temp,int num, QString* balances, std::vector<QString> writings,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Window3)
{
    ui->setupUi(this);
    total=temp;
    index=num;
    Balances=balances;
    purchased=writings;
    ui->Balance->setText(balances[index]);
    ui->Total->setText(QString::number(total));
    for(int i=0;i<purchased.size();i++)
    {

            // create a multi-line text item
            QListWidgetItem *item = new QListWidgetItem(ui->cartList);
            item->setText(purchased[i]);
            // add the item to the list widget
            ui->cartList->addItem(item);
            // show the list widget
            ui->cartList->show();

    }
}

Window3::~Window3()
{
    delete ui;
}

void Window3::on_BuyItem_clicked()
{
    if(ui->Total->text().toInt()>ui->Balance->text().toInt())
    {
      ui->Status->setText("Sorry, You cant proceed without recharging your balance. ") ;
    }
    else
    {
        ui->Status->setText("Purchased successfully. Enjoy your meal :) ");
        int temporary=ui->Balance->text().toInt()-ui->Total->text().toInt();
        Balances[index]=QString::number(temporary);
        ui->Balance->setText(Balances[index]);

    }
}


void Window3::on_RechargeBalance_clicked()
{
if(ui->RechargeText->text().toInt()<0)
{
    ui->RechargeText->setText("You cant enter a negative value");
    QTimer timer;    //  THIS PART WAS TAKEN FROM CHATGPT
        timer.start(1100);     //Start the timer with a 5-second interval


        QObject::connect(&timer, &QTimer::timeout, []()// Connect a lambda function to the timer's timeout signal
        {
            qDebug();
        });
        QEventLoop loop;   // Wait for the timer to finish
        QObject::connect(&timer, &QTimer::timeout, &loop, &QEventLoop::quit);//  THIS PART WAS TAKEN FROM CHATGPT
        loop.exec();
        ui->RechargeText->setText("");

}
else
{
    int extra=Balances[index].toInt()+ui->RechargeText->text().toInt();
    Balances[index]=QString::number(extra);
    ui->Balance->setText(Balances[index]);
    ui->RechargeText->clear();
}
}




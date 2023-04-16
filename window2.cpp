#include "window2.h"
#include "ui_window2.h"
#include<window3.h>
Window2::Window2(int x, QString* y,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Window2)
{
    ui->setupUi(this);
    accounts=y;
    signcount=x;
    ui->AccBalance->setText(accounts[x]);
}

Window2::~Window2()
{
    delete ui;
}

void Window2::on_ChickOpt_currentIndexChanged(int index)
{
    switch(index)
      {
      case 0:
          ui->ItemPrice->setText("");
          break;
      case 1:
                      ui->ItemPriceL->setText("Item Price");
         ui->MeatOpt->setCurrentIndex(0);
          ui->ItemPrice->setText("125");
          break;
      case 2:
                      ui->ItemPriceL->setText("Item Price");
            ui->MeatOpt->setCurrentIndex(0);
     ui->ItemPrice->setText("75");
          break;
      case 3:
                      ui->ItemPriceL->setText("Item Price");
            ui->MeatOpt->setCurrentIndex(0);
          ui->ItemPrice->setText("100");
          break;
      case 4:
                      ui->ItemPriceL->setText("Item Price");
            ui->MeatOpt->setCurrentIndex(0);
          ui->ItemPrice->setText("150");
          break;
      case 5:
                      ui->ItemPriceL->setText("Item Price");
            ui->MeatOpt->setCurrentIndex(0);
          ui->ItemPrice->setText("110");
          break;


      }
}


void Window2::on_MeatOpt_currentIndexChanged(int index)
{
    switch(index)
      {
      case 0:
          ui->ItemPrice->setText("");
          break;
      case 1:
              ui->ItemPriceL->setText("Item Price");
          ui->ChickOpt->setCurrentIndex(0);
          ui->ItemPrice->setText("200");
          break;
      case 2:
                      ui->ItemPriceL->setText("Item Price");
     ui->ChickOpt->setCurrentIndex(0);
     ui->ItemPrice->setText("375");
          break;
      case 3:
                      ui->ItemPriceL->setText("Item Price");
                ui->ChickOpt->setCurrentIndex(0);
          ui->ItemPrice->setText("275");
          break;
      case 4:
                      ui->ItemPriceL->setText("Item Price");
          ui->ChickOpt->setCurrentIndex(0);
          ui->ItemPrice->setText("250");
          break;
      case 5:
                      ui->ItemPriceL->setText("Item Price");
          ui->ChickOpt->setCurrentIndex(0);
          ui->ItemPrice->setText("500");
          break;
      case 6:
                      ui->ItemPriceL->setText("Item Price");
           ui->ChickOpt->setCurrentIndex(0);
           ui->ItemPrice->setText("300");
          break;


      }
}


void Window2::on_AddTocart_clicked()
{
    if(ui->ItemPrice->text()=="")
    {
        ui->ItemPriceL->setText("Choose an Item first");
    }
    else
    {
        ui->NumAddItems->setText(QString::number(++counter));
        cart.push_back(ui->ChickOpt->currentText()+ui->MeatOpt->currentText()+" : "+ui->ItemPrice->text());
        total+=ui->ItemPrice->text().toInt();
    }
}


void Window2::on_ViewCart_clicked()
{
    this->hide();
    Window3 window3(total,signcount,accounts,cart);
    window3.setModal(true);
    window3.exec();
}


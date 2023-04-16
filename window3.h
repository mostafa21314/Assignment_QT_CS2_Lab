#ifndef WINDOW3_H
#define WINDOW3_H

#include <QDialog>
#include<QMouseEvent>

namespace Ui {
class Window3;
}

class Window3 : public QDialog
{
    Q_OBJECT

public:
    explicit Window3(int,int,QString*,std::vector<QString>,QWidget *parent = nullptr);
    ~Window3();

private slots:
    void on_BuyItem_clicked();

    void on_RechargeBalance_clicked();
private:
    Ui::Window3 *ui;
    QString* Balances;
    int total;
    std::vector<QString> purchased;
    int index;
};

#endif // WINDOW3_H

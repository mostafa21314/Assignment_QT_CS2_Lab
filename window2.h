#ifndef WINDOW2_H
#define WINDOW2_H

#include <QDialog>
namespace Ui {
class Window2;
}

class Window2 : public QDialog
{
    Q_OBJECT

public:
    explicit Window2(int, QString* ,QWidget *parent = nullptr);
    ~Window2();

private slots:
    void on_ChickOpt_currentIndexChanged(int index);

    void on_MeatOpt_currentIndexChanged(int index);

    void on_AddTocart_clicked();

    void on_ViewCart_clicked();

private:
    Ui::Window2 *ui;
  QString* purchasedItems;
    QString* prices;
    int total=0;
    QString* accounts;
    int counter=0;
    int signcount;
    std::vector <QString> cart;
};

#endif // WINDOW2_H

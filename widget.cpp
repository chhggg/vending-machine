#include "widget.h"
#include "ui_widget.h"

int money = 0;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->coffee->setEnabled(false);
    ui->tea->setEnabled(false);
    ui->milk->setEnabled(false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::enableButtons(void)
{
    ui->coffee->setEnabled(money >= 100);
    ui->tea->setEnabled(money >= 150);
    ui->milk->setEnabled(money >= 200);
}

void Widget::changeMoney(int amount)
{
    money += amount;
    ui->lcdNumber->display(money);
    enableButtons();
}


void Widget::on_pb_10_clicked()
{
    changeMoney(10);
}


void Widget::on_pb_50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb_100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb_500_clicked()
{
    changeMoney(500);
}


void Widget::on_coffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_tea_clicked()
{
    changeMoney(-150);
}


void Widget::on_milk_clicked()
{
    changeMoney(-200);
}


void Widget::on_reset_clicked()
{
    QMessageBox MsgBox;

    int coin500 = money / 500;
    money %= 500;
    int coin100 = money / 100;
    money %= 100;
    int coin50 = money / 50;
    money %= 50;
    int coin10 = money / 10;
    money %= 10;

    QString str = QString("[500] : %1, [100] : %2, [50] : %3, [10] : %4").arg(coin500).arg(coin100).arg(coin50).arg(coin10);
    MsgBox.setText(str);
    MsgBox.exec();

    changeMoney(-money);
    enableButtons();
}


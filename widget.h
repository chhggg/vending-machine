#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    int money{0};
    void changeMoney(int);
    void enableButtons();

private slots:
    void on_pb_10_clicked();

    void on_pb_50_clicked();

    void on_pb_100_clicked();

    void on_pb_500_clicked();

    void on_coffee_clicked();

    void on_tea_clicked();

    void on_milk_clicked();

    void on_reset_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H

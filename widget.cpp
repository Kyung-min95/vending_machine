#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <cstdio>




Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    if(money <100)
        ui->pbCoffee->setEnabled(false);
    if(money <150)
        ui->pbTea->setEnabled(false);
    if(money <200)
        ui->pbCoke->setEnabled(false);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int n){
    // int money = 0;


    money += n;
    ui->lcdNumber->display(money);

    if(money<100){
        ui->pbCoffee->setEnabled(false);
    }
    else {
        ui->pbCoffee->setEnabled(true);
    }
    if(money<150){
        ui->pbTea->setEnabled(false);
    }
    else {
        ui->pbTea->setEnabled(true);
    }
    if(money<200){
        ui->pbCoke->setEnabled(false);
    }
    else {
        ui->pbCoke->setEnabled(true);
    }


}

/*void Widget::btdisable(int n){

}*/

void Widget::on_pbReturn_clicked()
{
     int a,b,c,d;
     a = money/500;
     b = (money%500)/100;
     c = ((money%500)%100)/50;
     d = (((money%500)%100)%50)/10;

     QString strTotal;
     QString str1 = QString::number(a);
     QString str2 = QString::number(b);
     QString str3 = QString::number(c);
     QString str4 = QString::number(d);
     changeMoney(money = 0);


     strTotal.sprintf("10won : %d, 50won : %d, 100won : %d, 500won : %d",d,c,b,a);
     QMessageBox msg;
     msg.information(nullptr,"Return",strTotal+" Return");
}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
    //ui -> pb10 -> setEnabled(false);  -> button Enabled
    //QMessageBox msg;
    //msg.information(nullptr,"error","error2");
}

void Widget::on_pb50_clicked()
{
   changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);

}

void Widget::on_pbTea_clicked()
{

     changeMoney(-150);
}

void Widget::on_pbCoke_clicked()
{
     changeMoney(-200);
}



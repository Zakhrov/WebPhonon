#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    dbtype="QMYSQL";
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    host=ui->lineEdit->text();
    dbname=ui->lineEdit_2->text();
    uname=ui->lineEdit_3->text();
    passwd=ui->lineEdit_4->text();
    tabname=ui->lineEdit_5->text();
    this->close();
}

void Dialog::on_pushButton_2_clicked()
{
    this->close();

}

void Dialog::on_comboBox_activated(const QString &arg1)
{
    if(arg1=="MySQL")
        dbtype="QMYSQL";
    else if(arg1=="Microsoft SQL Server (ODBC)")
        dbtype="QODBC";
    else
        dbtype="QMYSQL";

}

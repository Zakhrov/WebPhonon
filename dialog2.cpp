#include "dialog2.h"
#include "ui_dialog2.h"
#include <QSqlDatabase>
#include <QMessageBox>
Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
    dbtype="QMYSQL";
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::on_pushButton_clicked()
{
    dbhost=ui->lineEdit->text();
    dbname=ui->lineEdit_2->text();
    uname=ui->lineEdit_3->text();
    passwd=ui->lineEdit_4->text();
    this->close();


}

void Dialog2::on_pushButton_2_clicked()
{
    this->close();
}

void Dialog2::on_comboBox_activated(const QString &arg1)
{
    if(arg1=="MySQL")
        dbtype="QMYSQL";
    else if(arg1=="Microsoft SQL Server (ODBC)")
        dbtype="QODBC";
    else
        dbtype="QMYSQL";
}

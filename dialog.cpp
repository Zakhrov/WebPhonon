#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    dbtype="QMYSQL";
    ui->lineEdit->setText(custdbSettings.value("server").toString());
    ui->lineEdit_2->setText(custdbSettings.value("database").toString());
    ui->lineEdit_3->setText(custdbSettings.value("username").toString());
    ui->lineEdit_4->setText(custdbSettings.value("password").toString());

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

    custdbSettings.setValue("server",host);
    custdbSettings.setValue("username",uname);
    custdbSettings.setValue("password",passwd);
    custdbSettings.setValue("database",dbname);
    QMessageBox msg;
    msg.setText("Database settings saved. Restart WebPhonon for changes to take effect");
    msg.exec();
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
    else if(arg1=="SQLite")
        dbtype="QSQLITE";
    else if(arg1=="PostgreSQL")
        dbtype="QPSQL";
    else
        dbtype="QMYSQL";

    custdbSettings.setValue("dbtype",dbtype);

}

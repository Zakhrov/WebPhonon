#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
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
    this->close();
}

void Dialog::on_pushButton_2_clicked()
{
    this->close();

}

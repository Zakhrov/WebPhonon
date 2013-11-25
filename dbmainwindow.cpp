#include "dbmainwindow.h"
#include "ui_dbmainwindow.h"

DBMainWindow::DBMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DBMainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->hide();
    ui->pushButton->hide();
    ui->lineEdit->setText("http://localhost/phpmyadmin");


}

DBMainWindow::~DBMainWindow()
{
     delete ui;
}

void DBMainWindow::on_actionConnect_triggered()
{
   ui->lineEdit->show();
   ui->pushButton->show();
}

void DBMainWindow::on_actionBack_triggered()
{
    ui->webView->back();
}

void DBMainWindow::on_actionFoward_triggered()
{
    ui->webView->forward();
}

void DBMainWindow::on_pushButton_clicked()
{
    url=ui->lineEdit->text();
    ui->webView->setUrl(url);
    ui->lineEdit->hide();
    ui->pushButton->hide();
}

void DBMainWindow::on_actionReload_triggered()
{
    ui->webView->reload();
}

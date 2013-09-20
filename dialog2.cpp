#include "dialog2.h"
#include "ui_dialog2.h"
#include <QWebView>

Dialog2::Dialog2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
}

Dialog2::~Dialog2()
{
    delete ui;
}

void Dialog2::on_pushButton_clicked()
{
    QString url=ui->lineEdit->text();
    ui->webView->load(QUrl(url));
}

void Dialog2::on_pushButton_2_clicked()
{
    this->close();
}

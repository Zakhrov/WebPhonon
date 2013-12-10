#include "dbmainwindow.h"
#include "ui_dbmainwindow.h"
#include <QFileDialog>
#include <QtNetwork/QNetworkAccessManager>
#include <QDesktopServices>

DBMainWindow::DBMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DBMainWindow)
{

    ui->setupUi(this);
    ui->lineEdit->hide();
    ui->pushButton->hide();
    ui->lineEdit->setText("http://localhost/phpmyadmin");
    ui->webView->page()->setForwardUnsupportedContent(true);
    manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onNetworkReply(QNetworkReply*)));
    connect(ui->webView->page(),SIGNAL(downloadRequested(QNetworkRequest)),this,SLOT(download(QNetworkRequest)));
    connect(ui->webView->page(),SIGNAL(unsupportedContent(QNetworkReply*)),this,SLOT(unsupportedcontent(QNetworkReply*)));




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

void DBMainWindow::download(const QNetworkRequest request)
{
    manager->get(request);
}

void DBMainWindow::onNetworkReply(QNetworkReply *reply)
{
    if(reply->error() == QNetworkReply::NoError)
    {
        QString fname= QFileDialog::getSaveFileName(this,tr("Save File"),"DB.sql");
        //int httpstatuscode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toUInt();
        //if (reply->isReadable())
        //{
                    //Assuming this is a human readable file replyString now contains the file
                QFile *file=new QFile(fname);
                file->open(QFile::WriteOnly);
                file->write(reply->readAll());
                file->flush();
                file->close();
         //}


    }
}

void DBMainWindow::unsupportedcontent(QNetworkReply *reply)
{
    download(reply->request());
}


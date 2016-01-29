#include "addmoviedialog.h"
#include "ui_addmoviedialog.h"
#include <QMessageBox>
#include <QFileDialog>
AddMovieDialog::AddMovieDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMovieDialog)
{
    ui->setupUi(this);


}

AddMovieDialog::~AddMovieDialog()
{
    delete ui;


}

void AddMovieDialog::on_pushButton_clicked()
{
    QMessageBox msg;
//    QString host,database,uname,passwd,dbtype;
//    host=settings.value("server").toString();
//    database=settings.value("database").toString();
//    uname=settings.value("username").toString();
//    passwd=settings.value("password").toString();
//    dbtype=settings.value("dbtype").toString();
    url=ui->lineEdit->text();
    title=ui->lineEdit_2->text();
    language=ui->lineEdit_3->text();
    studio=ui->lineEdit_4->text();
    rating=ui->lineEdit_5->text();
    genre=ui->lineEdit_6->text();
    year=ui->lineEdit_7->text();
    db=QSqlDatabase::database("PlayConn");
//    db.setConnectOptions();
//    db.setHostName(host);
//    db.setDatabaseName(database);
//    db.setUserName(uname);
//    db.setPassword(passwd);
    db.open();



        QSqlQuery *query=new QSqlQuery(db);
        //query.prepare("insert into movies(url, title, language, studio, rating, genre, year) values(:url, :title, :language, :studio, :rating, :genre, :year");
        query->prepare("INSERT INTO `webphonon`.`movies` (`url`, `title`, `language`, `studio`, `rating`, `genre`, `year`) VALUES (:url, :title, :language, :studio, :rating, :genre, :year);");
        query->bindValue(":url",url);
        query->bindValue(":title",title);
        query->bindValue(":language",language);
        query->bindValue(":studio",studio);
        query->bindValue(":rating",rating);
        query->bindValue(":genre",genre);
        query->bindValue(":year",year);
        if(query->exec())
        {
            msg.setText("Movie Added");
            msg.exec();

        }
        else
        {
            msg.setText("Movie Not Added");
            msg.exec();

        }
        //db.close();





}

void AddMovieDialog::on_pushButton_2_clicked()
{
    this->close();
}

void AddMovieDialog::on_pushButton_3_clicked()
{
    url=QFileDialog::getOpenFileName(this,"Choose File");
    ui->lineEdit->setText(url);
}

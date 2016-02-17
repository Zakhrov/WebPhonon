#include "addmoviedialog.h"
#include "ui_addmoviedialog.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QSqlError>
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
    model=new QSqlTableModel(this,db);
    model->setTable("movies");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    QSqlRecord record=model->record();
    record.remove(0);
    record.setValue("url",QVariant(url));
    record.setValue("title",QVariant(title));
    record.setValue("language",QVariant(language));
    record.setValue("studio",QVariant(studio));
    record.setValue("rating",QVariant(rating));
    record.setValue("genre",QVariant(genre));
    record.setValue("year",QVariant(year));
    if(model->insertRecord(-1,record))
    {
        if(model->submitAll())
        {
        msg.setText("Movie Added");

        }
        else
        {
            msg.setText(model->lastError().text());

        }

    }
    else
    {
        msg.setText(model->lastError().text());
    }
    msg.exec();

}

void AddMovieDialog::on_pushButton_2_clicked()
{
    this->close();
}

void AddMovieDialog::on_pushButton_3_clicked()
{
    url=QFileDialog::getOpenFileName(this,"Choose File",QDir::currentPath(),tr("Videos (*.avi *.mp4 *.mpg *.mkv *.m4v *.ogv *.wmv)"));
    ui->lineEdit->setText(url);
}

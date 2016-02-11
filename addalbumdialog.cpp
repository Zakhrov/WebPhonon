#include "addalbumdialog.h"
#include "ui_addalbumdialog.h"

AddAlbumDialog::AddAlbumDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAlbumDialog)
{
    ui->setupUi(this);
}

AddAlbumDialog::~AddAlbumDialog()
{
    delete ui;
}

void AddAlbumDialog::on_pushButton_clicked()
{
    QMessageBox msg;
    album=ui->lineEdit->text();
    record_label=ui->lineEdit_2->text();
    db=QSqlDatabase::database("PlayConn");
    db.open();
    query=new QSqlQuery(db);
    if(db.driverName()=="QSQLITE")
        query->prepare("INSERT INTO `album` (`album_name`,`record_label`) VALUES (:name,:label);");
    else
    query->prepare("INSERT INTO `webphonon`.`album` (`album_name`,`record_label`) VALUES (:name,:label);");
    query->bindValue(":name",album);
    query->bindValue(":label",record_label);
    if(query->exec())
    {
        msg.setText("Album Added");
    }
    else
    {
        msg.setText("Album not added"+query->lastError().text());
    }
    msg.exec();
    //db.close();

}

void AddAlbumDialog::on_pushButton_2_clicked()
{
    this->close();
}

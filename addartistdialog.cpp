#include "addartistdialog.h"
#include "ui_addartistdialog.h"
#include <QMessageBox>
AddArtistDialog::AddArtistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddArtistDialog)
{
    ui->setupUi(this);
}

AddArtistDialog::~AddArtistDialog()
{
    delete ui;
}

void AddArtistDialog::on_pushButton_clicked()
{
    QMessageBox msg;
    artist=ui->lineEdit->text();
    db=QSqlDatabase::database("PlayConn");
    db.open();
    query=new QSqlQuery(db);
    query->prepare("INSERT INTO `webphonon`.`artist` (`name`) VALUES (:name);");
    query->bindValue(":name",artist);
    if(query->exec())
    {
        msg.setText("Artist Added");
    }
    else
    {
        msg.setText("Artist not added");
    }
    msg.exec();
    db.close();



}

void AddArtistDialog::on_pushButton_2_clicked()
{
    this->close();
}

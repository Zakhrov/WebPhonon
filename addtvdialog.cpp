#include "addtvdialog.h"
#include "ui_addtvdialog.h"
#include <QFileDialog>
#include <QMessageBox>
AddTVDialog::AddTVDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTVDialog)
{
    ui->setupUi(this);
}

AddTVDialog::~AddTVDialog()
{
    delete ui;
}

void AddTVDialog::on_pushButton_clicked()
{
    url=QFileDialog::getOpenFileName(this,"Choose file");
    ui->lineEdit->setText(url);
}

void AddTVDialog::on_pushButton_2_clicked()
{

    QMessageBox msg;
    url=ui->lineEdit->text();
    title=ui->lineEdit_2->text();
    season=ui->lineEdit_3->text();
    episode=ui->lineEdit_4->text();
    episode_title=ui->lineEdit_5->text();
    language=ui->lineEdit_6->text();
    genre=ui->lineEdit_7->text();
    db=QSqlDatabase::database("PlayConn");
    db.open();
    cmd=new QSqlQuery(db);
    if(db.driverName()=="QSQLITE")
        cmd->prepare("INSERT INTO `tv` (`url`, `title`, `season`, `episode`, `ep_title`, `language`, `genre`) VALUES (:url, :title, :season, :episode, :ep_title, :language, :genre);");
    else
    cmd->prepare("INSERT INTO `webphonon`.`tv` (`url`, `title`, `season`, `episode`, `ep_title`, `language`, `genre`) VALUES (:url, :title, :season, :episode, :ep_title, :language, :genre);");
    cmd->bindValue(":url",url);
    cmd->bindValue(":title",title);
    cmd->bindValue(":season",season);
    cmd->bindValue(":episode",episode);
    cmd->bindValue(":ep_title",episode_title);
    cmd->bindValue(":language",language);
    cmd->bindValue(":genre",genre);
    if(cmd->exec())
    {
        msg.setText("TV Show Added");
        msg.exec();

    }
    else
    {
        msg.setText("TV Show Not Added"+cmd->lastError().text());
        msg.exec();

    }
    //db.close();
    //this->close();



}

void AddTVDialog::on_pushButton_3_clicked()
{
    this->close();
}

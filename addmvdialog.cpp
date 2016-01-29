#include "addmvdialog.h"
#include "ui_addmvdialog.h"
#include <QMessageBox>
#include <QSqlError>
AddMVDialog::AddMVDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMVDialog)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PlayConn");
    db.open();
    model=new QSqlQueryModel(this);
    model->setQuery("select music_id, title from music",db);
    ui->comboBox->setModel(model);
    ui->comboBox->setModelColumn(1);
}

AddMVDialog::~AddMVDialog()
{
    delete ui;
}

void AddMVDialog::on_pushButton_clicked()
{
    url=QFileDialog::getOpenFileName(this);
    ui->lineEdit->setText(url);
}

void AddMVDialog::on_pushButton_2_clicked()
{

    QMessageBox msg;
    url=ui->lineEdit->text();
    music_id=model->data(model->index(ui->comboBox->currentIndex(),0)).toInt();
    db.open();
    query=new QSqlQuery(db);
    query->prepare("INSERT INTO `webphonon`.`music_videos` (`url`, `music_id`) VALUES (:url, :music_id);");
    query->bindValue(":url",url);
    query->bindValue(":muic_id",music_id);
    if(query->exec())
    {
        msg.setText("Music Video Added ");

    }
    else
    {
        msg.setText("Music Video not added "+query->lastError().text());
    }
    msg.exec();
    //db.close();
    //this->close();





}

void AddMVDialog::on_pushButton_3_clicked()
{
    this->close();
}

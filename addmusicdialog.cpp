#include "addmusicdialog.h"
#include "ui_addmusicdialog.h"
#include <QMessageBox>
#include <QSqlError>
AddMusicDialog::AddMusicDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMusicDialog)
{
    ui->setupUi(this);
}

AddMusicDialog::~AddMusicDialog()
{
    delete ui;
}

void AddMusicDialog::on_pushButton_clicked()
{
    url=QFileDialog::getOpenFileName(this,"Browse");
    ui->lineEdit->setText(url);
}

void AddMusicDialog::on_pushButton_2_clicked()
{
    QMessageBox msg;
    url=ui->lineEdit->text();
    title=ui->lineEdit_2->text();
    genre=ui->lineEdit_3->text();
    language=ui->lineEdit_4->text();
    db=QSqlDatabase::database("PlayConn");
    db.open();
    query=new QSqlQuery(db);
    query->prepare("INSERT INTO `webphonon`.`music` (`url`, `title`, `genre`, `language`) VALUES (:url, :title, :genre, :language);");
    query->bindValue(":url",url);
    query->bindValue(":title",title);
    query->bindValue(":genre",genre);
    query->bindValue(":language",language);
    if(query->exec())
    {
        msg.setText("Music Added");
    }
    else
    {
        msg.setText("Music Not Added "+query->lastError().text());
    }
    msg.exec();
    //db.close();



}

void AddMusicDialog::on_pushButton_3_clicked()
{
    this->close();
}

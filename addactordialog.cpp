#include "addactordialog.h"
#include "ui_addactordialog.h"
#include <QMessageBox>
AddActorDialog::AddActorDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddActorDialog)
{
    ui->setupUi(this);

}

AddActorDialog::~AddActorDialog()
{
    delete ui;
}

void AddActorDialog::on_pushButton_clicked()
{
    QMessageBox msg;
    actor=ui->lineEdit->text();
    db=QSqlDatabase::database("PlayConn");
    db.open();
    query=new QSqlQuery(db);
    if(db.driverName()=="QSQLITE")
        query->prepare("INSERT INTO actor(`name`) VALUES (:name);");
    else
    query->prepare("INSERT INTO `webphonon`.`actor` (`name`) VALUES (:name);");
    query->bindValue(":name",actor);
    if(query->exec())
    {
        msg.setText("Actor Added");
    }
    else
    {
        msg.setText("Actor not added"+query->lastError().text());
    }
    msg.exec();
    //db.close();



}

void AddActorDialog::on_pushButton_2_clicked()
{
    this->close();
}

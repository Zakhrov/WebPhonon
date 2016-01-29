#include "addmoviecastdialog.h"
#include "ui_addmoviecastdialog.h"
#include <QSqlError>
AddMovieCastDialog::AddMovieCastDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMovieCastDialog)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PlayConn");
    db.close();
    db.open();
    model1=new QSqlQueryModel(this);
    model1->setQuery("select movies_id, title from movies",db);
    model2=new QSqlQueryModel(this);
    model2->setQuery("select actor_id, actor.name from actor",db);
    ui->comboBox->setModel(model1);
    ui->comboBox->setModelColumn(1);
    ui->comboBox_2->setModel(model2);
    ui->comboBox_2->setModelColumn(1);
}

AddMovieCastDialog::~AddMovieCastDialog()
{
    delete ui;

}

void AddMovieCastDialog::on_pushButton_clicked()
{
    QMessageBox msg;
    charecter=ui->lineEdit->text();
    role=ui->lineEdit_2->text();
    actor_id = model2->data(model2->index(ui->comboBox_2->currentIndex(),0)).toInt();
    movie_id = model1->data(model1->index(ui->comboBox->currentIndex(),0)).toInt();
    query=new QSqlQuery(db);
    query->prepare("INSERT INTO `webphonon`.`movie_cast` (`movie_id`, `actor_id`, `charecter_name`, `role`) VALUES (:movie_id, :actor_id, :charecter_name, :role);");
    query->bindValue(":movie_id",movie_id);
    query->bindValue(":actor_id",actor_id);
    query->bindValue(":charecter_name",charecter);
    query->bindValue(":role",role);
    if(query->exec())
    {
        msg.setText("Movie Charecter and Role Added");
    }
    else
    {
        msg.setText("Error"+query->lastError().text());
    }
    msg.exec();
    //db.close();


}

void AddMovieCastDialog::on_pushButton_2_clicked()
{
    this->close();
}

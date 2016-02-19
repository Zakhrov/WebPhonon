#include "addmoviecastdialog.h"
#include "ui_addmoviecastdialog.h"
#include <QSqlError>
AddMovieCastDialog::AddMovieCastDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMovieCastDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Actors to Movies");
    db=QSqlDatabase::database("PlayConn");
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
    model=new QSqlTableModel(this,db);
    model->setTable("movie_cast");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    QSqlRecord record=model->record();
    record.remove(0);
    record.setValue("movie_id",QVariant(movie_id));
    record.setValue("actor_id",QVariant(actor_id));
    record.setValue("charecter_name",QVariant(charecter));
    record.setValue("role",QVariant(role));
    if(model->insertRecord(-1,record))
    {
        if(model->submitAll())
        {
        msg.setText("Movie Cast Added");

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

void AddMovieCastDialog::on_pushButton_2_clicked()
{
    this->close();
}

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
    model=new QSqlTableModel(this,db);
    model->setTable("tv");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    QSqlRecord record=model->record();
    record.remove(0);
    record.setValue("url",QVariant(url));
    record.setValue("title",QVariant(title));
    record.setValue("language",QVariant(language));
    record.setValue("season",QVariant(season));
    record.setValue("episode",QVariant(episode));
    record.setValue("genre",QVariant(genre));
    record.setValue("ep_title",QVariant(episode_title));
    if(model->insertRecord(-1,record))
    {
        if(model->submitAll())
        {
        msg.setText("TV Show Added");

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

void AddTVDialog::on_pushButton_3_clicked()
{
    this->close();
}

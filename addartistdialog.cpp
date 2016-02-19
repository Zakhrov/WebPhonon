#include "addartistdialog.h"
#include "ui_addartistdialog.h"
#include <QMessageBox>
AddArtistDialog::AddArtistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddArtistDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Artists");
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
    model=new QSqlTableModel(this,db);
    model->setTable("artist");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    QSqlRecord record=model->record();
    record.remove(0);
    record.setValue("name",QVariant(artist));
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

void AddArtistDialog::on_pushButton_2_clicked()
{
    this->close();
}

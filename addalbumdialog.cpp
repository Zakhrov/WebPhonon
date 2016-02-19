#include "addalbumdialog.h"
#include "ui_addalbumdialog.h"

AddAlbumDialog::AddAlbumDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAlbumDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Album");
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
    model=new QSqlTableModel(this,db);
    model->setTable("album");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    QSqlRecord record=model->record();
    record.remove(0);
    record.setValue("album_name",QVariant(album));
    record.setValue("record_label",QVariant(record_label));
    if(model->insertRecord(-1,record))
    {
        if(model->submitAll())
        {
        msg.setText("Album Added");

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

void AddAlbumDialog::on_pushButton_2_clicked()
{
    this->close();
}

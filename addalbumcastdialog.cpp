#include "addalbumcastdialog.h"
#include "ui_addalbumcastdialog.h"

AddAlbumCastDialog::AddAlbumCastDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAlbumCastDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Artists to Albums");
    db=QSqlDatabase::database("PlayConn");
    model1=new QSqlQueryModel(this);
    model1->setQuery("select album_id, album_name from album",db);
    model2=new QSqlQueryModel(this);
    model2->setQuery("select artist_id, artist.name from artist",db);
    ui->comboBox->setModel(model1);
    ui->comboBox->setModelColumn(1);
    ui->comboBox_2->setModel(model2);
    ui->comboBox_2->setModelColumn(1);
}

AddAlbumCastDialog::~AddAlbumCastDialog()
{
    delete ui;
}

void AddAlbumCastDialog::on_pushButton_clicked()
{
    QMessageBox msg;
    role=ui->lineEdit->text();

    artist_id = model2->data(model2->index(ui->comboBox_2->currentIndex(),0)).toInt();
    album_id = model1->data(model1->index(ui->comboBox->currentIndex(),0)).toInt();
    model=new QSqlTableModel(this,db);
    model->setTable("album_cast");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    QSqlRecord record=model->record();
    record.remove(0);
    record.setValue("artist_id",QVariant(artist_id));
    record.setValue("album_id",QVariant(album_id));
    record.setValue("role",QVariant(role));
    if(model->insertRecord(-1,record))
    {
        if(model->submitAll())
        {
        msg.setText("Album Cast Added");

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

void AddAlbumCastDialog::on_pushButton_2_clicked()
{
    this->close();
}

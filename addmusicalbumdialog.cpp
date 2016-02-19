#include "addmusicalbumdialog.h"
#include "ui_addmusicalbumdialog.h"

AddMusicAlbumDialog::AddMusicAlbumDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMusicAlbumDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Songs to Albums");
    db=QSqlDatabase::database("PlayConn");
    model1=new QSqlQueryModel(this);
    model1->setQuery("select album_id, album_name from album",db);
    model2=new QSqlQueryModel(this);
    model2->setQuery("select music_id, title from music",db);
    ui->comboBox->setModel(model1);
    ui->comboBox->setModelColumn(1);
    ui->comboBox_2->setModel(model2);
    ui->comboBox_2->setModelColumn(1);
}

AddMusicAlbumDialog::~AddMusicAlbumDialog()
{
    delete ui;
}

void AddMusicAlbumDialog::on_pushButton_clicked()
{
    QMessageBox msg;
    ui->lineEdit->setValidator(new QIntValidator(this));
    int track_number=ui->lineEdit->text().toInt();
    music_id = model2->data(model2->index(ui->comboBox_2->currentIndex(),0)).toInt();
    album_id = model1->data(model1->index(ui->comboBox->currentIndex(),0)).toInt();
    model=new QSqlTableModel(this,db);
    model->setTable("music_album");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    QSqlRecord record=model->record();
    record.remove(0);
    record.setValue("track",QVariant(track_number));
    record.setValue("music_id",QVariant(music_id));
    record.setValue("album_id",QVariant(album_id));
    if(model->insertRecord(-1,record))
    {
        if(model->submitAll())
        {
        msg.setText("Song Linked to Album");

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

void AddMusicAlbumDialog::on_pushButton_2_clicked()
{
    this->close();
}

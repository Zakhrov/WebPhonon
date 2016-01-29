#include "addmusicalbumdialog.h"
#include "ui_addmusicalbumdialog.h"

AddMusicAlbumDialog::AddMusicAlbumDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMusicAlbumDialog)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PlayConn");
    db.open();
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
    db.open();
    query=new QSqlQuery(db);
    query->prepare("INSERT INTO `webphonon`.`music_album` (`album_id`, `music_id`,`track`) VALUES (:album_id, :music_id, :track);");
    query->bindValue(":album_id",album_id);
    query->bindValue(":music_id",music_id);
    query->bindValue(":track",track_number);
    if(query->exec())
    {
        msg.setText("Song Linked to Album");
    }
    else
    {
        msg.setText("Error"+query->lastError().text());
    }
    msg.exec();
    //db.close();
    //this->close();
}

void AddMusicAlbumDialog::on_pushButton_2_clicked()
{
    this->close();
}

#include "addalbumcastdialog.h"
#include "ui_addalbumcastdialog.h"

AddAlbumCastDialog::AddAlbumCastDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAlbumCastDialog)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PlayConn");
    db.close();
    db.open();
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
    query=new QSqlQuery(db);
    query->prepare("INSERT INTO `webphonon`.`album_cast` (`album_id`, `artist_id`, `role`) VALUES (:album_id, :artist_id, :role);");
    query->bindValue(":album_id",album_id);
    query->bindValue(":artist_id",artist_id);
    query->bindValue(":role",role);
    if(query->exec())
    {
        msg.setText("Album Artist and Role Added");
    }
    else
    {
        msg.setText("Error"+query->lastError().text());
    }
    msg.exec();
    //db.close();


}

void AddAlbumCastDialog::on_pushButton_2_clicked()
{
    this->close();
}

#include "addmvcastdialog.h"
#include "ui_addmvcastdialog.h"

AddMVCastDialog::AddMVCastDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMVCastDialog)
{
    ui->setupUi(this);
    db=QSqlDatabase::database("PlayConn");
    db.open();
    model1=new QSqlQueryModel(this);
    model1->setQuery("select mv_id, title from music_videos INNER JOIN music ON music_videos.music_id=music.music_id",db);
    model2=new QSqlQueryModel(this);
    model2->setQuery("select actor_id, actor.name from actor",db);
    ui->comboBox->setModel(model1);
    ui->comboBox->setModelColumn(1);
    ui->comboBox_2->setModel(model2);
    ui->comboBox_2->setModelColumn(1);
}

AddMVCastDialog::~AddMVCastDialog()
{
    delete ui;
}

void AddMVCastDialog::on_pushButton_clicked()
{
    QMessageBox msg;
    actor_id = model2->data(model2->index(ui->comboBox_2->currentIndex(),0)).toInt();
    mv_id = model1->data(model1->index(ui->comboBox->currentIndex(),0)).toInt();
    db.open();
    query=new QSqlQuery(db);
    if(db.driverName()=="QSQLITE")
        query->prepare("INSERT INTO `music_video_cast` (`music_video_id`, `actor_id`) VALUES (:mv_id, :actor_id);");
    else
    query->prepare("INSERT INTO `webphonon`.`music_video_cast` (`music_video_id`, `actor_id`) VALUES (:mv_id, :actor_id);");
    query->bindValue(":mv_id",mv_id);
    query->bindValue(":actor_id",actor_id);
    if(query->exec())
    {
        msg.setText("Actor linked to Music Video");
    }
    else
    {
        msg.setText("Error"+query->lastError().text());
    }
    msg.exec();
    //db.close();
    //this->close();
}

void AddMVCastDialog::on_pushButton_2_clicked()
{
    this->close();
}

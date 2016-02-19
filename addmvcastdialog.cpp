#include "addmvcastdialog.h"
#include "ui_addmvcastdialog.h"

AddMVCastDialog::AddMVCastDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMVCastDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Actors to Music Videos");
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
    model=new QSqlTableModel(this,db);
    model->setTable("music_video_cast");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    QSqlRecord record=model->record();
    record.remove(0);
    record.setValue("music_video_id",QVariant(mv_id));
    record.setValue("actor_id",QVariant(actor_id));
    if(model->insertRecord(-1,record))
    {
        if(model->submitAll())
        {
        msg.setText("Music Video Cast Added");

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

void AddMVCastDialog::on_pushButton_2_clicked()
{
    this->close();
}

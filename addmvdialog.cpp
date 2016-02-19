#include "addmvdialog.h"
#include "ui_addmvdialog.h"
#include <QMessageBox>

AddMVDialog::AddMVDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMVDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Music Videos");
    db=QSqlDatabase::database("PlayConn");
    db.close();
    db.open();
    model1=new QSqlQueryModel(this);
    model1->setQuery("select music_id, title from music",db);
    ui->comboBox->setModel(model1);
    ui->comboBox->setModelColumn(1);
}

AddMVDialog::~AddMVDialog()
{
    delete ui;
}

void AddMVDialog::on_pushButton_clicked()
{
    url=QFileDialog::getOpenFileName(this,"Choose File",QDir::currentPath(),tr("Videos (*.avi *.mp4 *.mpg *.mkv *.m4v *.ogv *.wmv)"));
    ui->lineEdit->setText(url);
}

void AddMVDialog::on_pushButton_2_clicked()
{

    QMessageBox msg;
    url=ui->lineEdit->text();
    music_id=model1->data(model1->index(ui->comboBox->currentIndex(),0)).toInt();
    model=new QSqlTableModel(this,db);
    model->setTable("music_videos");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    QSqlRecord record=model->record();
    record.remove(0);
    record.setValue("url",QVariant(url));
    record.setValue("music_id",QVariant(music_id));
    if(model->insertRecord(-1,record))
    {
        if(model->submitAll())
        {
        msg.setText("Music Video Added");

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

void AddMVDialog::on_pushButton_3_clicked()
{
    this->close();
}

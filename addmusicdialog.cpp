#include "addmusicdialog.h"
#include "ui_addmusicdialog.h"
#include <QMessageBox>
#include <QSqlError>
AddMusicDialog::AddMusicDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMusicDialog)
{
    ui->setupUi(this);
    this->setWindowTitle("Add Songs");
}

AddMusicDialog::~AddMusicDialog()
{
    delete ui;
}

void AddMusicDialog::on_pushButton_clicked()
{
    url=QFileDialog::getOpenFileName(this,"Choose File",QDir::currentPath(),tr("Songs (*.wav *.mp3 *.m4a *.flac *.ogg *.wma)"));
    ui->lineEdit->setText(url);
}

void AddMusicDialog::on_pushButton_2_clicked()
{
    QMessageBox msg;
    url=ui->lineEdit->text();
    title=ui->lineEdit_2->text();
    genre=ui->lineEdit_3->text();
    language=ui->lineEdit_4->text();
    db=QSqlDatabase::database("PlayConn");
    model=new QSqlTableModel(this,db);
    model->setTable("music");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    QSqlRecord record=model->record();
    record.remove(0);
    record.setValue("url",QVariant(url));
    record.setValue("title",QVariant(title));
    record.setValue("language",QVariant(language));
    record.setValue("genre",QVariant(genre));
    if(model->insertRecord(-1,record))
    {
        if(model->submitAll())
        {
        msg.setText("Music Added");

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

void AddMusicDialog::on_pushButton_3_clicked()
{
    this->close();
}

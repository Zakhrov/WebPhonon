#include "tablelistdialog.h"
#include "ui_tablelistdialog.h"
#include <QSqlQuery>
#include <QSettings>
TableListDialog::TableListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableListDialog)
{
    ui->setupUi(this);



    db=QSqlDatabase::database("PlayConn");
    if(db.open())
    //ui->comboBox->addItems(db.tables());
    ui->comboBox->addItem("movies");
    ui->comboBox->addItem("tv");
    ui->comboBox->addItem("music_videos");
    ui->comboBox->addItem("music");
    tabname="movies";
    db.close();



}

TableListDialog::~TableListDialog()
{
    delete ui;

}

void TableListDialog::on_pushButton_clicked()
{

    this->close();


}

void TableListDialog::on_comboBox_activated(const QString &arg1)
{
    tabname=arg1;
}

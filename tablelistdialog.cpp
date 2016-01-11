#include "tablelistdialog.h"
#include "ui_tablelistdialog.h"
#include <QSqlQuery>
#include <QSettings>
TableListDialog::TableListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TableListDialog)
{
    ui->setupUi(this);

    QSettings settings;
    QString host,database,uname,passwd,dbtype;
    host=settings.value("server").toString();
    database=settings.value("database").toString();
    uname=settings.value("username").toString();
    passwd=settings.value("password").toString();
    dbtype=settings.value("dbtype").toString();
    db=QSqlDatabase::database("PlayConn");
    db.setConnectOptions();
    db.setHostName(host);
    db.setDatabaseName(database);
    db.setUserName(uname);
    db.setPassword(passwd);
    if(db.open())
    ui->comboBox->addItems(db.tables());
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

#include "dbmainwindow.h"
#include "ui_dbmainwindow.h"
#include "dialog2.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>

DBMainWindow::DBMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DBMainWindow)
{
    ui->setupUi(this);
    d2=new Dialog2(this);
    ui->tableWidget->setColumnCount(2);
}

DBMainWindow::~DBMainWindow()
{
    delete ui;
}

void DBMainWindow::on_actionConnect_triggered()
{

    DBName=d2->dbname;
    HostName=d2->dbhost;
    DBType=d2->dbtype;
    UName=d2->uname;
    Passwd=d2->passwd;
    MyDB=QSqlDatabase::addDatabase(DBType);
    MyDB.setConnectOptions();
    QPixmap img1,img2;
    img1.load(":/Icons/WebPhononIcon.png");
    img2=img1.scaled(32,32);
    QMessageBox msg;
    msg.setIconPixmap(img2);
    msg.setWindowTitle("Database Module");
    if(MyDB.isDriverAvailable(DBType)==true)
    {
        if(DBType=="QODBC")
        {
            QString dsn= QString("DRIVER={SQL Server};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(HostName).arg(DBName);
           MyDB.setDatabaseName(dsn);
           MyDB.open();
        }
        else
        {
           MyDB.setHostName(HostName);
            MyDB.setDatabaseName(DBName);
             MyDB.open(UName,Passwd);
        }

        if(MyDB.isOpen()==true)
        {
              msg.setText(MyDB.driverName()+" Database "+DBName+" Open");
              msg.exec();
        }
        QStringList tabs= MyDB.tables();
        ui->listWidget->addItems(tabs);
        //QSqlQuery request("SELECT url, name FROM ");
    }

}

void DBMainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    TabName=item->text();
    QString tabindex,titleindex;
    int i;
    QSqlQuery request("SELECT url, name FROM "+TabName);
    while(request.next())
    {

        tabindex=request.value(0).toString();
        titleindex=request.value(1).toString();
        QTableWidgetItem *item1=new QTableWidgetItem(tabindex,1);
        QTableWidgetItem *item2=new QTableWidgetItem(titleindex,1);
        i=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,item1);
        ui->tableWidget->setItem(i,1,item2);
    }
    ui->tableWidget->resizeColumnsToContents();
}

void DBMainWindow::on_actionAdd_Database_triggered()
{
    d2->show();
}

#include "dbmainwindow.h"
#include "ui_dbmainwindow.h"
#include "dialog2.h"
#include "addtabledialog.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>

DBMainWindow::DBMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DBMainWindow)
{
    ui->setupUi(this);
    d2=new Dialog2(this);
    tabdiag=new AddTableDialog(this);
    //ui->tableWidget->setColumnCount(2);
    QStringList collabel;
    collabel.append("URL");
    collabel.append("Title");
    //ui->tableWidget->setHorizontalHeaderLabels(collabel);

}

DBMainWindow::~DBMainWindow()
{
   MyDB.close();
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
     model=new QSqlTableModel(this,MyDB);
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
        tabs= MyDB.tables();
        ui->listWidget->addItems(tabs);
        //QSqlQuery request("SELECT url, name FROM ");
    }

}

void DBMainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    TabName=item->text();
    model->setTable(TabName);
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();
    model->setHeaderData(0,Qt::Horizontal,tr("URL"));
    model->setHeaderData(1,Qt::Horizontal,tr("title"));
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();

}

void DBMainWindow::on_actionAdd_Database_triggered()
{
    d2->show();
}

void DBMainWindow::on_actionNew_Table_triggered()
{
    tabdiag->showMaximized();

}

void DBMainWindow::on_actionInsert_Values_triggered()
{

    QSqlQuery ins("INSERT INTO "+TabName+"(url,name) VALUES('path to file','name of file')");
    ins.exec();
    model->setTable(TabName);
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    model->select();
    model->setHeaderData(0,Qt::Horizontal,tr("URL"));
    model->setHeaderData(1,Qt::Horizontal,tr("title"));
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();



}

void DBMainWindow::on_actionDelete_tuple_triggered()
{
    //get selections
    QItemSelection selection = ui->tableView->selectionModel()->selection();

    //find out selected rows
    QList<int> removeRows;
    foreach(QModelIndex index, selection.indexes()) {
    if(!removeRows.contains(index.row())) {
    removeRows.append(index.row());
    }
    }

    //loop through all selected rows
    for(int i=0;i<removeRows.count();++i)
    {
    //decrement all rows after the current - as the row-number will change if we remove the current
    for(int j=i;j<removeRows.count();++j) {
    if(removeRows.at(j) > removeRows.at(i)) {
    removeRows[j]--;
    }
    }
    //remove the selected row
    model->removeRows(removeRows.at(i), 1);
    }
    model->submitAll();

}

void DBMainWindow::on_actionDrop_Table_triggered()
{
    QSqlQuery dropqry("DROP TABLE "+TabName);
    dropqry.exec();
}

#ifndef DBMAINWINDOW_H
#define DBMAINWINDOW_H

#include "dialog2.h"
#include "addtabledialog.h"
#include <QMainWindow>
#include <QSqlDatabase>
#include <QListWidgetItem>
#include <QSqlTableModel>

namespace Ui {
class DBMainWindow;
}

class DBMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit DBMainWindow(QWidget *parent = 0);
    ~DBMainWindow();
    
private slots:
    void on_actionConnect_triggered();

    void on_listWidget_itemClicked(QListWidgetItem *item);

    void on_actionAdd_Database_triggered();


    void on_actionNew_Table_triggered();

    void on_actionInsert_Values_triggered();

    void on_actionDelete_tuple_triggered();

    void on_actionDrop_Table_triggered();

private:
    Ui::DBMainWindow *ui;
    Dialog2 *d2;
    AddTableDialog *tabdiag;
    QSqlDatabase MyDB;
    QString HostName,DBName,UName,Passwd,TabName,DBType;
    QSqlTableModel *model;
    QStringList tabs;
    void setnewtab();
};

#endif // DBMAINWINDOW_H

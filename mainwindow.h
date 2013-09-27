#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <phonon/phonon>
#include <Phonon/MediaObject>
#include <QPlainTextEdit>
#include "dialog.h"
#include "dialog2.h"
#include "backenddialog.h"
#include <QSqlDatabase>
#include <QWebView>
#include <QTableWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();
protected:

    
private slots:

    void on_actionLocal_File_triggered();

    void on_actionHttp_Stream_triggered();

    void on_actionPlay_triggered();

    void on_actionPause_triggered();

    void on_actionStop_triggered();

    void on_actionFull_Screen_triggered();

    void on_actionExit_triggered();

    void on_actionSet_Database_triggered();

    void on_actionFrom_Database_triggered();

    void on_actionManage_Databases_triggered();

    void next();

    void on_tableWidget_cellClicked(int row, int column);

    void on_actionHide_Table_triggered();

    void on_pushButton_clicked();

    void on_actionAvailable_Formats_triggered();

private:
    Ui::MainWindow *ui;
    Phonon::MediaObject *med;
    Dialog *d;
    QSqlDatabase MyDB;
    QString HostName,DBName,UName,Passwd,TabName;
    QList<QUrl> urls;
    Dialog2 *d2;
    QTableWidgetItem *item;
    BackendDialog *bkdiag;



};

#endif // MAINWINDOW_H

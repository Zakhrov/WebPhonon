#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <phonon/phonon>
#include <Phonon/MediaObject>
#include <QPlainTextEdit>
#include "dialog.h"
#include "dialog2.h"
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

    void on_actionPrevious_triggered();

    void on_actionNext_triggered();

    void on_actionManage_Databases_triggered();



    void on_tableWidget_cellClicked(int row, int column);

private:
    Ui::MainWindow *ui;
    Phonon::MediaObject *med;
    QList<Phonon::MediaSource> *src;
    Dialog *d;
    QSqlDatabase MyDB;
    QString HostName,DBName,UName,Passwd;
    QList<QUrl> urls;
    Dialog2 *d2;
    QTableWidgetItem *item;



};

#endif // MAINWINDOW_H

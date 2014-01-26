#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <phonon/phonon>
#include <Phonon/MediaObject>
#include <Phonon/AudioOutput>
#include <QPlainTextEdit>
#include "dialog.h"
#include "dbmainwindow.h"
#include "backenddialog.h"
#include "helpdialog.h"
#include "dropwidget.h"
#include <QSqlDatabase>
#include <QWebView>
#include <QTableWidgetItem>
#include <Phonon/VideoWidget>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    void cmdopen(QString cmdfile);

    ~MainWindow();

public slots:
    void dropdata(const QMimeData *mimeData);
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

    void on_tableWidget_cellClicked(int row, int column);

    void on_actionHide_Table_triggered();

    void on_pushButton_clicked();

    void on_actionAvailable_Formats_triggered();

    void next();

    void on_actionUser_Manual_triggered();

    void on_actionBack_triggered();

    void on_actionFoward_triggered();
    void widgetpause(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    Phonon::MediaObject *med;
    Phonon::AudioOutput *sndout;
    Dialog *d;
    QSqlDatabase MyDB;
    QString HostName,DBName,UName,Passwd,TabName,DBType;
    QList<QUrl> urls;
    QList <Phonon::MediaSource> sources;
    DBMainWindow *dm2;
    QTableWidgetItem *item;
    BackendDialog *bkdiag;
    HelpDialog *hdiag;
    DropWidget *dwidget;



};

#endif // MAINWINDOW_H

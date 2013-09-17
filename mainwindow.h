#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <phonon/phonon>
#include <Phonon/MediaObject>
#include <QPlainTextEdit>
#include "dialog.h"
#include <QSqlDatabase>

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

private:
    Ui::MainWindow *ui;
    Phonon::MediaObject *med;
    Phonon::MediaSource *src;
    Dialog *d;
    QSqlDatabase MyDB;
    QString HostName,DBName,UName,Passwd;



};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QTableWidgetItem>
#include <QSettings>
//#include <phonon/phonon>
#ifdef Q_OS_LINUX
#include <KDE/Phonon/MediaObject>
#include <KDE/Phonon/AudioOutput>
#include <KDE/Phonon/VideoWidget>
#include <KDE/Phonon/BackendCapabilities>
#include <KDE/Phonon/Effect>
#include <KDE/Phonon/ObjectDescription>
#include <KDE/Phonon/EffectWidget>
#include "widget.h"
#else
#include <Phonon/MediaObject>
#include <Phonon/AudioOutput>
#include <Phonon/VideoWidget>
#include <Phonon/BackendCapabilities>
#include <Phonon/Effect>
#include <Phonon/ObjectDescription>
#include <Phonon/EffectWidget>
#include "winwidget.h"
#endif
#include <QPlainTextEdit>
#include "dialog.h"
#include "dbmainwindow.h"
#include "backenddialog.h"
#include "helpdialog.h"
#include "dropwidget.h"
#include "tablelistdialog.h"
#include "visualizer.h"


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
    void switchviewports(bool vflag);
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

    void on_actionVolume_Up_triggered();

    void on_actionVolume_Down_triggered();

    void on_actionSkip_Foward_triggered();

    void on_actionSkip_Backward_triggered();
    void timechanged(qint64 time);
    void totalTimeChanged(qint64 newtottime);


    void on_actionClear_Playlist_triggered();

    void on_actionAbout_WebPhonon_triggered();

    void on_actionAuto_triggered();

    void on_actionSquare_triggered();

    void on_actionWideScreen_triggered();

    void on_actionEqualizer_triggered();

    void on_actionOpen_Visualizer_triggered();

private:
    Ui::MainWindow *ui;
    Phonon::MediaObject *med;
    DropWidget *dwidget;
    Phonon::AudioOutput *sndout;
    Dialog *d;
    QSqlDatabase MyDB;
    QString HostName,DBName,UName,Passwd,TabName,DBType;
    QList<QUrl> urls;
    QList <Phonon::MediaSource> sources;
    DBMainWindow *dm2;
    QTableWidgetItem *item;
    BackendDialog *bkdiag;
    TableListDialog *tbdialog;
    HelpDialog *hdiag;
    qreal volume;
    qint64 currenttime;

     Phonon::Path apath;
     Phonon::Path vpath;
#ifdef Q_OS_LINUX
    Widget *eqwidget;
#else
     WinWidget *eqwidget;
#endif
      QSettings dbSettings;
      Visualizer *vwidget;





};
//Phonon::MediaObject MainWindow::med;
//DropWidget MainWindow::dwidget;

#endif // MAINWINDOW_H

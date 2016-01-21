#ifndef DBMAINWINDOW_H
#define DBMAINWINDOW_H


#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QMainWindow>

#include "addmoviedialog.h"
#include "addtvdialog.h"
#include "addmusicdialog.h"
#include "addmvdialog.h"
#include "addactordialog.h"
#include "addmoviecastdialog.h"
#include "addtvcastdialog.h"
#include "addartistdialog.h"
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


    void on_actionSongs_triggered();

    void on_actionActors_triggered();

    void on_actionArtists_triggered();

    void on_actionAlbums_triggered();

    void on_actionMovie_Info_triggered();

    void on_actionMovie_Cast_triggered();

    void on_actionShow_Info_triggered();

    void on_actionShow_Cast_triggered();

    void on_actionMusic_Video_Info_triggered();

    void on_actionMusic_Video_Cast_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_actionCreate_Database_triggered();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

private:
    void on_actionConnect_triggered();
    Ui::DBMainWindow *ui;
    AddMovieDialog *addmovie;
    AddTVDialog *addtv;
    AddMusicDialog *addmusic;
    AddMVDialog *addmv;
    AddActorDialog *addactor;
    AddMovieCastDialog *addmoviecast;
    AddTVCastDialog *addtvcast;
    AddArtistDialog *addartist;
    QSqlDatabase db;
    QSqlQueryModel *DBModel;



};

#endif // DBMAINWINDOW_H

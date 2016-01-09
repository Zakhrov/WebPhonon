#ifndef DBMAINWINDOW_H
#define DBMAINWINDOW_H



#include <QMainWindow>
#include "addmoviedialog.h"
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

private:
    Ui::DBMainWindow *ui;
    AddMovieDialog *addmovie;

};

#endif // DBMAINWINDOW_H

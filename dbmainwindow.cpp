#include "dbmainwindow.h"
#include "ui_dbmainwindow.h"
#include <QFileDialog>
#include <QtNetwork/QNetworkAccessManager>
#include <QDesktopServices>

DBMainWindow::DBMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DBMainWindow)
{

    ui->setupUi(this);


    addmovie = new AddMovieDialog(this);
    movieModel = new QSqlQueryModel(this);





}

DBMainWindow::~DBMainWindow()
{
     delete ui;
}

void DBMainWindow::on_actionConnect_triggered()
{

}



void DBMainWindow::on_actionSongs_triggered()
{
    db=QSqlDatabase::database("PlayConn");
    db.open();
    movieModel->setQuery("SELECT url, title, genre FROM music",db);
    ui->tableView->setModel(movieModel);
    db.close();
}

void DBMainWindow::on_actionActors_triggered()
{

}

void DBMainWindow::on_actionArtists_triggered()
{

}

void DBMainWindow::on_actionAlbums_triggered()
{

}

void DBMainWindow::on_actionMovie_Info_triggered()
{

    db=QSqlDatabase::database("PlayConn");
    db.open();
    movieModel->setQuery("SELECT url, title, studio, language, rating, genre FROM movies",db);
    ui->tableView->setModel(movieModel);
    db.close();
}

void DBMainWindow::on_actionMovie_Cast_triggered()
{

}

void DBMainWindow::on_actionShow_Info_triggered()
{
    db=QSqlDatabase::database("PlayConn");
    db.open();
    movieModel->setQuery("SELECT url, title, season, episode, ep_title, language, genre FROM tv",db);
    ui->tableView->setModel(movieModel);
    db.close();
}

void DBMainWindow::on_actionShow_Cast_triggered()
{

}

void DBMainWindow::on_actionMusic_Video_Info_triggered()
{
    db=QSqlDatabase::database("PlayConn");
    db.open();
    movieModel->setQuery("SELECT music_videos.url, music.title, music.genre FROM music_videos INNER JOIN music ON music_videos.music_id=music.music_id;",db);
    ui->tableView->setModel(movieModel);
    db.close();
}

void DBMainWindow::on_actionMusic_Video_Cast_triggered()
{

}

void DBMainWindow::on_pushButton_clicked()
{
    addmovie->show();
}

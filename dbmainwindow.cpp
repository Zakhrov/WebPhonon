#include "dbmainwindow.h"
#include "ui_dbmainwindow.h"
#include <QFileDialog>
#include <QDesktopServices>
#include <QMessageBox>
#include <QSqlError>
DBMainWindow::DBMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DBMainWindow)
{

    ui->setupUi(this);




    DBModel = new QSqlQueryModel(this);





}

DBMainWindow::~DBMainWindow()
{
     delete ui;
}

void DBMainWindow::on_actionConnect_triggered()
{
//    QSettings settings;
//    QMessageBox msg;
//    QSqlDatabase cdb=QSqlDatabase::addDatabase(settings.value("dbtype").toString(),"CreateConn");
//    cdb.setHostName(settings.value("server").toString());
//    cdb.setUserName(settings.value("username").toString());
//    cdb.setPassword(settings.value("password").toString());
//    cdb.open();
//    QSqlQuery createdb("CREATE DATABASE  IF NOT EXISTS `webphonon`; USE `webphonon`; DROP TABLE IF EXISTS `movies`;"
//                        "CREATE TABLE `movies` ("
//                         "`movies_id` int(11) NOT NULL AUTO_INCREMENT,"
//                         "`url` varchar(255) DEFAULT NULL,"
//                         "`title` varchar(45) DEFAULT NULL,"
//                         "`language` varchar(45) DEFAULT NULL,"
//                         "`studio` varchar(45) DEFAULT NULL,"
//                         "`rating` varchar(45) DEFAULT NULL,"
//                         "`genre` varchar(45) DEFAULT NULL,"
//                         "`year` int(11) DEFAULT NULL,"
//                         "PRIMARY KEY (`movies_id`),"
//                         "UNIQUE KEY `url_UNIQUE` (`url`)"
//                       ") ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;"
//                       "DROP TABLE IF EXISTS `music`;"
//                       "CREATE TABLE `music` ("
//                         "`music_id` int(11) NOT NULL AUTO_INCREMENT,"
//                         "`url` varchar(255) DEFAULT NULL,"
//                         "`title` varchar(45) DEFAULT NULL,"
//                         "`genre` varchar(45) DEFAULT NULL,"
//                          "`language` varchar(45) DEFAULT NULL,"
//                         "PRIMARY KEY (`music_id`),"
//                         "UNIQUE KEY `url_UNIQUE` (`url`)"
//                       ") ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;"
//                       "DROP TABLE IF EXISTS `music_videos`;"
//                       "CREATE TABLE `music_videos` ("
//                         "`mv_id` int(11) NOT NULL AUTO_INCREMENT,"
//                         "`url` varchar(255) DEFAULT NULL,"
//                         "`music_id` int(11) DEFAULT NULL,"
//                         "PRIMARY KEY (`mv_id`),"
//                         "UNIQUE KEY `url_UNIQUE` (`url`),"
//                         "KEY `fk_music_videos_1_idx` (`music_id`),"
//                         "CONSTRAINT `fk_music_videos_1` FOREIGN KEY (`music_id`) REFERENCES `music` (`music_id`) ON DELETE CASCADE ON UPDATE CASCADE"
//                       ") ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;"
//                      "DROP TABLE IF EXISTS `tv`;"
//                       "CREATE TABLE `tv` ("
//                         "`tv_id` int(11) NOT NULL AUTO_INCREMENT,"
//                         "`url` varchar(255) NOT NULL,"
//                          "`title` varchar(45) DEFAULT NULL,"
//                         "`season` int(11) DEFAULT NULL,"
//                         "`episode` int(11) DEFAULT NULL,"
//                         "`ep_title` varchar(45) DEFAULT NULL,"
//                         "`language` varchar(45) DEFAULT NULL,"
//                         "`genre` varchar(45) DEFAULT NULL,"
//                         "PRIMARY KEY (`tv_id`),"
//                         "UNIQUE KEY `url_UNIQUE` (`url`)"
//                       ") ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8;",cdb);
//    if(createdb.exec())
//       {
//        msg.setText("Database Created, Restart WebPhonon for the change to register");
//        msg.exec();
//    }
//    else
//    {
//        msg.setText("Database creation failed "+createdb.lastError().text());
//        msg.exec();
//    }
//    cdb.close();
}



void DBMainWindow::on_actionSongs_triggered()
{
    db=QSqlDatabase::database("PlayConn");
    db.open();
    DBModel->setQuery("SELECT url, title, genre FROM music",db);
    DBModel->setHeaderData(0,Qt::Horizontal,"URL");
    DBModel->setHeaderData(1,Qt::Horizontal,"Title");
    DBModel->setHeaderData(2,Qt::Horizontal,"Genre");
    ui->tableView->setModel(DBModel);
    ui->tableView->resizeColumnsToContents();
    db.close();
}

void DBMainWindow::on_actionActors_triggered()
{
    db=QSqlDatabase::database("PlayConn");
    db.open();
    DBModel->setQuery("SELECT name FROM actor",db);
    DBModel->setHeaderData(0,Qt::Horizontal,"Name");
    ui->tableView->setModel(DBModel);
    db.close();
}

void DBMainWindow::on_actionArtists_triggered()
{
    db=QSqlDatabase::database("PlayConn");
    db.open();
    DBModel->setQuery("SELECT name FROM artist",db);
    DBModel->setHeaderData(0,Qt::Horizontal,"Name");
    ui->tableView->setModel(DBModel);
    db.close();
}

void DBMainWindow::on_actionAlbums_triggered()
{
    db=QSqlDatabase::database("PlayConn");
    db.open();
    DBModel->setQuery("SELECT album_name, record_label FROM album",db);
    DBModel->setHeaderData(0,Qt::Horizontal,"Name");
    DBModel->setHeaderData(1,Qt::Horizontal,"Record Label");
    ui->tableView->setModel(DBModel);
    db.close();
}

void DBMainWindow::on_actionMovie_Info_triggered()
{

    db=QSqlDatabase::database("PlayConn");
    db.open();
    DBModel->setQuery("SELECT url, title, studio, language, rating, genre FROM movies",db);
    DBModel->setHeaderData(0,Qt::Horizontal,"URL");
    DBModel->setHeaderData(1,Qt::Horizontal,"Title");
    DBModel->setHeaderData(2,Qt::Horizontal,"Studio");
    DBModel->setHeaderData(3,Qt::Horizontal,"Language");
    DBModel->setHeaderData(4,Qt::Horizontal,"Rating");
    DBModel->setHeaderData(5,Qt::Horizontal,"Genre");
    ui->tableView->setModel(DBModel);
    ui->tableView->resizeColumnsToContents();
    db.close();
}

void DBMainWindow::on_actionMovie_Cast_triggered()
{
    db=QSqlDatabase::database("PlayConn");
    db.open();
    DBModel->setQuery("SELECT movies.title, actor.name, movie_cast.charecter_name, movie_cast.role FROM movie_cast INNER JOIN actor ON movie_cast.actor_id=actor.actor_id INNER JOIN movies ON movie_cast.movie_id=movies.movies_id;",db);
    DBModel->setHeaderData(0,Qt::Horizontal,"Movie");
    DBModel->setHeaderData(1,Qt::Horizontal,"Actor");
    DBModel->setHeaderData(2,Qt::Horizontal,"Charecter");
    DBModel->setHeaderData(3,Qt::Horizontal,"Role");
    ui->tableView->setModel(DBModel);
    ui->tableView->resizeColumnsToContents();
    db.close();
}

void DBMainWindow::on_actionShow_Info_triggered()
{
    db=QSqlDatabase::database("PlayConn");
    db.open();
    DBModel->setQuery("SELECT url, title, season, episode, ep_title, language, genre FROM tv",db);
    DBModel->setHeaderData(0,Qt::Horizontal,"URL");
    DBModel->setHeaderData(1,Qt::Horizontal,"Title");
    DBModel->setHeaderData(2,Qt::Horizontal,"Season");
    DBModel->setHeaderData(3,Qt::Horizontal,"Episode");
    DBModel->setHeaderData(4,Qt::Horizontal,"Episode Title");
    DBModel->setHeaderData(5,Qt::Horizontal,"Language");
    DBModel->setHeaderData(6,Qt::Horizontal,"Genre");
    ui->tableView->setModel(DBModel);
    ui->tableView->resizeColumnsToContents();
    db.close();
}

void DBMainWindow::on_actionShow_Cast_triggered()
{
    db=QSqlDatabase::database("PlayConn");
    db.open();
    DBModel->setQuery("SELECT tv.title, actor.name, tv_cast.charecter_name, tv_cast.role FROM tv_cast INNER JOIN actor ON tv_cast.actor_id=actor.actor_id INNER JOIN tv ON tv_cast.tv_id=tv.tv_id;",db);
    DBModel->setHeaderData(0,Qt::Horizontal,"TV Show");
    DBModel->setHeaderData(1,Qt::Horizontal,"Actor");
    DBModel->setHeaderData(2,Qt::Horizontal,"Character");
    DBModel->setHeaderData(3,Qt::Horizontal,"Role");
    ui->tableView->setModel(DBModel);
    ui->tableView->resizeColumnsToContents();
    db.close();
}

void DBMainWindow::on_actionMusic_Video_Info_triggered()
{
    db=QSqlDatabase::database("PlayConn");
    db.open();
    DBModel->setQuery("SELECT music_videos.url, music.title, music.genre FROM music_videos INNER JOIN music ON music_videos.music_id=music.music_id;",db);
    DBModel->setHeaderData(0,Qt::Horizontal,"URL");
    DBModel->setHeaderData(1,Qt::Horizontal,"Title");
    DBModel->setHeaderData(2,Qt::Horizontal,"Genre");
    ui->tableView->setModel(DBModel);
    ui->tableView->resizeColumnsToContents();
    db.close();
}

void DBMainWindow::on_actionMusic_Video_Cast_triggered()
{
    db=QSqlDatabase::database("PlayConn");
    db.open();
    DBModel->setQuery("SELECT music.title, actor.`name` FROM music,actor,music_video_cast,music_videos where music_video_cast.music_video_id=music_videos.mv_id and music_video_cast.actor_id=actor.actor_id and music_videos.music_id=music.music_id;",db);
    DBModel->setHeaderData(0,Qt::Horizontal,"Song/Music Video");
    DBModel->setHeaderData(1,Qt::Horizontal,"Actor");
    ui->tableView->setModel(DBModel);
    ui->tableView->resizeColumnsToContents();
    db.close();
}

void DBMainWindow::on_actionAlbum_Artists_Collaborators_triggered()
{
    db=QSqlDatabase::database("PlayConn");
    db.open();
    DBModel->setQuery("SELECT album.album_name, artist.name, album_cast.role FROM album_cast INNER JOIN album ON album_cast.album_id=album.album_id INNER JOIN artist ON album_cast.artist_id=artist.artist_id ;",db);
    DBModel->setHeaderData(0,Qt::Horizontal,"Album");
    DBModel->setHeaderData(1,Qt::Horizontal,"Artist");
    DBModel->setHeaderData(2,Qt::Horizontal,"Role");
    ui->tableView->setModel(DBModel);
    ui->tableView->resizeColumnsToContents();
    db.close();
}
void DBMainWindow::on_actionAlbum_Tracks_triggered()
{
    db=QSqlDatabase::database("PlayConn");
    db.open();
    DBModel->setQuery("SELECT album.album_name, music.title, music_album.track FROM music_album INNER JOIN album ON music_album.album_id=album.album_id INNER JOIN music ON music_album.music_id=music.music_id ;",db);
    DBModel->setHeaderData(0,Qt::Horizontal,"Album");
    DBModel->setHeaderData(1,Qt::Horizontal,"Song");
    DBModel->setHeaderData(2,Qt::Horizontal,"Track Number");
    ui->tableView->setModel(DBModel);
    ui->tableView->resizeColumnsToContents();
    db.close();
}

void DBMainWindow::on_pushButton_clicked()
{
    addmovie = new AddMovieDialog(this);
    addmovie->show();
}

void DBMainWindow::on_pushButton_2_clicked()
{
    addtv=new AddTVDialog(this);
    addtv->show();
}

void DBMainWindow::on_pushButton_3_clicked()
{
    //add music vids
    addmv = new AddMVDialog(this);

    addmv->show();
}

void DBMainWindow::on_pushButton_4_clicked()
{
    //add music
    addmusic = new AddMusicDialog(this);

    addmusic->show();
}

void DBMainWindow::on_actionCreate_Database_triggered()
{
    this->on_actionConnect_triggered();
}

void DBMainWindow::on_pushButton_5_clicked()
{
    addactor = new AddActorDialog(this);

    addactor->show();
}

void DBMainWindow::on_pushButton_6_clicked()
{
    addmoviecast = new AddMovieCastDialog(this);

    addmoviecast->show();
}

void DBMainWindow::on_pushButton_7_clicked()
{
    addtvcast = new AddTVCastDialog(this);

    addtvcast->show();
}

void DBMainWindow::on_pushButton_8_clicked()
{
    addartist = new AddArtistDialog(this);

    addartist->show();
}

void DBMainWindow::on_pushButton_9_clicked()
{
    //Add Albums
    addalbum = new AddAlbumDialog(this);
    addalbum->show();
}

void DBMainWindow::on_pushButton_10_clicked()
{
    //Add Album Artists
    addalbumcast = new AddAlbumCastDialog(this);
    addalbumcast->show();
}



void DBMainWindow::on_pushButton_11_clicked()
{
    //Add music to albums
    addmusicalbum = new AddMusicAlbumDialog(this);
    addmusicalbum->show();
}



void DBMainWindow::on_pushButton_12_clicked()
{
    addmvcast = new AddMVCastDialog(this);
    addmvcast->show();
}


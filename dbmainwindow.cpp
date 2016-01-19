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



    addmovie = new AddMovieDialog(this);
    DBModel = new QSqlQueryModel(this);
    addtv=new AddTVDialog(this);
    addmusic = new AddMusicDialog(this);
    addmv = new AddMVDialog(this);
    addactor = new AddActorDialog(this);
    addmoviecast = new AddMovieCastDialog(this);
    addtvcast = new AddTVCastDialog(this);




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

}

void DBMainWindow::on_actionAlbums_triggered()
{

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

}

void DBMainWindow::on_pushButton_clicked()
{
    addmovie->show();
}

void DBMainWindow::on_pushButton_2_clicked()
{
    addtv->show();
}

void DBMainWindow::on_pushButton_3_clicked()
{
    //add music vids
    addmv->show();
}

void DBMainWindow::on_pushButton_4_clicked()
{
    //add music
    addmusic->show();
}

void DBMainWindow::on_actionCreate_Database_triggered()
{
    this->on_actionConnect_triggered();
}

void DBMainWindow::on_pushButton_5_clicked()
{
    addactor->show();
}

void DBMainWindow::on_pushButton_6_clicked()
{
    addmoviecast->show();
}

void DBMainWindow::on_pushButton_7_clicked()
{
    addtvcast->show();
}

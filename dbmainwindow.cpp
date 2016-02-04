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
    db=QSqlDatabase::database("PlayConn");
    TabModel=new QSqlRelationalTableModel(this,db);




}

DBMainWindow::~DBMainWindow()
{
     delete ui;
}

void DBMainWindow::on_actionConnect_triggered()
{
        QMessageBox msg;
        msg.setText("Import the DB.sql file from ../share/WebPhonon/db on Linux or from C:/Program Files(x86)/WebPhonon/bin on Linux");
        msg.exec();

}



void DBMainWindow::on_actionSongs_triggered()
{



    TabModel->setTable("music");
    TabModel->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    TabModel->select();
    TabModel->setHeaderData(1,Qt::Horizontal,"URL");
    TabModel->setHeaderData(2,Qt::Horizontal,"Title");
    TabModel->setHeaderData(3,Qt::Horizontal,"Genre");
    ui->tableView->setModel(TabModel);
    ui->tableView->hideColumn(0);
    ui->tableView->resizeColumnsToContents();
    //db.close();



}

void DBMainWindow::on_actionActors_triggered()
{

    TabModel->setTable("actor");
    TabModel->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    TabModel->select();
    TabModel->setHeaderData(1,Qt::Horizontal,"Name");
    ui->tableView->setModel(TabModel);
    ui->tableView->hideColumn(0);
    ui->tableView->resizeColumnsToContents();

}

void DBMainWindow::on_actionArtists_triggered()
{
    TabModel->setTable("artist");
    TabModel->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    TabModel->select();
    TabModel->setHeaderData(1,Qt::Horizontal,"Name");
    ui->tableView->setModel(TabModel);
    ui->tableView->hideColumn(0);
    ui->tableView->resizeColumnsToContents();
}

void DBMainWindow::on_actionAlbums_triggered()
{
    TabModel->setTable("album");
    TabModel->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    TabModel->select();
    TabModel->setHeaderData(1,Qt::Horizontal,"Album Name");
    TabModel->setHeaderData(2,Qt::Horizontal,"Record Label");
    ui->tableView->setModel(TabModel);
    ui->tableView->hideColumn(0);
    ui->tableView->resizeColumnsToContents();
}

void DBMainWindow::on_actionMovie_Info_triggered()
{

    TabModel->setTable("movies");
    TabModel->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    TabModel->select();
    TabModel->setHeaderData(1,Qt::Horizontal,"Url");
    TabModel->setHeaderData(2,Qt::Horizontal,"Title");
    TabModel->setHeaderData(3,Qt::Horizontal,"Studio");
    TabModel->setHeaderData(4,Qt::Horizontal,"Language");
    TabModel->setHeaderData(5,Qt::Horizontal,"Rating");
    TabModel->setHeaderData(6,Qt::Horizontal,"Genre");
    ui->tableView->setModel(TabModel);
    ui->tableView->hideColumn(0);
    ui->tableView->resizeColumnsToContents();

}

void DBMainWindow::on_actionMovie_Cast_triggered()
{

    TabModel->setTable("movie_cast");
    TabModel->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    TabModel->setRelation(1,QSqlRelation("movies","movies_id","title"));
    TabModel->setRelation(2,QSqlRelation("actor","actor_id","name"));
    TabModel->select();
    TabModel->setHeaderData(1,Qt::Horizontal,"Movie");
    TabModel->setHeaderData(2,Qt::Horizontal,"Actor");
    TabModel->setHeaderData(3,Qt::Horizontal,"Charecter");
    TabModel->setHeaderData(4,Qt::Horizontal,"Role");
    ui->tableView->setModel(TabModel);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    ui->tableView->hideColumn(0);
    ui->tableView->resizeColumnsToContents();


}

void DBMainWindow::on_actionShow_Info_triggered()
{
    TabModel->setTable("tv");
    TabModel->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    TabModel->select();
    TabModel->setHeaderData(1,Qt::Horizontal,"Url");
    TabModel->setHeaderData(2,Qt::Horizontal,"Title");
    TabModel->setHeaderData(3,Qt::Horizontal,"Season");
    TabModel->setHeaderData(4,Qt::Horizontal,"Episode");
    TabModel->setHeaderData(5,Qt::Horizontal,"Episode Title");
    TabModel->setHeaderData(6,Qt::Horizontal,"Language");
    TabModel->setHeaderData(7,Qt::Horizontal,"Genre");
    ui->tableView->setModel(TabModel);

    ui->tableView->hideColumn(0);
    ui->tableView->resizeColumnsToContents();
}

void DBMainWindow::on_actionShow_Cast_triggered()
{
    TabModel->setTable("tv_cast");
    TabModel->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    TabModel->setRelation(1,QSqlRelation("tv","tv_id","title"));
    TabModel->setRelation(2,QSqlRelation("actor","actor_id","name"));
    TabModel->select();
    TabModel->setHeaderData(1,Qt::Horizontal,"TV Show");
    TabModel->setHeaderData(2,Qt::Horizontal,"Actor");
    TabModel->setHeaderData(3,Qt::Horizontal,"Character");
    TabModel->setHeaderData(4,Qt::Horizontal,"Role");
    ui->tableView->setModel(TabModel);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    ui->tableView->hideColumn(0);
    ui->tableView->resizeColumnsToContents();




}

void DBMainWindow::on_actionMusic_Video_Info_triggered()
{
    TabModel->setTable("music_videos");
    TabModel->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    TabModel->setRelation(2,QSqlRelation("music","music_id","title"));
    TabModel->select();
    TabModel->setHeaderData(1,Qt::Horizontal,"URL");
    TabModel->setHeaderData(2,Qt::Horizontal,"Title");
    ui->tableView->setModel(TabModel);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    ui->tableView->hideColumn(0);
    ui->tableView->resizeColumnsToContents();

}

void DBMainWindow::on_actionMusic_Video_Cast_triggered()
{

    TabModel->setTable("music_video_cast");
    TabModel->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    TabModel->setRelation(1,QSqlRelation("music_videos","mv_id","url"));
    TabModel->setRelation(2,QSqlRelation("actor","actor_id","name"));
    TabModel->select();
    TabModel->setHeaderData(1,Qt::Horizontal,"Song/Music Video");
    TabModel->setHeaderData(2,Qt::Horizontal,"Actor");
    ui->tableView->setModel(TabModel);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    ui->tableView->hideColumn(0);
    ui->tableView->resizeColumnsToContents();

}

void DBMainWindow::on_actionAlbum_Artists_Collaborators_triggered()
{

    TabModel->setTable("album_cast");
    TabModel->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    TabModel->setRelation(1,QSqlRelation("album","album_id","album_name"));
    TabModel->setRelation(2,QSqlRelation("artist","artist_id","name"));
    TabModel->select();
    TabModel->setHeaderData(1,Qt::Horizontal,"Album");
    TabModel->setHeaderData(2,Qt::Horizontal,"Artist");
    TabModel->setHeaderData(3,Qt::Horizontal,"Role");
    ui->tableView->setModel(TabModel);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    ui->tableView->hideColumn(0);
    ui->tableView->resizeColumnsToContents();

}
void DBMainWindow::on_actionAlbum_Tracks_triggered()
{


    TabModel->setTable("music_album");
    TabModel->setEditStrategy(QSqlRelationalTableModel::OnFieldChange);
    TabModel->setRelation(1,QSqlRelation("album","album_id","album_name"));
    TabModel->setRelation(2,QSqlRelation("music","music_id","title"));
    TabModel->select();
    TabModel->setHeaderData(1,Qt::Horizontal,"Album");
    TabModel->setHeaderData(2,Qt::Horizontal,"Song");
    TabModel->setHeaderData(3,Qt::Horizontal,"Track Number");
    ui->tableView->setModel(TabModel);
    ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
    ui->tableView->hideColumn(0);
    ui->tableView->resizeColumnsToContents();
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


void DBMainWindow::on_actionDelete_Selected_Item_triggered()
{
    TabModel->removeRow(ui->tableView->currentIndex().row());
}

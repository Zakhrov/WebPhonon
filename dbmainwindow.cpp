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

}

void DBMainWindow::on_actionMovie_Cast_triggered()
{

}

void DBMainWindow::on_actionShow_Info_triggered()
{

}

void DBMainWindow::on_actionShow_Cast_triggered()
{

}

void DBMainWindow::on_actionMusic_Video_Info_triggered()
{

}

void DBMainWindow::on_actionMusic_Video_Cast_triggered()
{

}

void DBMainWindow::on_pushButton_clicked()
{
    addmovie->show();
}

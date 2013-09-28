#include "dialog.h"
#include "dialog2.h"
#include "backenddialog.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Phonon/AudioOutput>
#include <Phonon/MediaObject>
#include <QFileDialog>
#include <Phonon/BackendCapabilities>
#include <QDesktopServices>
#include <QSqlDatabase>
#include <QTableWidgetItem>
#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    d=new Dialog(this);
    d2=new Dialog2(this);
    bkdiag=new BackendDialog(this);
    Phonon::AudioOutput *sndout=new Phonon::AudioOutput(Phonon::VideoCategory,this);
    med=new Phonon::MediaObject(this);
    Phonon::createPath(med,ui->VideoWidget);
    Phonon::createPath(med,sndout);
    QStringList collabel;
    collabel.append("URL");
    collabel.append("Name");
    //Phonon::createPath(Phonon::BackendCapabilities::isMimeTypeAvailable(),ui->VideoWidget);
    ui->seekSlider->setMediaObject(med);
    ui->volumeSlider->setAudioOutput(sndout);
    ui->lineEdit->hide();
    urls.clear();
    connect(med,SIGNAL(finished()),this,SLOT(next()));
    ui->tableWidget->hide();
     ui->tableWidget->setColumnCount(2);
     ui->tableWidget->setHorizontalHeaderLabels(collabel);
     ui->pushButton->hide();


}


MainWindow::~MainWindow()
{
    MyDB.close();
    delete ui;
}

void MainWindow::on_actionLocal_File_triggered()
{
    int i;
    QString fname=QFileDialog::getOpenFileName(this,tr("Choose Files"));
    med->enqueue(Phonon::MediaSource(QUrl(fname)));
    QTableWidgetItem *fitem=new QTableWidgetItem(fname,1);
    i=ui->tableWidget->currentRow();
    ui->tableWidget->insertRow(i+1);
    ui->tableWidget->setItem(i+1,0,fitem);
     ui->tableWidget->resizeColumnsToContents();
    if(med->state()!=Phonon::PlayingState)
    med->play();
}


void MainWindow::on_actionHttp_Stream_triggered()
{

    ui->lineEdit->show();
    ui->pushButton->show();

}

void MainWindow::on_actionPlay_triggered()
{
    med->play();
    ui->lineEdit->hide();
}

void MainWindow::on_actionPause_triggered()
{
    if(med->state()==Phonon::PlayingState)
    med->pause();
    else
        med->play();
}

void MainWindow::on_actionStop_triggered()
{
    med->clearQueue();
    med->stop();




}

void MainWindow::on_actionFull_Screen_triggered()
{

   if(ui->VideoWidget->isFullScreen()==false)
   { 
       ui->VideoWidget->setFullScreen(true);

   }
   else
   {

      ui->VideoWidget->setFullScreen(false);
   }


}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionSet_Database_triggered()
{
    d->show();

}

void MainWindow::on_actionFrom_Database_triggered()
{

    QString tabindex,titleindex;
    int i=0;
    HostName=d->host;
    DBName=d->dbname;
    UName=d->uname;
    Passwd=d->passwd;
    TabName=d->tabname;

    MyDB=QSqlDatabase::addDatabase("QMYSQL");
    MyDB.setHostName(HostName);
    MyDB.setDatabaseName(DBName);
    MyDB.open(UName,Passwd);
    QSqlQuery request("SELECT url, name FROM "+TabName);
    while(request.next()){
      ui->tableWidget->insertRow(i);
      urls.append(QUrl(request.value(0).toString()));
      tabindex=request.value(0).toString();
      titleindex=request.value(1).toString();
      QTableWidgetItem *titletab=new QTableWidgetItem(titleindex,1);
      item=new QTableWidgetItem(tabindex,1);
      ui->tableWidget->setItem(i,1,titletab);
      ui->tableWidget->setItem(i,0,item);
      i++;
    }
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->show();
    med->enqueue(urls);
    if(med->state()!=Phonon::PlayingState)
    med->play();
    MyDB.close();
}

void MainWindow::on_actionManage_Databases_triggered()
{

    d2->show();
}


void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    if(column==0)
    {
        QTableWidgetItem *itab=ui->tableWidget->item(row,column);
        med->setCurrentSource(Phonon::MediaSource(itab->text()));
        med->play();
    }
}

void MainWindow::on_actionHide_Table_triggered()
{
    if(ui->tableWidget->isHidden()==true)
    ui->tableWidget->show();
    else
        ui->tableWidget->hide();
    ui->lineEdit->hide();

}
void MainWindow::next()
{
    int index=med->queue().indexOf(med->currentSource())+1;
    if(med->queue().size()>index)
        med->enqueue(med->queue().at(index));
}

void MainWindow::on_pushButton_clicked()
{
    int i;
    QString uname;
    uname.insert(0,ui->lineEdit->text());
    med->enqueue(Phonon::MediaSource(QUrl(uname)));
    QTableWidgetItem *uitem=new QTableWidgetItem(uname,1);
    i=ui->tableWidget->currentRow();
    ui->tableWidget->insertRow(i+1);
    ui->tableWidget->setItem(i+1,0,uitem);
     ui->tableWidget->resizeColumnsToContents();
     ui->lineEdit->hide();
     ui->pushButton->hide();
     if(med->state()!=Phonon::PlayingState)
     med->play();
}

void MainWindow::on_actionAvailable_Formats_triggered()
{
    bkdiag->show();
}

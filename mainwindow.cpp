#include "dialog.h"
#include "dbmainwindow.h"
#include "backenddialog.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "helpdialog.h"
#include <Phonon/AudioOutput>
#include <Phonon/MediaObject>
#include <QFileDialog>
#include <Phonon/BackendCapabilities>
#include <QDesktopServices>
#include <QSqlDatabase>
#include <QTableWidgetItem>
#include <QSqlQuery>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    this->setWindowIcon(QIcon(":/icons/WebPhononIcon.png"));
    ui->setupUi(this);
    d=new Dialog(this);
    dm2=new DBMainWindow(this);
    bkdiag=new BackendDialog(this);
    hdiag=new HelpDialog(this);
    Phonon::AudioOutput *sndout=new Phonon::AudioOutput(Phonon::VideoCategory,this);
    med=new Phonon::MediaObject(this);
    med->setTransitionTime(2000);
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
    ui->tableWidget->hide();
     ui->tableWidget->setColumnCount(2);
     ui->tableWidget->setHorizontalHeaderLabels(collabel);
     ui->pushButton->hide();
   connect(med,SIGNAL(aboutToFinish()),this,SLOT(next()));


}
MainWindow::~MainWindow()
{
    MyDB.close();
    delete ui;
}

void MainWindow::on_actionLocal_File_triggered()
{
    int i;
    int index=sources.size();
    QStringList fnames=QFileDialog::getOpenFileNames(this,tr("Choose Files"),QDesktopServices::storageLocation(QDesktopServices::MoviesLocation));
    foreach (QString fname, fnames) {
        sources.append(Phonon::MediaSource(fname));
        QTableWidgetItem *fitem=new QTableWidgetItem(fname,1);
        i=ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,fitem);
    }

     ui->tableWidget->resizeColumnsToContents();

     if(med->state()!=Phonon::PlayingState)
     {

         if(!sources.isEmpty())
        med->setCurrentSource(sources.at(index));
        med->play();
     }

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
    int i;
    int index=sources.size();
    HostName=d->host;
    DBName=d->dbname;
    UName=d->uname;
    Passwd=d->passwd;
    TabName=d->tabname;
    DBType=d->dbtype;
    QPixmap img1,img2;
    img1.load(":/Icons/WebPhononIcon.png");
    img2=img1.scaled(32,32);
    QMessageBox msg;
    msg.setIconPixmap(img2);
    msg.setWindowTitle("Database Module");
   // QStringList dnames;
    MyDB=QSqlDatabase::addDatabase(DBType);
    MyDB.setConnectOptions();
    if(MyDB.isDriverAvailable(DBType)==true)
    {
        if(DBType=="QODBC")
        {
            QString dsn= QString("DRIVER={SQL Server};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(HostName).arg(DBName);
           MyDB.setDatabaseName(dsn);
           MyDB.open();
        }
        else
        {
           MyDB.setHostName(HostName);
            MyDB.setDatabaseName(DBName);
             MyDB.open(UName,Passwd);
        }

        if(MyDB.isOpen()==true)
        {
              msg.setText(MyDB.driverName()+" Database "+DBName+" Open");
              msg.exec();
        }
        QSqlQuery request("SELECT url, name FROM "+TabName);
        while(request.next())
        {

            tabindex=request.value(0).toString();
            titleindex=request.value(1).toString();
            sources.append(Phonon::MediaSource(QUrl(request.value(0).toString())));
            QTableWidgetItem *item1=new QTableWidgetItem(tabindex,1);
            QTableWidgetItem *item2=new QTableWidgetItem(titleindex,1);
            i=ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(i);
            ui->tableWidget->setItem(i,0,item1);
            ui->tableWidget->setItem(i,1,item2);
        }
        ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget->show();
        if(med->state()!=Phonon::PlayingState)
        {
            if(!sources.isEmpty())
                med->setCurrentSource(sources.at(index));

            med->play();
        }

        MyDB.close();
    }
    else
    {
        msg.setText("Database Driver not Loaded");
        msg.exec();
    }

}

void MainWindow::on_actionManage_Databases_triggered()
{

    dm2->show();
}


void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    if(column==0)
    {

        med->stop();
        med->clearQueue();
        if(row>=sources.size())
            return;
        med->setCurrentSource(sources[row]);
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
    ui->pushButton->hide();

}
void MainWindow::on_pushButton_clicked()
{
    int i;
    QString uname;
    uname.insert(0,ui->lineEdit->text());
    int index=sources.size();
    sources.append(Phonon::MediaSource(QUrl(uname)));
    QTableWidgetItem *uitem=new QTableWidgetItem(uname,1);
    i=ui->tableWidget->currentRow();
    ui->tableWidget->insertRow(i+1);
    ui->tableWidget->setItem(i+1,0,uitem);
     ui->tableWidget->resizeColumnsToContents();
     ui->lineEdit->hide();
     ui->pushButton->hide();
     if(med->state()!=Phonon::PlayingState)
     {
         if(!sources.isEmpty())
             med->setCurrentSource(sources.at(index));

         med->play();
     }

}

void MainWindow::on_actionAvailable_Formats_triggered()
{
    bkdiag->show();
}

void MainWindow::next()
{
    int index=sources.indexOf(med->currentSource())+1;

       if(sources.size()>index)
           med->enqueue(sources.at(index));

}

void MainWindow::on_actionUser_Manual_triggered()
{
    hdiag->showMaximized();
}

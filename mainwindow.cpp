/* this is the main player window for WebPhonon. Here, a phonon graph is built that handles the audio and video
  from the various locations such as local files, http streams and from a database table
  The current databases supported are MySQL for Linux/Windows and
  Microsoft SQL Server as a windows only option.
  MS SQL support is not fully tested.
  TODO
  Add media from disks such as CD, DVD and Blu-Ray this means that fututre dependencies may include libdvdcss2 and libbluray
  Add proper media scanner and tagger for pulling metadata for a video file (like XBMC)
*/
#include "dialog.h"
#include "dbmainwindow.h"
#include "backenddialog.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "helpdialog.h"
#include "dropwidget.h"
#include "aboutdialog.h"
//#include <KDE/Phonon/AudioOutput>
//#include <KDE/Phonon/MediaObject>
#include <QFileDialog>
//#include <KDE/Phonon/BackendCapabilities>
#include <QDesktopServices>
#include <QSqlDatabase>
#include <QTableWidgetItem>
#include <QSqlQuery>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //setting window icon and initializing objects
    this->setWindowIcon(QIcon(":/icons/WebPhononIcon.png"));
    ui->setupUi(this);
    d=new Dialog(this);


    bkdiag=new BackendDialog(this);
    hdiag=new HelpDialog(this);
    sndout=new Phonon::AudioOutput(Phonon::VideoCategory,this);
    med=new Phonon::MediaObject(this);
    dwidget=new DropWidget(this);
    vwidget = new Visualizer(this);
    med->setTransitionTime(2000);
    effectDescriptions =Phonon::BackendCapabilities::availableAudioEffects();
#ifdef Q_OS_LINUX
    effectDescription = effectDescriptions.at(3);
#else
    effectDescription = effectDescriptions.at(0);
#endif
    effect = new Phonon::Effect(effectDescription);
    effectWidget = new Phonon::EffectWidget(effect);
    ui->gridLayout_3->addWidget(effectWidget);
    effectWidget->hide();
    vpath=Phonon::createPath(med,dwidget);
    apath=Phonon::createPath(med,sndout);
    apath.insertEffect(effect);
    QStringList collabel;
    collabel.append("URL");
    collabel.append("Name");
    ui->seekSlider->setMediaObject(med);
    ui->volumeSlider->setAudioOutput(sndout);
    ui->volumeSlider->setTracking(true);
    ui->lineEdit->hide();
    urls.clear();
    ui->tableWidget->hide();
     ui->tableWidget->setColumnCount(2);
     ui->tableWidget->setHorizontalHeaderLabels(collabel);
     ui->pushButton->hide();
     //vwidget->hide();
     //connecting signals and slots for going to next file and for drag n drop
     connect(med,SIGNAL(finished()),this,SLOT(next()));
   connect(dwidget,SIGNAL(geturls(const QMimeData*)),this,SLOT(dropdata(const QMimeData*)));
   connect(dwidget,SIGNAL(capturespace(QKeyEvent*)),this,SLOT(widgetpause(QKeyEvent*)));
   connect(med,SIGNAL(tick(qint64)),this,SLOT(timechanged(qint64)));
   //connect(med,SIGNAL(tick(qint64)),vwidget,SLOT(setXRotation(qint64)));
   connect(med,SIGNAL(totalTimeChanged(qint64)),this,SLOT(totalTimeChanged(qint64)));
   connect(med,SIGNAL(hasVideoChanged(bool)),this,SLOT(switchviewports(bool)));
   //adding custom video widget with drag n drop enabled
    ui->gridLayout->addWidget(dwidget);
   ui->gridLayout->addWidget(vwidget);
   vwidget->hide();
    ui->seekSlider->setIconVisible(false);
    ui->volumeSlider->setMuteVisible(false);
    ui->volumeSlider->setOrientation(Qt::Vertical);
    volume=sndout->volumeDecibel();
    ui->label->setText(QString::number(volume));
    //s_instance=this;
    HostName=dbSettings.value("server").toString();
    DBName=dbSettings.value("database").toString();
    UName=dbSettings.value("username").toString();
    Passwd=dbSettings.value("password").toString();
    DBType=dbSettings.value("dbtype").toString();
    MyDB=QSqlDatabase::addDatabase(DBType,"PlayConn");
    MyDB.setHostName(HostName);
    MyDB.setDatabaseName(DBName);
    MyDB.setUserName(UName);
    MyDB.setPassword(Passwd);



}

void MainWindow::cmdopen(QString cmdfile)
{
    int i;
    int index=sources.size();

    sources.append(Phonon::MediaSource(QUrl(cmdfile)));
    QTableWidgetItem *fitem=new QTableWidgetItem(cmdfile,1);
    i=ui->tableWidget->rowCount();
    ui->tableWidget->insertRow(i);
    ui->tableWidget->setItem(i,0,fitem);
    if(med->state()!=Phonon::PlayingState)
    {

        if(!sources.isEmpty())
       med->setCurrentSource(sources.at(index));
       this->on_actionPlay_triggered();
    }

    ui->tableWidget->resizeColumnsToContents();

}
MainWindow::~MainWindow()
{


    delete ui;

}
void MainWindow::on_actionLocal_File_triggered()
{
 //this function/slot triggers a dialog box for selecting files and adds files to the tablewidget (playlist)
    int i;
    int index=sources.size();
    QStringList fnames=QFileDialog::getOpenFileNames(this,tr("Choose Files"),QDesktopServices::storageLocation(QDesktopServices::MoviesLocation));
    foreach (QString fname, fnames) {
        sources.append(Phonon::MediaSource(QUrl::fromLocalFile(fname)));
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
        this->on_actionPlay_triggered();
     }

}



void MainWindow::on_actionHttp_Stream_triggered()
{

   //shows th url bar for adding http streams
    ui->lineEdit->show();
    ui->pushButton->show();

}

void MainWindow::on_actionPlay_triggered()
{
    //int aspect;
    med->play();
    ui->lineEdit->hide();
    ui->pushButton->hide();
    ui->tableWidget->selectRow(sources.indexOf(med->currentSource()));
    volume=sndout->volumeDecibel();


}

void MainWindow::on_actionPause_triggered()
{
    if(med->state()==Phonon::PlayingState)
    {
    med->pause();
   // vwidget->timer->setInterval(100);
    }
    else
        med->play();
}

void MainWindow::on_actionStop_triggered()
{
    med->stop();
    //vwidget->timer->stop();
}

void MainWindow::on_actionFull_Screen_triggered()
{

   if(dwidget->isFullScreen()==false)
   { 
       dwidget->setFullScreen(true);
       dwidget->setFocus();

   }
   else
   {

      dwidget->setFullScreen(false);
   }


}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionSet_Database_triggered()
{
    //opens the set database dialog
    d->show();

}

void MainWindow::on_actionFrom_Database_triggered()
{
    //queries the database for media information and urls
    QString tabindex,titleindex,studio,language,genre,year;
    int i;
    int index=sources.size();
    tbdialog=new TableListDialog(this);
    tbdialog->exec();

    TabName=tbdialog->tabname;

    QPixmap img1,img2;
    img1.load(":/Icons/WebPhononIcon.png");
    img2=img1.scaled(32,32);
    QMessageBox msg;
    msg.setIconPixmap(img2);
    msg.setWindowTitle("Database Module");
MyDB.open();

//    if(MyDB.isDriverAvailable(DBType)==true)
//    {
//        if(DBType=="QODBC")
//        {
//            QString dsn= QString("DRIVER={SQL Server};SERVER=%1;DATABASE=%2;Trusted_Connection=Yes;").arg(HostName).arg(DBName);
//           MyDB.setDatabaseName(dsn)Musiccollabel.append("Album");
//           MyDB.open();
//        }

//        if(MyDB.isOpen()==true)
//        {
//              msg.setText(MyDB.driverName()+" Database "+DBName+" Open");
//              msg.exec();
//        }
        if(TabName==""||!MyDB.tables().contains(TabName))
        {
            msg.setText(TabName+" does not exist");
            msg.exec();
        }
        else if(TabName=="movies")
        {
            //ui->tableWidget->clear();
            ui->tableWidget->setColumnCount(5);
            QStringList Moviecollabel;
            QString rating;
            Moviecollabel.append("URL");
            Moviecollabel.append("Title");
            Moviecollabel.append("Studio");
            Moviecollabel.append("Language");
            Moviecollabel.append("Rating");
            ui->tableWidget->setHorizontalHeaderLabels(Moviecollabel);
            QSqlQuery request("SELECT url, title, studio, language, rating FROM "+TabName,MyDB);
            while(request.next())
            {

                tabindex=request.value(0).toString();
                titleindex=request.value(1).toString();
                studio=request.value(2).toString();
                language=request.value(3).toString();
                rating=request.value(4).toString();
                sources.append(Phonon::MediaSource(QUrl(request.value(0).toString())));
                QTableWidgetItem *item1=new QTableWidgetItem(tabindex,1);
                QTableWidgetItem *item2=new QTableWidgetItem(titleindex,1);
                QTableWidgetItem *item3=new QTableWidgetItem(studio,1);
                QTableWidgetItem *item4=new QTableWidgetItem(language,1);
                QTableWidgetItem *item5=new QTableWidgetItem(rating,1);
                i=ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(i);
                ui->tableWidget->setItem(i,0,item1);
                ui->tableWidget->setItem(i,1,item2);
                ui->tableWidget->setItem(i,2,item3);
                ui->tableWidget->setItem(i,3,item4);
                ui->tableWidget->setItem(i,4,item5);
            }
        }
        else if(TabName=="music")
        {
            //ui->tableWidget->clear();
            ui->tableWidget->setColumnCount(4);
            QStringList Musiccollabel;
            Musiccollabel.append("URL");
            Musiccollabel.append("Title");
            Musiccollabel.append("Genre");
            Musiccollabel.append("language");
            ui->tableWidget->setHorizontalHeaderLabels(Musiccollabel);
            QSqlQuery request("SELECT url, title, genre,language FROM "+TabName,MyDB);
            while(request.next())
            {

                tabindex=request.value(0).toString();
                titleindex=request.value(1).toString();
                genre=request.value(2).toString();
                language=request.value(3).toString();
                sources.append(Phonon::MediaSource(QUrl(request.value(0).toString())));
                QTableWidgetItem *item1=new QTableWidgetItem(tabindex,1);
                QTableWidgetItem *item2=new QTableWidgetItem(titleindex,1);
                QTableWidgetItem *item3=new QTableWidgetItem(genre,1);
                QTableWidgetItem *item4=new QTableWidgetItem(language,1);
                i=ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(i);
                ui->tableWidget->setItem(i,0,item1);
                ui->tableWidget->setItem(i,1,item2);
                ui->tableWidget->setItem(i,2,item3);
                ui->tableWidget->setItem(i,3,item4);

            }
        }
        else if(TabName=="music_videos")
        {

           // ui->tableWidget->clear();
            ui->tableWidget->setColumnCount(4);
            QStringList MVidcollabel;
            MVidcollabel.append("URL");
            MVidcollabel.append("Title");
            MVidcollabel.append("Genre");
            MVidcollabel.append("Language");
            ui->tableWidget->setHorizontalHeaderLabels(MVidcollabel);
            QSqlQuery request("SELECT music_videos.url, music.title, music.genre, music.language FROM music, music_videos WHERE music_videos.music_id=music.music_id",MyDB);
            while(request.next())
            {

                tabindex=request.value(0).toString();
                titleindex=request.value(1).toString();
                genre=request.value(2).toString();
                language=request.value(3).toString();
                sources.append(Phonon::MediaSource(QUrl(request.value(0).toString())));
                QTableWidgetItem *item1=new QTableWidgetItem(tabindex,1);
                QTableWidgetItem *item2=new QTableWidgetItem(titleindex,1);
                QTableWidgetItem *item3=new QTableWidgetItem(genre,1);
                QTableWidgetItem *item4=new QTableWidgetItem(language,1);
                i=ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(i);
                ui->tableWidget->setItem(i,0,item1);
                ui->tableWidget->setItem(i,1,item2);
                ui->tableWidget->setItem(i,2,item3);
                ui->tableWidget->setItem(i,3,item4);

            }
        }
        else if(TabName=="tv")
        {
            int season,episode;
            QString eptitle;
           // ui->tableWidget->clear();
            ui->tableWidget->setColumnCount(7);
            QStringList TVcollabel;
            TVcollabel.append("URL");
            TVcollabel.append("Title");
            TVcollabel.append("Season");
            TVcollabel.append("Episode");
            TVcollabel.append("Episode Title");
            TVcollabel.append("Language");
            TVcollabel.append("Genre");
            ui->tableWidget->setHorizontalHeaderLabels(TVcollabel);
            QSqlQuery request("SELECT url, title, season, episode, ep_title, language, genre FROM "+TabName,MyDB);
            while(request.next())
            {

                tabindex=request.value(0).toString();
                titleindex=request.value(1).toString();
                season=request.value(2).toInt();
                episode=request.value(3).toInt();
                eptitle=request.value(4).toString();
                language=request.value(5).toString();
                genre=request.value(6).toString();
                sources.append(Phonon::MediaSource(QUrl(request.value(0).toString())));
                QTableWidgetItem *item1=new QTableWidgetItem(tabindex,1);
                QTableWidgetItem *item2=new QTableWidgetItem(titleindex,1);
                QTableWidgetItem *item3=new QTableWidgetItem(QString::number(season),1);
                QTableWidgetItem *item4=new QTableWidgetItem(QString::number(episode),1);
                QTableWidgetItem *item5=new QTableWidgetItem(eptitle,1);
                QTableWidgetItem *item6=new QTableWidgetItem(language,1);
                QTableWidgetItem *item7=new QTableWidgetItem(genre,1);
                i=ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(i);
                ui->tableWidget->setItem(i,0,item1);
                ui->tableWidget->setItem(i,1,item2);
                ui->tableWidget->setItem(i,2,item3);
                ui->tableWidget->setItem(i,3,item4);
                ui->tableWidget->setItem(i,4,item5);
                ui->tableWidget->setItem(i,5,item6);
                ui->tableWidget->setItem(i,6,item7);
            }
        }
        else
        {
            QSqlQuery request("SELECT url, title FROM "+TabName,MyDB);
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
        }
        ui->tableWidget->resizeColumnsToContents();
        ui->tableWidget->show();
        if(med->state()!=Phonon::PlayingState)
        {
            if(!sources.isEmpty())
                med->setCurrentSource(sources.at(index));
            this->on_actionPlay_triggered();
        }

        MyDB.close();
//    }
//    else
//    {
//        msg.setText("Database Driver not Loaded");
//        msg.exec();
//    }

}

void MainWindow::on_actionManage_Databases_triggered()
{
    //shows database manager window
    dm2=new DBMainWindow(this);
    dm2->showMaximized();
}


void MainWindow::on_tableWidget_cellClicked(int row, int column)
{
    if(column==0)
    {

        med->stop();
        med->clearQueue();
        if(row>=sources.size())
            //adds url typed in url bar to playlist
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
    //adds url typed in url bar to playlist
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
            this->on_actionPlay_triggered();
     }

}

void MainWindow::on_actionAvailable_Formats_triggered()
{
    bkdiag->show();
}

void MainWindow::next()
{

    this->on_actionFoward_triggered();
}

void MainWindow::on_actionUser_Manual_triggered()
{
    //opens user manual
    hdiag->showMaximized();
}

void MainWindow::dropdata(const QMimeData *mimeData)
{
    //activates drag n drop
    int i;
    int index=sources.size();
    if (mimeData->hasUrls()) {
             foreach (QUrl url, mimeData->urls()) {
                 sources.append(Phonon::MediaSource(url));
                QTableWidgetItem *uitem=new QTableWidgetItem(url.toString(),1);
                i=ui->tableWidget->rowCount();
                ui->tableWidget->insertRow(i);
                ui->tableWidget->setItem(i,0,uitem);
             }
             ui->tableWidget->resizeColumnsToContents();

             if(med->state()!=Phonon::PlayingState)
             {

                 if(!sources.isEmpty())
                med->setCurrentSource(sources.at(index));
                 this->on_actionPlay_triggered();
             }
    }
}

void MainWindow::switchviewports(bool vflag)
{

   if(!vflag)
   {
       dwidget->hide();

       vwidget->show();
       //qDebug() << "no video";
   }
   else
   {
        vwidget->hide();
        dwidget->show();
      // qDebug() << " video";
   }
}

void MainWindow::on_actionBack_triggered()
{
   // if(sources.size()>0)
    //{
    int index=-1;
    if(sources.size()>0)
    {
     index=sources.indexOf(med->currentSource());
//        QString size=QString::number(index);
//        QMessageBox *sizedisp=new QMessageBox(this);
//        sizedisp->setText(size);
//        sizedisp->show();
        if(index!=0)
        {
            med->setCurrentSource(sources.at(index-1));
            this->on_actionPlay_triggered();
        }
        else
        {
            med->setCurrentSource(sources.at(index));
            this->on_actionPlay_triggered();
         }



}
}

void MainWindow::on_actionFoward_triggered()
{
    int index=sources.indexOf(med->currentSource())+1;

       if(sources.size()>index)
       {
            med->setCurrentSource(sources.at(index));
            this->on_actionPlay_triggered();
       }
}

void MainWindow::widgetpause(QKeyEvent *event)
{


    switch(event->key())
    {
        case Qt::Key_Space: this->on_actionPause_triggered();
        break;
    case Qt::Key_MediaPrevious:this->on_actionBack_triggered();
        break;
    case Qt::Key_MediaNext:this->on_actionFoward_triggered();
        break;
    case Qt::Key_MediaStop: this->on_actionStop_triggered();
        break;
    case Qt::Key_F: if(dwidget->isFullScreen())
            dwidget->setFullScreen(false);
        else
            dwidget->setFullScreen(true);
        break;
    case Qt::Key_Right:this->on_actionSkip_Foward_triggered();
        break;
    case Qt::Key_Left: this->on_actionSkip_Backward_triggered();
        break;
    case Qt::Key_Control+Qt::Key_Up: this->on_actionVolume_Up_triggered();
        break;
    case Qt::Key_Control+Qt::Key_Down: this->on_actionVolume_Down_triggered();
        break;
    case Qt::Key_1: this->on_actionAuto_triggered();
        break;
    case Qt::Key_2: this->on_actionSquare_triggered();
        break;
    case Qt::Key_3: this->on_actionWideScreen_triggered();
        break;
//    case Qt::Key_V: this->on_actionOpen_Visualizer_triggered();
//        break;

    default: this->on_actionPlay_triggered();
    }


}

void MainWindow::on_actionVolume_Up_triggered()
{
    volume=sndout->volumeDecibel();
    if(volume<=50)
    {
        volume=volume+0.5;
        ui->label->setText(QString::number(volume));
        ui->volumeSlider->audioOutput()->setVolumeDecibel(volume);
    }
}

void MainWindow::on_actionVolume_Down_triggered()
{
    volume=sndout->volumeDecibel();
    if(volume>=-50)
    {
        volume=volume-0.5;
        ui->label->setText(QString::number(volume));
        ui->volumeSlider->audioOutput()->setVolumeDecibel(volume);
    }

}

void MainWindow::on_actionSkip_Foward_triggered()
{
    currenttime=med->currentTime();
    if(currenttime < med->totalTime()-10000)
    ui->seekSlider->mediaObject()->seek(currenttime+10000);
}

void MainWindow::on_actionSkip_Backward_triggered()
{
    currenttime=med->currentTime();
    if(currenttime > 10000)
        ui->seekSlider->mediaObject()->seek(currenttime-10000);

}

void MainWindow::timechanged(qint64 time)
{
   qint64 hour,min,sec,dispsec,dmin;
    hour=min=dmin=0;
    time=med->currentTime();
    sec=time/1000;
    dispsec=sec;
    if(sec>59)
    {
        min=sec/60;
        dispsec=sec%60;
        dmin=min;

    }
    if(min>59)
    {
        hour=min/60;
        dmin=min%60;
    }
    ui->hourlabel1->setText(QString::number(hour));
    ui->minlabel1->setText(QString::number(dmin));
    ui->slabel1->setText(QString::number(dispsec));



}

void MainWindow::totalTimeChanged(qint64 newtottime)
{
    qint64 hour,min,sec,dispsec,dmin;
     hour=min=sec=dispsec=dmin=0;
     newtottime=med->totalTime();
     sec=newtottime/1000;
     dispsec=sec;
     if(sec>59)
     {
         min=sec/60;
         dispsec=sec%60;
         dmin=min;
     }
     if(min>59)
     {
         hour=min/60;
         dmin=min%60;
     }
     ui->hourlabel2->setText(QString::number(hour));
     ui->minlabel2->setText(QString::number(dmin));
     ui->slabel2->setText(QString::number(dispsec));


}

void MainWindow::on_actionClear_Playlist_triggered()
{
    sources.clear();
    int i, rcnt;
    rcnt=ui->tableWidget->rowCount();
    ui->tableWidget->clearContents();
    for(i=0;i<=rcnt;i++)
    {
        ui->tableWidget->removeRow(i);
    }

}

void MainWindow::on_actionAbout_WebPhonon_triggered()
{
    AboutDialog *adiag=new AboutDialog(this);
    adiag->show();
}

void MainWindow::on_actionAuto_triggered()
{
    dwidget->setAspectRatio(Phonon::VideoWidget::AspectRatioAuto);
}

void MainWindow::on_actionSquare_triggered()
{
    dwidget->setAspectRatio(Phonon::VideoWidget::AspectRatio4_3);
}

void MainWindow::on_actionWideScreen_triggered()
{
    dwidget->setAspectRatio(Phonon::VideoWidget::AspectRatio16_9);
}

void MainWindow::on_actionEqualizer_triggered()
{
    if(effectWidget->isVisible())
    effectWidget->hide();
    else
        effectWidget->show();
}

void MainWindow::on_actionOpen_Visualizer_triggered()
{
    if(dwidget->isVisible())
    {
    dwidget->hide();
    vwidget->show();
    }
    else
    {
        vwidget->hide();
        dwidget->show();
    }
}

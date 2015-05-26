#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QCoreApplication>
#include <QPixmap>
#include <QSplashScreen>
#include <QTextStream>
#include <QDesktopServices>
//#include <kcmdlineargs.h>
//#include <kurl.h>
//#include <kaboutdata.h>
#include <KDE/KCmdLineArgs>
#include <KDE/KUrl>
#include <KDE/KAboutData>
#include <KDE/KUniqueApplication>


int main(int argc, char *argv[])
{
    KAboutData aboutData( "WebPhonon", "WebPhonon",
          ki18n("WebPhonon"), "1.6",
          ki18n("Media Player"),
          KAboutData::License_GPL,
          ki18n("Copyright (c) 2013 Aaron Zakhrov") );

    KCmdLineArgs::init( argc, argv, &aboutData );
    KCmdLineOptions options; //new
      options.add("+[file]", ki18n("Document to open")); //new
      KCmdLineArgs::addCmdLineOptions(options); //new
    KUniqueApplication::addCmdLineOptions();

   QApplication a(argc, argv);
    QCoreApplication::setApplicationName("WebPhonon");
    //AppWrapper app;
    QPixmap img;
    //QString imgurl=QCoreApplication::applicationDirPath();
    //img.load(":/splash/WebPhonon-Master-text2.png");
    //img.load("/WebPhonon/splash/WebPhonon-Master-text2.png");
    img.load("/usr/share/WebPhonon/splash/WebPhonon-Master-text2.png");
    //qDebug()<<imgurl;
    //img.load(imgurl);
    QSplashScreen spl;
    spl.setPixmap(img);
    spl.show();
    MainWindow w;

   // QStringList cmd=a.arguments();
//    QTextStream cout(stdout);
//    cout<<argv[0]<<endl;
//    cout<<argv[1]<<endl;

//    if(!cmd.isEmpty())
//    {
//        w.cmdopen(cmd.last());
//    }
    KCmdLineArgs *args = KCmdLineArgs::parsedArgs(); //new
     if(args->count()) //new
     {
         w.cmdopen(args->url(0).url()); //new
     }
    w.showMaximized();

   // a.exec();
    return a.exec();

}

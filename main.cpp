#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QCoreApplication>
#include <QPixmap>
#include <QSplashScreen>
#include <QTextStream>
#include <QDesktopServices>
#include <QSettings>
//#include <kcmdlineargs.h>
//#include <kurl.h>
//#include <kaboutdata.h>
#ifdef Q_OS_LINUX
#include <KDE/KCmdLineArgs>
#include <KDE/KUrl>
#include <KDE/KAboutData>
#include <KDE/KUniqueApplication>
#endif

int main(int argc, char *argv[])
{
#ifdef Q_OS_LINUX
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
#endif
   QApplication a(argc, argv);
    a.setApplicationName("WebPhonon");
    a.setApplicationVersion("1.6");
    a.setOrganizationName("Zakhrov");
    a.setOrganizationDomain("Zakhrov");
    //AppWrapper app;
    QPixmap img;
    //QString imgurl=QCoreApplication::applicationDirPath();

    //img.load("/WebPhonon/splash/WebPhonon-Master-text2.png");
#ifdef Q_OS_LINUX
    img.load("/usr/share/WebPhonon/splash/WebPhonon-Master-text2.png");
#else
    img.load(":/splash/WebPhonon-Master-text2.png");
#endif
    QSettings defaultSettings;
    if(!defaultSettings.contains("server"))
    {
    defaultSettings.setValue("server","localhost");
    defaultSettings.setValue("username","root");
    defaultSettings.setValue("password","root");
    defaultSettings.setValue("database","webphonon");
    defaultSettings.setValue("dbtype","QMYSQL");
    defaultSettings.sync();
    }
    //qDebug()<<imgurl;
    //img.load(imgurl);
    QSplashScreen spl;
    spl.setPixmap(img);
    spl.show();
    MainWindow w;
#ifdef Q_OS_LINUX
    KCmdLineArgs *args = KCmdLineArgs::parsedArgs(); //new
     if(args->count()) //new
     {
         w.cmdopen(args->url(0).url()); //new
     }
#else

      if(argc>1)
      {
          w.cmdopen(argv[1]);
      }
#endif
    w.showMaximized();

   // a.exec();
    return a.exec();

}

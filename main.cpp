#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QCoreApplication>
#include <QPixmap>
#include <QSplashScreen>
#include <QTextStream>
//#include <kcmdlineargs.h>
//#include <kurl.h>
//#include <kaboutdata.h>
#include <KDE/KCmdLineArgs>
#include <KDE/KUrl>
#include <KDE/KAboutData>


int main(int argc, char *argv[])
{
    KAboutData aboutData( "WebPhonon", "WebPhonon",
          ki18n("WebPhonon"), "1.4",
          ki18n("Media Player"),
          KAboutData::License_GPL,
          ki18n("Copyright (c) 2013 Zakhrov") );

    KCmdLineArgs::init( argc, argv, &aboutData );
    KCmdLineOptions options; //new
      options.add("+[file]", ki18n("Document to open")); //new
      KCmdLineArgs::addCmdLineOptions(options); //new


    QApplication a(argc, argv);
    QCoreApplication::setApplicationName("WebPhonon");
    MainWindow w;
    QPixmap img;
    img.load(":/splash/WebPhonon-Master-text2.png");
    QSplashScreen spl;
    spl.setPixmap(img);
    spl.show();

    QStringList cmd=a.arguments();
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
    
    return a.exec();
}

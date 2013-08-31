#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QCoreApplication>
#include <QPixmap>
#include <QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setApplicationName("WebPhonon");
    MainWindow w;
    QPixmap img;
    img.load(":/splash/WebPhonon-Master-text2.png");
    QSplashScreen spl;
    spl.setPixmap(img);
    spl.show();
    w.showMaximized();


    
    return a.exec();
}

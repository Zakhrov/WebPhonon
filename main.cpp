#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QCoreApplication>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCoreApplication::setApplicationName("NetPlayer");
    MainWindow w;

    w.show();

    
    return a.exec();
}

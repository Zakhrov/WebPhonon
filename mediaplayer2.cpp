#include "mediaplayer2.h"
#include "dropwidget.h"
#include "mainwindow.h"
#include "mpris2.h"
#include "codeine.h"
#include <QtDBus/QDBusAbstractAdaptor>
#include <QApplication>

MediaPlayer2::MediaPlayer2(QObject * parent) : QDBusAbstractAdaptor(parent)
{
    connect(MainWindow::med,SIGNAL(hasVideoChanged(bool)),this,SLOT(emitFullscreenChange(bool)));
}

bool MediaPlayer2::CanQuit() const
{
    return true;
}

bool MediaPlayer2::Fullscreen() const
{
    return MainWindow::dwidget->isFullScreen();
}

void MediaPlayer2::setFullscreen(bool fullscreen) const
{
    MainWindow::dwidget->setFullScreen(fullscreen);
}

bool MediaPlayer2::CanSetFullscreen() const
{
    return MainWindow::med->hasVideo();
}



void MediaPlayer2::quit()
{

}

void MediaPlayer2::emitFullscreenChange(bool fullscreen) const
{
    QVariantMap properties;
    properties["Fullscreen"] = fullscreen;
    properties["CanSetFullscreen"] = CanSetFullscreen();
    Mpris2::signalPropertiesChange(this,properties);
}



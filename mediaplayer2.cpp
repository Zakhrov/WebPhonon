#include "mediaplayer2.h"
#include "dropwidget.h"
#include "mainwindow.h"
#include "mpris2.h"
#include "codeine.h"
#include <QtDBus/QDBusAbstractAdaptor>
#include <QApplication>

MediaPlayer2::MediaPlayer2(QObject * parent) : QDBusAbstractAdaptor(parent)
{
    //connect(w->med,SIGNAL(hasVideoChanged(bool)),this,SLOT(emitFullscreenChange(bool)));
}

bool MediaPlayer2::CanQuit() const
{
    return true;
}

bool MediaPlayer2::Fullscreen() const
{
    return w->dwidget->isFullScreen();
}

void MediaPlayer2::setFullscreen(bool fullscreen) const
{
    w->dwidget->setFullScreen(fullscreen);
}

bool MediaPlayer2::CanSetFullscreen() const
{
    return w->med->hasVideo();
}



void MediaPlayer2::quit()
{
    w->close();
}

void MediaPlayer2::emitFullscreenChange(bool fullscreen) const
{
    QVariantMap properties;
    properties["Fullscreen"] = fullscreen;
    properties["CanSetFullscreen"] = CanSetFullscreen();
    Mpris2::signalPropertiesChange(this,properties);
}



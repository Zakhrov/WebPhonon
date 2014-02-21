#include "mediaplayer2player.h"
#include "mainwindow.h"
#include "mpris2.h"
#include "dropwidget.h"
#include "codeine.h"
#include <QtDBus/QDBusAbstractAdaptor>
#include <QCryptographicHash>

static QByteArray makeTrackId(const QString& source)

{

    return QByteArray("/org/kde/") + APP_NAME + "/tid_" + QCryptographicHash::hash(source.toLocal8Bit(), QCryptographicHash::Sha1).toHex();

}

MediaPlayer2Player::MediaPlayer2Player(QObject *parent): QDBusAbstractAdaptor(parent)
{
    connect(MainWindow::med,SIGNAL(currentSourceChanged(Phonon::MediaSource)),this,SLOT(currentSourceChanged()));
}

bool MediaPlayer2Player::CanGoNext() const
{

        return false;
}

bool MediaPlayer2Player::CanGoPrevious() const
{
    return false;
}

bool MediaPlayer2Player::CanPlay() const
{
    return true;
}

bool MediaPlayer2Player::CanPause() const
{
    return MainWindow::med->state()!= Phonon::ErrorState;
}

QVariantMap MediaPlayer2Player::Metadata() const
{
    QVariantMap metadata;
    switch(MainWindow::med->currentSource().type())
    {
        case Phonon::MediaSource::Invalid:
    case Phonon::MediaSource::Empty:
                  break;
    default:
        metadata["mpris:length"]=MainWindow::med->totalTime();

    }
    return metadata;
}

void MediaPlayer2Player::Next() const
{
    //MainWindow::on_actionFoward_triggered();
}

void MediaPlayer2Player::Previous() const
{
    //MainWindow::on_actionBack_triggered();
}

void MediaPlayer2Player::Pause() const
{
    MainWindow::med->pause();
}

void MediaPlayer2Player::Stop() const
{
    MainWindow::med->stop();
}

void MediaPlayer2Player::Play() const
{
    MainWindow::med->play();
}

void MediaPlayer2Player::currentSourceChanged() const
{
        QVariantMap properties;
         properties["Metadata"] = Metadata();
             Mpris2::signalPropertiesChange(this, properties);
}

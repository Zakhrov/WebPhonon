#ifndef MEDIAPLAYER2PLAYER_H
#define MEDIAPLAYER2PLAYER_H
#include "codeine.h"
#include<QtDBus/QDBusAbstractAdaptor>
#include <Phonon/MediaSource>
#include<QtDBus/QDBusObjectPath>
#include <QVariantMap>

class MediaPlayer2Player: public QDBusAbstractAdaptor
{
    Q_OBJECT
    Q_PROPERTY(bool CanGoNext READ CanGoNext)
    Q_PROPERTY(bool CanGoPrevious READ CanGoPrevious)
    Q_PROPERTY(bool CanPlay READ CanPlay)
    Q_PROPERTY(bool CanPause READ CanPause)

public:
    MediaPlayer2Player(QObject * parent);
    bool CanGoNext() const;
    bool CanGoPrevious() const;
    bool CanPlay() const;
    bool CanPause() const;
    QVariantMap Metadata() const;

public slots:
    void Next() const;

    void Previous() const;

    void Pause() const;

    void Stop() const;

    void Play() const;
private slots:
            void currentSourceChanged() const;


};

#endif // MEDIAPLAYER2PLAYER_H

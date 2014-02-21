#ifndef MEDIAPLAYER2_H
#define MEDIAPLAYER2_H
#include "codeine.h"
#include "mainwindow.h"
#include<QtDBus/QDBusAbstractAdaptor>

class MediaPlayer2 :QDBusAbstractAdaptor
{
    Q_OBJECT
     Q_PROPERTY(bool CanQuit READ CanQuit)
    Q_PROPERTY(bool Fullscreen READ Fullscreen WRITE setFullscreen)
    Q_PROPERTY(bool CanSetFullscreen READ CanSetFullscreen)

public:
    MediaPlayer2(QObject* parent);
            bool CanQuit() const;
            bool Fullscreen() const;
            void setFullscreen(bool fullscreen) const;
            bool CanSetFullscreen() const;

public slots:
    void quit();
private slots:

            void emitFullscreenChange(bool fullscreen) const;
private:
    MainWindow *w;

};

#endif // MEDIAPLAYER2_H

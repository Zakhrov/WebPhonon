#ifndef WINWIDGET_H
#define WINWIDGET_H

#include <QWidget>
#ifdef Q_OS_LINUX
#include <KDE/Phonon/Effect>
#include <KDE/Phonon/MediaObject>
#include <KDE/Phonon/AudioOutput>
#include <KDE/Phonon/EffectParameter>
#include <KDE/Phonon/BackendCapabilities>
#else
#include <Phonon/Effect>
#include <Phonon/MediaObject>
#include <Phonon/AudioOutput>
#include <Phonon/EffectParameter>
#include <Phonon/BackendCapabilities>
#endif
namespace Ui {
class WinWidget;
}

class WinWidget : public QWidget
{
    Q_OBJECT

public:
    explicit WinWidget(QWidget *parent = 0);
    Phonon::Effect *equalizer;
    ~WinWidget();
private slots:
   void valuechange1(int value);
   void valuechange2(int value);
   void valuechange3(int value);
private:
    Ui::WinWidget *ui;
    QList<Phonon::EffectDescription> effectDescriptions;
     Phonon::EffectDescription effectDescription ;
};

#endif // WINWIDGET_H

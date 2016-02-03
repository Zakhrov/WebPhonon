#ifndef WIDGET_H
#define WIDGET_H

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
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    Phonon::Effect *equalizer;
    ~Widget();
private slots:
   void valuechange1(int value);
   void valuechange2(int value);
   void valuechange3(int value);
   void valuechange4(int value);
   void valuechange5(int value);
   void valuechange6(int value);
   void valuechange7(int value);
   void valuechange8(int value);
   void valuechange9(int value);
   void valuechange10(int value);
private:
    Ui::Widget *ui;
    QList<Phonon::EffectDescription> effectDescriptions;
     Phonon::EffectDescription effectDescription ;
};

#endif // WIDGET_H

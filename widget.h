#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <KDE/Phonon/Effect>
#include <KDE/Phonon/MediaObject>
#include <KDE/Phonon/AudioOutput>
#include <KDE/Phonon/Path>
#include <KDE/Phonon/EffectParameter>
#include <KDE/Phonon/BackendCapabilities>
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
private:
    Ui::Widget *ui;


    QList<Phonon::EffectDescription> effectDescriptions;
     Phonon::EffectDescription effectDescription ;
};

#endif // WIDGET_H

#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    effectDescriptions =Phonon::BackendCapabilities::availableAudioEffects();
#ifdef Q_OS_LINUX
    effectDescription = effectDescriptions.at(3);
#else
    effectDescription = effectDescriptions.at(0);
#endif
     equalizer = new Phonon::Effect(effectDescription);
    ui->horizontalSlider->setMinimum(equalizer->parameters().at(0).minimumValue().toInt());
    ui->horizontalSlider->setMaximum(equalizer->parameters().at(0).maximumValue().toInt());
    ui->horizontalSlider_2->setMinimum(equalizer->parameters().at(0).minimumValue().toInt());
    ui->horizontalSlider_2->setMaximum(equalizer->parameters().at(0).maximumValue().toInt());
    ui->horizontalSlider_3->setMinimum(equalizer->parameters().at(0).minimumValue().toInt());
    ui->horizontalSlider_3->setMaximum(equalizer->parameters().at(0).maximumValue().toInt());
    ui->horizontalSlider_4->setMinimum(equalizer->parameters().at(0).minimumValue().toInt());
    ui->horizontalSlider_4->setMaximum(equalizer->parameters().at(0).maximumValue().toInt());
    ui->horizontalSlider_5->setMinimum(equalizer->parameters().at(0).minimumValue().toInt());
    ui->horizontalSlider_5->setMaximum(equalizer->parameters().at(0).maximumValue().toInt());
     connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(valuechange1(int)));
     connect(ui->horizontalSlider_2,SIGNAL(valueChanged(int)),this,SLOT(valuechange2(int)));
     connect(ui->horizontalSlider_3,SIGNAL(valueChanged(int)),this,SLOT(valuechange3(int)));
     connect(ui->horizontalSlider_4,SIGNAL(valueChanged(int)),this,SLOT(valuechange4(int)));
     connect(ui->horizontalSlider_5,SIGNAL(valueChanged(int)),this,SLOT(valuechange5(int)));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::valuechange1(int value)
{
    equalizer->setParameterValue(equalizer->parameters().at(0),value);
    equalizer->setParameterValue(equalizer->parameters().at(1),value);

}

void Widget::valuechange2(int value)
{
    equalizer->setParameterValue(equalizer->parameters().at(2),value);
    equalizer->setParameterValue(equalizer->parameters().at(3),value);
}

void Widget::valuechange3(int value)
{
    equalizer->setParameterValue(equalizer->parameters().at(4),value);
    equalizer->setParameterValue(equalizer->parameters().at(5),value);
}

void Widget::valuechange4(int value)
{
    equalizer->setParameterValue(equalizer->parameters().at(6),value);
    equalizer->setParameterValue(equalizer->parameters().at(7),value);
}

void Widget::valuechange5(int value)
{
    equalizer->setParameterValue(equalizer->parameters().at(8),value);
    equalizer->setParameterValue(equalizer->parameters().at(9),value);
}


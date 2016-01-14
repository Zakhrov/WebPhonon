#include "winwidget.h"
#include "ui_winwidget.h"

WinWidget::WinWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WinWidget)
{
    ui->setupUi(this);

}

WinWidget::~WinWidget()
{
    delete ui;
    effectDescriptions =Phonon::BackendCapabilities::availableAudioEffects();
#ifdef Q_OS_LINUX
    effectDescription = effectDescriptions.at(3);
#else
    effectDescription = effectDescriptions.at(0);
#endif
     equalizer = new Phonon::Effect(effectDescription);

     ui->label->setText(equalizer->parameters().at(0).name());
     ui->label_2->setText(equalizer->parameters().at(1).name());
     ui->label_3->setText(equalizer->parameters().at(2).name());
     ui->verticalSlider->setMinimum(equalizer->parameters().at(0).minimumValue().toInt());
     ui->verticalSlider->setMaximum(equalizer->parameters().at(0).maximumValue().toInt());
     ui->verticalSlider_2->setMinimum(equalizer->parameters().at(1).minimumValue().toInt());
     ui->verticalSlider_2->setMaximum(equalizer->parameters().at(1).maximumValue().toInt());
     ui->verticalSlider_3->setMinimum(equalizer->parameters().at(2).minimumValue().toInt());
     ui->verticalSlider_3->setMaximum(equalizer->parameters().at(2).maximumValue().toInt());
     connect(ui->verticalSlider,SIGNAL(valueChanged(int)),this,SLOT(valuechange1(int)));
     connect(ui->verticalSlider_2,SIGNAL(valueChanged(int)),this,SLOT(valuechange2(int)));
     connect(ui->verticalSlider_3,SIGNAL(valueChanged(int)),this,SLOT(valuechange3(int)));
}

void WinWidget::valuechange1(int value)
{
    equalizer->setParameterValue(equalizer->parameters().at(0),value);

}

void WinWidget::valuechange2(int value)
{
    equalizer->setParameterValue(equalizer->parameters().at(1),value);

}

void WinWidget::valuechange3(int value)
{
    equalizer->setParameterValue(equalizer->parameters().at(2),value);

}

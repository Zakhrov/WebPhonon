#include "widget.h"
#include "ui_widget.h"
#include <KDE/Phonon/EffectWidget>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{


    effectDescriptions =Phonon::BackendCapabilities::availableAudioEffects();
    if(effectDescriptions.size()>0)
    {
    ui->setupUi(this);
#ifdef Q_OS_LINUX
    //effectDescription = effectDescriptions.at(3);
    Phonon::EffectDescription eqdesc=effectDescriptions.at(0);
    foreach (effectDescription, effectDescriptions) {
        //qDebug()<< effectDescription.name();
        if(effectDescription.name().contains("equal"))
        {
            eqdesc=effectDescription;
        }

    }
#else
    effectDescription = effectDescriptions.at(0);
#endif
    equalizer = new Phonon::Effect(eqdesc);
    if(equalizer->parameters().size()==10)
    {
    ui->label->setText(equalizer->parameters().at(0).name());
    ui->label_2->setText(equalizer->parameters().at(1).name());
    ui->label_3->setText(equalizer->parameters().at(2).name());
    ui->label_4->setText(equalizer->parameters().at(3).name());
    ui->label_5->setText(equalizer->parameters().at(4).name());
    ui->label_6->setText(equalizer->parameters().at(5).name());
    ui->label_7->setText(equalizer->parameters().at(6).name());
    ui->label_8->setText(equalizer->parameters().at(7).name());
    ui->label_9->setText(equalizer->parameters().at(8).name());
    ui->label_10->setText(equalizer->parameters().at(9).name());
    ui->horizontalSlider->setMinimum(equalizer->parameters().at(0).minimumValue().toInt());
    ui->horizontalSlider->setMaximum(equalizer->parameters().at(0).maximumValue().toInt());
    ui->horizontalSlider_2->setMinimum(equalizer->parameters().at(1).minimumValue().toInt());
    ui->horizontalSlider_2->setMaximum(equalizer->parameters().at(1).maximumValue().toInt());
    ui->horizontalSlider_3->setMinimum(equalizer->parameters().at(2).minimumValue().toInt());
    ui->horizontalSlider_3->setMaximum(equalizer->parameters().at(2).maximumValue().toInt());
    ui->horizontalSlider_4->setMinimum(equalizer->parameters().at(3).minimumValue().toInt());
    ui->horizontalSlider_4->setMaximum(equalizer->parameters().at(3).maximumValue().toInt());
    ui->horizontalSlider_5->setMinimum(equalizer->parameters().at(4).minimumValue().toInt());
    ui->horizontalSlider_5->setMaximum(equalizer->parameters().at(4).maximumValue().toInt());
    ui->horizontalSlider_6->setMinimum(equalizer->parameters().at(5).minimumValue().toInt());
    ui->horizontalSlider_6->setMaximum(equalizer->parameters().at(5).maximumValue().toInt());
    ui->horizontalSlider_7->setMinimum(equalizer->parameters().at(6).minimumValue().toInt());
    ui->horizontalSlider_7->setMaximum(equalizer->parameters().at(6).maximumValue().toInt());
    ui->horizontalSlider_8->setMinimum(equalizer->parameters().at(7).minimumValue().toInt());
    ui->horizontalSlider_8->setMaximum(equalizer->parameters().at(7).maximumValue().toInt());
    ui->horizontalSlider_9->setMinimum(equalizer->parameters().at(8).minimumValue().toInt());
    ui->horizontalSlider_9->setMaximum(equalizer->parameters().at(8).maximumValue().toInt());
    ui->horizontalSlider_10->setMinimum(equalizer->parameters().at(9).minimumValue().toInt());
    ui->horizontalSlider_10->setMaximum(equalizer->parameters().at(9).maximumValue().toInt());
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(valuechange1(int)));
    connect(ui->horizontalSlider_2,SIGNAL(valueChanged(int)),this,SLOT(valuechange2(int)));
    connect(ui->horizontalSlider_3,SIGNAL(valueChanged(int)),this,SLOT(valuechange3(int)));
     connect(ui->horizontalSlider_4,SIGNAL(valueChanged(int)),this,SLOT(valuechange4(int)));
     connect(ui->horizontalSlider_5,SIGNAL(valueChanged(int)),this,SLOT(valuechange5(int)));
     connect(ui->horizontalSlider_6,SIGNAL(valueChanged(int)),this,SLOT(valuechange6(int)));
     connect(ui->horizontalSlider_7,SIGNAL(valueChanged(int)),this,SLOT(valuechange7(int)));
     connect(ui->horizontalSlider_8,SIGNAL(valueChanged(int)),this,SLOT(valuechange8(int)));
     connect(ui->horizontalSlider_9,SIGNAL(valueChanged(int)),this,SLOT(valuechange9(int)));
     connect(ui->horizontalSlider_10,SIGNAL(valueChanged(int)),this,SLOT(valuechange10(int)));
    }
    else
    {
        ui->widget->hide();
        Phonon::EffectWidget *ewidget=new Phonon::EffectWidget(equalizer,this);
        ui->gridLayout_2->addWidget(ewidget);



    }
}
else
    {
        QLabel *messagelabel=new QLabel(this);
        messagelabel->setText("No effects found :(");
        messagelabel->show();
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::valuechange1(int value)
{
    equalizer->setParameterValue(equalizer->parameters().at(0),value);


}

void Widget::valuechange2(int value)
{
    equalizer->setParameterValue(equalizer->parameters().at(1),value);


}

void Widget::valuechange3(int value)
{
    equalizer->setParameterValue(equalizer->parameters().at(2),value);


}
#ifdef Q_OS_LINUX
void Widget::valuechange4(int value)
{
    equalizer->setParameterValue(equalizer->parameters().at(3),value);


}

void Widget::valuechange5(int value)
{
    equalizer->setParameterValue(equalizer->parameters().at(4),value);


}

void Widget::valuechange6(int value)
{
    equalizer->setParameterValue(equalizer->parameters().at(5),value);
}

void Widget::valuechange7(int value)
{
    equalizer->setParameterValue(equalizer->parameters().at(6),value);
}

void Widget::valuechange8(int value)
{
    equalizer->setParameterValue(equalizer->parameters().at(7),value);
}

void Widget::valuechange9(int value)
{
    equalizer->setParameterValue(equalizer->parameters().at(8),value);
}

void Widget::valuechange10(int value)
{
    equalizer->setParameterValue(equalizer->parameters().at(9),value);
}

#endif

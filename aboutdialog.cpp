#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    QPixmap img,simg;
    img.load(":/Icons/WebPhononIcon.png");
    simg=img.scaled(128,128);
    ui->label->setPixmap(simg);

    ui->label_3->setText("1.6");
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

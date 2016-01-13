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
    ui->label_3->setText(QApplication::applicationVersion());

}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_pushButton_clicked()
{
    QApplication::aboutQt();
}

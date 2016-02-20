#include "aboutdialog.h"
#include "ui_aboutdialog.h"
#include <QMessageBox>
AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    QPixmap img,simg;
#ifdef Q_OS_LINUX
    img.load(":/Icons/WebPhononIcon.png");
#else
    img.load(":/Icons/WebPhonon_win.ico");
#endif
    simg=img.scaled(256,256);
    ui->label->setPixmap(simg);
    ui->label_3->setText(QApplication::applicationVersion());
    //ui->label_4->setText(QApplication::organizationName());
    //ui->label_5->setText(QApplication::organizationDomain());
    cdialog=new CreditsDialog(this);
    cdialog->setWindowTitle("Credits");

}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_pushButton_clicked()
{
    QApplication::aboutQt();
}

void AboutDialog::on_pushButton_2_clicked()
{
//    QMessageBox Authors;
//    Authors.setText("Lead Developer: Aaron Dominick \n Developers: Neha A, Aishwarya P");
//    Authors.exec();
    cdialog->show();

}

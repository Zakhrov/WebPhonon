#include "creditsdialog.h"
#include "ui_creditsdialog.h"
#include <QPixmap>

CreditsDialog::CreditsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreditsDialog)
{
    ui->setupUi(this);
    QPixmap LeadImg = QPixmap(":/profiles/AMD_Logo11.jpg");
    ui->label_2->setPixmap(LeadImg.scaled(64,64));
    ui->label_3->setText("Aaron Dominick [https://github.com/Zakhrov]");
    ui->label_6->setText("K. Aishwarya Pawar [https://github.com/aish942]");
    ui->label_8->setText("Neha Agarwal [https://github.com/neha947]");

}

CreditsDialog::~CreditsDialog()
{
    delete ui;
}

void CreditsDialog::on_pushButton_clicked()
{
    this->close();
}

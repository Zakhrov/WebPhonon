#include "creditsdialog.h"
#include "ui_creditsdialog.h"
#include <QPixmap>

CreditsDialog::CreditsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreditsDialog)
{
    ui->setupUi(this);
    LeadImg = QPixmap(":/profiles/AMD_Logo11.jpg");
    ui->label_2->setPixmap(LeadImg.scaled(128,128));
    ui->label_3->setText("Aaron Dominick [https://github.com/Zakhrov]");


}

CreditsDialog::~CreditsDialog()
{
    delete ui;
}

void CreditsDialog::on_pushButton_clicked()
{
    this->close();
}

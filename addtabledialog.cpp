#include "addtabledialog.h"
#include "ui_addtabledialog.h"
#include <QMessageBox>
AddTableDialog::AddTableDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTableDialog)
{
    ui->setupUi(this);
    ui->webView->setUrl(QUrl("http://localhost/phpmyadmin"));

}

AddTableDialog::~AddTableDialog()
{
    delete ui;
}

void AddTableDialog::on_pushButton_clicked()
{

    this->close();

}

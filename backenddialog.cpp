#include "backenddialog.h"
#include "ui_backenddialog.h"
#include <Phonon/BackendCapabilities>

BackendDialog::BackendDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BackendDialog)
{
    ui->setupUi(this);
    ui->listWidget->addItems(Phonon::BackendCapabilities::availableMimeTypes());
}

BackendDialog::~BackendDialog()
{
    delete ui;
}

#include "backenddialog.h"
#include "ui_backenddialog.h"
//#if QT_VERSION > 0x48100
#include <KDE/Phonon/BackendCapabilities>
//#else
//#include <Phonon/BackendCapabilities>
//#endif
#include <phonon/phononnamespace.h>
BackendDialog::BackendDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BackendDialog)
{
    ui->setupUi(this);
    ui->listWidget->addItem(Phonon::phononVersion());
    ui->listWidget->addItems(Phonon::BackendCapabilities::availableMimeTypes());
}

BackendDialog::~BackendDialog()
{
    delete ui;
}

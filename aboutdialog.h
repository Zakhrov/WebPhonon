#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H
#include "creditsdialog.h"
#include <QDialog>

namespace Ui {
class AboutDialog;
}

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = 0);
    ~AboutDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AboutDialog *ui;
    CreditsDialog *cdialog;
};

#endif // ABOUTDIALOG_H

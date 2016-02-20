#ifndef CREDITSDIALOG_H
#define CREDITSDIALOG_H

#include <QDialog>
#include <QPixmap>
namespace Ui {
class CreditsDialog;
}

class CreditsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreditsDialog(QWidget *parent = 0);
    ~CreditsDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::CreditsDialog *ui;
    QPixmap LeadImg,ADevImg1,ADevImg2;
};

#endif // CREDITSDIALOG_H

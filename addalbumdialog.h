#ifndef ADDALBUMDIALOG_H
#define ADDALBUMDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QMessageBox>
#include <QSqlError>
namespace Ui {
class AddAlbumDialog;
}

class AddAlbumDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddAlbumDialog(QWidget *parent = 0);
    ~AddAlbumDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddAlbumDialog *ui;
    QString album,record_label;
    QSqlDatabase db;
    QSqlTableModel *model;
};

#endif // ADDALBUMDIALOG_H

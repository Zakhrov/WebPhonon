#ifndef ADDALBUMCASTDIALOG_H
#define ADDALBUMCASTDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQueryModel>
#include <QSqlError>
namespace Ui {
class AddAlbumCastDialog;
}

class AddAlbumCastDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddAlbumCastDialog(QWidget *parent = 0);
    ~AddAlbumCastDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddAlbumCastDialog *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    QSqlQueryModel *model1;
    QSqlQueryModel *model2;
    QString role;

    int album_id,artist_id;
};

#endif // ADDALBUMCASTDIALOG_H

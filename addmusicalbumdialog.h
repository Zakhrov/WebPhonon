#ifndef ADDMUSICALBUMDIALOG_H
#define ADDMUSICALBUMDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QMessageBox>
namespace Ui {
class AddMusicAlbumDialog;
}

class AddMusicAlbumDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddMusicAlbumDialog(QWidget *parent = 0);
    ~AddMusicAlbumDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddMusicAlbumDialog *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    QSqlQueryModel *model1;
    QSqlQueryModel *model2;
    QString charecter,role;

    int album_id,music_id;
};

#endif // ADDMUSICALBUMDIALOG_H

#ifndef ADDARTISTDIALOG_H
#define ADDARTISTDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
namespace Ui {
class AddArtistDialog;
}

class AddArtistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddArtistDialog(QWidget *parent = 0);
    ~AddArtistDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddArtistDialog *ui;
    QString artist;
    QSqlDatabase db;
    QSqlQuery *query;
};

#endif // ADDARTISTDIALOG_H

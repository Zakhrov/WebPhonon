#ifndef ADDTVDIALOG_H
#define ADDTVDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlError>
#include <QDesktopServices>
namespace Ui {
class AddTVDialog;
}

class AddTVDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddTVDialog(QWidget *parent = 0);
    ~AddTVDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::AddTVDialog *ui;
    QString url,title,language,season,genre,episode,episode_title;
    QSqlDatabase db;
    QSqlTableModel *model;

};

#endif // ADDTVDIALOG_H

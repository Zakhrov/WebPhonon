#ifndef ADDMUSICDIALOG_H
#define ADDMUSICDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlError>
#include <QDesktopServices>
namespace Ui {
class AddMusicDialog;
}

class AddMusicDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddMusicDialog(QWidget *parent = 0);
    ~AddMusicDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::AddMusicDialog *ui;
    QString url,title,language,genre;
    QSqlDatabase db;
    QSqlTableModel *model;
};

#endif // ADDMUSICDIALOG_H

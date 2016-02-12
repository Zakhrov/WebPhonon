#ifndef ADDMOVIECASTDIALOG_H
#define ADDMOVIECASTDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlError>
namespace Ui {
class AddMovieCastDialog;
}

class AddMovieCastDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddMovieCastDialog(QWidget *parent = 0);
    ~AddMovieCastDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddMovieCastDialog *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    QSqlQueryModel *model1;
    QSqlQueryModel *model2;
    QString charecter,role;

    int actor_id,movie_id;
};

#endif // ADDMOVIECASTDIALOG_H

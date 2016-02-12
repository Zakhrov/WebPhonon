#ifndef ADDMVCASTDIALOG_H
#define ADDMVCASTDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QMessageBox>
namespace Ui {
class AddMVCastDialog;
}

class AddMVCastDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddMVCastDialog(QWidget *parent = 0);
    ~AddMVCastDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddMVCastDialog *ui;
    QSqlDatabase db;
    QSqlTableModel *model;
    QSqlQueryModel *model1;
    QSqlQueryModel *model2;
    QString charecter,role;

    int actor_id,mv_id;
};

#endif // ADDMVCASTDIALOG_H

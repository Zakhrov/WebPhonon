#ifndef ADDTVCASTDIALOG_H
#define ADDTVCASTDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QSqlError>
namespace Ui {
class AddTVCastDialog;
}

class AddTVCastDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddTVCastDialog(QWidget *parent = 0);
    ~AddTVCastDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddTVCastDialog *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlQueryModel *model1;
    QSqlQueryModel *model2;
    QString charecter,role;

    int actor_id,tv_id;
};

#endif // ADDTVCASTDIALOG_H

#ifndef ADDACTORDIALOG_H
#define ADDACTORDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlError>
namespace Ui {
class AddActorDialog;
}

class AddActorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddActorDialog(QWidget *parent = 0);
    ~AddActorDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddActorDialog *ui;
    QString actor;
    QSqlDatabase db;
    QSqlTableModel *model;
};

#endif // ADDACTORDIALOG_H

#ifndef TABLELISTDIALOG_H
#define TABLELISTDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
namespace Ui {
class TableListDialog;
}

class TableListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TableListDialog(QWidget *parent = 0);
    QString tabname;
    ~TableListDialog();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::TableListDialog *ui;
    QSqlDatabase db;
};

#endif // TABLELISTDIALOG_H

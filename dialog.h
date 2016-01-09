#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit Dialog(QWidget *parent = 0);
    //QString tabname;
    ~Dialog();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_activated(const QString &arg1);

private:
    Ui::Dialog *ui;
    QString host,dbname,uname,passwd;
    QString dbtype;
    QSettings custdbSettings;
};

#endif // DIALOG_H

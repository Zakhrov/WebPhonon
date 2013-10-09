#ifndef ADDTABLEDIALOG_H
#define ADDTABLEDIALOG_H

#include <QDialog>

namespace Ui {
class AddTableDialog;
}

class AddTableDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit AddTableDialog(QWidget *parent = 0);
    ~AddTableDialog();
    
private slots:
    void on_pushButton_clicked();

private:
    Ui::AddTableDialog *ui;
};

#endif // ADDTABLEDIALOG_H

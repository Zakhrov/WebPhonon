#ifndef BACKENDDIALOG_H
#define BACKENDDIALOG_H

#include <QDialog>

namespace Ui {
class BackendDialog;
}

class BackendDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit BackendDialog(QWidget *parent = 0);
    ~BackendDialog();
    
private:
    Ui::BackendDialog *ui;
};

#endif // BACKENDDIALOG_H

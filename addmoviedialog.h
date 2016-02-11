#ifndef ADDMOVIEDIALOG_H
#define ADDMOVIEDIALOG_H

#include <QDialog>
#include <QSettings>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
namespace Ui {
class AddMovieDialog;
}

class AddMovieDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddMovieDialog(QWidget *parent = 0);
    ~AddMovieDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::AddMovieDialog *ui;
    QSettings settings;
    QSqlDatabase db;
    QString url,title,language,rating,genre,year,studio;


};

#endif // ADDMOVIEDIALOG_H

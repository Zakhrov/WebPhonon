#ifndef DBMAINWINDOW_H
#define DBMAINWINDOW_H



#include <QMainWindow>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkAccessManager>
namespace Ui {
class DBMainWindow;
}

class DBMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit DBMainWindow(QWidget *parent = 0);
    ~DBMainWindow();
    
private slots:
    void on_actionConnect_triggered();

    void on_actionBack_triggered();

    void on_actionFoward_triggered();

    void on_pushButton_clicked();

    void on_actionReload_triggered();
    void download(const QNetworkRequest request);
    void onNetworkReply(QNetworkReply *reply);
    void unsupportedcontent(QNetworkReply* reply);


private:
    Ui::DBMainWindow *ui;
     QString url;
     QNetworkAccessManager *manager;
};

#endif // DBMAINWINDOW_H

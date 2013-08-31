#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <phonon/phonon>
#include <Phonon/MediaObject>
#include <QPlainTextEdit>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();
protected:

    
private slots:

    void on_actionLocal_File_triggered();

    void on_actionHttp_Stream_triggered();

    void on_actionPlay_triggered();

    void on_actionPause_triggered();

    void on_actionStop_triggered();

    void on_actionFull_Screen_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    Phonon::MediaObject *med;
    Phonon::MediaSource *src;



};

#endif // MAINWINDOW_H

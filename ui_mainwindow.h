/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Aug 28 22:35:37 2013
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include <phonon/seekslider.h>
#include <phonon/videowidget.h>
#include <phonon/volumeslider.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLocal_File;
    QAction *actionHttp_Stream;
    QAction *actionPlay;
    QAction *actionPause;
    QAction *actionStop;
    QAction *actionFull_Screen;
    QAction *actionExit;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    Phonon::VideoWidget *VideoWidget;
    Phonon::VolumeSlider *volumeSlider;
    Phonon::SeekSlider *seekSlider;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOpen;
    QMenu *menuPlayer;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(747, 344);
        actionLocal_File = new QAction(MainWindow);
        actionLocal_File->setObjectName(QString::fromUtf8("actionLocal_File"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Icons/document-open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLocal_File->setIcon(icon);
        actionHttp_Stream = new QAction(MainWindow);
        actionHttp_Stream->setObjectName(QString::fromUtf8("actionHttp_Stream"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Icons/applications-internet.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHttp_Stream->setIcon(icon1);
        actionPlay = new QAction(MainWindow);
        actionPlay->setObjectName(QString::fromUtf8("actionPlay"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Icons/media-playback-start.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPlay->setIcon(icon2);
        actionPause = new QAction(MainWindow);
        actionPause->setObjectName(QString::fromUtf8("actionPause"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Icons/media-playback-pause.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPause->setIcon(icon3);
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Icons/media-playback-stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon4);
        actionFull_Screen = new QAction(MainWindow);
        actionFull_Screen->setObjectName(QString::fromUtf8("actionFull_Screen"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Icons/video-television.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFull_Screen->setIcon(icon5);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Icons/application-exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon6);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        VideoWidget = new Phonon::VideoWidget(centralWidget);
        VideoWidget->setObjectName(QString::fromUtf8("VideoWidget"));

        gridLayout->addWidget(VideoWidget, 1, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 1, 0, 1, 1);

        volumeSlider = new Phonon::VolumeSlider(centralWidget);
        volumeSlider->setObjectName(QString::fromUtf8("volumeSlider"));
        volumeSlider->setOrientation(Qt::Vertical);

        gridLayout_2->addWidget(volumeSlider, 1, 1, 1, 1);

        seekSlider = new Phonon::SeekSlider(centralWidget);
        seekSlider->setObjectName(QString::fromUtf8("seekSlider"));

        gridLayout_2->addWidget(seekSlider, 2, 0, 1, 1);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 747, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuOpen = new QMenu(menuFile);
        menuOpen->setObjectName(QString::fromUtf8("menuOpen"));
        menuPlayer = new QMenu(menuBar);
        menuPlayer->setObjectName(QString::fromUtf8("menuPlayer"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuPlayer->menuAction());
        menuFile->addAction(menuOpen->menuAction());
        menuFile->addAction(actionExit);
        menuOpen->addAction(actionLocal_File);
        menuOpen->addAction(actionHttp_Stream);
        menuPlayer->addAction(actionPlay);
        menuPlayer->addAction(actionPause);
        menuPlayer->addAction(actionStop);
        menuPlayer->addAction(actionFull_Screen);
        mainToolBar->addAction(actionLocal_File);
        mainToolBar->addAction(actionHttp_Stream);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionPlay);
        mainToolBar->addAction(actionPause);
        mainToolBar->addAction(actionStop);
        mainToolBar->addAction(actionFull_Screen);
        mainToolBar->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "WebPhonon", 0, QApplication::UnicodeUTF8));
        actionLocal_File->setText(QApplication::translate("MainWindow", "Local File", 0, QApplication::UnicodeUTF8));
        actionHttp_Stream->setText(QApplication::translate("MainWindow", "Http Stream", 0, QApplication::UnicodeUTF8));
        actionPlay->setText(QApplication::translate("MainWindow", "Play", 0, QApplication::UnicodeUTF8));
        actionPlay->setShortcut(QApplication::translate("MainWindow", "Media Play", 0, QApplication::UnicodeUTF8));
        actionPause->setText(QApplication::translate("MainWindow", "Pause", 0, QApplication::UnicodeUTF8));
        actionPause->setShortcut(QApplication::translate("MainWindow", "Space", 0, QApplication::UnicodeUTF8));
        actionStop->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        actionStop->setShortcut(QApplication::translate("MainWindow", "Media Stop", 0, QApplication::UnicodeUTF8));
        actionFull_Screen->setText(QApplication::translate("MainWindow", "Full Screen", 0, QApplication::UnicodeUTF8));
        actionFull_Screen->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+F", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuOpen->setTitle(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        menuPlayer->setTitle(QApplication::translate("MainWindow", "Player", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

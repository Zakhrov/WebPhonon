#-------------------------------------------------
#
# Project created by QtCreator 2013-05-22T21:37:22
#
#-------------------------------------------------

QT       += core gui phonon sql
TARGET = WebPhonon
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui

RESOURCES += \
    Icons.qrc

OTHER_FILES += \
    WebPhonon-Master-text2.png \
    video-television.png \
    media-playback-stop.png \
    media-playback-start.png \
    media-playback-pause.png \
    internet-web-browser.png \
    document-open.png \
    document-open-remote.png \
    applications-internet.png \
    application-exit.png \
    document-export-table.png \
    application-vnd.oasis.opendocument.database.png

target.path = /usr/bin

INSTALLS +=target



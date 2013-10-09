#-------------------------------------------------
#
# Project created by QtCreator 2013-05-22T21:37:22
#
#-------------------------------------------------

QT       += core gui phonon sql webkit


TARGET = WebPhonon
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialog.cpp \
    dialog2.cpp \
    backenddialog.cpp \
    helpdialog.cpp \
    dbmainwindow.cpp \
    addtabledialog.cpp

HEADERS  += mainwindow.h \
    dialog.h \
    dialog2.h \
    backenddialog.h \
    helpdialog.h \
    dbmainwindow.h \
    addtabledialog.h

FORMS    += mainwindow.ui \
    dialog.ui \
    dialog2.ui \
    backenddialog.ui \
    helpdialog.ui \
    dbmainwindow.ui \
    addtabledialog.ui

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
    application-vnd.oasis.opendocument.database.png \
    media-skip-forward.png \
    media-skip-backward.png \
    view-close.png \
    server-database.png \
    debian/copyright \
    debian/control \
    debian/compat \
    debian/changelog \
    debian/rules \
    debian/source/format \
    WebPhononIcon.png \
    WebPhonon.desktop \
    icons/16x16/WebPhononIcon.png \
    icons/32x32/WebPhononIcon.png \
    icons/64x64/WebPhononIcon.png \
    icons/128x128/WebPhononIcon.png \
    icons/256x256/WebPhononIcon.png \
    icons/512x512/WebPhononIcon.png \
    icons/48x48/WebPhononIcon.png \
    WebPhonon_Documentation.html \
    helpimages/menu.png \
    helpimages/image10.png \
    helpimages/image09.png \
    helpimages/image08.png \
    helpimages/image07.png \
    helpimages/image06.png \
    helpimages/image05.png \
    helpimages/image04.png \
    helpimages/image03.png \
    helpimages/image02.png \
    helpimages/image00.png

    target.path = /usr/bin
    desktop.path= /usr/share/applications
    desktop.files += WebPhonon.desktop
    icon16.path= /usr/share/icons/hicolor/16x16/apps
    icon32.path= /usr/share/icons/hicolor/32x32/apps
    icon48.path= /usr/share/icons/hicolor/48x48/apps
    icon64.path= /usr/share/icons/hicolor/64x64/apps
    icon128.path= /usr/share/icons/hicolor/128x128/apps
    icon256.path= /usr/share/icons/hicolor/256x256/apps
    icon512.path= /usr/share/icons/hicolor/512x512/apps

    icon16.files +=    icons/16x16/WebPhononIcon.png
    icon32.files +=    icons/32x32/WebPhononIcon.png
    icon48.files +=    icons/48x48/WebPhononIcon.png
    icon64.files +=    icons/64x64/WebPhononIcon.png
    icon128.files +=    icons/128x128/WebPhononIcon.png
    icon256.files +=    icons/256x256/WebPhononIcon.png
    icon512.files +=    icons/512x512/WebPhononIcon.png



INSTALLS+=target icon16 icon32 icon48 icon64 icon128 icon256 icon512 desktop







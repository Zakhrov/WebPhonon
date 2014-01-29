project (WebPhonon)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)
find_package(KDE4 REQUIRED)
include (KDE4Defaults)
include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR} ${KDE4_INCLUDES})
INCLUDE(${QT_USE_FILE})
ADD_DEFINITIONS(${QT_DEFINITIONS})
ADD_SUBDIRECTORY(icons)
SET(WebPhonon_SOURCES main.cpp mainwindow.cpp dialog.cpp backenddialog.cpp helpdialog.cpp dbmainwindow.cpp dropwidget.cpp )
SET(WebPhonon_HEADERS mainwindow.h dialog.h backenddialog.h helpdialog.h dbmainwindow.h dropwidget.h)
SET(WebPhonon_FORMS mainwindow.ui dialog.ui backenddialog.ui helpdialog.ui dbmainwindow.ui)
SET(WebPhonon_RESOURCES Icons.qrc)
#set(CMAKE_AUTOMOC ON)
#set(WebPhononSources icons/hi16-app-WebPhonon.png icons/hi32-app-WebPhonon.png icons/hi48-app-WebPhonon.png icons/hi64-app-WebPhonon.png icons/hi128-app-WebPhonon.png icons/hi256-app-WebPhonon.png icons/hi512-app-WebPhonon.png)
qt4_automoc(${WebPhonon_SOURCES})
QT4_WRAP_CPP(WebPhonon_HEADERS_MOC ${WebPhonon_HEADERS})
QT4_WRAP_UI(WebPhonon_FORMS_HEADERS ${WebPhonon_FORMS})
QT4_ADD_RESOURCES(WebPhonon_RESOURCES_RCC ${WebPhonon_RESOURCES})

#kde4_add_app_icon(WebPhononSources "icons/hi*-apps-WebPhonon.png")

add_executable(WebPhonon ${WebPhonon_SOURCES} ${WebPhonon_HEADERS_MOC} ${WebPhonon_FORMS_HEADERS} ${WebPhonon_RESOURCES_RCC})
target_link_libraries(WebPhonon ${QT_LIBRARIES} ${QT_QTCORE_LIBRARY} ${QT_QTSQL_LIBRARY} ${QT_QTNETWORK_LIBRARY} ${QT_QTWEBKIT_LIBRARY} ${QT_QTGUI_LIBRARY} ${KDE4_KDEUI_LIBS} ${PHONON_LIBS} ${KDE4_PHONON_LIBS} ${KDE4_KDECORE_LIBS})
install(TARGETS WebPhonon ${INSTALL_TARGETS_DEFAULT_ARGS})

#INSTALL( PROGRAMS WebPhonon.desktop DESTINATION ${XDG_APPS_INSTALL_DIR} )
#INSTALL(FILES ${WebPhononSources} DESTINATION ${DATA_INSTALL_DIR}/WebPhonon)




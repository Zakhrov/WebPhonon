#include "appwrapper.h"
#include "mainwindow.h"
#include <KDE/KCmdLineArgs>

AppWrapper::AppWrapper():KUniqueApplication(true,true),w(0)
{

}

AppWrapper::~AppWrapper()
{
    if(w)
    {
        w=0;
    }
    delete w;
}

int AppWrapper::newInstance()
{
    if(!w)
    {
        w=new MainWindow;
    }
    w->showMaximized();
    return KUniqueApplication::newInstance();
}



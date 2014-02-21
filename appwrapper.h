#ifndef APPWRAPPER_H
#define APPWRAPPER_H
#include <KDE/KUniqueApplication>

class MainWindow;
class AppWrapper : public KUniqueApplication
{
    Q_OBJECT
public:
    AppWrapper();
    ~AppWrapper();
    virtual int newInstance();
private:
    MainWindow *w;
};

#endif // APPWRAPPER_H

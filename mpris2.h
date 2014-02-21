#ifndef MPRIS2_H
#define MPRIS2_H
#include "codeine.h"
#include <QObject>
#include <QVariantMap>

class Mpris2 : public QObject
{
    Q_OBJECT
public:
    explicit Mpris2(QObject *parent = 0);

    static void signalPropertiesChange(const QObject* adaptor, const QVariantMap& properties);

signals:

public slots:

};

#endif // MPRIS2_H

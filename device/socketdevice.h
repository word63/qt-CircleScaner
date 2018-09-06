#ifndef SOCKETDEVICE_H
#define SOCKETDEVICE_H

#include "abstractiodevice.h"

class SocketDevice : public AbstractIODevice
{
public:
    SocketDevice(QString description);

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;

    // AbstractIODevice interface
protected:
    void Initialization() override;
};

#endif // SOCKETDEVICE_H

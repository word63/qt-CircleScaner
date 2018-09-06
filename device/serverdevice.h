#ifndef SERVERDEVICE_H
#define SERVERDEVICE_H

#include "device/abstractiodevice.h"

class ServerDevice : public AbstractIODevice
{
public:
    ServerDevice(QString description);

    // AbstractIODevice interface
protected:
    void Initialization() override;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // SERVERDEVICE_H

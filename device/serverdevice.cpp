#include "serverdevice.h"

ServerDevice::ServerDevice(QString description)
{
    this->description = description;
    Initialization();
}


void ServerDevice::Initialization()
{
    this->setMinimumSize(100,100);
    this->setMaximumHeight(100);

    mainLayout = new QVBoxLayout();

    QLineEdit *lOpenStatus = new  QLineEdit();
    QLineEdit *lReadData = new  QLineEdit();
    QLineEdit *lWriteData = new  QLineEdit();

    createLineWidget(description);
    createLineWidget("Open: ", lOpenStatus);
    createLineWidget("Read: ", lReadData);
    createLineWidget("Write: ", lWriteData);

    this->setLayout(mainLayout);
}


void ServerDevice::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    p.setRenderHint(QPainter::Antialiasing, true);
    p.setPen(QPen(QColor(Qt::red)));
    p.drawRoundedRect(1, 1, width() - 2, height() - 2,3,3, Qt::AbsoluteSize);
}

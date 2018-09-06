#include "comportdevice.h"


ComPortDevice::ComPortDevice(QWidget *parent) : QWidget(parent)
{
    Initialization();
}

void ComPortDevice::Initialization()
{
    this->setMinimumSize(100,100);
    this->setMaximumHeight(100);

    newLay = new QVBoxLayout();

    desc  = new QLabel(description);
    newLay->addWidget(desc);

    QHBoxLayout *hLay = new QHBoxLayout();

    QLabel *lOpen = new QLabel("Open :");
    QLineEdit *lOpenStatus = new  QLineEdit();
    hLay->addWidget(lOpen);
    hLay->addWidget(lOpenStatus);
    newLay->addLayout(hLay);

    hLay = new QHBoxLayout();

    QLabel *lRead = new QLabel("Read :");
    QLineEdit *lReadData = new  QLineEdit();
    hLay->addWidget(lRead);
    hLay->addWidget(lReadData);
    newLay->addLayout(hLay);

    hLay = new QHBoxLayout();

    QLabel *lWrite = new QLabel("Write :");
    QLineEdit *lWriteData = new  QLineEdit();
    hLay->addWidget(lWrite);
    hLay->addWidget(lWriteData);
    newLay->addLayout(hLay);

    this->setLayout(newLay);
}


void ComPortDevice::setDescription(const QString &value)
{
    description = value;
    desc->setText(description);
}

void ComPortDevice::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    p.setRenderHint(QPainter::Antialiasing, true);
    p.setPen(QPen(QColor(Qt::cyan)));
    p.drawRoundedRect(1, 1, width() - 2, height() - 2,3,3, Qt::AbsoluteSize);

}


#include "abstractiodevice.h"

AbstractIODevice::AbstractIODevice(QWidget *parent) : QWidget(parent)
{
    Initialization();
}


void AbstractIODevice::Initialization() // Virtual function
{

}

void AbstractIODevice::createLineWidget(QString labelStr, QLineEdit *lineEdit)
{
    QHBoxLayout *hlayout = new QHBoxLayout();

    QLabel *label = new QLabel(labelStr);
    hlayout->addWidget(label);

    if(lineEdit!=nullptr)
        hlayout->addWidget(lineEdit);

    mainLayout->addLayout(hlayout);
}

void AbstractIODevice::setDesription(QString description)
{
    this->description = description;
}

void AbstractIODevice::paintEvent(QPaintEvent *event)
{
    QPainter p(this);

    p.setRenderHint(QPainter::Antialiasing, true);
    p.setPen(QPen(QColor(Qt::cyan)));
    p.drawRoundedRect(1, 1, width() - 2, height() - 2,3,3, Qt::AbsoluteSize);
}


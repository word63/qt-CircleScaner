#ifndef COMPORTDEVICE_H
#define COMPORTDEVICE_H

#include <QWidget>
#include <QPushButton>


#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QLabel>
#include <QLineEdit>


#include <QPainter>


class ComPortDevice : public QWidget
{
    Q_OBJECT
public:
    explicit ComPortDevice(QWidget *parent = nullptr);

    void setDescription(const QString &value);

signals:

public slots:

private:
    QLabel *desc;
    QString description = "COM_Port_1";
    QVBoxLayout *newLay;

    void Initialization();

protected:
    void paintEvent(QPaintEvent *event);


};

#endif // COMPORTDEVICE_H

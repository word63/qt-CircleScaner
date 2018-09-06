#ifndef ABSTRACTIODEVICE_H
#define ABSTRACTIODEVICE_H

#include <QWidget>
#include <QPushButton>


#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QLabel>
#include <QLineEdit>

#include <QPainter>

class AbstractIODevice : public QWidget
{
    Q_OBJECT
    
public:
    AbstractIODevice(QWidget *parent = nullptr);
    void setDesription(QString description);
protected:

    virtual void Initialization(); // call this func from your constructor
    
    void createLineWidget(QString labelStr, QLineEdit *lineEdit = nullptr);

    void paintEvent(QPaintEvent *event) override;
    
    QString description;
    QVBoxLayout *mainLayout;
    
signals:

public slots:
    
    // QWidget interface

};

#endif // ABSTRACTIODEVICE_H

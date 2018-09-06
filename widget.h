#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "models/simpletreemodel.h"
#include "device/comportdevice.h"
#include "device/serverdevice.h"
#include "device/socketdevice.h"
#include <QVBoxLayout>
#include <QSpacerItem>


namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private Q_SLOTS:
    void on_pushButton_clicked();
    void tableUpbate();

private:
    Ui::Widget *ui;

    SimpleTreeModel localModel;
};

#endif // WIDGET_H

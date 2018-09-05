#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->treeView->setModel(&localModel);

    QTreeView *temp = ui->treeView;


    connect(temp, &QTreeView::expanded , this, &Widget::tableUpbate);
    connect(temp, &QTreeView::collapsed, this, &Widget::tableUpbate);


    QVBoxLayout *scrollLay = new QVBoxLayout();

    ComPortDevice *dev = new ComPortDevice();
    dev->setDescription("Com_port_1");
    scrollLay->addWidget(dev);

    ComPortDevice *dev2 = new ComPortDevice();
    dev2->setDescription("Com_port_2");
    scrollLay->addWidget(dev2);

    ServerDevice *dev3 = new ServerDevice("Server_Port_3");
    scrollLay->addWidget(dev3);

    SocketDevice *dev4 = new SocketDevice("Socket_Port_4");
    scrollLay->addWidget(dev4);

    QSpacerItem *spaser = new QSpacerItem(10,10,QSizePolicy::Minimum,QSizePolicy::Expanding);
    scrollLay->addSpacerItem(spaser);
    ui->scrollAreaWidgetContents->setLayout(scrollLay);



}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QModelIndex index = ui->treeView->currentIndex();
    localModel.insertRows(0,0, index);

    //ui->treeView->resizeColumnToContents(0);
    //ui->treeView->update(index);
}

void Widget::tableUpbate()
{
    ui->treeView->resizeColumnToContents(0);
}

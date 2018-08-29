#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QList>
#include "locallist.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QList<QList<int>> listochek;
    //listochek.append(*new QList<int>());

    QString name = "list.csv;list2.csv;list3.csv";



    return a.exec();
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include "locallist.h"
#include "tablemodel.h"
#include "tabledelegate.h"
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    TableModel tableModel;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionAdd_row_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

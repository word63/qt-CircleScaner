
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "LOL";
    QList<QList<int>> listochek;
    //listochek.append(*new QList<int>());

    QString path = "list.csv;list2.csv;list3.csv";

    localList *list = new localList();
    list->parseCSV(path);

    tableModel.setAlgData(list->getBigAlg());
    ui->tableView->setModel(&tableModel);
    ui->tableView->setItemDelegate(new TableDelegate());
    ui->tableView->viewport()->setAttribute(Qt::WA_Hover);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAdd_row_triggered()
{
//    TableModel *tmp;
//    tmp = static_cast<TableModel*>(ui->tableView->model()) ;

//    int row = tmp->rowCount();

    QModelIndex index = ui->tableView->currentIndex();
    Alg tmp;
    tmp.flag = false;
    tmp.str = "Preved Medved";
    tmp.value = 20;


    tableModel.insertRows(0,1,index);

    ui->tableView->viewport()->update();
//    ui->tableView->show();
    ui->tableView->reset();
//    ui->tableView->showRow(tableModel.rowCount(index));



}


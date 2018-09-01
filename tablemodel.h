#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>
#include <QBrush>
#include <QColor>
#include "locallist.h"


// TODO: struct reuired to fix
// duplicated definition uses in locallist


class TableModel : public QAbstractTableModel
{
    QList<Alg> bigTable;

public:
    TableModel();

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;

    QVariant data(const QModelIndex &index, int role) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

    bool setData(const QModelIndex &index, const QVariant &value, int role) override;

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void setAlgData(const QList<Alg> &table);

//    QList<Alg>* data(); // мож понадобится потом

    // QAbstractItemModel interface

public:
    bool insertRows(int row, int count, const QModelIndex &parent) override;
//    bool insertColumns(int column, int count, const QModelIndex &parent) override;
//    bool removeRows(int row, int count, const QModelIndex &parent) override;
//    bool removeColumns(int column, int count, const QModelIndex &parent) override;
};

#endif // TABLEMODEL_H

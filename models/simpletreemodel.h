#ifndef SIMPLETREEMODEL_H
#define SIMPLETREEMODEL_H

#include <QAbstractItemModel>
#include <QBrush>
#include <QColor>
#include "node.h"

class SimpleTreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    explicit SimpleTreeModel(QObject *parent = nullptr);

    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    Qt::ItemFlags flags(const QModelIndex &index) const override;

    bool insertRows(int row, int count, const QModelIndex &parent) override;
    bool removeRows(int row, int count, const QModelIndex &parent) override;

private:

    Node *rootItem;

};

#endif // SIMPLETREEMODEL_H

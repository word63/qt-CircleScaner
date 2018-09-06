#include "simpletreemodel.h"

SimpleTreeModel::SimpleTreeModel(QObject *parent)
    : QAbstractItemModel(parent)
{

    rootItem = new Node(algorithm{0,"adsfas",321});

    rootItem->appendChild(new Node(algorithm{0,"3333",1},rootItem));

    rootItem->appendChild(new Node(algorithm{0,"555",3},rootItem));

    rootItem->child(1)->appendChild(new Node(algorithm{1,"444",2},rootItem->child(1)));
    rootItem->child(1)->child(0)->appendChild(new Node(algorithm{1,"444",2},rootItem->child(1)->child(0)));

}

QVariant SimpleTreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if( orientation == Qt::Horizontal && role == Qt::DisplayRole)
        switch (section ) {
            case 0: return "flag";
            case 1: return "str";
            case 2: return "value";
        }
    return QVariant();

}

QModelIndex SimpleTreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    Node *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<Node*>(parent.internalPointer());

    Node *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex SimpleTreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    Node *childItem = static_cast<Node*>(index.internalPointer());
    Node *parentItem = childItem->getParent();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int SimpleTreeModel::rowCount(const QModelIndex &parent) const
{
    Node *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<Node*>(parent.internalPointer());

    return parentItem->childCount();
}

int SimpleTreeModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return static_cast<Node *>(parent.internalPointer())->columnCount();
    else
        return rootItem->columnCount();
}

QVariant SimpleTreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();


    if (role == Qt::BackgroundRole)
        if(index.row()%2) return QBrush(QColor(0,128,0,100));
        else return QBrush(QColor(0,255,255,100));


    if (role != Qt::DisplayRole)
        return QVariant();

    Node *item = static_cast<Node*>(index.internalPointer());

    return item->data(index.column());
}

bool SimpleTreeModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
        return false;

    Node *curentNode = static_cast<Node *>(index.internalPointer());

    if(role != Qt::EditRole)
        return false;

    algorithm tmp = curentNode->getItem();

    switch (index.column()) {
    case 0: tmp.flag = value.toBool();
        break;
    case 1: tmp.str = value.toString();
        break;
    case 2: tmp.value = value.toInt();
        break;
    default:
        break;
    }
    curentNode->setItem(tmp);

    emit dataChanged(index, index);

    return true;

}

Qt::ItemFlags SimpleTreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    return QAbstractItemModel::flags(index)|Qt::ItemIsUserCheckable|Qt::ItemIsEditable;
}

bool SimpleTreeModel::insertRows(int row, int count, const QModelIndex &parent)
{
    Q_UNUSED(count);

    Node *curenNode = static_cast<Node *>(parent.internalPointer()) ;

    beginInsertRows(parent, row, row);
    Node *newNode = new Node(algorithm{0,"try men",222},curenNode);

    curenNode->appendChild(newNode);

    endInsertRows();



    return true;
}

bool SimpleTreeModel::removeRows(int row, int count, const QModelIndex &parent)
{

}

#include "tablemodel.h"



TableModel::TableModel()
{
    for(int i = 0; i <3; i++)
    {
        Alg tmp;
        tmp.flag = i*i%2>0?true:false;
        tmp.str = QString::number(i*i);
        tmp.value = i*i;

        bigTable << tmp;
    }
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    qDebug() << "row count = " << bigTable.length();
    return bigTable.length();
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    return 3; // Это вообще что за 3
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
        return QVariant();

    int row = index.row();
    int column =index.column();

    if(role == Qt::BackgroundRole)
    {
        switch (column)
        {
        case 0: return QBrush(QColor(200,0,0,100));
        case 1: return QBrush(QColor(200,112,36,100));
        case 2: return QBrush(QColor(0,0,255,100));
        }
    }

    if(role == Qt::DisplayRole)
    {

        switch (column)
        {
        case 0:return bigTable[row].flag;
        case 1: return bigTable[row].str;
        case 2: return  bigTable[row].value;
        }

    }

    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();

    if(orientation & Qt::Horizontal)
    {
        switch (section)
        {
        case 0: return "bool";
        case 1: return "str" ;
        case 2: return  "value";
        default: return QVariant();
        }
    }

    if(orientation & Qt::Vertical)
    {
        return section+1;
    }

    return QVariant();
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

    if(role != Qt::EditRole || !index.isValid())
        return false;


    int row = index.row();
    int column = index.column();

    bool result = false;
    switch (column)
    {
    case 0: bigTable[row].flag = value.toBool();
        result = 1; break;
    case 1: bigTable[row].str = value.toString();
        result = 1; break;
    case 2: bigTable[row].value = value.toInt();
        result = 1; break;
    default: result = 0;
    }
    emit dataChanged(index,index);
    return result;

}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    return  Qt::ItemIsEditable|Qt::ItemIsEnabled;
}

void TableModel::setAlgData(const QList<Alg> &table)
{
    bigTable = table;
}

bool TableModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row+count-1);

    Alg tmp;
    tmp.flag = false;
    tmp.str = "Preved Medved";
    tmp.value = 20;

    bigTable.insert(row, tmp);
    qDebug()<< "count in list " << bigTable.length();

    endInsertRows();

    return true;

}


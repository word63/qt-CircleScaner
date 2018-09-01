#include "tabledelegate.h"

TableDelegate::TableDelegate()
{

}

void TableDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{

    if(option.state & QStyle::State_MouseOver)
    {
        QRect rect = option.rect;
        QBrush brush = QBrush(Qt::red);

        painter->setBrush(brush);
        painter->drawRect(rect);

    }

    QStyledItemDelegate::paint(painter, option, index);
}


QWidget *TableDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSlider *trueSlider = new QSlider(parent);

    trueSlider->setGeometry(option.rect);
    trueSlider->setOrientation(Qt::Horizontal);
    trueSlider->setAutoFillBackground(true);
    trueSlider->setMinimum(0);
    trueSlider->setMaximum(100);

    int column = index.column();
    if(column == 2)
        return trueSlider;

    return QStyledItemDelegate::createEditor(parent, option, index);
}

void TableDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QSlider* slider = static_cast<QSlider*>(editor);

    int column = index.column();
    if(column == 2)
        slider->setValue(index.data().toInt());
    else
        QStyledItemDelegate::setEditorData(editor, index);
}

void TableDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    int column = index.column();
    if(column == 2)
    {
        QSlider* slider = static_cast<QSlider*>(editor);
        model->setData(index, slider->value());
    }
    QStyledItemDelegate::setModelData(editor, model, index);
}

void TableDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

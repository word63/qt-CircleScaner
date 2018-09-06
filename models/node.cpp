#include "node.h"

Node::Node(algorithm item, Node *parent):
    parent(parent), item(item)
{

}

algorithm Node::getItem() const
{
    return item;
}

void Node::setItem(const algorithm &value)
{
    item = value;
}

void Node::appendChild(Node *child)
{
    children.append(child);
}

Node *Node::child(int row) const
{
    return children.value(row);
}

int Node::childCount() const
{
    return children.length();
}

int Node::columnCount() const
{
    return 3;
}

int Node::row() const
{
    if(parent)
        return parent->children.indexOf(const_cast<Node *>(this));
    return 0;
}

QVariant Node::data(int column)
{
    switch (column) {
        case 0: return item.flag;
        case 1: return item.str;
        case 2: return item.value;
    }

    return QVariant();
}

Node *Node::getParent() const
{
    return parent;
}

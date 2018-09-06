#ifndef NODE_H
#define NODE_H

#include "QString"
#include "QList"

struct algorithm{
    bool flag;
    QString str;
    int value;
};

class Node
{
public:
    Node(algorithm item, Node *parent = 0);

    algorithm getItem() const;
    void setItem(const algorithm &value);

    void appendChild(Node *child);
    Node *child(int row) const;

    int childCount() const;
    int columnCount() const;

    int row() const;
    QVariant data(int column);

    Node *getParent() const;

private:
    Node *parent;
    algorithm item;
    QList<Node *> children;

};

#endif // NODE_H

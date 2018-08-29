#ifndef LOCALLIST_H
#define LOCALLIST_H

#include <QObject>
#include <QFile>
#include <QTextStream>

enum type{
    _alg = 0,
    _insert = 1
};

const QString PARAM_ALG = "[ALG]";
const QString PARAM_INSERT = "[INSERT]";

struct alg{
    bool flag;
    QString str;
    int volvo;
};

struct insert{
   QString key;
   int data;
};

class localList : public QObject
{
    Q_OBJECT
public:
    explicit localList(QObject *parent = nullptr);

    void parseCSV(QString path);
signals:

public slots:

private:
    QList< QList<alg>> bigAlg;
    QList< QList<insert>> bigInsert;
};

#endif // LOCALLIST_H

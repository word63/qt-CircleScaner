#ifndef LOCALLIST_H
#define LOCALLIST_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QtSql/QSqlTableModel>

enum type{
    _alg = 0,
    _insert = 1
};

const QString PARAM_ALG = "[ALG]";
const QString PARAM_INSERT = "[INSERT]";

struct Alg{
    bool flag;
    QString str;
    int value;
};

struct Insert{
   QString key;
   int data;
};

class localList : public QObject
{
    Q_OBJECT


public:
    explicit localList(QObject *parent = nullptr);

    void parseCSV(QString path);



    QList<Alg> getBigAlg() const;

signals:

public slots:

private:
    QList<Alg> bigAlg;
    QList<Insert> bigInsert;
};

#endif // LOCALLIST_H

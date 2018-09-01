#include "locallist.h"

localList::localList(QObject *parent) : QObject(parent)
{

}

void localList::parseCSV(QString path)
{
    QStringList files = path.split(';', QString::SkipEmptyParts);
    while(!files.isEmpty())
    {
        QString fileName = files.takeFirst();

        QFile fileInfo(fileName);
        if(!fileInfo.open(QIODevice::ReadOnly))
            return;

        QTextStream in(&fileInfo);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            QStringList parsedLine = line.split(';', QString::SkipEmptyParts);

            QString singleLine = parsedLine.first();

            int processingType;
            if(singleLine == PARAM_ALG)
                processingType = _alg;
            else if (singleLine == PARAM_INSERT)
                processingType = _insert;
            else
            {
                if(processingType == _alg)
                {
                    Alg tmp;

                    tmp.flag = parsedLine[0].toInt();
                    tmp.str = parsedLine[1];
                    tmp.value = parsedLine[2].toInt();

                    bigAlg.append(tmp);

                }
                else if(processingType == _insert)
                {
                    Insert tmp;

                    tmp.key = parsedLine.takeFirst();
                    tmp.data = parsedLine.takeFirst().toInt();

                    bigInsert.append(tmp);
                }
            }
        }
    }
}

QList<Alg> localList::getBigAlg() const
{
    return bigAlg;
}

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
            if(parsedLine.first() == PARAM_ALG)
            {

            }
            else if (parsedLine.first() == PARAM_INSERT) {

            }
        }
    }
}


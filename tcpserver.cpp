#include "tcpserver.h"

void TcpServer::slotNewConnection()
{
    QTcpSocket* pSocket = pTcpServer->nextPendingConnection();

    connect(pSocket, SIGNAL(disconnected()), pSocket, SLOT(deleteLater()));
    connect(pSocket, SIGNAL(readyRead()), this, SLOT(slotReadClient()));

    sendToClient(pSocket, "Connected");
}

void TcpServer::slotReadClient()
{
    QTcpSocket* clientSocket = static_cast<QTcpSocket*>(sender());
    QDataStream in(clientSocket);
    in.setVersion(QDataStream::Qt_DefaultCompiledVersion);
    while(true)
    {
        if(!nextBlockSize)
        {
            if(clientSocket->bytesAvailable() < sizeof(quint16))
                break;
            in >> nextBlockSize;
        }
        if(clientSocket->bytesAvailable() < nextBlockSize)
                break;

        QTime time;
        QString str;

        in >> time >> str;
        QString strMessage = time.toString() + " " + "Client has sent - " + str;

        sendToClient(clientSocket, "Server Responce: Received \"" + str + "\"");

    }
}

TcpServer::TcpServer(int port, QObject *parent) : QObject(parent)
{
    pTcpServer = new QTcpServer(this);
    if(!pTcpServer->listen(QHostAddress::Any, quint16(port)))
    {
        QMessageBox::critical(nullptr,
                              "Fatal Error",
                              "Server is unable to start: "
                              + pTcpServer->errorString()
                              );
    }
}

void TcpServer::sendToClient(QTcpSocket *pSocket,const QString &strPrint)
{
    QByteArray arrBlock;
    QDataStream out(&arrBlock, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_DefaultCompiledVersion);
    out << quint16(0) << QTime::currentTime() << strPrint;

    out.device()->seek(0);
    out << quint16(quint16(arrBlock.size()) - sizeof(quint16));

    pSocket->write(arrBlock);
}

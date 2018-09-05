#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>

#include <QObject>
#include <QMessageBox>
#include <QTime>

class TcpServer : public QObject
{
    Q_OBJECT

private:
    QTcpServer* pTcpServer;
    quint16 nextBlockSize;

private slots:
    virtual void slotNewConnection();
    void slotReadClient();

public:
    explicit TcpServer(int port, QObject *parent = nullptr);
    void sendToClient(QTcpSocket* pSocket, const QString &strPrint);
signals:

public slots:
};

#endif // TCPSERVER_H

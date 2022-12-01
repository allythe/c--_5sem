#include "server.h"
#include <QTcpSocket>
#include <QTextStream>

Server::Server(QObject *parent)
    : QTcpServer(parent)
{
    mSocket = nullptr;
    connect(this, &Server::newConnection, [&]() { mSocket = nextPendingConnection(); });
}

void Server::send(const QString &msj)
{
    if (mSocket) {
        QTextStream T(mSocket);
        T << msj;
        mSocket->flush();
    }
}

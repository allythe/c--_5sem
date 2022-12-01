#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>

class QTcpSocket;

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject* parent = 0);
    void send(const QString &msj);
private:
    QTcpSocket *mSocket;

};

#endif // SERVER_H

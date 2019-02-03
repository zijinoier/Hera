#ifndef NETRECEIVE_H
#define NETRECEIVE_H

#include <QUdpSocket>
#include <QObject>
#include "staticparams.h"

class NetReceive : public QObject
{
    Q_OBJECT
public:
    NetReceive(QObject *parent = 0);
private:
    QUdpSocket udpReceiveSocket;
    void udpSocketConnect();
    void udpSocketDisconnect();
    void storeData();

    int vision_port;
};

#endif // NETRECEIVE_H

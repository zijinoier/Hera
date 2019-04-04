#ifndef NETRECEIVE_H
#define NETRECEIVE_H

#include <QObject>
#include <QQueue>
#include <QUdpSocket>
#include "netreceive_global.h"

class NETRECEIVESHARED_EXPORT NetReceive : public QObject
{
    Q_OBJECT
public:
    NetReceive(int port,QObject *parent = 0);
    ~NetReceive();
    QQueue<QByteArray> datagrams;
    int vision_port = 10020;

public slots:
    void storeData();

private:
    QUdpSocket udpReceiveSocket;
    void udpSocketConnect();
    void udpSocketDisconnect();




//    VisionModule vm;
};

#endif // NETRECEIVE_H

#ifndef NETSEND_H
#define NETSEND_H

#include <QUdpSocket>

class NetSend
{
public:
    NetSend();
    void udpSend(QByteArray buffer);

private:
    QUdpSocket udpSendSocket;
};

#endif // NETSEND_H

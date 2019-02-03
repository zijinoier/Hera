#include "netreceive.h"
#include "parammanager.h"

NetReceive::NetReceive(QObject *parent) : QObject(parent){

}

void NetReceive::udpSocketConnect() {
    udpReceiveSocket.bind(QHostAddress::AnyIPv4, vision_port, QUdpSocket::ShareAddress);
    udpReceiveSocket.joinMulticastGroup(QHostAddress(ZSS::SSL_ADDRESS));
    connect(&udpReceiveSocket, SIGNAL(readyRead()), this, SLOT(storeData()), Qt::DirectConnection);
}

void NetReceive::udpSocketDisconnect() {
    disconnect(&udpReceiveSocket, 0, this, 0);
    udpReceiveSocket.abort();
}

void NetReceive::storeData() {
    static QByteArray datagram;
    while (udpReceiveSocket.hasPendingDatagrams()) {
        datagram.resize(udpReceiveSocket.pendingDatagramSize());
        udpReceiveSocket.readDatagram(datagram.data(), datagram.size());
//        parse((void*)datagram.data(), datagram.size());
//        这里通过sharememory将数据给convert
    }
}

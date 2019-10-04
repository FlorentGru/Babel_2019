/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** client_udp.cpp
*/

#include <iostream>
#include <QCoreApplication>
#include "client_udp.hpp"

bool client_udp::connection(char **argv)
{
    udpsocket = new QUdpSocket();
    address = argv[1];
    port = std::stoi(argv[2]);
    udpsocket->bind(QHostAddress(QHostAddress::AnyIPv4), port);
    QObject::connect(udpsocket, &QAbstractSocket::readyRead, this, &client_udp::retrieveData);
    timer.start(1000);
    QObject::connect(&timer, &QTimer::timeout, this, &client_udp::sendData);
    return (true);
}

bool client_udp::retrieveData() const
{
    QByteArray buffer;
    buffer.resize(int(udpsocket->pendingDatagramSize()));

    QHostAddress sender;
    quint16 senderPort;

    udpsocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);
    //std::cout << "Message from: " << sender.toString() << std::endl; 
    std::cout << "Message port: " << senderPort << std::endl;
    return (true);
}

bool client_udp::sendData() const
{
    QByteArray Data;
    Data.append("Test");
    std::cout << port << std::endl;
    udpsocket->writeDatagram(Data, address, port);
    return (true);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    client_udp clientudp;
    clientudp.connection(argv);
    return a.exec();
}
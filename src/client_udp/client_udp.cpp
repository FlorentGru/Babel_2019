/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** client_udp.cpp
*/

#include "client_udp.hpp"
#include <iostream>

void client_udp::connection(char **argv)
{
    udpsocket = new QUdpSocket();
    // port = 8888;
    address = argv[1];
    port = std::stoi(argv[2]);
    udpsocket->bind(QHostAddress(QHostAddress::AnyIPv4), port);
    QObject::connect(udpsocket, &QAbstractSocket::readyRead, this, &client_udp::readyRead);
    timer.start(1000);
    QObject::connect(&timer, &QTimer::timeout, this, &client_udp::sendDatagram);
}

void client_udp::readyRead()
{
    QByteArray buffer;
    buffer.resize(int(udpsocket->pendingDatagramSize()));

    QHostAddress sender;
    quint16 senderPort;

    udpsocket->readDatagram(buffer.data(), buffer.size(), &sender, &senderPort);
    //std::cout << "Message from: " << sender.toString() << std::endl; 
    std::cout << "Message port: " << senderPort << std::endl;
    std::cout << "Message: " << buffer.toStdString() << std::endl;
}

void client_udp::sendDatagram()
{
    QByteArray Data;
    Data.append("Test");
    std::cout << port << std::endl;
    udpsocket->writeDatagram(Data, address, port);
}
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
    std::cout << "TAMER" << std::endl;
    udpsocket = new QUdpSocket();
    // port = 8888;
    address = argv[1];
    port = std::stoi(argv[2]);
    udpsocket->connectToHost(address, port);
    QObject::connect(udpsocket, &QAbstractSocket::readyRead, this, &client_udp::readyRead);
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
    // std::cout << "Message: " << buffer << std::endl;
}

void client_udp::send_datagram(char **argv)
{
    QByteArray Data;
    Data.append("Test");
    udpsocket->writeDatagram(Data, address, port);
}
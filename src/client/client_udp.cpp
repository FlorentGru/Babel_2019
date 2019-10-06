/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** client_udp.cpp
*/

#include <iostream>
#include <QCoreApplication>
#include "client_udp.hpp"

bool client_udp::connection(QHostAddress address, quint16 port)
{
    udpsocket = new QUdpSocket();
    udpsocket->bind(QHostAddress(QHostAddress::AnyIPv4), port);
    address_class = address;
    port_class = port;
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
    std::cout << "Message port: " << senderPort << std::endl;
    return (true);
}

bool client_udp::sendData() const
{
    QByteArray Data;
    Data.append("Test");
    std::cout << "Utilisation du port : " << port_class << std::endl;
    udpsocket->writeDatagram(Data, address_class, port_class);
    return (true);
}
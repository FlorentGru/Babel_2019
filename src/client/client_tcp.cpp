/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** client_tcp.hpp
*/

#include <iostream>
#include "client_tcp.hpp"

client_tcp::client_tcp(QObject *parent) : QObject(parent)
{
    this->tcpSocket = new QTcpSocket(this);
    this->packet_ = new packet;

    QObject::connect(tcpSocket, &QAbstractSocket::connected, this, &client_tcp::sendData);
    QObject::connect(tcpSocket, &QAbstractSocket::readyRead, this, &client_tcp::retrieveData);
}

bool client_tcp::connection(QHostAddress address, quint16 port)
{
    this->tcpSocket->connectToHost(address, port);
    if (this->tcpSocket->waitForConnected(1000) == false)
        return (false);
    return(true);
}

bool client_tcp::sendData() const
{
    std::string prot = "SIGNIN";
    std::string pseudo = "TAMER";
    std::string pwd = "LA GROSSE PUTE";
    this->packet_->fill_packet(prot, pseudo, pwd);
    if (this->tcpSocket->write(packet_->pck.rawData, sizeof(packet_->pck.info)) == -1)
        return (false);
    retrieveData();
    return(true);
}

bool client_tcp::retrieveData() const
{
    memcpy(packet_->pck.rawData, tcpSocket->readAll().data(), sizeof(packet_->pck.info));
    std::cout << ":" << packet_->pck.info.proto << ":" << std::endl;
    std::cout << ":" << packet_->pck.info.pseudo << ":" << std::endl;
    std::cout << ":" << packet_->pck.info.password << ":" << std::endl;
    return (true);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    client_tcp clienttcp;
    clienttcp.connection(argv);
    return a.exec();
}
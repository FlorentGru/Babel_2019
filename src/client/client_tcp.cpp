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
    data_ = "HELLO SERVER!";

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
    if (this->tcpSocket->write(data_.c_str()) == -1)
        return (false);
    retrieveData();
    return(true);
}

bool client_tcp::retrieveData() const
{
    char *yes = tcpSocket->readAll().data();
    if (strcmp(yes, data_.c_str()) == 0)
        std::cout << "server respond  :  " << yes << std::endl;
    return (true);
}
/*
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    client_tcp clienttcp;
    clienttcp.connection(argv);
    return a.exec();
}*/
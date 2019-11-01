/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** client_tcp.hpp
*/

#ifndef CLIENTTCP_HPP
#define CLIENTTCP_HPP

#include <QObject>
#include <QTcpSocket>
#include <QCoreApplication>
#include <QString>
#include "packet.hpp"

class client_tcp : public QObject
{
    Q_OBJECT
public:
    client_tcp(QString address, int port);
    ~client_tcp(){};
    void sendData();
    void retrieveData();
    bool SignIn(std::string, std::string);
    void SignUp(std::string, std::string);
//    void addContact(std::string, std::string);
    packet &getPacket();
private:
    QString address_;
    int port_;
    QTcpSocket tcpSocket;
    packet packet_;
    std::string login_;
};

#endif

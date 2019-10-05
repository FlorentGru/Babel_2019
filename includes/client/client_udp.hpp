/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** client_udp.hpp
*/


#ifndef CLIENT_UDP_HPP
#define CLIENT_UDP_HPP

#include <QUdpSocket>
#include <QTimer>
#include <QObject>
#include <QString>
#include <QHostAddress>
#include "AClientConnection.hpp"
#include "client_tcp.hpp"

class client_udp : public QObject, AClientConnection
{
    Q_OBJECT
public:
        bool connection(QHostAddress address, quint16 port) override;
        client_udp(){};
        ~client_udp(){};
private:
        QUdpSocket *udpsocket;
        QTimer timer;
        QHostAddress address_class;
        quint16 port_class;
signals:

public slots:
    bool sendData() const override;
    bool retrieveData() const override;
};

#endif
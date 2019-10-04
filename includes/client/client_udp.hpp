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

class client_udp : public QObject, AClientConnection
{
    Q_OBJECT

    public:
        bool connection(char **) override;
    private:
        QUdpSocket *udpsocket;
        QTimer timer;
        QHostAddress address;
        quint16 port;
    signals:

    public slots:
        // void readyRead();
        // void sendDatagram();
        bool sendData() const override;
        bool retrieveData() const override;
};

#endif
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

class client_udp : public QObject
{
    Q_OBJECT

    public:
        void connection(char **argv);
    
    signals:

    private slots:
        void readyRead();
        void sendDatagram();
    
    private:
        QUdpSocket *udpsocket;
        QTimer timer;
        QHostAddress address;
        quint16 port;
};

#endif //CLIENT_UDP
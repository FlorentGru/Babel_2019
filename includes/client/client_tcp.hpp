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
#include <QHostAddress>
#include "AClientConnection.hpp"
#include "packet.hpp"

class client_tcp : public QObject, AClientConnection
{
    Q_OBJECT
public:
    explicit client_tcp(QObject *parent = nullptr);
    ~client_tcp(){};
    bool connection(QHostAddress address, quint16 port) override;
private:
    QTcpSocket *tcpSocket;
    packet *packet_;
    enum { max_length = 1024 };
    char data_[max_length];
signals:

public slots:
    bool sendData() const override;
    bool retrieveData() const override;
};

#endif

/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** AClientConnection.hpp
*/

#ifndef ACLIENTCONNECTION_HPP
#define ACLIENTCONNECTION_HPP

#include <QHostAddress>
#include <QtGlobal>

class AClientConnection
{
protected:
public:
    ~AClientConnection();
    virtual bool connection(QHostAddress address, quint16 port) = 0;
    void disconnection();

    public slots:
    virtual bool sendData() const = 0;
    virtual bool retrieveData() const = 0;
};

#endif

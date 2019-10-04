/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** AClientConnection.hpp
*/

#ifndef ACLIENTCONNECTION_HPP
#define ACLIENTCONNECTION_HPP

class AClientConnection
{
protected:
public:
    virtual ~AClientConnection() = 0;
    virtual bool sendData() const = 0;
    virtual bool retrieveData() const = 0;
    virtual bool connection(char **) = 0;
    void disconnection();
};

#endif

/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** main.cpp
*/

#include "client_udp.hpp"
#include <QCoreApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    client_udp clientudp;
    clientudp.connection(argv);
    clientudp.send_datagram(argv);
    return a.exec();
}
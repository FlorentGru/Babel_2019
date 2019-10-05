/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** contactwindow.cpp
*/

#include "contactwindow.hpp"
#include <iostream>

contactwindow::contactwindow()
{
    setFixedSize(1280, 720);

    setBackground();
    setLineEdit();
    setPushButton();
    // clientudp = new client_udp;

    QObject::connect(send, SIGNAL(clicked()), this, SLOT(search_address()));
}

void contactwindow::setBackground()
{
    background = new QLabel(this);
    background->setPixmap(QPixmap("/home/fgru/Pictures/Babel/Fabien.jpg"));
}

void contactwindow::setLineEdit()
{
    ip_address = new QLineEdit(this);
    ip_address->setPlaceholderText("Ip_adress");
    ip_address->setFixedWidth(260);
    ip_address->setFixedHeight(40);
    ip_address->move(30, 160);

    port = new QLineEdit(this);
    port->setPlaceholderText("Port");
    port->setFixedWidth(260);
    port->setFixedHeight(40);
    port->move(30, 200);
}

void contactwindow::setPushButton()
{
    send = new QPushButton("Send", this);
    send->setFixedWidth(100);
    send->setFixedHeight(40);
    send->move(30, 240);
}

void contactwindow::search_address()
{
    QHostAddress ip_address_string;
    ip_address_string = ip_address->text();
    quint16 port_string = port->text().toInt();
    puts("fdsfes");
    std::cout << port_string << std::endl;
    // clientudp->connection(ip_address_string, port_string);
}
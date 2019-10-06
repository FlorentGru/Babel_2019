/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** client_tcp.hpp
*/

#include <iostream>
#include <cstdlib>
#include <memory>
#include <utility>
#include <cstring>
#include "client_tcp.hpp"

client_tcp::client_tcp(QObject *parent) : QObject(parent)
{
    this->tcpSocket = new QTcpSocket(this);
    this->packet_ = new packet;

    std::string prot = "connection";
    std::string psd = "pseudo";
    std::string pwd = "password";
    packet_->fill_packet(prot, psd, pwd, login_);
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
    // std::string prot = "signup";
    // std::string pseudo = "Michel";
    // std::string pwd = "Berger";
    // this->packet_->fill_packet(prot, pseudo, pwd, login_);
    if (this->tcpSocket->write(packet_->pck.rawData, sizeof(packet_->pck.info)) == -1)
        return (false);
    return (true);
}

bool client_tcp::retrieveData() const
{
    memcpy(packet_->pck.rawData, tcpSocket->readAll().data(), sizeof(packet_->pck.info));
    std::cout << ":" << packet_->pck.info.proto << ":" << std::endl;
    std::cout << ":" << packet_->pck.info.pseudo << ":" << std::endl;
    std::cout << ":" << packet_->pck.info.password << ":" << std::endl;
    if (std::strcmp(packet_->pck.info.proto, "signup") == 0) {
        std::cout << "upnoice" << std::endl;
        return (true);
    }
    else if (std::strcmp(packet_->pck.info.proto, "signin") == 0) {
        std::cout << "innoice" << std::endl;
        //std::strcpy(login_, packet_->pck.info.pseudo);
        //std::cout << login_ << std::endl;
        return (true);
    } else if (std::strcmp(packet_->pck.info.proto, "addcontact") == 0){
        std::cout << "connoice" << std::endl;
        return (true);
    }
    std::cout << "NOPE" << std::endl;
    return (false);
}

void client_tcp::SignIn(std::string pseudo, std::string password)
{
    std::string prot = "signin";
    std::string psd = pseudo;
    std::string pwd = password;
    this->packet_->fill_packet(prot, psd, pwd, login_);
}

void client_tcp::SignUp(std::string pseudo, std::string password)
{
    std::string prot = "signup";
    std::string psd = pseudo;
    std::string pwd = password;
    this->packet_->fill_packet(prot, psd, pwd, login_);
}

void client_tcp::addContact(std::string pseudo, std::string ip)
{
    std::string prot = "addcontact";
    std::string psd = pseudo;
    std::string pwd = ip;
    this->packet_->fill_packet(prot, psd, pwd, login_);
}

// int main(int argc, char *argv[])
// {
//     QCoreApplication a(argc, argv);
//     QHostAddress address;
//     address = argv[1];
//     quint16 port = std::stoi(argv[2]);
//     client_tcp clienttcp;
//     clienttcp.connection(address, port);
//     return a.exec();
// }

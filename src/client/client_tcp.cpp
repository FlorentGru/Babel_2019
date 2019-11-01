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

client_tcp::client_tcp(QString address, int port) : address_(address), port_(port)
{
    tcpSocket.connectToHost(address_, port_);
    if (tcpSocket.waitForConnected(5000) == false) {
        std::cout << "Can't connect to server" << std::endl;
        return;
    }
}

void client_tcp::sendData()
{
    if (!tcpSocket.isWritable())
        std::cout << "Can't write" << std::endl;
    tcpSocket.write(packet_.getPacket(), 1024);
    tcpSocket.waitForBytesWritten();
}

void client_tcp::retrieveData()
{
    if (!tcpSocket.isReadable())
        std::cout << "Can't read" << std::endl;
    tcpSocket.waitForReadyRead();
    packet_.fill_packet(tcpSocket.readAll().data());

}

packet &client_tcp::getPacket()
{
    return (packet_);
}


bool client_tcp::SignIn(std::string pseudo, std::string password)
{
    packet_.setProto(packet::Protocol::SIGNIN);
    packet_.setPseudo(pseudo);
    packet_.setPassword(password);
    sendData();
    packet_.clearPacket();
    retrieveData();
    if (packet_.getProto() == packet::Protocol::FAIL)
        return (false);
    return (true);
}

void client_tcp::SignUp(std::string pseudo, std::string password)
{
    packet_.setProto(packet::Protocol::SIGNUP);
    packet_.setPseudo(pseudo);
    packet_.setPassword(password);
    sendData();
    packet_.clearPacket();
    retrieveData();
}
/*
void client_tcp::addContact(std::string pseudo, std::string ip)
{
    std::string prot = "addcontact";
    std::string psd = pseudo;
    std::string pwd = ip;
    packet_->fill_packet(prot, psd, pwd, login_);
}*/
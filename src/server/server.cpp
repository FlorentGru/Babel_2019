/*
** EPITECH PROJECT, 2019
** babel_boost_test
** File description:
** test_boost.cpp
*/

#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "server.hpp"

using boost::asio::ip::tcp;

connection::connection(boost::asio::io_context &iocontext) : socket_(iocontext)
{
    packet_ = new packet;
}


void connection::start()
{
    std::cout << "started" << std::endl;
    is_reading();
}

void connection::handleRead(boost::system::error_code ec)
{
    //int proto;
    if (!ec) {
        std::cout << packet_->pck.info.proto << std::endl;
        std::cout << packet_->pck.info.pseudo << std::endl;
        std::cout << packet_->pck.info.password << std::endl;
        is_writting();
        /*if (std::strcmp(packet_->info.proto, "signin\r\n") == 0)
            action_ = "Signed in";
        else if (std::strcmp(packet_->info.proto, "signup\r\n") == 0)
            action_ = "Signed up";
        else if (std::strcmp(packet_->info.proto, "addcontact\r\n") == 0)
            action_ = "Contact added";
        else if (std::strcmp(packet_->info.proto, "call\r\n") == 0)
            action_ = "Calling someone";
        else if (std::strcmp(packet_->info.proto, "hangup\r\n") == 0)
            action_ = "Hanging up";
        is_writting(action_.length());
        action_ = "Unknown action\n";*/
    } else
        delete this;
}

void connection::is_reading()
{
    socket_.async_read_some(boost::asio::buffer(packet_->pck.rawData, max_length), boost::bind(&connection::handleRead, this, boost::asio::placeholders::error));
}

void connection::handleWrite(boost::system::error_code ec)
{
    action_.clear();
    if (!ec)
        is_reading();
    else
        delete this;
}

void connection::is_writting()
{
    std::string prot = "YOU LOG IN";
    std::string pseudo = "HAS TAMER";
    std::string pwd = "DE CES MORTS";
    this->packet_->fill_packet(prot, pseudo, pwd);
    boost::asio::async_write(socket_, boost::asio::buffer(packet_->pck.rawData, sizeof(packet_->pck.info)), boost::bind(&connection::handleWrite, this, boost::asio::placeholders::error));
}

tcp::socket &connection::getSocket()
{
    return (socket_);
}

server::server(boost::asio::io_context& io_context, short port) : acceptor_(io_context, tcp::endpoint(tcp::v4(), port)), io_context_(io_context)
{
    accepting();
}

void server::handleAccept(connection *myConnection, boost::system::error_code ec)
{
    if(!ec) {
        myConnection->start();
        accepting();
    }
}

void server::accepting()
{
    connection *myconnection = new connection(io_context_);

    acceptor_.async_accept(myconnection->getSocket(), boost::bind(&server::handleAccept, this, myconnection, boost::asio::placeholders::error));
}

int main(int argc, char* argv[])
{
    try {
        if (argc != 2) {
            std::cerr << "Usage: async_tcp_echo_server <port>\n";
            return (0);
        }
        boost::asio::io_context io_context;
        server s(io_context, std::stoi(argv[1]));
        io_context.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return (84);
    }
    return (0);
}
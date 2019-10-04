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
}

void connection::start()
{
    std::cout << "started" << std::endl;
    is_reading();
}

void connection::handleRead(boost::system::error_code ec, std::size_t length)
{
    if (!ec)
        is_writting(length);
    else
        delete this;
}

void connection::is_reading()
{
    socket_.async_read_some(boost::asio::buffer(data_, max_length), boost::bind(&connection::handleRead, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
}

void connection::handleWrite(boost::system::error_code ec, std::size_t length)
{
    if (!ec)
        is_reading();
    else
        delete this;
}

void connection::is_writting(std::size_t length)
{
    boost::asio::async_write(socket_, boost::asio::buffer(data_, length), boost::bind(&connection::handleWrite, this, boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
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
    myConnection->start();
    accepting();
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
        server s(io_context, 8888);
        io_context.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return (84);
    }
    return (0);
}
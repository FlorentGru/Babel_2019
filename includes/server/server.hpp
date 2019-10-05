/*
** EPITECH PROJECT, 2019
** babel_boost_test
** File description:
** test_boost.hpp
*/

#ifndef __TEST_BOOST__
#define __TEST_BOOST__

#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <boost/asio.hpp>
#include "packet.hpp"

using boost::asio::ip::tcp;

class connection
{
    public:
        connection(boost::asio::io_context&);
        tcp::socket &getSocket();
        void start();
        void handleRead(boost::system::error_code);
        void handleWrite(boost::system::error_code);
    private:
        void is_reading();
        void is_writting();
        tcp::socket socket_;
        packet *packet_;
        enum { max_length = 1024 };
        char data_[max_length];
        std::string action_;
};

class server
{
    public:
        server(boost::asio::io_context& io_context, short port);
        void handleAccept(connection *, boost::system::error_code);
    private:
        void accepting();
        tcp::acceptor acceptor_;
        boost::asio::io_context &io_context_;
};

#endif
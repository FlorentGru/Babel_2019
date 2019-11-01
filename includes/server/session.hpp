/*
** EPITECH PROJECT, 2019
** babel_boost_test
** File description:
** session.hpp
*/

#ifndef _SESSION_HPP_
#define _SESSION_HPP_

#include <cstdlib>
#include <iostream>
#include <memory>
#include <utility>
#include <sqlite3.h>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "packet.hpp"
#include "database.hpp"

using boost::asio::ip::tcp;

class Session
{
public:
    Session(boost::asio::io_context&);
    void start();
    void handleRead(boost::system::error_code);
    void isReading();
    void handleWrite(boost::system::error_code);
    void isWritting();
    void checkData();
    tcp::socket &getSocket();
private:
    tcp::socket socket_;
    packet packet_;
    database database_;
    std::size_t max_lenght;
};

#endif
/*
** EPITECH PROJECT, 2019
** babel_boost_test
** File description:
** test_boost.hpp
*/

#ifndef __TEST_BOOST__
#define __TEST_BOOST__

#include "session.hpp"

using boost::asio::ip::tcp;

class server
{
    public:
        server(boost::asio::io_context& io_context, short port);
        void handleAccept(Session *, boost::system::error_code);
    private:
        void accepting();
        tcp::acceptor acceptor_;
        boost::asio::io_context &io_context_;
};

#endif
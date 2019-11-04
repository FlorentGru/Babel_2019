/*
** EPITECH PROJECT, 2019
** babel_boost_test
** File description:
** server.hpp
*/

#ifndef _SERVER_HPP_
#define _SERVER_HPP_

#include "session.hpp"
#include "AServer.hpp"

using boost::asio::ip::tcp;

class server: public AServer
{
    public:
        server(boost::asio::io_context& io_context, short port);
        void accepting() override;
    private:
        void startAccept(Session *, boost::system::error_code);
        tcp::acceptor acceptor_;
        boost::asio::io_context &io_context_;
};

#endif
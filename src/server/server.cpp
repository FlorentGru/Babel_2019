/*
** EPITECH PROJECT, 2019
** babel_boost_test
** File description:
** test_boost.cpp
*/

#include <memory>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "server.hpp"

using boost::asio::ip::tcp;

server::server(boost::asio::io_context& io_context, short port) : acceptor_(io_context, tcp::endpoint(tcp::v4(), port)), io_context_(io_context)
{
}

void server::startAccept(Session *mySession, boost::system::error_code ec)
{
    if(!ec) {
        mySession->start();
    }
    accepting();
}

void server::accepting()
{
    Session *mySession = new Session(io_context_);

    acceptor_.async_accept(mySession->getSocket(), boost::bind(&server::startAccept, this, mySession, boost::asio::placeholders::error));
}

int main(int argc, char* argv[])
{
    try {
        if (argc != 2) {
            std::cerr << "Usage: async_tcp_echo_server <port>\n";
            return (0);
        }
        boost::asio::io_context io_context;
        std::unique_ptr<AServer> s(new server(io_context, std::stoi(argv[1])));
        s->accepting();
        io_context.run();
    } catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return (84);
    }
    return (0);
}
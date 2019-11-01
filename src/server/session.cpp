/*
** EPITECH PROJECT, 2019
** babel_boost_test
** File description:
** session.hpp
*/

#include "session.hpp"

using boost::asio::ip::tcp;

Session::Session(boost::asio::io_context &iocontext) : socket_(tcp::socket(iocontext))
{
    max_lenght = 1024;
}

void Session::start()
{
    database_.databaseSession();
    std::cout << "started" << std::endl;
    isReading();
}

void Session::checkData()
{
    if (packet_.getProto() == packet::Protocol::SIGNUP) {
        if (database_.checkSignUp(packet_.getPseudo(), packet_.getPassword()) == false)
            packet_.setProto(packet::Protocol::FAIL);
    } else if (packet_.getProto() == packet::Protocol::SIGNIN) {
        if (database_.checkSignIn(packet_.getPseudo(), packet_.getPassword()) == false)
            packet_.setProto(packet::Protocol::FAIL);
    }
    //else if (std::strcmp(packet_->pck.info.proto, "addcontact") == 0)
    //    addContact();
}

void Session::handleRead(boost::system::error_code ec)
{
    if (!ec) {
        std::cout << "Pseudo : " << packet_.getPseudo() << std::endl;
        std::cout << "Password : " << packet_.getPassword() << std::endl;
        checkData();
        isWritting();
    } else
        delete this;
}

void Session::isReading()
{
    socket_.wait(tcp::socket::wait_read);
    socket_.async_read_some(boost::asio::buffer(packet_.getPacket(), max_lenght), boost::bind(&Session::handleRead, this, boost::asio::placeholders::error));
}

void Session::handleWrite(boost::system::error_code ec)
{
    if (!ec)
        isReading();
    else
        delete this;
}

void Session::isWritting()
{
    socket_.wait(tcp::socket::wait_write);
    socket_.async_write_some(boost::asio::buffer(packet_.getPacket(), max_lenght), boost::bind(&Session::handleWrite, this, boost::asio::placeholders::error));
}

tcp::socket &Session::getSocket()
{
    return (socket_);
}
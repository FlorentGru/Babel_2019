/*
** EPITECH PROJECT, 2019
** babel_boost_test
** File description:
** test_boost.cpp
*/

#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include "server.hpp"

using boost::asio::ip::tcp;

int existing;

connection::connection(boost::asio::io_context &iocontext) : socket_(iocontext)
{
    packet_ = new packet;
    existing = 0;
}


void connection::start()
{
    databaseConnection();
    std::cout << "started" << std::endl;
    isReading();
}

int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    std::cout << argc << std::endl;
    std::cout << existing << std::endl;
    std::cout << argv[0] << std::endl;
    if (argc == 0) {
        existing = 0;
        std::cout << "zero" << std::endl;
    } else {
        existing = argc;
        std::cout << "severals" << std::endl;
    }
    return (0);
}

void connection::databaseConnection()
{
    sqlite3_open("babel.db", &db_);
    char *error;

    std::string sql = "CREATE TABLE babel(id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, pseudo TEXT NOT NULL, password TEXT NOT NULL);";
    std::string search = "SELECT pseudo FROM babel WHERE pseudo = 'admin';";
    std::string admin = "INSERT INTO babel (pseudo, password) VALUES('admin', 'admin');";
    std::string contacts = "CREATE TABLE contacts(id INTEGER NOT NULL, pseudo TEXT NOT NULL, ip TEXT NOT NULL);";

    sqlite3_exec(this->db_, sql.c_str(), 0, 0, &error);
    sqlite3_exec(this->db_, search.c_str(), callback, 0, &error);
    if (existing == 0)
        sqlite3_exec(this->db_, admin.c_str(), 0, 0, &error);
    sqlite3_exec(this->db_, contacts.c_str(), 0, 0, &error);
}

void connection::signUpClient()
{
    char *error;
    std::string sch = "SELECT pseudo FROM babel WHERE pseudo = '" + std::string(packet_->pck.info.pseudo) + "';";

    sqlite3_exec(this->db_, sch.c_str(), callback, 0, &error);
    if (existing != 0) {
        std::string prot = "KO";
        std::string pseudo = "PSEUDO";
        std::string pwd = "ALREADY EXIST";
        this->packet_->fill_packet(prot, pseudo, pwd, "");
        return;
    }
    std::string add = "INSERT INTO babel (pseudo, password) VALUES('" + std::string(packet_->pck.info.pseudo) + "', '" + std::string(packet_->pck.info.password) + "');";
    sqlite3_exec(this->db_, add.c_str(), 0, 0, &error);
}

void connection::signInClient()
{
    char *error;
    std::cout << "men" << std::endl;
    std::string sch = "SELECT pseudo FROM babel WHERE pseudo = '" + std::string(packet_->pck.info.pseudo) + "' AND password = '" + std::string(packet_->pck.info.password) + "';";

    sqlite3_exec(this->db_, sch.c_str(), callback, 0, &error);
    if (existing == 0) {
        std::string prot = "KO: INVALID";
        std::string pseudo = "USERNAME OR PASSWD";
        std::string pwd = "NEED TO REGISTER BEFORE";
        this->packet_->fill_packet(prot, pseudo, pwd, "");
        return;
    }
}

void connection::addContact()
{

}

void connection::handleRead(boost::system::error_code ec)
{
    if (!ec) {
        std::cout << packet_->pck.info.proto << std::endl;
        std::cout << packet_->pck.info.pseudo << std::endl;
        std::cout << packet_->pck.info.password << std::endl;
        if (std::strcmp(packet_->pck.info.proto, "signup") == 0)
            signUpClient();
        else if (std::strcmp(packet_->pck.info.proto, "signin") == 0)
            signInClient();
        isWritting();
        /*else if (std::strcmp(packet_->pck.info.proto, "addcontact") == 0)
            addContact();
        else if (std::strcmp(packet_->pck.info.proto, "call") == 0)
            action_ = "Calling someone";
        else if (std::strcmp(packet_->pck.info.proto, "hangup") == 0)
            action_ = "Hanging up";
        is_writting(action_.length());
        action_ = "Unknown action\n";*/
    } else
        delete this;
}

void connection::isReading()
{
    socket_.async_read_some(boost::asio::buffer(packet_->pck.rawData, max_length), boost::bind(&connection::handleRead, this, boost::asio::placeholders::error));
}

void connection::handleWrite(boost::system::error_code ec)
{
    action_.clear();
    if (!ec)
        isReading();
    else
        delete this;
}

void connection::isWritting()
{
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
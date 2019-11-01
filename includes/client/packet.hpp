/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** packet.hpp
*/

#ifndef _PACKET_HPP_
#define _PACKET_HPP_

class packet
{
    private:
    public:
        enum Protocol {
            SIGNIN,
            SIGNUP,
            ADDCONTACT,
            CALL,
            HANGUP,
            FAIL
        };
        struct package
        {
            union
            {
                char rawData[1024];
                struct {
                    Protocol proto;
                    char pseudo[20];
                    char password[30];
                    char login[20];
                } info;
            };
        };
        package pck;
        void fill_packet(char *packet);
        void setProto(Protocol proto);
        void setPseudo(std::string pseudo);
        void setPassword(std::string password);
        void setLogin(std::string login);
        void clearPacket();
        Protocol getProto();
        std::string getPseudo();
        std::string getPassword();
        std::string getLogin();
        char *getPacket();
};

#endif
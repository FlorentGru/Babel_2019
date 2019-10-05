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
        struct package {
            union
            {
                char rawData[1024];
                struct {
                    char proto[15];
                    char pseudo[15];
                    char password[20];
                } info;
            };
        };
        enum Protocol {
            SIGNIN,
            SIGNUP,
            ADDCONTACT,
            CALL,
            HANGUP,
            END
        };

        //packet();
        Protocol protocol;
        package pck;
        void fill_packet(std::string, std::string, std::string);
};

#endif
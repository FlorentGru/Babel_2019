/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** packet.cpp
*/

#include <iostream>
#include <cstring>
#include "packet.hpp"

void packet::fill_packet(std::string proto, std::string pseudo, std::string passwd, std::string login)
{
    memset(pck.rawData, 0, sizeof(pck.info));
    #ifdef _WIN64
        strcpy_s(pck.info.proto , proto.c_str());
        strcpy_s(pck.info.pseudo, pseudo.c_str());
        strcpy_s(pck.info.password, passwd.c_str());
        strcpy_s(pck.info.login, login.c_str());
    #else
        std::strcpy(pck.info.proto , proto.c_str());
        std::strcpy(pck.info.pseudo, pseudo.c_str());
        std::strcpy(pck.info.password, passwd.c_str());
        std::strcpy(pck.info.login, login.c_str());
    #endif
}
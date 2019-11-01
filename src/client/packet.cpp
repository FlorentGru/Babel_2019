/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** packet.cpp
*/

#include <iostream>
#include <cstring>
#include "packet.hpp"

void packet::fill_packet(char *pckt)
{
    memset(pck.rawData, 0, 1024);
    for (size_t i = 0; i < 1024; i++)
        pck.rawData[i] = pckt[i];
}

char *packet::getPacket()
{
    return(pck.rawData);
}

void packet::setProto(Protocol proto)
{
    pck.info.proto = proto;
}

void packet::setPseudo(std::string pseudo)
{
    memset(pck.info.pseudo, 0, 20);
    for (int i = 0; i < 20 && pseudo[i] != '\0'; i++)
        pck.info.pseudo[i] = pseudo[i];
}

void packet::setPassword(std::string password)
{
    memset(pck.info.password, 0, 30);
    for (int i = 0; i < 20 && password[i] != '\0'; i++)
        pck.info.password[i] = password[i];
}

void packet::setLogin(std::string login)
{
    memset(pck.info.login, 0, 20);
    for (int i = 0; i < 20 && login[i] != '\0'; i++)
        pck.info.login[i] = login[i];
}

packet::Protocol packet::getProto()
{
    return(pck.info.proto);
}

std::string packet::getPseudo()
{
    return(pck.info.pseudo);
}

std::string packet::getPassword()
{
    return(pck.info.password);
}

std::string packet::getLogin()
{
    return(pck.info.login);
}

void packet::clearPacket()
{
    memset(pck.rawData, 0, 1024);
}
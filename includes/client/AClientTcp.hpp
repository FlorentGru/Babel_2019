/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** AClientTcp.hpp
*/

#ifndef _ACLIENTTCP_HPP_
#define _ACLIENTTCP_HPP_

#include <iostream>

class AClientTcp
{
    public:
        AClientTcp();
        virtual ~AClientTcp();
        virtual void sendData() = 0;
        virtual void retrieveData() = 0;
        virtual bool SignIn(std::string, std::string) = 0;
        virtual void SignUp(std::string, std::string) = 0;
};

#endif
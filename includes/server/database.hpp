/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** database.hpp
*/

#ifndef _DATABASE_HPP_
#define _DATABASE_HPP_

#include <sqlite3.h>
#include <iostream>
#include <vector>

class database
{
    public:
        database();
        bool checkSignIn(std::string pseudo, std::string password);
        bool checkSignUp(std::string pseudo, std::string password);
        void databaseSession();
        //void addContact();
    protected:
        sqlite3* db_;
};

#endif
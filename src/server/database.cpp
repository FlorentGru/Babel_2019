/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** database.cpp
*/

#include "database.hpp"

int exist;

database::database()
{
    exist = 0;
    sqlite3_open("babel.db", &db_);
}

int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    exist = argc;
    return (0);
}

void database::databaseSession()
{
    char *error;

    std::string sql = "CREATE TABLE babel(id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, pseudo TEXT NOT NULL, password TEXT NOT NULL);";
    std::string search = "SELECT pseudo FROM babel WHERE pseudo = 'admin';";
    std::string admin = "INSERT INTO babel (pseudo, password) VALUES('admin', 'admin');";
    std::string contacts = "CREATE TABLE contacts(id INTEGER NOT NULL, pseudo TEXT NOT NULL, ip TEXT NOT NULL);";

    sqlite3_exec(this->db_, sql.c_str(), 0, 0, &error);
    sqlite3_exec(this->db_, search.c_str(), callback, 0, &error);
    if (exist == 0)
        sqlite3_exec(this->db_, admin.c_str(), 0, 0, &error);
    sqlite3_exec(this->db_, contacts.c_str(), 0, 0, &error);
}

bool database::checkSignUp(std::string pseudo, std::string password)
{
    char *error;
    std::string sch = "SELECT pseudo FROM babel WHERE pseudo = '" + pseudo + "';";

    sqlite3_exec(this->db_, sch.c_str(), callback, 0, &error);
    if (exist != 0)
        return (false);
    std::string add = "INSERT INTO babel (pseudo, password) VALUES('" + pseudo + "', '" + password + "');";
    sqlite3_exec(this->db_, add.c_str(), 0, 0, &error);
    return(true);
}

bool database::checkSignIn(std::string pseudo, std::string password)
{
    char *error;
    std::string sch = "SELECT pseudo FROM babel WHERE pseudo = '" + pseudo + "' AND password = '" + password + "';";

    sqlite3_exec(this->db_, sch.c_str(), callback, 0, &error);
    if (exist == 0)
        return(false);
    return(true);
}
/*
void database::addContact()
{

}
*/
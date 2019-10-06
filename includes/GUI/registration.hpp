/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** registration.hpp
*/

#ifndef REGISTRATION_HPP
#define REGISTRATION_HPP

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFont>
#include <string>
#include <iostream>
#include "client_tcp.hpp"

class registration : public QWidget
{
    Q_OBJECT

    public:
        registration(client_tcp *ClientTcp);
        void setBackground();
        void setText();
        void setLineEdit();
        void setQpushButton();

    public slots:
        void finish_registration();

    private:
        QLabel *background;
        QLabel *username_text;
        QLabel *password_text;
        QLabel *babel_text;
        QLabel *account_text;
        QLineEdit *username;
        QLineEdit *password;
        QPushButton *registe;
        client_tcp *ClientTcp;
};

#endif // REGISTRATION_HPP
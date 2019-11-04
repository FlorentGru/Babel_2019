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
#include "AGui.hpp"

class registration : public QWidget, public AGui
{
    Q_OBJECT

public:
    registration(AClientTcp *ClientTcp);
    void setBackground() override;
    void setText() override;
    void setLineEdit() override;
    void setPushButton() override;

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
    AClientTcp *ClientTcp;
};

#endif // REGISTRATION_HPP
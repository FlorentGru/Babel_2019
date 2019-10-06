/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** add_contact.hpp
*/

#ifndef ADDCONTACT_HPP
#define ADDCONTACT_HPP

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFont>
#include "client_tcp.hpp"

class addcontact : public QWidget
{
    Q_OBJECT

    public:
    addcontact();
    void setBackground();
    void setLineEdit();
    void setText();
    void setPushButton();

    public slots:
    // void add_contact();

    private:
    QLabel *background;
    QLabel *pseudo_text;
    QLabel *ip_address_text;
    QLineEdit *pseudo;
    QLineEdit *ip_address;
    QPushButton *add;
};

#endif //ADDCONTACT_HPP
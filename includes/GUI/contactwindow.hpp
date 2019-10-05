/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** contactwindow.hpp
*/

#ifndef CONTACTWINDOW_HPP
#define CONTACTWINDOW_HPP

#include "QWidget"
#include "QLabel"
#include <QLineEdit>
#include <QPushButton>
#include <QHostAddress>
// #include "client_udp.hpp"

class contactwindow : public QWidget
{
    Q_OBJECT

    public:
    contactwindow();
    void setBackground();
    void setLineEdit();
    void setPushButton();

    public slots:
        void search_address();

    private:
    QLabel *background;
    QLineEdit *ip_address;
    QLineEdit *port;
    QPushButton *send;
    // client_udp *clientudp;
};

#endif // CONTACTWINDOW_HPP
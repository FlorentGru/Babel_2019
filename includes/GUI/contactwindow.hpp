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
#include <QPalette>
#include <QItemSelection>
#include <QMenuBar>
#include <QGridLayout>
#include "client_udp.hpp"
#include "add_contact.hpp"

class contactwindow : public QWidget
{
    Q_OBJECT

public:
    contactwindow();
    void setBackground();
    void setLineEdit();
    void setPushButton();
    void CreateMenu(std::string pseudo , int size);

public slots:
    void search_address();
    void logout();
    void add_contact();

private:
    QLabel *background;
    QLineEdit *ip_address;
    QLineEdit *port;
    QPushButton *send;
    QPushButton *logout_button;
    QPushButton *add_contact_button;
    QAction *editAct;
    QAction *removeAct;
    QMenu *toolMenu;
    client_udp *clientudp;
    addcontact *Add_contact;

    QLabel *name;
    QPushButton *call;
    QPushButton *delete_user;
};

#endif // CONTACTWINDOW_HPP
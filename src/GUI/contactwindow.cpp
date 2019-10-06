/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** contactwindow.cpp
*/

#include "contactwindow.hpp"
#include <iostream>
#include <QAction>
#include <QFileDialog>

contactwindow::contactwindow()
{
    setFixedSize(1280, 720);
    setWindowTitle("Contact List");

    setBackground();
    setLineEdit();
    setPushButton();
    for (int i = 0; i < 2; i++)
        CreateMenu("Pseudo", i);
    clientudp = new client_udp;

    QObject::connect(send, SIGNAL(clicked()), this, SLOT(search_address()));
    QObject::connect(logout_button, SIGNAL(clicked()), this, SLOT(logout()));
    QObject::connect(add_contact_button, SIGNAL(clicked()), this, SLOT(add_contact()));
}

void contactwindow::setBackground()
{
    background = new QLabel(this);
    background->setPixmap(QPixmap("./rsc/Fond_contact.png"));
}

void contactwindow::setLineEdit()
{
    ip_address = new QLineEdit(this);
    ip_address->setPlaceholderText("Ip_adress");
    ip_address->setFixedWidth(260);
    ip_address->setFixedHeight(40);
    ip_address->move(230, 160);

    port = new QLineEdit(this);
    port->setPlaceholderText("Port");
    port->setFixedWidth(260);
    port->setFixedHeight(40);
    port->move(230, 200);
}

void contactwindow::setPushButton()
{
    send = new QPushButton("Send", this);
    QPalette pal = send->palette();
    pal.setColor(QPalette::Button, QColor(Qt::blue));
    send->setAutoFillBackground(true);
    send->setPalette(pal);
    send->update();
    send->setFixedWidth(100);
    send->setFixedHeight(40);
    send->move(230, 240);

    logout_button = new QPushButton("Logout", this);
    QPalette pall = logout_button->palette();
    pall.setColor(QPalette::Button, QColor(Qt::red));
    logout_button->setAutoFillBackground(true);
    logout_button->setPalette(pall);
    logout_button->update();
    logout_button->setFixedWidth(80);
    logout_button->setFixedHeight(25);
    logout_button->move(1180, 20);

    add_contact_button = new QPushButton("Add Contact", this);
    QPalette contact = add_contact_button->palette();
    contact.setColor(QPalette::Button, QColor(Qt::blue));
    add_contact_button->setAutoFillBackground(true);
    add_contact_button->setPalette(contact);
    add_contact_button->update();
    add_contact_button->setFixedWidth(80);
    add_contact_button->setFixedHeight(25);
    add_contact_button->move(1080, 20);
}

void contactwindow::CreateMenu(std::string pseudo, int size)
{
    name = new QLabel(this);
    call = new QPushButton("Call", this);
    delete_user = new QPushButton("Delete", this);
    QFont font_account("Arial", 20);

    name->setText(pseudo.c_str());
    name->move(700, (115 * (size + 1)));
    name->setFont(font_account);
    name->show();

    QPalette pal = call->palette();
    pal.setColor(QPalette::Button, QColor(Qt::green));
    call->setAutoFillBackground(true);
    call->setPalette(pal);
    call->update();
    call->setFixedWidth(70);
    call->setFixedHeight(30);
    call->move(830, (115 * (size + 1)));

    QPalette pall = delete_user->palette();
    pall.setColor(QPalette::Button, QColor(Qt::red));
    delete_user->setAutoFillBackground(true);
    delete_user->setPalette(pall);
    delete_user->update();
    delete_user->setFixedWidth(70);
    delete_user->setFixedHeight(30);
    delete_user->move(920, (115 * (size + 1)));

    QObject::connect(call, SIGNAL(clicked()), this, SLOT(search_address()));
}

void contactwindow::search_address()
{
    QHostAddress ip_address_string;
    ip_address_string = ip_address->text();
    quint16 port_string = port->text().toInt();
    std::cout << port_string << std::endl;
    clientudp->connection(ip_address_string, port_string);
}

void contactwindow::logout()
{
    close();
}

void contactwindow::add_contact()
{
    Add_contact = new addcontact();
    Add_contact->show();
}
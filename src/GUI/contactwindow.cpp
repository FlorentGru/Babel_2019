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
    // CreateMenu();
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
    pall.setColor(QPalette::Button, QColor(Qt::gray));
    logout_button->setAutoFillBackground(true);
    logout_button->setPalette(pall);
    logout_button->update();
    logout_button->setFixedWidth(80);
    logout_button->setFixedHeight(25);
    logout_button->move(1180, 20);

    add_contact_button = new QPushButton("Add Contact", this);
    QPalette contact = add_contact_button->palette();
    contact.setColor(QPalette::Button, QColor(Qt::gray));
    add_contact_button->setAutoFillBackground(true);
    add_contact_button->setPalette(contact);
    add_contact_button->update();
    add_contact_button->setFixedWidth(80);
    add_contact_button->setFixedHeight(25);
    add_contact_button->move(1080, 20);
}

void contactwindow::CreateMenu()
{
    pseudo = new QLabel("pseudo");
    call = new QPushButton("Call");
    delete_user = new QPushButton("Delete");

    QGridLayout *gLayout = new QGridLayout;
    gLayout->addWidget(pseudo);

    gLayout->addWidget(call, 0, 0);
    gLayout->addWidget(delete_user);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(gLayout);
    setLayout(mainLayout);
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
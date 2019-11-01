/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** add_contact.cpp
*/

#include "add_contact.hpp"

addcontact::addcontact()
{
    setFixedSize(400, 120);
    setWindowTitle("Add Contact");

    setBackground();
    setLineEdit();
    setText();
    setPushButton();

    //QObject::connect(add, SIGNAL(clicked()), this, SLOT(add_contact()));
}

void addcontact::setBackground()
{
    background = new QLabel(this);
    background->setPixmap(QPixmap("../../rsc/Fond_contact.png"));
}

void addcontact::setLineEdit()
{
    pseudo = new QLineEdit(this);
    pseudo->setPlaceholderText("");
    pseudo->setFixedWidth(160);
    pseudo->setFixedHeight(40);
    pseudo->move(100, 20);

    ip_address = new QLineEdit(this);
    ip_address->setPlaceholderText("");
    ip_address->setFixedWidth(160);
    ip_address->setFixedHeight(40);
    ip_address->move(100, 70);
}

void addcontact::setText()
{
    pseudo_text = new QLabel(this);
    pseudo_text->setText("<font color='White'>Pseudo");
    QFont font_account("", 15);
    pseudo_text->setFont(font_account);
    pseudo_text->show();
    pseudo_text->move(10, 30);

    ip_address_text = new QLabel(this);
    ip_address_text->setText("<font color='White'>Ip_address");
    QFont font_ip("", 18);
    ip_address->setFont(font_ip);
    ip_address->show();
    ip_address_text->move(10, 80);
}

void addcontact::setPushButton()
{
    add = new QPushButton("Add", this);
    QPalette pal = add->palette();
    pal.setColor(QPalette::Button, QColor(Qt::darkMagenta));
    add->setAutoFillBackground(true);
    add->setPalette(pal);
    add->update();
    add->setFixedWidth(100);
    add->setFixedHeight(50);
    add->move(290, 35);
}

// void addcontact::add_contact()
// {
        // QString pseudo_string = pseudo->text();
        // QString ip_address_string = ip_address->text();
        // clientTcp->addContact(pseudo_string, ip_address_string);
        // close();
// }
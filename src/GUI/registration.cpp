/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** registration.cpp
*/

#include "registration.hpp"

registration::registration()
{
    setFixedSize(1280, 720);

    setBackground();
    setText();
    setLineEdit();
    setQpushButton();
    QObject::connect(registe, SIGNAL(clicked()), this, SLOT(finish_registration()));
}

void registration::setBackground()
{
    background = new QLabel(this);
    background->setPixmap(QPixmap("/home/fgru/TEK3/Babel/CPP_babel_2019/rsc/background_registration_end.png"));
    background->show();
}

void registration::setText()
{
    babel_text = new QLabel(this);
    babel_text->setText("<font color='White'>Babel");
    QFont font_babel("Comic Sans Ms", 40);
    babel_text->move(40, 10);
    babel_text->setFont(font_babel);
    babel_text->show();

    account_text = new QLabel(this);
    account_text->setText("<font color='White'>Account");
    QFont font_account("Comic Sans Ms", 50);
    account_text->move(550, 120);
    account_text->setFont(font_babel);
    account_text->show();
}

void registration::setLineEdit()
{
    username = new QLineEdit(this);
    username->setPlaceholderText("UserName");
    username->setFixedWidth(260);
    username->setFixedHeight(40);
    username->move(500, 250);

    password = new QLineEdit(this);
    password->setPlaceholderText("Password");
    password->setFixedWidth(260);
    password->setFixedHeight(40);
    password->move(500, 350);
}

void registration::setQpushButton()
{
    registe = new QPushButton("Register", this);
    registe->setFixedWidth(100);
    registe->setFixedHeight(40);
    registe->move(580, 440);
}

void registration::finish_registration()
{
    close();
}
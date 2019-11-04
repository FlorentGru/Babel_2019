/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** registration.cpp
*/

#include "registration.hpp"

registration::registration(AClientTcp *Clienttcp)
{
    setFixedSize(1280, 720);
    ClientTcp = Clienttcp;
    setBackground();
    setWindowTitle("Registration");
    setText();
    setLineEdit();
    setQpushButton();

    QObject::connect(registe, SIGNAL(clicked()), this, SLOT(finish_registration()));
}

void registration::setBackground()
{
    background = new QLabel(this);
    background->setPixmap(QPixmap("../../rsc/background_registration_end.png"));
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
    password->setEchoMode(QLineEdit::Password);
    password->move(500, 350);
}

void registration::setPushButton()
{
    registe = new QPushButton("Create", this);
    registe->setFixedWidth(100);
    registe->setFixedHeight(40);
    registe->move(580, 440);
}

void registration::finish_registration()
{
    QString username_qstring = username->text();
    QString password_qstring = password->text();
    std::string usernameString = username_qstring.toUtf8().constData();
    std::string passwordString = password_qstring.toUtf8().constData();

    ClientTcp->SignUp(usernameString, passwordString);
    close();
}
/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** mainwindow.cpp
*/

#include "login.hpp"

Login::Login() : QWidget()
{
    setFixedSize(1280, 720);
    setBackground();
    setText();
    setLineEdit();
    setPushButton();

    QObject::connect(login_but, SIGNAL(clicked()), this, SLOT(on_pushButton_Login_clicked()));
    QObject::connect(registe, SIGNAL(clicked()), this, SLOT(open_registration()));
}

void Login::setBackground()
{
    background = new QLabel(this);
    background->setPixmap(QPixmap("/home/fgru/TEK3/Babel/CPP_babel_2019/rsc/Fond accueil fini.jpg"));
}

void Login::setText()
{
    username = new QLineEdit(this);
    username->setPlaceholderText("UserName");
    username->setFixedWidth(150);
    username->setFixedHeight(30);
    username->move(580, 350);

    password = new QLineEdit(this);
    password->setPlaceholderText("Password");
    password->setFixedWidth(150);
    password->setFixedHeight(30);
    password->move(580, 390);
}

void Login::setLineEdit()
{
    username_text = new QLabel(this);
    username_text->setText("<font color='White'>Username");
    username_text->move(500, 360);

    password_text = new QLabel(this);
    password_text->setText("<font color='White'>Password");
    password->setEchoMode(QLineEdit::Password);
    password_text->move(500, 395);
}

void Login::setPushButton()
{
    login_but = new QPushButton("Login", this);
    login_but->move(550, 440);

    registe = new QPushButton("Register", this);
    registe->move(660, 440);
}

void Login::on_pushButton_Login_clicked()
{
    QString password_writen = password->text();
    QString username_writen = username->text();

    if (username_writen == "test" && password_writen == "test") {
        hide();
        contactWindow = new contactwindow();
        contactWindow->show();
    } else {
        QLabel *errormessage = new QLabel(this);
        errormessage->setText("<font color='White'>Username or Password are incorrect");
        errormessage->move(500, 500);
        errormessage->show();
    }
}

void Login::open_registration()
{
    Registration = new registration();
    Registration->show();
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Login window;
    window.show();

    return app.exec();
}
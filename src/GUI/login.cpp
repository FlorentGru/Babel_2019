/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** mainwindow.cpp
*/

#include "login.hpp"

Login::Login(QString address, int port) : QWidget(), ClientTcp(address, port)
{
    setFixedSize(1280, 720);
    setWindowTitle("Login");
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
    background->setPixmap(QPixmap("../../rsc/background_registration_end.png"));
}

void Login::setText()
{
    babel = new QLabel(this);
    babel->setText("<font color='White'>Babel");
    QFont font_account("Comic Sans Ms", 50);
    babel->move(550, 120);
    babel->setFont(font_account);
    babel->show();

    username_text = new QLabel(this);
    username_text->setText("<font color='White'>Username");
    username_text->move(480, 280);

    password_text = new QLabel(this);
    password_text->setText("<font color='White'>Password");
    password_text->move(480, 330);
}

void Login::setLineEdit()
{
    username = new QLineEdit(this);
    username->setPlaceholderText("UserName");
    username->setFixedWidth(170);
    username->setFixedHeight(40);
    username->move(570, 270);

    password = new QLineEdit(this);
    password->setPlaceholderText("Password");
    password->setFixedWidth(170);
    password->setFixedHeight(40);
    password->setEchoMode(QLineEdit::Password);
    password->move(570, 320);
}

void Login::setPushButton()
{
    login_but = new QPushButton("Login", this);
    login_but->setFixedWidth(130);
    login_but->setFixedHeight(40);
    login_but->move(500, 390);

    registe = new QPushButton("Register", this);
    registe->setFixedWidth(130);
    registe->setFixedHeight(40);
    registe->move(650, 390);
}

void Login::on_pushButton_Login_clicked()
{
    QString password_writen = password->text();
    QString username_writen = username->text();
    std::string usernameString = username_writen.toUtf8().constData();
    std::string passwordString = password_writen.toUtf8().constData();

    if (ClientTcp.SignIn(usernameString, passwordString) == false) {
        QLabel *errormessage = new QLabel(this);
        errormessage->setText("<font color='White'>Username or Password are incorrect");
        errormessage->move(520, 500);
        errormessage->show();
    } else {
        close();
        contactWindow = new contactwindow();
        contactWindow->show();
    }
}

void Login::open_registration()
{
    Registration = new registration(&ClientTcp);
    Registration->show();
}

int main(int argc, char *argv[])
{
    try {
        if (argc != 3)
            return(84);
        QApplication app(argc, argv);
        Login window(argv[1], std::atoi(argv[2]));
        window.show();
        return app.exec();
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }
    return(0);
}
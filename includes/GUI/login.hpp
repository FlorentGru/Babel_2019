/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** mainwindow.hpp
*/

#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <QApplication>
#include <QMessageBox>
#include <QThread>
#include "contactwindow.hpp"
#include "registration.hpp"
#include "client_tcp.hpp"

class Login : public QWidget
{
    Q_OBJECT

public:
    Login();
    void initClient(char**);
    void setBackground();
    void setText();
    void setLineEdit();
    void setPushButton();

public slots:
    void on_pushButton_Login_clicked();
    void open_registration();

signals:

private:
    QPushButton *login_but;
    QLabel *background;
    QLabel *babel;
    QLabel *username_text;
    QLabel *password_text;
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *registe;
    contactwindow *contactWindow;
    registration *Registration;
    client_tcp *ClientTcp;
};

#endif //LOGIN_HPP
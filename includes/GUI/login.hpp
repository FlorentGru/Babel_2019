/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** mainwindow.hpp
*/

#ifndef LOGIN_HPP
#define LOGIN_HPP

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include <QGroupBox>
#include <QComboBox>
#include <QThread>
#include <QLineEdit>
#include "contactwindow.hpp"
#include "registration.hpp"

class Login : public QWidget
{
    Q_OBJECT

    public:
        Login();
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
};

#endif //LOGIN_HPP
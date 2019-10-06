/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** registration.hpp
*/

#ifndef REGISTRATION_HPP
#define REGISTRATION_HPP

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QFont>

class registration : public QWidget
{
    Q_OBJECT

    public:
        registration();
        void setBackground();
        void setText();
        void setLineEdit();
        void setQpushButton();

    public slots:
        void finish_registration();

    private:
        QLabel *background;
        QLabel *username_text;
        QLabel *password_text;
        QLabel *babel_text;
        QLabel *account_text;
        QLineEdit *username;
        QLineEdit *password;
        QPushButton *registe;
};

#endif // REGISTRATION_HPP
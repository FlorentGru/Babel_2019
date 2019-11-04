/*
** EPITECH PROJECT, 2019
** CPP_babel_2019
** File description:
** AGui.hpp
*/

#ifndef _AGUI_HPP
#define _AGUI_HPP

class AGui
{
    public:
        AGui();
        virtual ~AGui();
        virtual void setBackground() = 0;
        virtual void setText() = 0;
        virtual void setLineEdit() = 0;
        virtual void setPushButton() = 0;
};

#endif //_AGUI_HPP_
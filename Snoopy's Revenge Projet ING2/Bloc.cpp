#include <iostream>
#include "Bloc.h"

///Bloc : classe mère
//constructeurs
Bloc::Bloc(int posX, int posY, char type)
{
    m_pos_x = posX;
    m_pos_y = posY;
    m_type = type;
}
Bloc::Bloc(){m_pos_x = 0; m_pos_y = 0; m_type = ' ';}
//destructeur
Bloc::~Bloc(){}

//getters
int Bloc::getPosX()const{return m_pos_x;}
int Bloc::getPosY()const{return m_pos_y;}
char Bloc::getType()const{return m_type;}

//setters
void Bloc::setPosX(int posX){m_pos_x = posX;}
void Bloc::setPosY(int posY){m_pos_y = posY;}
void Bloc::setType(char type){m_type = type;}

///Bloc Cassable
Cassable::Cassable(int posX, int posY, char type) : Bloc(posX, posY, type)
{
    m_pos_x = posX;
    m_pos_y = posY;
    m_type = type;
}
//Destructeur
Cassable::~Cassable(){}

///Bloc Poussable
//constructeur surchargé
Poussable::Poussable(int posX, int posY, char type, bool estPoussable) : Bloc(posX, posY, type)
{
    m_pos_x = posX;
    m_pos_y = posY;
    m_type = type;
    m_estPoussable = estPoussable;
}

//destructeur
Poussable::~Poussable(){}

//getters
bool Poussable::getEstPoussable()const{return m_estPoussable;}

//setters
void Poussable::setEstPoussable(bool estPoussable)
{
    m_estPoussable = estPoussable;
}

#include <iostream>
#include "Bloc.h"

//constructeur surchargé
Bloc::Bloc(int posX, int posY, char type)
{
    m_pos_x = posX;
    m_pos_y = posY;
    m_type = type;
}

//destructeur
Bloc::~Bloc()
{
}

//getters
int Bloc::getPosX(){return m_pos_x;}
int Bloc::getPosY(){return m_pos_y;}
char Bloc::getType(){return m_type;}

//setters
void Bloc::setPosX(int posX){m_pos_x = posX;}
void Bloc::setPosY(int posY){m_pos_y = posY;}
void Bloc::setType(char type){m_type = type;}

#include "Poussable.h"

///Bloc Poussable
//constructeur surchargé
Poussable::Poussable(int posX, int posY, char type,bool estPoussableblocmere,bool estPoussable) : Bloc(posX,posY,type,estPoussableblocmere)
{
    m_pos_x = posX;
    m_pos_y = posY;
    m_type = type;
    m_estPoussableblocmere = estPoussableblocmere;
    m_estPoussable = estPoussable;
}

//destructeur
Poussable::~Poussable() {}

//getters
bool Poussable::getEstPoussable()const
{
    return m_estPoussable;
}

//setters
void Poussable::setEstPoussable(bool estPoussable)
{
    m_estPoussable = estPoussable;
}

#include "Poussable.h"

///Bloc Poussable
//Constructeur surchargé
Poussable::Poussable(int posX, int posY, char type,bool estPoussableblocmere,bool estCassableblocmere,bool estPoussable) : Bloc(posX,posY,type,estPoussableblocmere,estCassableblocmere)
{
    m_pos_x = posX;
    m_pos_y = posY;
    m_type = type;
    m_estPoussableblocmere = estPoussableblocmere;
    m_estCassableblocmere = estCassableblocmere;
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

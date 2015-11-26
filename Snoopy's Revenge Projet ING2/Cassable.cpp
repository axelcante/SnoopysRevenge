#include "Cassable.h"

///Bloc Cassable
Cassable::Cassable(int posX, int posY, char type,bool estPoussableblocmere,bool estPiege) : Bloc(posX,posY,type,estPoussableblocmere)
{
    m_pos_x = posX;
    m_pos_y = posY;
    m_type = type;
    m_estPoussableblocmere = estPoussableblocmere;
    m_estPiege = estPiege; //Savoir s'il est piégé ou pas
}
//Destructeur
Cassable::~Cassable() {}
//getters
bool Cassable::getEstPiege()const
{
    return m_estPiege;
}
//setters
void Cassable::setEstPiege(bool estPiege)
{
    m_estPiege = estPiege;
}

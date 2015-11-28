#include "Piege.h"

///Bloc qui tue
//constructeur surchargé
Piege::Piege(int posX, int posY, char type,bool estPoussableblocmere) : Bloc(posX,posY,type,estPoussableblocmere)
{
    m_pos_x = posX;
    m_pos_y = posY;
    m_type = type;
    m_estPoussableblocmere = estPoussableblocmere;
}

//destructeur
Piege::~Piege() {}


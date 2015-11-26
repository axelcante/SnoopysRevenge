#include "Balle.h"

///Bloc Balle
//Initialisation : Constructeur surchargé
Balle::Balle(int posX, int posY, char type,bool estPoussableblocmere) : Bloc(posX,posY,type,estPoussableblocmere)
{
    m_pos_x = posX;
    m_pos_y = posY;
    m_type = type;
    m_estPoussableblocmere = estPoussableblocmere;
}
Balle::~Balle() {}

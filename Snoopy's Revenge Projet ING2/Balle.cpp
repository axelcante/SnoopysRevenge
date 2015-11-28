#include "Balle.h"

///Bloc Balle
//Initialisation : Constructeur surchargé
Balle::Balle(int posX, int posY, char type,bool estPoussableblocmere,bool estCassableblocmere) : Bloc(posX,posY,type,estPoussableblocmere,estCassableblocmere)
{
    m_pos_x = posX;
    m_pos_y = posY;
    m_type = type;
    m_estPoussableblocmere = estPoussableblocmere;
    m_estCassableblocmere = estCassableblocmere;
}
Balle::~Balle() {}

#include "console.h"
#include "Bloc.h"


///Bloc : classe mère
//Constructeur par défaut
Bloc::Bloc() {}
//constructeur surchargé
Bloc::Bloc(int posX, int posY, char type,bool estPoussableblocmere,bool estCassableblocmere)
{
    m_pos_x = posX;
    m_pos_y = posY;
    m_type = type;
    m_estPoussableblocmere = estPoussableblocmere;
    m_estCassableblocmere = estCassableblocmere;
}

//destructeur
Bloc::~Bloc() {}

//getters
int Bloc::getPosX()const
{
    return m_pos_x;
}
int Bloc::getPosY()const
{
    return m_pos_y;
}
char Bloc::getType()const
{
    return m_type;
}
bool Bloc::getEstPoussableblocmere()const
{
    return m_estPoussableblocmere;
}
bool Bloc::getEstCassableblocmere()const
{
    return m_estCassableblocmere;
}

//setters
void Bloc::setPosX(int posX)
{
    m_pos_x = posX;
}
void Bloc::setPosY(int posY)
{
    m_pos_y = posY;
}
void Bloc::setType(char type)
{
    m_type = type;
}
void Bloc::setEstPoussableblocmere(bool estPoussableblocmere)
{
    m_estPoussableblocmere = estPoussableblocmere;
}
void Bloc::setEstCassableblocmere(bool estCassableblocmere)
{
    m_estPoussableblocmere = estCassableblocmere;
}

#include <iostream>
#include "Poussable.h"
#include "Bloc.h"

//constructeur surcharg�
Poussable::Poussable(int posX, int posY, char type, bool estPoussable) : Bloc(posX, posY, type), m_estPoussable(estPoussable)
{
}

//destructeur
Poussable::~Poussable()
{
}

//getters
bool Poussable::getEstPoussable(){return m_estPoussable;}

//setters
void Poussable::setEstPoussable(bool estPoussable)
{
    m_estPoussable = estPoussable;
}

//m�thodes
/*void Poussable::bougerBlocPoussable(int posX, int posY)
{
}*/

#include <iostream>
#include "Cassable.h"
#include "Bloc.h"

Cassable::Cassable(int posX, int posY, char type) : Bloc(posX, posY, type)
{
    m_pos_x = posX;
    m_pos_y = posY;
    m_type = type;
}

Cassable::~Cassable()
{
}

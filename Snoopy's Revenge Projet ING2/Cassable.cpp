#include "Cassable.h"

///Bloc Cassable
//Constructeur surchargé
Cassable::Cassable(int posX, int posY, char type,bool estPoussableblocmere,bool estCassableblocmere,bool estCassable) : Bloc(posX,posY,type,estPoussableblocmere,estCassableblocmere)
{
    m_pos_x = posX;
    m_pos_y = posY;
    m_type = type;
    m_estPoussableblocmere = estPoussableblocmere;
    m_estCassableblocmere = estCassableblocmere;
    m_estCassable = estCassable; //nous n'avons pas su accéder à cet attribut unique de la classe fille cassable (idem pour poussable) car nous utilisons une matrice de Bloc sans polymorphisme.
                                //Le compilateur ne nous autorise donc pas a utiliser cette varibale !
}
//Destructeur
Cassable::~Cassable() {}
//getters
bool Cassable::getEstCassable()const
{
    return m_estCassable;
}
//setters
void Cassable::setEstCassable(bool estCassable)
{
    m_estCassable = estCassable;
}

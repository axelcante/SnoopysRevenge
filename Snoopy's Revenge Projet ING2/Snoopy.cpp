#include "Snoopy.h"

///Bloc Snoopy
//Initialisation: constructeurs & Destructeurs
//constructeur surchargé
Snoopy::Snoopy(int posX, int posY, char type,bool estPoussableblocmere,int vies,int score,int oiseaux) : Bloc(posX,posY,type,estPoussableblocmere)
{
    m_pos_x = posX;
    m_pos_y = posY;
    m_type = type;
    m_estPoussableblocmere = estPoussableblocmere;
    m_vies=vies;
    m_score=score;
    m_oiseaux=oiseaux;

}

//Destructeur unique
Snoopy::~Snoopy() {}

//Méthodes

//Accesseurs
//Getters
int Snoopy::getVies() const
{
    return m_vies;
}
int Snoopy::getScore() const
{
    return m_score;
}
int Snoopy::getOiseaux() const
{
    return m_oiseaux;
}

//Setters
void Snoopy::setVies(int vies)
{
    m_vies=vies;
}
void Snoopy::setScore(int score)
{
    m_score=score;
}
void Snoopy::setOiseaux(int oiseaux)
{
    m_oiseaux=oiseaux;
}

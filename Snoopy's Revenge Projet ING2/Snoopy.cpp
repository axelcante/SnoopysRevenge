#include "Snoopy.h"

///Initialisation: constructeurs & Destructeurs
//Par défaut
Snoopy::Snoopy() {}
//Surchargé
Snoopy::Snoopy(int posx,int posy,int vies,int score,int oiseaux)
    :m_pos_x(posx), m_pos_y(posy),m_vies(vies),m_score(score),m_oiseaux(oiseaux) {}
//Destructeur unique
Snoopy::~Snoopy() {}

///Méthodes
/*    void moveSnoopy();
    void breakBlock();
    void saveGame();
    void loadGame();
*/

///Accesseurs
//Getters
int Snoopy::getPosX() const
{
    return m_pos_x;
}
int Snoopy::getPosY() const
{
    return m_pos_y;
}
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
void setPosX(int posX)
{
    m_pos_x=posX;
}
void setPosY(int posY)
{
    m_pos_y=posY;
}
void setVies(int vies)
{
    m_vies=vies;
}
void setScore(int score)
{
    m_score=score;
}
void setOiseaux(int oiseaux)
{
    m_oiseaux=oiseaux;
}

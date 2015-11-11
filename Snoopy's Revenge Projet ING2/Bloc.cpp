#include <iostream>
#include "Bloc.h"

///Bloc : classe mère
//constructeur surchargé
Bloc::Bloc(int posX, int posY, char type)
{
    m_pos_x = posX;
    m_pos_y = posY;
    m_type = type;
}

//destructeur
Bloc::~Bloc(){}

//getters
int Bloc::getPosX()const{return m_pos_x;}
int Bloc::getPosY()const{return m_pos_y;}
char Bloc::getType()const{return m_type;}

//setters
void Bloc::setPosX(int posX){m_pos_x = posX;}
void Bloc::setPosY(int posY){m_pos_y = posY;}
void Bloc::setType(char type){m_type = type;}

///Bloc Cassable
Cassable::Cassable(int posX, int posY, char type) : Bloc(posX, posY, type)
{
    m_pos_x = posX;
    m_pos_y = posY;
    m_type = type;
}
//Destructeur
Cassable::~Cassable(){}

///Bloc Poussable
//constructeur surchargé
Poussable::Poussable(int posX, int posY, char type, bool estPoussable) : Bloc(posX, posY, type)
{
    m_pos_x = posX;
    m_pos_y = posY;
    m_type = type;
    m_estPoussable = estPoussable;
}

//destructeur
Poussable::~Poussable(){}

//getters
bool Poussable::getEstPoussable()const{return m_estPoussable;}

//setters
void Poussable::setEstPoussable(bool estPoussable)
{
    m_estPoussable = estPoussable;
}

///Bloc vide
//Constructeur surchargé
Vide::Vide(int posX, int posY, char type) : Bloc(posX, posY, type)
{
    m_pos_x = posX;
    m_pos_y = posY;
    m_type = type;
}

//Destructeur
Vide::~Vide(){}


///Bloc Snoopy
//Initialisation: constructeurs & Destructeurs
//Par défaut
Snoopy::Snoopy() {}
//Destructeur unique
Snoopy::~Snoopy() {}

//Méthodes
/*    void moveSnoopy();
    void breakbloc(Bloc &bloc);
    void saveGame();
    void loadGame();
*/

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

#include "console.h"
#include "Bloc.h"


///Bloc : classe m�re
//Constructeur par d�faut
Bloc::Bloc(){}
//constructeur surcharg�
Bloc::Bloc(int posX, int posY, char type,bool estPoussableblocmere)
{
    m_pos_x = posX;
    m_pos_y = posY;
    m_type = type;
    m_estPoussableblocmere = estPoussableblocmere;
}

//destructeur
Bloc::~Bloc(){}

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

///----------------------------------------------------------------
///Bloc Cassable
Cassable::Cassable(int posX, int posY, char type,bool estPoussableblocmere,bool estPiege) : Bloc(posX,posY, type,estPoussableblocmere)
{
    m_pos_x = posX;
    m_pos_y = posY;
    m_type = type;
    m_estPoussableblocmere = estPoussableblocmere;
    m_estPiege = estPiege; //Savoir s'il est pi�g� ou pas
}
//Destructeur
Cassable::~Cassable() {}
//getters
bool Cassable::getEstPiege()const
{
    return m_estPiege;
}
//setters
void Cassable::setEstPiege(bool estPiege)
{
    m_estPiege = estPiege;
}

///----------------------------------------------------------------
///Bloc Poussable
//constructeur surcharg�
Poussable::Poussable(int posX, int posY, char type,bool estPoussableblocmere,bool estPoussable) : Bloc(posX,posY,type,estPoussableblocmere)
{
    m_pos_x = posX;
    m_pos_y = posY;
    m_type = type;
    m_estPoussableblocmere = estPoussableblocmere;
    m_estPoussable = estPoussable;
}

//destructeur
Poussable::~Poussable() {}

//getters
bool Poussable::getEstPoussable()const
{
    return m_estPoussable;
}

//setters
void Poussable::setEstPoussable(bool estPoussable)
{
    m_estPoussable = estPoussable;
}

//M�thodes


///----------------------------------------------------------------
///Bloc Snoopy
//Initialisation: constructeurs & Destructeurs
//constructeur surcharg�
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

//M�thodes

/*  void moveSnoopy();
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

///----------------------------------------------------------------
///Bloc Balle
//Initialisation : Constructeur surcharg�
Balle::Balle(int posX, int posY, char type,bool estPoussableblocmere) : Bloc(posX,posY,type,estPoussableblocmere)
{
    m_pos_x = posX;
    m_pos_y = posY;
    m_type = type;
    m_estPoussableblocmere = estPoussableblocmere;
}
Balle::~Balle(){}

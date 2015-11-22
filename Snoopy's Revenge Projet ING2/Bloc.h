#ifndef BLOC_H_INCLUDED
#define BLOC_H_INCLUDED
#include <iostream>
#include "console.h"

///Classe mère : one bloc to rule them all...
class Bloc
{
protected:
    int m_pos_x;
    int m_pos_y;
    char m_type; //cet attribut permet de choisir quel type de bloc nous voulons créer
    bool m_estPoussableblocmere;

public:
    //constructeur par défaut
    Bloc();
    //constructeur surchargé
    Bloc(int posX, int posY, char type, bool estPoussableblocmere);
    //destructeur
    ~Bloc();
    //getters
    int getPosX()const;
    int getPosY()const;
    char getType()const;
    bool getEstPoussableblocmere()const;
    //setters
    void setPosX(int posX);
    void setPosY(int posY);
    void setType(char type);
    void setEstPoussableblocmere(bool estPoussableblocmere);
};

///----------------------------------------------------------------
///Bloc que Snoopy pourra casser
class Cassable : public Bloc
{
private :
    bool m_estPiege;
public:
    //constructeur surchargé
    Cassable(int posX, int posY, char type,bool estPoussableblocmere,bool estPiege);
    //destructeur
    ~Cassable();
    //getters
    bool getEstPiege()const;
    //setters
    void setEstPiege(bool estPiege);
};

///----------------------------------------------------------------
///Bloc que Snoopy pourra pousser
class Poussable : public Bloc
{
private:
    bool m_estPoussable;
public:
    //constructeur surchargé
    Poussable(int posX, int posY, char type,bool estPoussableblocmere, bool estPoussable);
    //destructeur
    ~Poussable();
    //getters
    bool getEstPoussable()const;
    //setters
    void setEstPoussable(bool estPoussable);
    //méthodes (dans Snoopy ?)
};

///----------------------------------------------------------------
///Bloc Snoopy
class Snoopy : public Bloc
{
private :
    int m_vies;
    int m_score;
    int m_oiseaux;

public :
    //Constructeurs
    Snoopy(int posX, int posY, char type,bool estPoussableblocmere,int vies,int score,int oiseaux);
    //Destructeur
    ~Snoopy();
    //getters
    int getVies()const;
    int getScore()const;
    int getOiseaux()const;
//setters
    void setVies(int vies);
    void setScore(int score);
    void setOiseaux(int oiseaux);
    /* //Méthodes
       void moveSnoopy();
       void breakbloc(Bloc &bloc); ///
       void saveGame();
       void loadGame();*/
};

///-----------------------------------------------------
///Classe Balle
class Balle : public Bloc
{
public :
    //Constructeur surchargé
    Balle(int posX, int posY, char type,bool estPoussableblocmere);
    //Destructeur
    ~Balle();
    //Méthodes
};

#endif // BLOC_H_INCLUDED

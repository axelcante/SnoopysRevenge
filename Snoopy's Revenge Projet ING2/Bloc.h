#ifndef BLOC_H_INCLUDED
#define BLOC_H_INCLUDED
#include <iostream>
#include "console.h"

///Classe m�re : one block to rule them all...
class Bloc
{
protected:
    int m_pos_x;
    int m_pos_y;
    char m_type; //cet attribut permet de choisir quel type de bloc nous voulons cr�er
    bool m_estPoussableblocmere;
    /*bool m_estCassableblocmere;
    bool m_estPiegeblocmere;*/ ///Si on met �a dans BLOC, on n'a plus vraiment besoin de blocs filles, si ? sauf pour faire joli

public:
    //constructeur par d�faut
    Bloc();
    //constructeur surcharg�
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

#endif // BLOC_H_INCLUDED

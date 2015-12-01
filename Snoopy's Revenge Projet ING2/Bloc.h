#ifndef BLOC_H_INCLUDED
#define BLOC_H_INCLUDED
#include <iostream>
#include "console.h"

///Classe m�re : one block to rule them all...
///Les blocs n'ont pas de fonctions. Tout est g�r� par la Matrice (et, dans une moindre mesure, par le Niveau). Ils ne servent qu'a fragmenter le code et rendre le tout plus logique pour nous.
///En effet, on g�re une matrice de blocs. Tout objet manipul� est une classe fille de bloc (ou un bloc tout court :D).
class Bloc
{
protected:
    int m_pos_x;
    int m_pos_y;
    char m_type; //cet attribut permet de choisir quel type de bloc nous voulons cr�er
    bool m_estPoussableblocmere;
    bool m_estCassableblocmere;
    /*bool m_estCassableblocmere;
    bool m_estPiegeblocmere;*/ ///Si on met �a dans BLOC, on n'a plus vraiment besoin de blocs filles, si ? sauf pour faire joli

public:
    //constructeur par d�faut
    Bloc();
    //constructeur surcharg�
    Bloc(int posX, int posY, char type, bool estPoussableblocmere, bool estCassableblocmere);
    //destructeur
    ~Bloc();
    //getters
    int getPosX()const;
    int getPosY()const;
    char getType()const;
    bool getEstPoussableblocmere()const;        //Ce bool�en n'est mis true que pour les blocs de type Poussable. L'utilisation de ce bool�en s'est faite car nous n'utilisons pas de polymorphisme.
    bool getEstCassableblocmere()const;
    //setters
    void setPosX(int posX);
    void setPosY(int posY);
    void setType(char type);
    void setEstPoussableblocmere(bool estPoussableblocmere);
    void setEstCassableblocmere(bool estCassableblocmere);
};

#endif // BLOC_H_INCLUDED

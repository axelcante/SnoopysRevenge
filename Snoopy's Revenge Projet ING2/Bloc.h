#ifndef BLOC_H_INCLUDED
#define BLOC_H_INCLUDED
#include <iostream>
#include "console.h"

///Classe mère : one block to rule them all...
///Les blocs n'ont pas de fonctions. Tout est géré par la Matrice (et, dans une moindre mesure, par le Niveau). Ils ne servent qu'a fragmenter le code et rendre le tout plus logique pour nous.
///En effet, on gère une matrice de blocs. Tout objet manipulé est une classe fille de bloc (ou un bloc tout court :D).
class Bloc
{
protected:
    int m_pos_x;
    int m_pos_y;
    char m_type; //cet attribut permet de choisir quel type de bloc nous voulons créer
    bool m_estPoussableblocmere;
    bool m_estCassableblocmere;
    /*bool m_estCassableblocmere;
    bool m_estPiegeblocmere;*/ ///Si on met ça dans BLOC, on n'a plus vraiment besoin de blocs filles, si ? sauf pour faire joli

public:
    //constructeur par défaut
    Bloc();
    //constructeur surchargé
    Bloc(int posX, int posY, char type, bool estPoussableblocmere, bool estCassableblocmere);
    //destructeur
    ~Bloc();
    //getters
    int getPosX()const;
    int getPosY()const;
    char getType()const;
    bool getEstPoussableblocmere()const;        //Ce booléen n'est mis true que pour les blocs de type Poussable. L'utilisation de ce booléen s'est faite car nous n'utilisons pas de polymorphisme.
    bool getEstCassableblocmere()const;
    //setters
    void setPosX(int posX);
    void setPosY(int posY);
    void setType(char type);
    void setEstPoussableblocmere(bool estPoussableblocmere);
    void setEstCassableblocmere(bool estCassableblocmere);
};

#endif // BLOC_H_INCLUDED

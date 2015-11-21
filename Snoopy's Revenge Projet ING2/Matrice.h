#ifndef MATRICE_H_INCLUDED
#define MATRICE_H_INCLUDED
#include <vector>
#include <iostream>
#include <string>


#include "Bloc.h"

class Matrice
{

private :
    std::vector<std::vector<Bloc> > m_matrice;
    Balle m_balle = Balle(5,10,'B');

public :
    //constructeur
    Matrice();
    //getters
    std::vector<std::vector<Bloc> > getMatrice()const;
    Balle getBalle() const;
    //setters
    void setBloc(int posX, int posY, Bloc bloc);
    //methodes
    void initialisationMatrice();
    void afficherMatrice();
    void bougerBalle();
    //void changerBloc();
};

#endif // MATRICE_H_INCLUDED

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

public :
    //constructeur
    Matrice();
    //getters
    std::vector<std::vector<Bloc> > getMatrice()const;
    //setters

    std::vector<std::vector<Bloc> > getMatrice();

    //setters
    void setBloc(int posX, int posY, Bloc Bloc);
    //methodes
    void afficherMatrice();
    //void changerBloc();
};

#endif // MATRICE_H_INCLUDED

#ifndef MATRICE_H_INCLUDED
#define MATRICE_H_INCLUDED
#include "Bloc.h"
#include <vector>

class Matrice
{
private :
    std::vector<std::vector<Bloc> > m_matrice;

public :
    //constructeur
    Matrice();
    //getters
    std::vector<std::vector<Bloc> > getMatrice();
    //setters
    //void setMatrice(Bloc matrice);

    //methodes
    //Bloc construireMatrice();
    void afficherMatrice();
    //void changerBloc();
};

#endif // MATRICE_H_INCLUDED
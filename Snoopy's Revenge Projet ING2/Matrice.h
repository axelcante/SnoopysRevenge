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
    //constructeur par défaut
    Matrice();
    //constructeur surchargé
    Matrice(std::vector<std::vector<Bloc> > matrice);
    //destructeur
    ~Matrice();
    //getters
    std::vector<std::vector<Bloc> > getMatrice()const;
    //setters

    std::vector<std::vector<Bloc> > getMatrice();

    //setters
    void setBloc(int posX, int posY, Bloc Bloc);
    //methodes
    void afficherMatrice();
    //void changerBloc();
    //pousser
    void pousser(Console* conso, char& touche,Matrice* matrice, int& posXSnoopy, int& posYSnoopy);
};

#endif // MATRICE_H_INCLUDED

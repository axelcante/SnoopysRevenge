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
    Balle m_balle = Balle(5,10,'B',false);
    Bloc m_blocVide = Bloc(0,0,' ',false);
    Bloc m_Oiseau = Bloc(0,0,'O',false);
    Snoopy m_Snoopy = Snoopy(4,4,'S',false,0,0,0);
    Poussable m_blocPoussable = Poussable(0,0,'P',true,true);
    Bloc m_blocP = Bloc(0,0,'P',true);

public :
    //constructeur
    Matrice();
    //destructeur
    ~Matrice();
    //getters
    std::vector<std::vector<Bloc> > getMatrice()const;
    Balle getBalle() const;
    Poussable getBlocPoussable() const;
    Bloc getBlocP()const;
    //setters
    void setBloc(int posX, int posY, Bloc bloc);

    //methodes
    void initialisationMatrice();
    void afficherMatrice();
    void bougerBalle();
    //void changerBloc();
    //pousser
    void pousser(Console* conso, char& touche,Matrice* matrice, int& posXSnoopy, int& posYSnoopy);
};

#endif // MATRICE_H_INCLUDED

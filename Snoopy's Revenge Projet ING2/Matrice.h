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
    int m_decalage_X = 1, m_decalage_Y = 1;
    Balle m_balle = Balle(5,10,'B',false);
    Bloc m_blocVide = Bloc(0,0,' ',false);
    Bloc m_Oiseau = Bloc(0,0,'O',false);
    Bloc m_blocP = Bloc(0,0,'P',true);
    Snoopy m_Snoopy = Snoopy(4,4,'S',false,3,0,0);
    Poussable m_blocPoussable = Poussable(0,0,'P',true,true); //sert à rien pour le moment (?)


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
    int getDecalageX()const;
    int getDecalageY()const;
    //setters
    void setBloc(int posX, int posY, Bloc bloc);
    void setDecalageX(int);
    void setDecalageY(int);

    //methodes
    void initialisationMatrice();
    void afficherMatrice(Console* conso);
    void bougerElements(Console* conso);
    void bougerBalle();
    void bougerSnoopy(char& touche);
    //void changerBloc();
    //pousser
    void pousser(Console* conso, char& touche,Matrice* matrice, int& posXSnoopy, int& posYSnoopy);
};

#endif // MATRICE_H_INCLUDED

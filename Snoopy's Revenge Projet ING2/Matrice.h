#ifndef MATRICE_H_INCLUDED
#define MATRICE_H_INCLUDED
#include <vector>
#include <iostream>
#include <string>
#include <windows.h>
#include "Constantes.h"
#include "Bloc.h"
#include "Snoopy.h"
#include "Cassable.h"
#include "Balle.h"
#include "Poussable.h"
#include "Cassable.h"
#include "Piege.h"

///Matrice de blocs
class Matrice
{
private :
    std::vector<std::vector<Bloc> > m_matrice;
    int m_decalage_X = 1, m_decalage_Y = 1;
    char m_tableau_sauvegarde[N_LIGNES][N_COLONNES];
    Balle m_balle = Balle(BALLPOSX,BALLPOSY,'B',false,false); //On a C++11
    Bloc m_blocVide = Bloc(0,0,' ',false,false);
    Bloc m_Oiseau = Bloc(0,0,'O',false,false);
    Bloc m_blocP = Bloc(0,0,'P',true,false);
    Bloc m_blocT = Bloc(0,0,'T',false,false);
    Bloc m_blocC = Bloc(0,0,'C',false,true);
    Snoopy m_Snoopy = Snoopy(SNOOPYPOSX,SNOOPYPOSY,'S',false,false,3,0,0);
    Poussable m_blocPoussable = Poussable(0,0,'P',true,false,true); ///sert à rien pour le moment (?)
    double m_time;

public :
    //constructeur
    Matrice();

    //destructeur
    ~Matrice();

    //getters
    std::vector<std::vector<Bloc> > getMatrice()const;
    char getTableau()const;
    Balle getBalle() const;
    Poussable getBlocPoussable() const;
    Bloc getBlocP()const;
    Snoopy getSnoopy()const;
    int getDecalageX()const;
    int getDecalageY()const;
    float getTime()const;

    //setters
    void setBloc(int posX, int posY, Bloc bloc);
    void setDecalageX(int);
    void setDecalageY(int);
    void setTime(float);
    void setTableau(int);

    //methodes
    void initialisationMatrice(int& niv);
    void initialisationElements(int& niv);
    void afficherMatrice(Console* conso);
    void bougerElements(Console* conso,int& niv);
    bool bougerBalle();
    void afficherCadre(Console* conso);
    void bougerSnoopy(Console* conso,char& touche, bool& dead);
    bool pousser(Console* conso, char& touche);
    void casser(Console* conso, int& poslig, int& poscol);
    void ecranMort(Console* conso);
    void ecranVictoire(Console* conso);
    void traduireMatrice();
    void traduireTableau();
};

#endif // MATRICE_H_INCLUDED

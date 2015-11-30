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
    //Matrice de jeu
    std::vector<std::vector<Bloc> > m_matrice;
    //Décalages pour la balle
    int m_decalage_X = 1, m_decalage_Y = 1;
    //Création de blocs
    Balle m_balle = Balle(BALLPOSX,BALLPOSY,'B',false,false); //On a C++11
    Bloc m_blocVide = Bloc(0,0,' ',false,false);
    Bloc m_Oiseau = Bloc(0,0,'O',false,false);
    Bloc m_blocP = Bloc(0,0,'P',true,false);
    Bloc m_blocT = Bloc(0,0,'T',false,false);
    Bloc m_blocC = Bloc(0,0,'C',false,true);
    Snoopy m_Snoopy = Snoopy(SNOOPYPOSX,SNOOPYPOSY,'S',false,false,3,0,0);
    Poussable m_blocPoussable = Poussable(0,0,'P',true,false,true); ///sert à rien pour le moment (?)
    //Déclaration du temps
    double m_time;

public :

    //attribut public : tableau de sauvegarde
    char m_tableau_sauvegarde[N_LIGNES][N_COLONNES];

    //constructeur
    Matrice();

    //destructeur
    ~Matrice();

    ///Accesseurs
    //getters
    std::vector<std::vector<Bloc> > getMatrice()const;
    char getTableau()const;
    Balle getBalle() const;
    Poussable getBlocPoussable() const;
    Bloc getBlocP()const;
    Snoopy getSnoopy()const;
    int getDecalageX()const;
    int getDecalageY()const;
    double getTime()const;

    //setters
    void setBloc(int posX, int posY, Bloc bloc);
    void setDecalageX(int);
    void setDecalageY(int);
    void setTime(float);
    void setTableau(int);

    ///Méthodes
    //Initialisations
    void initialisationMatrice(int& niv); //Matrice de jeu
    void initialisationElements(int& niv); //Elements dans la matrice : blocs, perso
   //Affichage
    void afficherMatrice(Console* conso);
    void afficherCadre(Console* conso); //contour
    void ecranMort(Console* conso);
    void ecranVictoire(Console* conso,int& score);
    //Déplacements
    void bougerElements(Console* conso,int& niv,int& score);
    bool bougerBalle();
    void bougerSnoopy(Console* conso,char& touche, bool& dead,int& niv);
    //Actions
    bool pousser(Console* conso, char& touche); //Pousser les blocs
    void casser(Console* conso, int& poslig, int& poscol); //Casser les blocs
    void boomShakaLaka(Console* conso, int& poslig, int& poscol); //BOUUUM explosion
    //Pour la sauvegarde
    void traduireMatrice();
    void traduireTableau();
};

#endif // MATRICE_H_INCLUDED

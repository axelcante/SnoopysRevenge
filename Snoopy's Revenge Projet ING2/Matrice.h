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
    //D�calages pour le d�placement de la balle
    int m_decalage_X = 1, m_decalage_Y = 1;
    //On a C++11 pour pouvoir cr�er des objets directement dans le .h
    ///Cr�ation de blocs
    //ici on initialise tous les blocs utilis�s lors du jeu : balle, snoopy, bloc poussable, etc. TOUT dans notre matrice est un bloc, ou une classe fille de bloc
    Balle m_balle = Balle(BALLPOSX,BALLPOSY,'B',false,false);  //c'est la balle du jeu snoopy !
    Bloc m_blocVide = Bloc(0,0,' ',false,false);    //c'est le bloc vide qui initialise la matrice en d�but de partie/
    Bloc m_Oiseau = Bloc(0,0,'O',false,false);
    Bloc m_blocP = Bloc(0,0,'P',true,false);
    Bloc m_blocT = Bloc(0,0,'T',false,false);
    Bloc m_blocC = Bloc(0,0,'C',false,true);
    Snoopy m_Snoopy = Snoopy(SNOOPYPOSX,SNOOPYPOSY,'S',false,false,3,0,0);
    Poussable m_blocPoussable = Poussable(0,0,'P',true,false,true); ///sert � rien pour le moment (?)
    //D�claration du temps
    double m_time;

public :

    //attribut public : tableau de sauvegarde
    //Nous avons fais le choix de mettre cet attribut en public car il importe peu pour le reste du programme (uniquement pour chargement/sauvegarde). Ceci nous �vite de passer par les pointeurs
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

    ///M�thodes
    //Initialisations
    void initialisationMatrice(int& niv); //Matrice de jeu : initialise certains �l�ments en fonction du niveau (balle, blocs poussables, cassables, truqu�s...)
    void initialisationElements(int& niv); //Elements dans la matrice : blocs, perso
   //Affichage
    void afficherMatrice(Console* conso); //fonction simple qui r�cup�re la position de snoopy et de la balle ainsi que des blocs pour les afficher sur la console
    void afficherCadre(Console* conso); //contour
    void ecranMort(Console* conso); //�cran de d�faite
    void ecranVictoire(Console* conso,int& score); //�cran de victoire
    //D�placements
    void bougerElements(Console* conso,int& niv,int& score);    ///BOUCLE PRINCIPALE : c'est elle qui g�re le reste du jeu !
    bool bougerBalle(); //fonction qui bouge la balle d'une case en faisant une s�rie de tests sur les blocs alentours. LA BALLE REBONDIT SUR LES BLOCS
    void bougerSnoopy(Console* conso,char& touche, bool& dead,int& niv); //fonction de mouvement de Snoopy
    //Actions
    bool pousser(Console* conso, char& touche); //Pousser les blocs
    void casser(Console* conso, int& poslig, int& poscol); //Casser les blocs
    void boomShakaLaka(Console* conso, int& poslig, int& poscol); //BOUUUM explosion
    //Pour la sauvegarde
    void traduireMatrice(); //traduit la matrice de blocs en tableau 2D de char (on r�cup�re les types de blocs -> cf classe Bloc
    void traduireTableau(); //on r�cup�re un tableau 2D de chars et on initialise une matrice de blocs avec les types !
};

#endif // MATRICE_H_INCLUDED

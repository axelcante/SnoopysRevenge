#ifndef NIVEAU_H_INCLUDED
#define NIVEAU_H_INCLUDED
#include "Matrice.h"
#include "Bloc.h"
#include <fstream>

class Niveau
{
private :
    std::string m_mdp; //Mot de passe
    Matrice m_matriceDeJeu = Matrice();//c'est la matrice de jeu !

public :
    ///Constructeurs et destructeur
    Niveau();
    ~Niveau();
    ///Accesseurs
    //Getters
    std::string getMdp() const;

    //Setters
    void setMdp(std::string mdp);

    ///Methods
    void effetMenu(int choix, Console* conso); //méthode pour rendre le menu plus flashy
    int lancerJeu(Console* conso, int& niveaumdp, bool partie); //méthode qui lance véritablement la boucle de jeu. Fait la transition niveau ->main.cpp
    void afficherMenu(Console* conso);
    void play(Console* conso); //méthode qui permet de faire le pont main.cpp -> niveau
    int mdpNiveau(Console* conso);
    void readFile(std::string name, char tableau[N_LIGNES][N_COLONNES], int vies, int score, int oiseaux, int decalageX, int decalageY, int& niveau, Console* conso);
};



#endif // NIVEAU_H_INCLUDED

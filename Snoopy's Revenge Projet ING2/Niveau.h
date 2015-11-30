#ifndef NIVEAU_H_INCLUDED
#define NIVEAU_H_INCLUDED
#include "Matrice.h"
#include "Bloc.h"
#include <fstream>

class Niveau
{
private :
    std::string m_mdp; //Mot de passe
    char matrice_traduite[N_LIGNES][N_COLONNES];
    Matrice m_matriceDeJeu = Matrice();

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
    void effetMenu(int choix, Console* conso);
    int lancerJeu(Console* conso);
    void afficherMenu(Console* conso);
    void play(Console* conso);

    //passerNiveau();
    ///Idees Diedler en cours :
    //g�rer blocs  (pousser, casser ,..)
    //Deplacer (ennemis balle et snoopy) //Sauvergarder la position du Snoopy et Balle pour chargement ?
    ///METTRE LA SAUVEGARDE ICI ?
/*
    void saveGame();
    void loadGame();
*/

};



#endif // NIVEAU_H_INCLUDED

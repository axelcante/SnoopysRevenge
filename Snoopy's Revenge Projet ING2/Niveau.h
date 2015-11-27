#ifndef NIVEAU_H_INCLUDED
#define NIVEAU_H_INCLUDED
#include "Matrice.h"
#include <fstream>

class Niveau
{
private :
    float m_temps; //Pas dans matrice ça ? :0
    Matrice m_matriceDeJeu; //Avec ses caractéristiques spécifiques
    std::string m_mdp; //Mot de passe

public :
    ///Constructeurs et destructeur
    Niveau();
    ~Niveau();
    ///Accesseurs
    //Getters
    float getTemps() const;
    Matrice getMatrice() const;
    std::string getMdp() const;

    //Setters
    void setTemps(float temps);
    void setMatrice(Matrice matriceDeJeu);
    void setMdp(std::string mdp);

    ///Methods
    void effetMenu(int choix, Console* conso);
    int lancerJeu(Console* conso);
    void afficherMenu(Console* conso);
    void play(Console* conso);
    //std::string lireFichier(std::ifstream& Fichier);

    //passerNiveau();
    ///Idees Diedler en cours :
    //gérer blocs  (pousser, casser ,..)
    //Deplacer (ennemis balle et snoopy) //Sauvergarder la position du Snoopy et Balle pour chargement ?
    ///METTRE LA SAUVEGARDE ICI ?
/*
    void saveGame();
    void loadGame();
*/

};



#endif // NIVEAU_H_INCLUDED

#ifndef NIVEAU_H_INCLUDED
#define NIVEAU_H_INCLUDED
#include "Matrice.h"

class Niveau
{
private :
    float m_temps; //Pas dans matrice ça ? :0
    Matrice m_matriceDeJeu; //Avec ses caractéristiques spécifiques
    ///Idees Diedler en cours :
    //balle ennemis s'il y a
    //Snoopy

public :
    ///Constructeurs et destructeur
    Niveau();
    ~Niveau();
    ///Accesseurs
    //Getters
    float getTemps() const;
    Matrice getMatrice() const;

    //Setters
    void setTemps(float temps);
    void setMatrice(Matrice matriceDeJeu);

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

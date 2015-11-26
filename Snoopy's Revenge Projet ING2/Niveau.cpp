#include "Niveau.h"

///Niveau gère la partie
//Initialisation: constructeurs & Destructeurs
//Constructeur
Niveau::Niveau(){};
//Desctruteur
Niveau::~Niveau(){};

//Méthodes

//Accesseurs
    float Niveau::getTemps() const
    {
        return m_temps;
    }
    Matrice Niveau::getMatrice() const
    {
        return m_matriceDeJeu;
    }
    std::string Niveau::getMdp() const
    {
        return m_mdp;
    }

    //Setters
    void Niveau::setTemps(float temps)
    {
        m_temps = temps;
    }
    void Niveau::setMatrice(Matrice matriceDeJeu)
    {
        m_matriceDeJeu = matriceDeJeu;
    }
    void Niveau::setMdp(std::string mdp)
    {
        m_mdp = mdp;
    }

#include <iostream>
#include <vector>
#include "Constantes.h"
#include "Matrice.h"
#include "console.h"
#include "Bloc.h"

//constructeur
Matrice::Matrice()
{
<<<<<<< HEAD
    Bloc blocVide =  Bloc(0,0,'P');
=======
    Bloc blocVide =  Bloc(0,0,' ');
    Balle Balle = Balle(10,5,'B') : Bloc(10,5,'B');
>>>>>>> 483f22727128a3bce1355375e30a13c93d9650d1
    std::vector<Bloc>column;
    for (int i = 0; i < N_COLONNES; i++)
    {
        column.push_back(blocVide);
    }
    for (int i = 0; i < N_LIGNES; i++)
    {
        m_matrice.push_back(column);
    }
    m_matrice[Balle.getPosX()][Balle.getPosY()] = Balle;
}

//getters
std::vector<std::vector<Bloc> > Matrice::getMatrice() const
{
    return m_matrice;
}


//Methodes
/*Bloc Matrice::construireMatrice()
{
    std::vector <Bloc> mat_jeu;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            mat_jeu.push_back(Vide blocVide Vide(0, 0, ' ');
        }
    }
    return mat_jeu;
}*/

void Matrice::afficherMatrice()
{
    for (int i = 0; i < N_LIGNES; i++)
    {
        for (int j = 0; j < N_COLONNES; j++)
        {
            std::cout << '|' << m_matrice[i][j].getType();
        }
        std::cout <<"|\n";
    }
}

#include <iostream>
#include <vector>
#include "Constantes.h"
#include "Matrice.h"
#include "console.h"
#include "Bloc.h"

//constructeur intialisant les positions de la Balle et de Snoopy (?)
Matrice::Matrice()
{
<<<<<<< HEAD
    Bloc blocVide =  Bloc(0,0,'P');
=======
    Bloc blocVide =  Bloc(0,0,' ');
<<<<<<< HEAD
    Balle Balle = Balle(10,5,'B') : Bloc(10,5,'B');
>>>>>>> 483f22727128a3bce1355375e30a13c93d9650d1
=======
    Balle Balle(5,9,'B');
    Bloc Oiseau(0,0,'O');
    //Balle& refBalle = Balle;
>>>>>>> 5a2bfd08d2996de1bf3af315bd8e4bb8ea674023
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
    m_matrice[0][0] = Oiseau;
    m_matrice[9][19] = Oiseau;
    m_matrice[9][0] = Oiseau;
    m_matrice[0][19] = Oiseau;
}

//getters
std::vector<std::vector<Bloc> > Matrice::getMatrice() const
{
    return m_matrice;
}

<<<<<<< HEAD
=======
//setters
//Permet de modifier manuellement un bloc de la matrice
void Matrice::setBloc(int posX, int posY, Bloc Bloc)
{
    m_matrice[posX][posY] = Bloc;
}
>>>>>>> 5a2bfd08d2996de1bf3af315bd8e4bb8ea674023

//Methodes

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

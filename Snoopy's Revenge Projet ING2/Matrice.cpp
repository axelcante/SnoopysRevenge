#include <iostream>
#include <vector>
#include "Constantes.h"
#include "Matrice.h"
#include "console.h"
#include "Bloc.h"

//constructeur intialisant les positions de la Balle et de Snoopy (?)
Matrice::Matrice()
{
    Bloc blocVide =  Bloc(0,0,' ');
    Balle balle(5,9,'B');
    Balle& ref_Balle = balle;
    Bloc Oiseau(0,0,'O');
    std::vector<Bloc>column;
    for (int i = 0; i < N_COLONNES; i++)
    {
        column.push_back(blocVide);
    }
    for (int i = 0; i < N_LIGNES; i++)
    {
        m_matrice.push_back(column);
    }
    m_matrice[balle.getPosX()][balle.getPosY()] = balle;
    m_matrice[0][0] = Oiseau;
    m_matrice[9][19] = Oiseau;
    m_matrice[9][0] = Oiseau;
    m_matrice[0][19] = Oiseau;
}

//getters
std::vector<std::vector<Bloc> > Matrice::getMatrice()
{
    return m_matrice;
}

//setters
//Permet de modifier manuellement un bloc de la matrice
void Matrice::setBloc(int posX, int posY, Bloc Bloc)
{
    m_matrice[posX][posY] = Bloc;
}

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

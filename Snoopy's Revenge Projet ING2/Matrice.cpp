#include "Constantes.h"
#include "Matrice.h"
#include "Bloc.h"

//constructeur intialisant les positions de la Balle et de Snoopy (?)
Matrice::Matrice()
{
    /*Bloc Oiseau1(0,0,'O');
    Bloc Oiseau2(9,19,'O');
    Bloc Oiseau3(9,0,'O');
    Bloc Oiseau4(0,19,'O');
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
    m_matrice[Oiseau1.getPosX()][Oiseau2.getPosY()] = Oiseau1;
    m_matrice[Oiseau2.getPosX()][Oiseau2.getPosY()] = Oiseau2;
    m_matrice[Oiseau3.getPosX()][Oiseau3.getPosY()] = Oiseau3;
    m_matrice[Oiseau3.getPosX()][Oiseau3.getPosY()] = Oiseau4;*/
}

//getters
std::vector<std::vector<Bloc> > Matrice::getMatrice() const
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

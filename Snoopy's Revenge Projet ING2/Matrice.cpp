#include <iostream>
#include <vector>
#include "Matrice.h"

//constructeur
Matrice::Matrice()
{
    Bloc blocVide =  Bloc(0,0,'C');
    std::vector<Bloc>column;
    for (int i = 0; i < 20; i++)
        {
            column.push_back(blocVide);
        }
    for (int i = 0; i < 10; i++)
        {
            m_matrice.push_back(column);
        }
}

//getters
std::vector<std::vector<Bloc> > Matrice::getMatrice()
{
    return m_matrice;
}

//setters
//Do we need one ?

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
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            std::cout << '|' << m_matrice[i][j].getType();
        }
        std::cout <<"|\n";
    }
}

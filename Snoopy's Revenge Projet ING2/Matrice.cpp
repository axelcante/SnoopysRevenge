#include "Constantes.h"
#include "Matrice.h"
#include "Bloc.h"

//constructeur
Matrice::Matrice() {}

//desctructeur unique
Matrice::~Matrice() {}

//getters
std::vector<std::vector<Bloc> > Matrice::getMatrice() const
{
    return m_matrice;
}

Balle Matrice::getBalle() const
{
    return m_balle;
}
Poussable Matrice::getBlocPoussable()const
{
    return m_blocPoussable;
}
Bloc Matrice::getBlocP()const
{
    return m_blocP;
}

//setters
//Permet de modifier manuellement un bloc de la matrice
void Matrice::setBloc(int posX, int posY, Bloc bloc)
{
    m_matrice[posX][posY] = bloc;
}

///Methodes
//Cette méthode initialise les oiseaux
void Matrice::initialisationMatrice()
{
    std::vector<Bloc>column;
    for (int i = 0; i < N_COLONNES; i++)
    {
        column.push_back(m_blocVide);
    }
    for (int i = 0; i < N_LIGNES; i++)
    {
        m_matrice.push_back(column);
    }
    //Oiseaux
    m_matrice[0][0] = m_Oiseau;
    m_matrice[0][19] = m_Oiseau;
    m_matrice[9][0] = m_Oiseau;
    m_matrice[9][19] = m_Oiseau;
    //Balle position initiale
    m_matrice[m_balle.getPosX()][m_balle.getPosY()] = m_balle;
    //Blocs poussables
    m_matrice[6][12] = m_blocPoussable;
    m_matrice[3][7] = m_blocPoussable;

}

void Matrice::afficherMatrice(Console* conso)
{
    conso->gotoLigCol(5,10);
    int lignes=0;
    for (int i = 0; i < N_LIGNES; i++)
    {
        for (int j = 0; j < N_COLONNES; j++)
        {
            std::cout << '|' << m_matrice[i][j].getType();
        }

        std::cout <<"|";
        lignes++;
        conso->gotoLigCol(5+lignes,10);
    }
}

void Matrice::bougerBalle()
{
    m_matrice[m_balle.getPosX()][m_balle.getPosY()] = m_blocVide;
    int decalage_X = 1, decalage_Y = 1;
    m_balle.setPosX(m_balle.getPosX()+decalage_X);
    m_balle.setPosY(m_balle.getPosY()+decalage_Y);
    if(m_balle.getPosX() == 19 || m_balle.getPosX() == 0)
    {
        decalage_X *= -1;
    }
    if(m_balle.getPosY() == 9 || m_balle.getPosY() == 0)
    {
        decalage_Y *= -1;
    }
    m_matrice[m_balle.getPosX()][m_balle.getPosY()] = m_balle;
}

void Matrice::pousser(Console* conso, char& touche, Matrice* matrice,int& posXSnoopy, int& posYSnoopy)
{
    /****
    /// Supposé fait :
    ///     touche=conso->getInputKey(); // Touche récupéréé
    ///     Vérifier que le "bloc" soit bien poussable AVANT de "pousser"
    ****/

    //Déclaration de variables
    int i=posXSnoopy,j=posYSnoopy;

    switch(touche)
    {
    ///Chez nous, Snoopy bouge en même temps que la bloc poussable
    case '2': ///Pousser "bloc" vers le bas
        //Vérification que bloc poussable faite AVANT "pousser"
        if(m_matrice[i+1][j].getEstPoussableblocmere()==true)
        {
            if((i+2)<=N_LIGNES) //Pas sortir de la matrice
            {
                m_matrice[i][j]=m_blocVide;
                m_matrice[i+1][j]=m_Snoopy;
                m_matrice[i+2][j]=m_blocPoussable;
                ///Rendre ce bloc 'P' non-poussable
                m_matrice[i+2][j].setEstPoussableblocmere(false);
            }
        }
        break;
    case '4':///Pousser "bloc" vers gauche
        //Vérification que bloc poussable faite AVANT "pousser"
        if(m_matrice[i][j-1].getEstPoussableblocmere()==true)
        {
            if((j-2)>=0) //Pas sortir de la matrice
            {
                m_matrice[i][j]=m_blocVide;
                m_matrice[i][j-1]=m_Snoopy;
                m_matrice[i][j-2]=m_blocPoussable;
                ///Rendre ce bloc 'P' non-poussable
                m_matrice[i][j-2].setEstPoussableblocmere(false);
            }
        }
        break;
    case '6':///Pousser "bloc" vers droite
        //Vérification que bloc poussable faite AVANT "pousser"
        if(m_matrice[i][j+1].getEstPoussableblocmere()==true)
        {

            if((j+2)<=N_COLONNES) //Pas sortir de la matrice
            {
                m_matrice[i][j]=m_blocVide;
                m_matrice[i][j+1]=m_Snoopy;
                m_matrice[i][j+2]=m_blocPoussable;
                ///Rendre ce bloc 'P' non-poussable
                m_matrice[i][j+2].setEstPoussableblocmere(false);
            }
        }
        break;
    case '8':///Pousser "bloc" vers haut
        //Vérification que bloc poussable faite AVANT "pousser"
        if(m_matrice[i-1][j].getEstPoussableblocmere()==true)
        {

            if((i-2)>=0) //Pas sortir de la matrice
            {
                m_matrice[i][j]=m_blocVide;
                m_matrice[i-1][j]=m_Snoopy;
                m_matrice[i-2][j]=m_blocPoussable;
                ///Rendre ce bloc 'P' non-poussable
                m_matrice[i-2][j].setEstPoussableblocmere(false);
            }
        }
        break;
    case 's': //sauver la partie
        break;
    }
}

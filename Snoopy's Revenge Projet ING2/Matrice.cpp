#include "Constantes.h"
#include "Matrice.h"
#include "Bloc.h"

//constructeur
Matrice::Matrice(){}

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
    Bloc oiseau1(0,0,'O');
    Bloc oiseau2(0,19,'O');
    Bloc oiseau3(9,0,'O');
    Bloc oiseau4(9,19,'O');
    Bloc blocVide(0,0,' ');

    std::vector<Bloc>column;
    for (int i = 0; i < N_COLONNES; i++)
    {
        column.push_back(blocVide);
    }
    for (int i = 0; i < N_LIGNES; i++)
    {
        m_matrice.push_back(column);
    }
    m_matrice[oiseau1.getPosX()][oiseau1.getPosY()] = oiseau1;
    m_matrice[oiseau2.getPosX()][oiseau2.getPosY()] = oiseau2;
    m_matrice[oiseau3.getPosX()][oiseau3.getPosY()] = oiseau3;
    m_matrice[oiseau4.getPosX()][oiseau4.getPosY()] = oiseau4;
    m_matrice[m_balle.getPosX()][m_balle.getPosY()] = m_balle;
}

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

void Matrice::bougerBalle()
{
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
}

void Matrice::pousser(Console* conso, char& touche, Matrice* matrice,int& posXSnoopy, int& posYSnoopy)
{
    /****
    /// touche=conso->getInputKey(); //en commentaire car supposée déjà faite
    ///saisie de la touche appuyée par le joueur faite AVANT "pousser", touche récupérée
    ****/
    ///Vérification que bloc poussable faite AVANT "pousser"
    //Déclaration de variables
    int i=posXSnoopy,j=posYSnoopy;
    switch(touche)//
    {
    ///Chez nous, Snoopy bouge en même temps que la bloc poussable
    case '2': //pousser "bloc" vers le bas
        if((i+2)<=N_LIGNES) //Pas sortir de la matrice
        {
            matrice->getMatrice()[i][j].setType('V');
            matrice->getMatrice()[i+1][j].setType('S');
            matrice->getMatrice()[i+2][j].setType('P');
            //Rendre ce bloc 'P' non-poussable
            /// matrice->getMatrice()[i+2][j].setEstPoussable(false);
        }
        break;
    case '4'://pousser "bloc" vers gauche
        if((j-2)>=0) //Pas sortir de la matrice
        {
            matrice->getMatrice()[i][j].setType('V');
            matrice->getMatrice()[i][j-1].setType('S');
            matrice->getMatrice()[i][j-2].setType('P');
            //Rendre ce bloc 'P' non-poussable
            /// matrice->getMatrice()[i][j-2].setEstPoussable(false);
        }
        break;
    case '6'://pousser "bloc" vers droite
        if((j+2)<=N_COLONNES) //Pas sortir de la matrice
        {
            matrice->getMatrice()[i][j].setType('V');
            matrice->getMatrice()[i][j+1].setType('S');
            matrice->getMatrice()[i][j+2].setType('P');
            //Rendre ce bloc 'P' non-poussable
            /// matrice->getMatrice()[i][j+2].setEstPoussable(false);
        }
        break;
    case '8'://Pousser "bloc" vers haut
        if((i-2)>=0) //Pas sortir de la matrice
        {
            matrice->getMatrice()[i][j].setType('V');
            matrice->getMatrice()[i-1][j].setType('S');
            matrice->getMatrice()[i-2][j].setType('P');
            //Rendre ce bloc 'P' non-poussable
            /// matrice->getMatrice()[i-2][j].setEstPoussable(false);
        }
        break;
    case 's': //sauver la partie
        break;
    }
}

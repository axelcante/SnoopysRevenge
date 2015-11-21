#include "Constantes.h"
#include "Matrice.h"
#include "Bloc.h"

//constructeur intialisant les positions de la Balle et de Snoopy (?)
Matrice::Matrice()
{
<<<<<<< HEAD
    /*
    Bloc blocPoussable(0,0,'P');
    Bloc blocVide(0,0,' ');
    Balle balle(10,5,'B');
    Bloc Oiseau(0,0,'O');
=======
    /*Bloc Oiseau1(0,0,'O');
    Bloc Oiseau2(9,19,'O');
    Bloc Oiseau3(9,0,'O');
    Bloc Oiseau4(0,19,'O');
>>>>>>> 14fb0b17d377e13a26fb3b8d489e829acde339fc
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
<<<<<<< HEAD
    m_matrice[0][0] = Oiseau;
    m_matrice[9][19] = Oiseau;
    m_matrice[9][0] = Oiseau;
    m_matrice[0][19] = Oiseau;*/
}

//Constructeur surchargé
Matrice::Matrice(std::vector<std::vector<Bloc> > matrice)
{
    m_matrice=matrice;
=======
    m_matrice[Oiseau1.getPosX()][Oiseau2.getPosY()] = Oiseau1;
    m_matrice[Oiseau2.getPosX()][Oiseau2.getPosY()] = Oiseau2;
    m_matrice[Oiseau3.getPosX()][Oiseau3.getPosY()] = Oiseau3;
    m_matrice[Oiseau3.getPosX()][Oiseau3.getPosY()] = Oiseau4;*/
>>>>>>> 14fb0b17d377e13a26fb3b8d489e829acde339fc
}
//desctructeur unique
Matrice::~Matrice() {}

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

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
    m_matrice[0][0] = m_Oiseau;
    m_matrice[9][19] = m_Oiseau;
    m_matrice[0][19] = m_Oiseau;
    m_matrice[9][0] = m_Oiseau;
    m_matrice[m_balle.getPosX()][m_balle.getPosY()] = m_balle;
}

void Matrice::afficherMatrice(Console* conso)
{
    conso->gotoLigCol(5,10);
    int lignes = 0;
    for (int i = 0; i < N_LIGNES; i++)
    {
        for (int j = 0; j < N_COLONNES; j++)
        {
            /*if (m_matrice[i][j] == m_balle)
            {
                conso->setColor(COLOR_RED);
            }*/
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
    int decalage_X = -1, decalage_Y = 1;
    if(m_balle.getPosX()==19 || m_balle.getPosX()==0)
    {
        decalage_X *= -1;
    }
    if(m_balle.getPosY() == 9 || m_balle.getPosY() == 0)
    {
        decalage_Y *= -1;
    }
    m_balle.setPosX(m_balle.getPosX()+decalage_X);
    m_balle.setPosY(m_balle.getPosY()+decalage_Y);
    std::cout << decalage_X << decalage_Y;
    m_matrice[m_balle.getPosX()][m_balle.getPosY()] = m_balle;
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
    // std::vector<Bloc*> bb;
    //bb.push_back(new Poussable);
    //bb.push_back(new Poussable);

    switch(touche)//
    {
    ///Chez nous, Snoopy bouge en même temps que la bloc poussable
    case '2': //pousser "bloc" vers le bas
        if((i+2)<=N_LIGNES) //Pas sortir de la matrice
        {
            m_matrice[i][j]=m_blocVide;
            m_matrice[i+1][j]=m_Snoopy;
            m_matrice[i+2][j]=m_blocPoussable;
            /* matrice->getMatrice()[i][j].setType('V');
             matrice->getMatrice()[i+1][j].setType('S');
             matrice->getMatrice()[i+2][j].setType('P');*/
            ///Rendre ce bloc 'P' non-poussable
            //matrice->getMatrice()[i+2][j].setEstPoussable(false);
        ///    m_matrice[i+2][j].getBlocPoussable().setEstPoussable(false);
        }
        break;
    case '4'://pousser "bloc" vers gauche
        if((j-2)>=0) //Pas sortir de la matrice
        {
            m_matrice[i][j]=m_blocVide;
            m_matrice[i][j-1]=m_Snoopy;
            m_matrice[i][j-2]=m_blocPoussable;
            /* matrice->getMatrice()[i][j].setType('V');
             matrice->getMatrice()[i][j-1].setType('S');
             matrice->getMatrice()[i][j-2].setType('P');*/
            ///Rendre ce bloc 'P' non-poussable
            // matrice->getMatrice()[i][j-2].setEstPoussable(false);
         ///   m_matrice[i][j-2].getBlocPoussable().setEstPoussable(false);
        }
        break;
    case '6'://pousser "bloc" vers droite
        if((j+2)<=N_COLONNES) //Pas sortir de la matrice
        {
            m_matrice[i][j]=m_blocVide;
            m_matrice[i][j+1]=m_Snoopy;
            m_matrice[i][j+2]=m_blocPoussable;
            /*matrice->getMatrice()[i][j].setType('V');
            matrice->getMatrice()[i][j+1].setType('S');
            matrice->getMatrice()[i][j+2].setType('P');*/
            ///Rendre ce bloc 'P' non-poussable
            // matrice->getMatrice()[i][j+2].setEstPoussable(false);
         ///   m_matrice[i][j+2].getBlocPoussable().setEstPoussable(false);
        }
        break;
    case '8'://Pousser "bloc" vers haut
        if((i-2)>=0) //Pas sortir de la matrice
        {
            m_matrice[i][j]=m_blocVide;
            m_matrice[i-1][j]=m_Snoopy;
            m_matrice[i-2][j]=m_blocPoussable;
            /*matrice->getMatrice()[i][j].setType('V');
            matrice->getMatrice()[i-1][j].setType('S');
            matrice->getMatrice()[i-2][j].setType('P');*/
            ///Rendre ce bloc 'P' non-poussable
            //matrice->getMatrice()[i-2][j].setEstPoussable(false);
           /// m_matrice[i-2][j].getBlocPoussable().setEstPoussable(false);
        }
        break;
    case 's': //sauver la partie
        break;
    }
}

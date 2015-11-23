#include "Constantes.h"
#include "Matrice.h"
#include "Bloc.h"

//constructeur
Matrice::Matrice() {}

//desctructeur unique
Matrice::~Matrice() {}

//getters
std::vector<std::vector<Bloc>> Matrice::getMatrice()const
{
    return m_matrice;
}
Balle Matrice::getBalle()const
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
int Matrice::getDecalageX()const
{
    return m_decalage_X;
}
int Matrice::getDecalageY()const
{
    return m_decalage_Y;
}

//setters
//Permet de modifier manuellement un bloc de la matrice
void Matrice::setBloc(int posX, int posY, Bloc bloc)
{
    m_matrice[posX][posY] = bloc;
}

void Matrice::setDecalageX(int decalageX)
{
    m_decalage_X = decalageX;
}

void Matrice::setDecalageY(int decalageY)
{
    m_decalage_Y = decalageY;
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
    //Snoopy
    m_matrice[m_Snoopy.getPosX()][m_Snoopy.getPosY()] = m_Snoopy;
    //Blocs poussables TEST
    m_matrice[6][12] = m_blocPoussable;
    m_matrice[3][7] = m_blocPoussable;
}

void Matrice::afficherMatrice(Console* conso)
{
    conso->gotoLigCol(POSLIGNE,POSCOLONNE);
    int lignes = 0;
    for (int i = 0; i < N_LIGNES; i++)
    {
        for (int j = 0; j < N_COLONNES; j++)
        {
            std::cout << m_matrice[i][j].getType();
        }
        lignes++;
        conso->gotoLigCol(POSLIGNE+lignes,POSCOLONNE);
    }
}

void Matrice::afficherCadre(Console* conso)
{
    char horizontal=205,vertical=186;
    char C_right_top=187,C_right_bottom=188;
    char C_left_top=201,C_left_bottom=200;
    int decalage = 0;

    conso->gotoLigCol(POSLIGNE-1, POSCOLONNE);
    for (int i = 0; i < N_COLONNES; i ++)
    {
        std::cout << horizontal;
    }
    conso->gotoLigCol(POSLIGNE+N_LIGNES, POSCOLONNE);
    for (int i = 0; i < N_COLONNES; i++)
    {
        std::cout << horizontal;
    }
    for (int i = 0; i < N_LIGNES; i++)
    {
        conso->gotoLigCol(POSLIGNE+decalage, POSCOLONNE-1);
        std::cout << vertical;
        decalage++;
    }
    decalage = 0;
    for (int i = 0; i < N_LIGNES; i++)
    {
        conso->gotoLigCol(POSLIGNE+decalage, POSCOLONNE+N_COLONNES);
        std::cout << vertical;
        decalage++;
    }
    conso->gotoLigCol(POSLIGNE-1, POSCOLONNE-1); std::cout << C_left_top;
    conso->gotoLigCol(POSLIGNE-1, POSCOLONNE+N_COLONNES); std::cout << C_right_top;
    conso->gotoLigCol(POSLIGNE+N_LIGNES, POSCOLONNE-1); std::cout << C_left_bottom;
    conso->gotoLigCol(POSLIGNE+N_LIGNES, POSCOLONNE+N_COLONNES); std::cout << C_right_bottom;
}

void Matrice::bougerBalle()
{
    m_matrice[m_balle.getPosX()][m_balle.getPosY()] = m_blocVide;
    if((m_balle.getPosX() == 9) || (m_balle.getPosX() == 0))
    {
        m_decalage_X *= -1;
    }
    if((m_balle.getPosY() == 19) || (m_balle.getPosY() == 0))
    {
        m_decalage_Y *= -1;
    }
    m_balle.setPosX(m_balle.getPosX()+m_decalage_X);
    m_balle.setPosY(m_balle.getPosY()+m_decalage_Y);
    m_matrice[m_balle.getPosX()][m_balle.getPosY()] = m_balle;
}

void Matrice::bougerSnoopy(char& touche)
{
    //Ressources
    //Position de Snoopy par rapport au TABLEAU
    int poslig = m_Snoopy.getPosX(), poscol = m_Snoopy.getPosY(); // position initiale du TABLEAU indice = celle de Snoopy
    //int i = poslig-POSLIGNE,j = poscol-POSCOLONNE;//position de la ligne et de la colonne par rapport au tableau (CONSOLE)
    //Nombre de lignes et colonnes par rapport A LA CONSOLE (affichage)
    int nbl = N_LIGNES;
    int nbc = N_COLONNES;
    switch(touche)
    {
    case 's'://descendre
        if ((poslig+1>=0)&&(poslig+1<nbl)) //blindage
        {
            poslig++; //incrementer la position de la ligne
        }
        break;
    case 'q'://aller a gauche
        if ((poscol-1<nbc)&&(poscol-1>=0))//blindage
        {
            poscol--; //decrementer la position de la colonne
        }
        break;
    case 'd'://aller a droite
        if ((poscol+1<nbc)&&(poscol+1>=0))//blindage
        {
            poscol++;//incrementer la position colonnne
        }
        break;
    case 'z'://monter
        if((poslig-1>=0)&&(poslig-1<nbl))//blindage
        {
            poslig--;//Decrementer la position de la ligne
        }
        break;
    case 'w': //Sauvegarder
        break;
    }
    if((poslig != m_Snoopy.getPosX())||(poscol != m_Snoopy.getPosY()))
    {
    m_matrice[m_Snoopy.getPosX()][m_Snoopy.getPosY()] = m_blocVide;
    m_Snoopy.setPosX(poslig);
    m_Snoopy.setPosY(poscol);
    m_matrice[m_Snoopy.getPosX()][m_Snoopy.getPosY()] = m_Snoopy;
    }
}

void Matrice::bougerElements(Console* conso)
{
    afficherCadre(conso);
    bool quit = false;
    char touche;
    initialisationMatrice();
    afficherMatrice(conso);
    do
    {
        bougerBalle();
        afficherMatrice(conso);
        if(conso->ifKeyboardPressed())
        {
            if(conso->getInputKey() == 27)
            {
                quit = true;
            }
            else
            {
                touche=conso->getInputKey();
                bougerSnoopy(touche);
            }
        }
    }
    while(!quit);
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

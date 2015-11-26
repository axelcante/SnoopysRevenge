#include "Constantes.h"
#include "Matrice.h"
#include "Bloc.h"
#include <windows.h>

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
    m_matrice[6][6] = m_blocPoussable;
    m_matrice[9][18] = m_blocPoussable;
}

void Matrice::afficherMatrice(Console* conso)
{
    conso->gotoLigCol(POSLIGNE,POSCOLONNE);
    int lignes = 0;
    for (int i = 0; i < N_LIGNES; i++)

    {
        {
            for (int j = 0; j < N_COLONNES; j++)
            {
                std::cout << m_matrice[i][j].getType();
            }
            lignes++;
            conso->gotoLigCol(POSLIGNE+lignes,POSCOLONNE);
        }
    }
    ///Affichage nombre d'oiseaux
    conso->gotoLigCol(POSLIGNE+N_LIGNES+5, POSCOLONNE);
    std::cout <<"Nombre d'oiseaux : "<< m_Snoopy.getOiseaux();
    conso->gotoLigCol(POSLIGNE+N_LIGNES+6, POSCOLONNE);
    std::cout <<"Score : "<< m_Snoopy.getScore();
    conso->gotoLigCol(POSLIGNE+N_LIGNES+7, POSCOLONNE);
    std::cout <<"Nombre de vies : "<< m_Snoopy.getVies();
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
    conso->gotoLigCol(POSLIGNE-1, POSCOLONNE-1);
    std::cout << C_left_top;
    conso->gotoLigCol(POSLIGNE-1, POSCOLONNE+N_COLONNES);
    std::cout << C_right_top;
    conso->gotoLigCol(POSLIGNE+N_LIGNES, POSCOLONNE-1);
    std::cout << C_left_bottom;
    conso->gotoLigCol(POSLIGNE+N_LIGNES, POSCOLONNE+N_COLONNES);
    std::cout << C_right_bottom;
}

bool Matrice::bougerBalle()
{
    bool dead = false;
    m_matrice[m_balle.getPosX()][m_balle.getPosY()] = m_blocVide;
    if((m_balle.getPosX() == (N_LIGNES-1)) || (m_balle.getPosX() == 0))
    {
        m_decalage_X *= -1;
    }
    if((m_balle.getPosY() == (N_COLONNES-1)) || (m_balle.getPosY() == 0))
    {
        m_decalage_Y *= -1;
    }
    if((m_matrice[m_balle.getPosX() + m_decalage_X][m_balle.getPosY()].getType() == m_blocVide.getType()) || (m_matrice[m_balle.getPosX() + m_decalage_X][m_balle.getPosY()].getType() == m_Snoopy.getType()))
    {
        m_decalage_X += 0;
    }
    else
    {
        m_decalage_X *= -1;
    }
    if((m_matrice[m_balle.getPosX()][m_balle.getPosY() + m_decalage_Y].getType() == m_blocVide.getType()) || (m_matrice[m_balle.getPosX()][m_balle.getPosY() + m_decalage_Y].getType() == m_Snoopy.getType()))
    {
        m_decalage_Y += 0;
        dead = true;
    }
    else
    {
        m_decalage_Y *= -1;
    }
    if((m_matrice[m_balle.getPosX() + m_decalage_X][m_balle.getPosY() + m_decalage_Y].getType() == m_blocVide.getType()) || (m_matrice[m_balle.getPosX() + m_decalage_X][m_balle.getPosY() + m_decalage_Y].getType() == m_Snoopy.getType()))
    {
        m_decalage_X += 0;
    }
    else
    {
        m_decalage_X *= -1;
        m_decalage_Y *= -1;
    }
    m_balle.setPosX(m_balle.getPosX()+m_decalage_X);
    m_balle.setPosY(m_balle.getPosY()+m_decalage_Y);
    m_matrice[m_balle.getPosX()][m_balle.getPosY()] = m_balle;
    return dead;
}

void Matrice::bougerSnoopy(Console*conso,char& touche)
{
    //Ressources
    //Position de Snoopy par rapport au TABLEAU
    int poslig = m_Snoopy.getPosX(), poscol = m_Snoopy.getPosY(); // position initiale du TABLEAU indice = celle de Snoopy
    //Nombre de lignes et colonnes par rapport A LA CONSOLE (affichage)
    int nbl = N_LIGNES;
    int nbc = N_COLONNES;

    /********
    QUE FAIRE SI BALLE TOUCHE ? : faire une condition dans balle directement.
    **********/

    switch(touche)
    {
    case 's'://descendre
        if ((poslig+1>=0)&&(poslig+1<nbl)) //blindage
        {
            poslig++; //incrementer la position de la ligne
            ///Pousser si poussable
            if(m_matrice[poslig][poscol].getEstPoussableblocmere()==true)
            {
                pousser(conso,touche);
            }
            ///Ne pas pousser si AUTRE blocs non poussables
            else
            {
                if(m_matrice[poslig][poscol].getType()=='O')
                {
                    m_Snoopy.setOiseaux(m_Snoopy.getOiseaux()+1);
                }
                else if(m_matrice[poslig][poscol].getType()!=' ')
                {
                    poslig--;
                    //Si 'C' : cassable
                    /// if((m_matrice[poslig][poscol].getType()=='C'))
                    //Si 'T' : piégé
                    /// else if((m_matrice[poslig][poscol].getType()=='T'))
                }
            }
        }
        break;
    case 'q'://aller a gauche
        if ((poscol-1<nbc)&&(poscol-1>=0))//blindage
        {
            poscol--; //decrementer la position de la colonne
            ///Pousser si poussable
            if(m_matrice[poslig][poscol].getEstPoussableblocmere()==true)
            {
                pousser(conso,touche);
            }
            ///Ne pas pousser si AUTRE blocs non poussables
            else
            {
                if(m_matrice[poslig][poscol].getType()=='O')
                {
                    m_Snoopy.setOiseaux(m_Snoopy.getOiseaux()+1);
                }
                else if(m_matrice[poslig][poscol].getType()!=' ')
                {
                    poscol++;
                    //Si 'C' : cassable
                    /// if((m_matrice[poslig][poscol].getType()=='C'))
                    //Si 'T' : piégé
                    /// else if((m_matrice[poslig][poscol].getType()=='T'))
                }
            }
        }
        break;
    case 'd'://aller a droite
        if ((poscol+1<nbc)&&(poscol+1>=0))//blindage
        {
            poscol++;//incrementer la position colonnne
            ///Pousser si poussable
            if(m_matrice[poslig][poscol].getEstPoussableblocmere()==true)
            {
                pousser(conso,touche);
            }
            ///Ne pas pousser si AUTRE blocs non poussables
            else
            {
                if(m_matrice[poslig][poscol].getType()=='O')
                {
                    m_Snoopy.setOiseaux(m_Snoopy.getOiseaux()+1);
                }
                else if(m_matrice[poslig][poscol].getType()!=' ')
                {
                    poscol--;
                    //Si 'C' : cassable
                    /// if((m_matrice[poslig][poscol].getType()=='C'))
                    //Si 'T' : piégé
                    /// else if((m_matrice[poslig][poscol].getType()=='T'))
                }
            }
        }
        break;
    case 'z'://monter
        if((poslig-1>=0)&&(poslig-1<nbl))//blindage
        {
            poslig--;//Decrementer la position de la ligne
            ///Pousser si poussable
            if(m_matrice[poslig][poscol].getEstPoussableblocmere()==true)
            {
                pousser(conso,touche);
            }
            ///Ne pas pousser si AUTRE blocs non poussables
            else
            {
                if(m_matrice[poslig][poscol].getType()=='O')
                {
                    m_Snoopy.setOiseaux(m_Snoopy.getOiseaux()+1);
                }
                else if(m_matrice[poslig][poscol].getType()!=' ')
                {
                    poslig++;
                    //Si 'C' : cassable
                    /// if((m_matrice[poslig][poscol].getType()=='C'))
                    //Si 'T' : piégé
                    /// else if((m_matrice[poslig][poscol].getType()=='T'))
                }
            }
        }
        break;
    case 'w': //Sauvegarder
        break;
    }
    if((poslig != m_Snoopy.getPosX())||(poscol != m_Snoopy.getPosY())) ///Si changement de position : remplacement de bloc.
    {
        m_matrice[m_Snoopy.getPosX()][m_Snoopy.getPosY()] = m_blocVide;
        m_Snoopy.setPosX(poslig);
        m_Snoopy.setPosY(poscol);
        m_matrice[m_Snoopy.getPosX()][m_Snoopy.getPosY()] = m_Snoopy;
    }
}

void Matrice::bougerElements(Console* conso)
{
    bool quit = false;
    bool dead = false;
    char touche;
    initialisationMatrice();
    afficherMatrice(conso);
    do
    {
        Sleep(80);  //Le sleep permet de ralentir le mouvement automatique de la balle
        dead = bougerBalle();
        afficherMatrice(conso);
        if(conso->ifKeyboardPressed())
        {
            touche=conso->getInputKey();
            if(touche == 27)
            {
                quit = true;
            }
            else
            {
                bougerSnoopy(conso,touche);
            }
        }
        //if(dead == true) break;
    }
    while(!quit);
}

void Matrice::pousser(Console* conso, char& touche)
{
    /****
    /// Supposé fait :
    ///     touche=conso->getInputKey(); // Touche récupéréé
    ///     Vérifier que le "bloc" soit bien poussable AVANT de "pousser"
    ****/

    //Déclaration de variables
    int i = m_Snoopy.getPosX(),j = m_Snoopy.getPosY();

    switch(touche)
    {
    ///Chez nous, Snoopy bouge en même temps que la bloc poussable
    case 's': ///Pousser "bloc" vers le bas
        if((i+2)<=N_LIGNES) //Pas sortir de la matrice
        {
            m_matrice[i][j]=m_blocVide;
            // m_matrice[i+1][j]=m_Snoopy; //fait
            m_matrice[i+2][j]=m_blocPoussable;
            ///Rendre ce bloc 'P' non-poussable
            m_matrice[i+2][j].setEstPoussableblocmere(false);
        }
        break;
    case 'q':///Pousser "bloc" vers gauche
        if((j-2)>=0) //Pas sortir de la matrice
        {
            m_matrice[i][j]=m_blocVide;
            //m_matrice[i][j-1]=m_Snoopy; //fait
            m_matrice[i][j-2]=m_blocPoussable;
            ///Rendre ce bloc 'P' non-poussable
            m_matrice[i][j-2].setEstPoussableblocmere(false);
        }
        break;
    case 'd':///Pousser "bloc" vers droite
        if((j+2)<=N_COLONNES) //Pas sortir de la matrice
        {
            m_matrice[i][j]=m_blocVide;
            //m_matrice[i][j+1]=m_Snoopy; //fait
            m_matrice[i][j+2]=m_blocPoussable;
            ///Rendre ce bloc 'P' non-poussable
            m_matrice[i][j+2].setEstPoussableblocmere(false);
        }
        break;
    case 'z':///Pousser "bloc" vers haut
        if((i-2)>=0) //Pas sortir de la matrice
        {
            m_matrice[i][j]=m_blocVide;
            //m_matrice[i-1][j]=m_Snoopy; //fait
            m_matrice[i-2][j]=m_blocPoussable;
            ///Rendre ce bloc 'P' non-poussable
            m_matrice[i-2][j].setEstPoussableblocmere(false);
        }
        break;
    case 'w': //sauver la partie
        break;
    }
}

#include "Constantes.h"
#include "Matrice.h"
#include "Bloc.h"

//constructeur
Matrice::Matrice(){}

//desctructeur unique
Matrice::~Matrice(){}

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
    m_matrice[4][4] = m_Snoopy;
    //Blocs poussables TEST
    m_matrice[6][12] = m_blocPoussable;
    m_matrice[3][7] = m_blocPoussable;
<<<<<<< HEAD


=======
>>>>>>> e9097651414dd455332662ea222b8998310e188f
}

void Matrice::afficherMatrice(Console* conso)
{
    conso->gotoLigCol(5,10);
    int lignes = 0;
    for (int i = 0; i < N_LIGNES; i++)
    {std::cout <<"|";
        for (int j = 0; j < N_COLONNES; j++)
        {
<<<<<<< HEAD
            std::cout << m_matrice[i][j].getType();
=======
            std::cout << "|" << m_matrice[i][j].getType();
>>>>>>> e9097651414dd455332662ea222b8998310e188f
        }
        std::cout <<"|";
        lignes++;
        conso->gotoLigCol(5+lignes,10);
    }
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

<<<<<<< HEAD
void Matrice::bougerSnoopy(Console* conso,char& touche)
{
    //Ressources
    //Position de Snoopy par rapport au TABLEAU
    int poslig = m_Snoopy.getPosX(), poscol = m_Snoopy.getPosY(); // position initiale du TABLEAU indice = celle de Snoopy
    int i = poslig-POSLIGNE,j = poscol-POSCOLONNE;//position de la ligne et de la colonne par rapport au tableau (CONSOLE)
    //Nombre de lignes et colonnes par rapport A LA CONSOLE (affichage)
    int nbl = N_LIGNES+POSLIGNE;
    int nbc = N_COLONNES+POSCOLONNE+1;

    touche = conso->getInputKey();//Saisie de la touche
    switch(touche)
    {
    case 's'://descendre
        if ((poslig+1>=POSLIGNE)&&(poslig+1<=nbl)) //blindage
        {
            poslig++; //incrementer la position de la ligne
        }
        break;
    case 'q'://aller a gauche
        if ((poscol-1<=nbc)&&(poscol-1>=POSCOLONNE+1))//blindage
        {
            poscol--; //decrementer la position de la colonne
        }
        break;
    case 'd'://aller a droite
        if ((poscol+1<=nbc)&&(poscol+1>=POSCOLONNE+1))//blindage
        {
            poscol++;//incrementer la position colonnne
        }
        break;
    case 'z'://monter
        if((poslig-1>=POSLIGNE)&&(poslig-1<nbl))//blindage
        {
            poslig--;//Decrementer la position de la ligne
        }
        break;
    case 'w': //Sauvegarder
        break;
    }
    //Reinitialiser les positions
    i = poslig+POSLIGNE;
    j = poscol+POSCOLONNE;
    conso->gotoLigCol(i,j);//positionner le curseur a lendroit voulu
    m_Snoopy.setPosX(poslig);
    m_Snoopy.setPosY(poscol);
    int x= m_Snoopy.getPosX();
    int y= m_Snoopy.getPosY();
    std::cout << x << std::endl << y;
}

=======
void Matrice::bougerElements(Console* conso)
{
    bool quit = false;
    initialisationMatrice();
    afficherMatrice(conso);
    do
    {
        bougerBalle();
        std::cout << m_balle.getPosX();
        afficherMatrice(conso);
        if(conso->ifKeyboardPressed())
        {
            if(conso->getInputKey() == 27)
            {
                quit = true;
            }
        }
    } while(!quit);
}



>>>>>>> e9097651414dd455332662ea222b8998310e188f
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

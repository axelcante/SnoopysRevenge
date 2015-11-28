#include "Matrice.h"
#include <time.h>
#include <cmath>

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
Snoopy Matrice::getSnoopy()const
{
    return m_Snoopy;
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

///_________________________________________________________________________
///Methodes
void Matrice::initialisationMatrice(int& niv)
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
    initialisationElements(niv);

}

///_________________________________________________________________________
void Matrice::initialisationElements(int& niv)
{
    //Matrice vide
    for(int i = 0; i < N_LIGNES; i++)
    {
        for(int j = 0; j < N_COLONNES; j++)
        {
            m_matrice[i][j] = m_blocVide;
        }
    }
    ///TOUJOURS LA
    //Oiseaux
    m_matrice[0][0] = m_Oiseau;
    m_matrice[0][19] = m_Oiseau;
    m_matrice[9][0] = m_Oiseau;
    m_matrice[9][19] = m_Oiseau;
    //Balle position initiale
    m_matrice[m_balle.getPosX()][m_balle.getPosY()] = m_balle;
    m_decalage_X = 1;
    m_decalage_Y = 1;
    //Snoopy
    m_matrice[m_Snoopy.getPosX()][m_Snoopy.getPosY()] = m_Snoopy;
    m_Snoopy.setOiseaux(0);
    ///Architecture sp�ciale
    switch(niv)
    {
    case 1:
        //Blocs poussables TEST
        m_matrice[6][12] = m_blocPoussable;
        m_matrice[3][7] = m_blocPoussable;
        m_matrice[6][6] = m_blocPoussable;
        //Blocs Pi�g�s TEST
        m_matrice[5][8] = m_blocT;
        //Blocs Cassables TEST
        m_matrice[6][8] = m_blocC;
        break;
    case 2:
        //Blocs poussables TEST
        m_matrice[0][5] = m_blocPoussable;
        m_matrice[1][5] = m_blocPoussable;
        m_matrice[0][17] = m_blocPoussable;
        m_matrice[1][17] = m_blocPoussable;
        //Blocs Pi�g�s TEST
        m_matrice[3][5] = m_blocT;
        m_matrice[3][15] = m_blocT;
        //Blocs Cassables TEST
        m_matrice[6][8] = m_blocC;
        m_matrice[7][8] = m_blocC;
        break;
    case 3:
        break;
    }
}

///_________________________________________________________________________
void Matrice::afficherMatrice(Console* conso)
{
    conso->gotoLigCol(POSLIGNE,POSCOLONNE);
    int lignes = 0;
    for (int i = 0; i < N_LIGNES; i++)

    {
        {
            for (int j = 0; j < N_COLONNES; j++)
            {
                if(m_matrice[i][j].getType() == 'S')
                {
                    conso->setColor(COLOR_YELLOW);
                }
                if(m_matrice[i][j].getType() == 'T')
                {
                    conso->setColor(COLOR_RED);
                }
                if(m_matrice[i][j].getType() == 'P')
                {
                    conso->setColor(COLOR_BLUE);
                }
                if(m_matrice[i][j].getType() == 'B')
                {
                    conso->setColor(COLOR_RED);
                }
                if(m_matrice[i][j].getType() == 'O')
                {
                    conso->setColor(COLOR_GREEN);
                }
                std::cout << m_matrice[i][j].getType();
                conso->setColor(COLOR_DEFAULT);
            }
            lignes++;
            conso->gotoLigCol(POSLIGNE+lignes,POSCOLONNE);
        }
    }
    ///Affichage nombre d'oiseaux
    conso->gotoLigCol(POSLIGNE+N_LIGNES+3, POSCOLONNE);
    conso->setColor(COLOR_YELLOW);
    std::cout <<"Nombre d'oiseaux : ";
    conso->setColor(COLOR_GREEN);
    std::cout<< m_Snoopy.getOiseaux();
    conso->gotoLigCol(POSLIGNE+N_LIGNES+5, POSCOLONNE);
    conso->setColor(COLOR_YELLOW);
    std::cout <<"Score : ";
    conso->setColor(COLOR_BLUE);
    std::cout << m_Snoopy.getScore();
    conso->gotoLigCol(POSLIGNE+N_LIGNES+7, POSCOLONNE);
    conso->setColor(COLOR_YELLOW);
    std::cout <<"Nombre de vies : ";
    conso->setColor(COLOR_RED);
    std::cout << m_Snoopy.getVies();
    conso->setColor(COLOR_DEFAULT);
}

///_________________________________________________________________________
void Matrice::afficherCadre(Console* conso)
{
    char horizontal=205,vertical=186;
    char C_right_top=187,C_right_bottom=188;
    char C_left_top=201,C_left_bottom=200;
    int decalage = 0;

    conso->gotoLigCol(POSLIGNE-1, POSCOLONNE);
    conso->setColor(COLOR_WHITE);
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
    conso->setColor(COLOR_DEFAULT);

    for(int i = 0; i < 60; i++)
    {
        conso->setColor(COLOR_WHITE);
        conso->gotoLigCol(POSLIGNE+N_LIGNES+10,POSCOLONNE+i);
        std::cout << (char)254u;
        conso->setColor(COLOR_DEFAULT);
    }

    conso->setColor(COLOR_YELLOW);

    conso->gotoLigCol(15,60);       //affichage du titre styl� de Snoopy's Revenge
    std::cout <<
              " ___                        _   ___";
    conso->gotoLigCol(16,60);
    std::cout <<
              "/ __|_ _  ___ ___ _ __ _  _( __| _ \\_____ _____ _ _  __ _ ___";
    conso->gotoLigCol(17,60);
    std::cout <<
              "\\__ | ' \\/ _ / _ | '_ | || |(_-|   / -_\\ V / -_| ' \\/ _` / -_)";
    conso->gotoLigCol(18,60);
    std::cout <<
              "|___|_||_\\___\\___| .__/\\_, |/__|_|_\\___|\\_/\\___|_||_\\__, \\___|";
    conso->gotoLigCol(19,60);
    std::cout <<
              "                 |_|   |__/                         |___/";
}

///_________________________________________________________________________
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
        //euuh
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
    ///Diminuer nombre de vies de Snoopy si Balle touche Snoopy : mettre du sang :D
    if((m_balle.getPosX()==m_Snoopy.getPosX())&&(m_balle.getPosY()==m_Snoopy.getPosY()))
    {
        return dead;
    }
    else dead = false;
    return dead;
}

///_________________________________________________________________________
void Matrice::bougerSnoopy(Console*conso,char& touche,bool& dead)
{
    //Ressources
    //Position de Snoopy par rapport au TABLEAU
    int poslig = m_Snoopy.getPosX();
    int poscol = m_Snoopy.getPosY(); // position initiale du TABLEAU indice = celle de Snoopy
    //Nombre de lignes et colonnes par rapport A LA CONSOLE (affichage)
    int nbl = N_LIGNES;
    int nbc = N_COLONNES;

    switch(touche)
    {
    case 's'://descendre
        if ((poslig+1>=0)&&(poslig+1<nbl)) //blindage
            poslig++; //incrementer la position de la ligne
        break;
    case 'q'://aller a gauche
        if ((poscol-1<nbc)&&(poscol-1>=0))//blindage
            poscol--; //decrementer la position de la colonne
        break;
    case 'd'://aller a droite
        if ((poscol+1<nbc)&&(poscol+1>=0))//blindage
            poscol++;//incrementer la position colonnne
        break;
    case 'z'://monter
        if((poslig-1>=0)&&(poslig-1<nbl))//blindage
            poslig--;//Decrementer la position de la ligne
        break;
    case 'a'://Casser ?
        if((poslig+1<nbl)&&(poscol-1>=0)&&(poscol+1<nbc)&&(poslig-1>=0))
        {
            if((m_matrice[poslig+1][poscol].getEstCassableblocmere()==true)||(m_matrice[poslig][poscol+1].getEstCassableblocmere()==true)||(m_matrice[poslig-1][poscol].getEstCassableblocmere()==true)||(m_matrice[poslig][poscol-1].getEstCassableblocmere()==true))
            {
                if(m_matrice[poslig+1][poscol].getEstCassableblocmere()==true)
                    poslig=poslig+1;
                else if(m_matrice[poslig][poscol+1].getEstCassableblocmere()==true)
                    poscol=poscol+1;
                else if(m_matrice[poslig-1][poscol].getEstCassableblocmere()==true)
                    poslig=poslig-1;
                else if(m_matrice[poslig][poscol-1].getEstCassableblocmere()==true)
                    poscol=poscol-1;
                casser(conso, poslig, poscol);
                poslig = m_Snoopy.getPosX(); //revenir aux coordonn�es de d�part
                poscol = m_Snoopy.getPosY();
                conso->gotoLigCol(12, 45);
                std::cout << "                 ";
            }
        }
        break;
    case 'w': //Sauvegarder
        break;
    }

    ///Si 'P' : pousser si poussable
    if(m_matrice[poslig][poscol].getEstPoussableblocmere()==true)
        pousser(conso,touche);
    else
    {
        ///Si 'O' : oiseau � r�cup�rer
        if(m_matrice[poslig][poscol].getType()=='O')
            m_Snoopy.setOiseaux(m_Snoopy.getOiseaux()+1);
        ///Si 'T' : pi�g�
        else if(m_matrice[poslig][poscol].getType()=='T')
            dead = true;
        ///Si 'C' :
        else if (m_matrice[poslig][poscol].getType()!=' ')
        {
            if(m_matrice[poslig][poscol].getType()=='C')
            {
                ///Afficher si cassable
                conso->gotoLigCol(12, 45);
                std::cout << "'a' pour casser";
            }
            poslig = m_Snoopy.getPosX(); //revenir aux coordonn�es de d�part
            poscol = m_Snoopy.getPosY();
        }
    }
    ///Si changement de position : remplacement de bloc.
    if((poslig != m_Snoopy.getPosX())||(poscol != m_Snoopy.getPosY()))
    {
        conso->gotoLigCol(12, 45);
        std::cout << "                 ";
        m_matrice[m_Snoopy.getPosX()][m_Snoopy.getPosY()] = m_blocVide;
        m_Snoopy.setPosX(poslig);
        m_Snoopy.setPosY(poscol);
        m_matrice[m_Snoopy.getPosX()][m_Snoopy.getPosY()] = m_Snoopy;
    }
}

///_________________________________________________________________________
void Matrice::bougerElements(Console* conso,int& niv)
{
    bool quit = false;
<<<<<<< HEAD
        bool dead = false;
        char touche;
        initialisationMatrice(niv);
        afficherCadre(conso);
        afficherMatrice(conso);
        int start = clock();

        do
=======
    bool dead = false;
    char touche;
    initialisationMatrice();
    afficherMatrice(conso);
    int start = clock();

    do
    {
        m_time = (clock()-start);
        for(int j = 60-(m_time/(CLOCKS_PER_SEC)); j < 60; j++) //efface les carr�s de temps
>>>>>>> 906cba46d12d5823c830e50a005c2efa5ef5fd2f
        {

            m_time = (clock()-start);
            for(int j = 60-(m_time/(CLOCKS_PER_SEC)); j < 60; j++) //efface les carr�s de temps
            {
                conso->gotoLigCol(POSLIGNE+N_LIGNES+10,POSCOLONNE+j);
                std::cout << ' ';
            }
<<<<<<< HEAD
            if(60000-m_time >= 0)
=======
            conso->gotoLigCol(10,45);
            //std::cout << (60-(m_time/CLOCKS_PER_SEC));    ligne qui permet d'afficher les secondes : ne sert que pour debugger
            conso->setColor(COLOR_DEFAULT);
            if(60000-m_time <= 200)
>>>>>>> 906cba46d12d5823c830e50a005c2efa5ef5fd2f
            {
                conso->setColor(COLOR_YELLOW);
                if(60000-m_time < 10000)
                {
                    conso->gotoLigCol(POSLIGNE+N_LIGNES+12,POSCOLONNE);
                    conso->setColor(COLOR_RED);
                    std::cout << "ATTENTION ! Moins de 10 secondes restantes...";
                    conso->gotoLigCol(10,46);
                    std::cout << ' ';
                }
                conso->gotoLigCol(10,45);
                std::cout << (60-(m_time/CLOCKS_PER_SEC));
                conso->setColor(COLOR_DEFAULT);
                if(60000-m_time <= 200)
                {
                    dead = true;
                    m_Snoopy.setVies(0);
                }
            }
            if(fmod(m_time,100) < 52)
            {
                dead = bougerBalle();
            }
            afficherMatrice(conso);
            if(conso->ifKeyboardPressed())
            {
                touche=conso->getInputKey();
                if(touche == 27)
                {
                    quit = true;
                    system("cls");
                }
                else if(touche == 'p') //pause
                {
                    do
                    {
                        touche = conso->getInputKey();
                    }
                    while (touche != 'p'); ///Stopper le timer aussi
                }
                else
                {
                    bougerSnoopy(conso,touche,dead);
                }
            }
            if(dead == true)
            {
                m_Snoopy.setVies(m_Snoopy.getVies()-1);
                dead = false;
                //R�initialisation de la matrice de d�part;
                Sleep(1000);
                m_Snoopy.setPosX(SNOOPYPOSX);
                m_Snoopy.setPosY(SNOOPYPOSY);
                m_matrice[m_balle.getPosX()][m_balle.getPosY()] = m_blocVide;
                m_balle.setPosX(BALLPOSX);
                m_balle.setPosY(BALLPOSY);
                initialisationElements(niv);
                if (m_Snoopy.getVies()<=0)
                {
                    system("cls");
                    ecranMort(conso);
                    quit=true;
                }
            }
            if(m_Snoopy.getOiseaux()==4)
            {
                ///Gagner partie : bouger le score
                m_Snoopy.setScore(m_Snoopy.getScore() + ((60-(m_time/CLOCKS_PER_SEC)))*100);
                ///Afficher qu'on a gagn�
                system("cls");
                ecranVictoire(conso);
                quit=true;
                system("cls");
            }
        }
        while(!quit);
}

///_________________________________________________________________________
void Matrice::casser(Console* conso, int& poslig, int& poscol)
{
    m_matrice[poslig][poscol] = m_blocVide;
}

///_________________________________________________________________________
void Matrice::pousser(Console* conso, char& touche)
{
    /****
    /// Suppos� fait :
    ///     touche=conso->getInputKey(); // Touche r�cup�r��
    ///     V�rifier que le "bloc" soit bien poussable AVANT de "pousser"
    ****/

    //D�claration de variables
    int i = m_Snoopy.getPosX(),j = m_Snoopy.getPosY();

    switch(touche)
    {
    ///Chez nous, Snoopy bouge en m�me temps que la bloc poussable
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

void Matrice::ecranMort(Console* conso)
{
    conso->gotoLigCol(20,30);
    conso->setColor(COLOR_RED);
    std::cout << "VOUS AVEZ PERDU ! QUEL DOMMAGE !";
    conso->gotoLigCol(25,30);
    std::cout << "VOTRE SCORE EST DE : " << m_Snoopy.getScore()<<std::endl<<std::endl;
    system("pause");
    conso->setColor(COLOR_DEFAULT);

}

void Matrice::ecranVictoire(Console* conso)
{
    conso->gotoLigCol(20,30);
    conso->setColor(COLOR_YELLOW);
    std::cout << "EXCELLENT ! VOUS AVEZ REMPORTE LA PARTIE !";
    conso->gotoLigCol(25,30);
    std::cout << "VOTRE SCORE EST DE : " << m_Snoopy.getScore()<<std::endl<<std::endl;
    system("pause");
    conso->setColor(COLOR_DEFAULT);
}

void Matrice::traduireMatrice(char tableau[N_LIGNES][N_COLONNES])
{
    for(int i = 0; i < N_LIGNES; i++)
    {
        for(int j = 0; j < N_COLONNES; j++)
        {
            tableau[i][j] = m_matrice[i][j].getType();
        }
    }
}


void Matrice::traduireTableau(char tableau[N_LIGNES][N_COLONNES])
{
    for(int i = 0; i < N_LIGNES; i++)
    {
        for(int j = 0; j < N_COLONNES; j++)
        {
            if((tableau[i][j] == 'O'))
            {
                m_matrice[i][j] = m_Oiseau;
            }
            if((tableau[i][j] = ' '))
            {
                m_matrice[i][j] = m_blocVide;
            }
            if((tableau[i][j] = 'P'))
            {
                m_matrice[i][j] = m_blocP;
            }
            if((tableau[i][j] = 'T'))
            {
                m_matrice[i][j] = m_blocT;
            }
            if((tableau[i][j] = 'C'))
            {
                m_matrice[i][j] = m_blocC;
            }
            if((tableau[i][j] = 'S'))
            {
                m_Snoopy.setPosX(i);
                m_Snoopy.setPosY(j);
                m_matrice[m_Snoopy.getPosX()][m_Snoopy.getPosY()] = m_Snoopy;
            }
            if((tableau[i][j] = 'B'))
            {
                m_balle.setPosX(i);
                m_balle.setPosY(j);
                m_matrice[m_balle.getPosX()][m_balle.getPosY()] = m_balle;
            }
        }
    }
}

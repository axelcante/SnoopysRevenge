#include "Matrice.h"
#include <time.h>
#include <cmath>

//constructeur
Matrice::Matrice() {}

//desctructeur unique
Matrice::~Matrice() {}

///Getters
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
//Bloc Matrice::getBlocP()const
//{
// return m_blocP;
//}
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
double Matrice::getTime()const
{
    return m_time;
}

///Setters
//Permet de modifier manuellement un bloc de la matrice
void Matrice::setBloc(int posX, int posY, Bloc bloc) //n'est pas utilis� mais toujours utile ! :D
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
///_________________________________________________________________________
//Initialisation de la matrice de jeu
void Matrice::initialisationMatrice(int& niv)
{
    //D�claration de variables
    std::vector<Bloc>column; // PREMIERE PARTIE : faire un vecteur de bloc: ce sont les colonnes
    for (int i = 0; i < N_COLONNES; i++)
    {
        column.push_back(m_blocVide);
    }
    //DEUXIEME PARTIE : faire les lignes maintenant
    for (int i = 0; i < N_LIGNES; i++)
    {
        m_matrice.push_back(column);
    }
    //Initialisation des �l�ments dans la matrice
    initialisationElements(niv);

}

///_________________________________________________________________________
void Matrice::initialisationElements(int& niv)
{
    //Initialisation de matrice vide
    for(int i = 0; i < N_LIGNES; i++)
    {
        for(int j = 0; j < N_COLONNES; j++)
        {
            m_matrice[i][j] = m_blocVide;
        }
    }
    ///ELEMENTS QUI SONT TOUJOURS LA
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

    ///Architecture sp�ciale
    switch(niv) //selon le niveau
    {
    case 1:
        //Blocs poussables TEST
        m_matrice[4][12] = m_blocPoussable;
        m_matrice[6][12] = m_blocPoussable;
        m_matrice[4][6] = m_blocPoussable;
        m_matrice[6][6] = m_blocPoussable;
        //Blocs Pi�g�s TEST
        m_matrice[2][9] = m_blocT;
        m_matrice[6][9] = m_blocT;
        m_matrice[3][11] = m_blocT;
        //Blocs Cassables TEST
        m_matrice[1][0] = m_blocC;
        m_matrice[1][19] = m_blocC;
        m_matrice[8][19] = m_blocC;
        m_matrice[8][0] = m_blocC;
        break;
    case 2:
        //Blocs poussables TEST
        m_matrice[4][12] = m_blocPoussable;
        m_matrice[6][12] = m_blocPoussable;
        m_matrice[4][6] = m_blocPoussable;
        m_matrice[6][6] = m_blocPoussable;
        m_matrice[5][9] = m_blocPoussable;
        //Blocs Pi�g�s TEST
        m_matrice[0][1] = m_blocT;
        m_matrice[0][18] = m_blocT;
        m_matrice[9][1] = m_blocT;
        m_matrice[9][18] = m_blocT;
        m_matrice[4][8] = m_blocT;
        m_matrice[4][10] = m_blocT;
        //Blocs Cassables TEST
        m_matrice[1][0] = m_blocC;
        m_matrice[1][19] = m_blocC;
        m_matrice[8][19] = m_blocC;
        m_matrice[8][0] = m_blocC;
        break;
    case 3:
        //Blocs poussables TEST
        m_matrice[4][12] = m_blocPoussable;
        m_matrice[6][12] = m_blocPoussable;
        m_matrice[4][6] = m_blocPoussable;
        m_matrice[6][6] = m_blocPoussable;
        m_matrice[5][9] = m_blocPoussable;
        //Blocs Pi�g�s TEST
        m_matrice[0][1] = m_blocT;
        m_matrice[0][18] = m_blocT;
        m_matrice[9][1] = m_blocT;
        m_matrice[9][18] = m_blocT;
        m_matrice[4][8] = m_blocT;
        m_matrice[5][10] = m_blocT;
        m_matrice[6][10] = m_blocT;
        m_matrice[4][11] = m_blocT;
        m_matrice[3][9] = m_blocT;
        m_matrice[5][9] = m_blocT;
        m_matrice[2][0] = m_blocT;
        m_matrice[3][0] = m_blocT;
        m_matrice[5][0] = m_blocT;
        m_matrice[6][0] = m_blocT;
        m_matrice[2][19] = m_blocT;
        m_matrice[3][19] = m_blocT;
        m_matrice[5][19] = m_blocT;
        m_matrice[6][19] = m_blocT;
        //Blocs Cassables TEST
        m_matrice[1][0] = m_blocC;
        m_matrice[1][19] = m_blocC;
        m_matrice[8][19] = m_blocC;
        m_matrice[8][0] = m_blocC;
        break;
    case 6:
        //Blocs poussables TEST
        m_matrice[4][12] = m_blocPoussable;
        m_matrice[6][12] = m_blocPoussable;
        m_matrice[4][6] = m_blocPoussable;
        m_matrice[6][6] = m_blocPoussable;
        m_matrice[5][9] = m_blocPoussable;
        m_matrice[1][0] = m_blocPoussable;
        m_matrice[1][19] = m_blocPoussable;
        m_matrice[8][0] = m_blocPoussable;
        //Blocs Pi�g�s TEST
        m_matrice[0][1] = m_blocT;
        m_matrice[0][18] = m_blocT;
        m_matrice[9][1] = m_blocT;
        m_matrice[9][18] = m_blocT;
        m_matrice[4][8] = m_blocT;
        m_matrice[5][10] = m_blocT;
        m_matrice[6][10] = m_blocT;
        m_matrice[4][11] = m_blocT;
        m_matrice[3][9] = m_blocT;
        m_matrice[5][9] = m_blocT;
        m_matrice[2][0] = m_blocT;
        m_matrice[3][0] = m_blocT;
        m_matrice[5][0] = m_blocT;
        m_matrice[6][0] = m_blocT;
        m_matrice[2][19] = m_blocT;
        m_matrice[3][19] = m_blocT;
        m_matrice[5][19] = m_blocT;
        m_matrice[6][19] = m_blocT;
        //Blocs Cassables TEST
        m_matrice[8][19] = m_blocC;
        m_matrice[8][18] = m_blocC;
        m_matrice[7][18] = m_blocC;
        m_matrice[8][17] = m_blocC;

        //Bloc snoopy
        break;
    case 7:
        m_Snoopy.setVies(m_Snoopy.getVies()-2);
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
                if(m_matrice[i][j].getType() == 'S')        ///SUITE D'INSTRUCTIONS QUI COLORIE LES ELEMENTS DE LA MATRICE EN FONCTION DE LEUR TYPE
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
                std::cout << m_matrice[i][j].getType();         ///ON AFFICHE LE TYPE DES BLOCS
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
    ///Affichage du score
    conso->gotoLigCol(POSLIGNE+N_LIGNES+5, POSCOLONNE);
    conso->setColor(COLOR_YELLOW);
    std::cout <<"Score : ";
    conso->setColor(COLOR_BLUE);
    std::cout << m_Snoopy.getScore();
    //Affichage du nombre de vies
    conso->gotoLigCol(POSLIGNE+N_LIGNES+7, POSCOLONNE);
    conso->setColor(COLOR_YELLOW);
    std::cout <<"Nombre de vies : ";
    conso->setColor(COLOR_RED);
    std::cout << m_Snoopy.getVies();
    conso->setColor(COLOR_DEFAULT);
}

///_________________________________________________________________________
void Matrice::afficherCadre(Console* conso) //Affiche un joli cadre autour de la matrice de jeu + titre snoopy
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
bool Matrice::bougerBalle()     //fonction qui bouge la balle de une case a chaque fois
{
    bool dead = false;
    m_matrice[m_balle.getPosX()][m_balle.getPosY()] = m_blocVide;

    ///REBOND SUR MATRICE
    if((m_balle.getPosX()<=0)||(m_balle.getPosX()>=N_LIGNES-1)) //BAS ou HAUT de la matrice
        m_decalage_X = -m_decalage_X;
    if((m_balle.getPosY()<=0)||(m_balle.getPosY()>=N_COLONNES-1)) //DROITE ou GAUCHE de la matrice
        m_decalage_Y = -m_decalage_Y;

    ///REBOND SUR BLOCS (on test si le bloc est vide / snoopy, SI NON, elle rebondit !)
    if((m_matrice[m_balle.getPosX()][m_balle.getPosY() + m_decalage_Y].getType()!=' ')&&(m_matrice[m_balle.getPosX()][m_balle.getPosY() + m_decalage_Y].getType()!='S'))
        m_decalage_Y = -m_decalage_Y;
    if((m_matrice[m_balle.getPosX()+m_decalage_X][m_balle.getPosY()].getType()!=' ')&&(m_matrice[m_balle.getPosX()+m_decalage_X][m_balle.getPosY()].getType()!='S'))
        m_decalage_X = -m_decalage_Y;
    if((m_matrice[m_balle.getPosX()+m_decalage_X][m_balle.getPosY() + m_decalage_Y].getType()!=' ')&&(m_matrice[m_balle.getPosX()+m_decalage_X][m_balle.getPosY() + m_decalage_Y].getType()!='S'))
    {
        m_decalage_Y = -m_decalage_Y;
        m_decalage_X = -m_decalage_Y;
        if (((m_balle.getPosX()+m_decalage_X<=0)||(m_balle.getPosX()+m_decalage_Y>=N_LIGNES))||((m_balle.getPosY()+m_decalage_Y<=0)||(m_balle.getPosY()+m_decalage_Y>=N_COLONNES)))
        {
            m_decalage_Y = -m_decalage_Y;
            m_decalage_X = -m_decalage_Y;
        }
    }

    ///SI COINCE
    if((m_balle.getPosX()+m_decalage_X==-1)&&((m_matrice[m_balle.getPosX()+m_decalage_X][m_balle.getPosY() + m_decalage_Y].getType()==' ')||(m_matrice[m_balle.getPosX()+m_decalage_X][m_balle.getPosY() + m_decalage_Y].getType()=='S')))//� l'interieur
        m_decalage_X = -m_decalage_X;
    else if((m_balle.getPosX()+m_decalage_X==N_LIGNES)&&((m_matrice[m_balle.getPosX()+m_decalage_X][m_balle.getPosY() + m_decalage_Y].getType()==' ')||(m_matrice[m_balle.getPosX()+m_decalage_X][m_balle.getPosY() + m_decalage_Y].getType()=='S')))
        m_decalage_X = -m_decalage_X;
    else if((m_balle.getPosY()+m_decalage_Y==-1)&&((m_matrice[m_balle.getPosX()+m_decalage_X][m_balle.getPosY() + m_decalage_Y].getType()==' ')||(m_matrice[m_balle.getPosX()+m_decalage_X][m_balle.getPosY() + m_decalage_Y].getType()=='S')))
        m_decalage_Y = -m_decalage_Y;
    else if((m_balle.getPosY()+m_decalage_Y==N_COLONNES-1)&&((m_matrice[m_balle.getPosX()+m_decalage_X][m_balle.getPosY() + m_decalage_Y].getType()==' ')||(m_matrice[m_balle.getPosX()+m_decalage_X][m_balle.getPosY() + m_decalage_Y].getType()=='S')))
        m_decalage_Y = -m_decalage_Y;

    ///REMPLACEMENT
    /***    POUR PAS QUE CA EFFACE NAWAK QUOI
             if((m_matrice[m_balle.getPosX()+m_decalage_X][m_balle.getPosY()+m_decalage_Y].getType()!=' ')&&(m_matrice[m_balle.getPosX()+m_decalage_X][m_balle.getPosY()+m_decalage_Y].getType()!='S'))
             {
                 m_decalage_X = -m_decalage_X;
                 m_decalage_Y = -m_decalage_Y;
             }
    ***/
    m_balle.setPosX(m_balle.getPosX()+m_decalage_X);
    m_balle.setPosY(m_balle.getPosY()+m_decalage_Y);
    m_matrice[m_balle.getPosX()][m_balle.getPosY()] = m_balle;

    ///Diminuer nombre de vies de Snoopy si Balle touche Snoopy : mettre du sang :D ?
    if((m_balle.getPosX()==m_Snoopy.getPosX())&&(m_balle.getPosY()==m_Snoopy.getPosY()))
    {
        dead = true;
    }
    else dead = false;
    return dead;
}

///_________________________________________________________________________
void Matrice::bougerSnoopy(Console*conso,char& touche,bool& dead,int& niv)  ///Fonction de mouvement de Snoopy
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
        casser(conso, poslig, poscol);
        break;
    case 'b': ///BOMBE !!!!!!!! PROUUUUUU BOUM GNIAAAAH
        if((m_Snoopy.getOiseaux()>=1)&&(m_Snoopy.getVies()>2))
            boomShakaLaka(conso,poslig,poscol);
        break;
    }

    ///Si 'P' : pousser si poussable
    if(m_matrice[poslig][poscol].getEstPoussableblocmere()==true)
    {
        if(pousser(conso,touche)==false)
        {
            poslig = m_Snoopy.getPosX(); //revenir aux coordonn�es de d�part
            poscol = m_Snoopy.getPosY();
        }
    }
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
void Matrice::bougerElements(Console* conso,int& niv,int& score)        /// !!!!!! FONCTION PRINCIPALE DE NOTRE CODE : TOURNE TANT QU'ON NE MEURT PAS / QUITTE PAS
{
    bool quit = false;
    bool dead = false;
    char touche;
    if(niv>6)
    {
        niv=1;
        m_Snoopy.setVies(m_Snoopy.getVies()+3);   ///Vie bonus
    }

    initialisationMatrice(niv);
    afficherMatrice(conso);
    int start = clock();    //pour le temps : fonctions tr�s approximative. On note le temps lors du lancement du niveau, sinon mesure le temps �coul� depuis le lancement du programme
    std::string name; //pour la sauvegarde
    do
    {
        m_time = (clock()-start);
        for(int j = 60-(m_time/(CLOCKS_PER_SEC)); j < 60; j++) //efface les carr�s de temps chaque seconde (60 carr�s)
        {
            conso->gotoLigCol(POSLIGNE+N_LIGNES+10,POSCOLONNE+j);
            std::cout << ' ';
        }
        conso->setColor(COLOR_YELLOW);
        if(60000-m_time < 10000) // si on arrive a moins de 10 secondes restantes, alors un message en ROUGE s'affiche pour nous le dire !
        {
            conso->gotoLigCol(POSLIGNE+N_LIGNES+12,POSCOLONNE);
            conso->setColor(COLOR_RED);
            std::cout << "ATTENTION ! Moins de 10 secondes restantes...";
        }
        /*if(60000-m_time >= 0)
        {
            conso->gotoLigCol(10,45);
            std::cout << (60-(m_time/CLOCKS_PER_SEC)); // Lignes qui permettent d'afficher le temps : ne sert que pour debugger
            conso->setColor(COLOR_DEFAULT);
        }*/
        if(60000-m_time <= 200) // processeurs pas assez rapides pour tester == 0, donc on met une valeur tr�s petite (en milisecondes). Si le test est v�rifi�, TIME'S OUT
        {
            dead = true;
            m_Snoopy.setVies(0);
            m_Snoopy.setOiseaux(0); //tous les �l�ments sont automatiquements mis a 0. On quitte le jeu et on est renvoy� au menu !
        }
        if(fmod(m_time,100) < 26)   ///PLUS GROSSE SOURCE DE DIFFERENCES ENTRE ORDINATEUR : CETTE PARTIE DU CODE DEPEND ENTIREMENT DU PROCESSEUR ET SA CAPACITE A RENTRER DANS LA BOUCLE DE TEST
        {
            dead = bougerBalle(); //G�re la vitesse de la balle mais peut �tre tr�s al�atoire
        }
        afficherMatrice(conso);
        if(conso->ifKeyboardPressed())
        {
            touche=conso->getInputKey();
            if(touche == 27)
            {
                quit = true; //si on appuie sur "ESC", on quitte la partie
                system("cls");
                niv=4;
            }
            else if(touche == 'p') //pause
            {
                int menu_choix = 0;
                conso->setColor(COLOR_YELLOW);
                conso->gotoLigCol(5,46);
                std::cout << "MENU PAUSE"; //affiche un menu pause a droite de la matrice
                conso->gotoLigCol(7,46);
                conso->setColor(COLOR_RED);
                std::cout << "1. Sauvegarder votre partie";
                conso->setColor(COLOR_YELLOW);
                conso->gotoLigCol(9,46);
                std::cout << "2. Quitter ?";
                do
                {
                    touche = conso->getInputKey();
                    if(touche == 'z')
                    {
                        menu_choix = 0;
                        conso->gotoLigCol(7,46);    //comme pour le menu d'origine, on peut naviguer ce petit menu avec Z et S, puis la touche "Entr�e"
                        conso->setColor(COLOR_RED);
                        std::cout << "1. Sauvegarder votre partie";
                        conso->setColor(COLOR_YELLOW);
                        conso->gotoLigCol(9,46);
                        std::cout << "2. Quitter ?";
                    }
                    if(touche == 's')
                    {
                        menu_choix = 1;
                        conso->gotoLigCol(7,46);
                        conso->setColor(COLOR_YELLOW);
                        std::cout << "1. Sauvegarder votre partie";
                        conso->setColor(COLOR_RED);
                        conso->gotoLigCol(9,46);
                        std::cout << "2. Quitter ?";
                    }
                    if(touche == 13 && menu_choix == 1)   //choix du menu pause et reste sauvegarde a faire
                    {
                        quit = true;
                        niv = 4;
                        touche = 'p';
                    }
                    if(touche == 13 && menu_choix == 0) // sauvegarde de la partie
                    {
                        system("cls");
                        conso->gotoLigCol(POSLIGNE,POSCOLONNE);
                        std::cout << "Entrez votre nom de joueur : ";
                        std::cin >> name;
                        traduireMatrice();
                        conso->writeFile(name, m_tableau_sauvegarde,m_Snoopy.getVies(),m_Snoopy.getScore(),m_Snoopy.getOiseaux(),m_decalage_X,m_decalage_Y,niv);
                        touche = 'p';
                        system("cls");
                        quit = true; //on est renvoy� au menu !
                        niv = 4;
                    }
                }
                while (touche != 'p');
                conso->gotoLigCol(5,46);
                std::cout << "                     ";           // On "efface" le menu pause une fois la partie recommenc�e
                conso->gotoLigCol(7,46);
                std::cout << "                                       ";
                conso->gotoLigCol(9,46);
                std::cout << "                     ";
            }
            else
            {
                bougerSnoopy(conso,touche,dead,niv); ///on r�cup�re la touche entr�e par l'utilisateur et on fait bouger snoopy en fonction
            }
        }
        if(dead == true) //MORT
        {
            m_Snoopy.setVies(m_Snoopy.getVies()-1);
            m_Snoopy.setOiseaux(0);
            dead = false;
            //R�initialisation de la matrice de d�part du niveau !
            Sleep(1000);// Si on meurt : 1 seconde de latence pour marquer notre mort :D
            m_Snoopy.setPosX(SNOOPYPOSX);
            m_Snoopy.setPosY(SNOOPYPOSY); //on remet snoopy a 0, et la balle aussi
            m_matrice[m_balle.getPosX()][m_balle.getPosY()] = m_blocVide;
            m_balle.setPosX(BALLPOSX);
            m_balle.setPosY(BALLPOSY);
            initialisationElements(niv);
            if (m_Snoopy.getVies()==0)
            {
                m_Snoopy.setOiseaux(0);
                m_Snoopy.setVies(3);
                system("cls");
                ecranMort(conso);
                niv=4;
                m_Snoopy.setScore(0);
                quit=true;
            }
        }
        if(m_Snoopy.getOiseaux()==4) // VICTOIRE
        {
            ///Gagner partie : bouger le score
            m_Snoopy.setScore(m_Snoopy.getScore() + ((60-(m_time/CLOCKS_PER_SEC)))*100);
            score+=m_Snoopy.getScore();
            conso->writeHS(score);
            m_Snoopy.setOiseaux(0);
            ///Afficher qu'on a gagn�
            system("cls");
            ecranVictoire(conso,score);
            niv++;
            m_Snoopy.setPosX(SNOOPYPOSX);
            m_Snoopy.setPosY(SNOOPYPOSY);
            m_matrice[m_balle.getPosX()][m_balle.getPosY()] = m_blocVide;
            m_balle.setPosX(BALLPOSX);
            m_balle.setPosY(BALLPOSY);
            initialisationElements(niv);
            quit=true;
            system("cls");
            ///LE SCORE S'AJOUTE A LA FIN DE NOTRE SESSION DE JEU
        }
    }
    while(!quit);
}

///_________________________________________________________________________
void Matrice::casser(Console* conso, int& poslig, int& poscol) //fonction qui test si un bloc cassable est autour, et le casse si oui :D
{
    if(((poslig+1>=0)&&(poslig+1<N_COLONNES))||((poscol-1<N_LIGNES)&&(poscol-1>=0))||((poscol+1<N_LIGNES)&&(poscol+1>=0))||((poslig-1>=0)&&(poslig-1<N_COLONNES)))
    {
        if((m_matrice[poslig+1][poscol].getEstCassableblocmere()==true)||(m_matrice[poslig][poscol+1].getEstCassableblocmere()==true)||(m_matrice[poslig-1][poscol].getEstCassableblocmere()==true)||(m_matrice[poslig][poscol-1].getEstCassableblocmere()==true))
        {
            if(m_matrice[poslig+1][poscol].getEstCassableblocmere()==true)      /// ICI, on blinde la position de Snoopy pour effectuer les tests de blocs cassables ou non.
                poslig = poslig+1;
            else if(m_matrice[poslig][poscol+1].getEstCassableblocmere()==true)
                poscol = poscol+1;
            else if(m_matrice[poslig-1][poscol].getEstCassableblocmere()==true)
                poslig = poslig-1;
            else if(m_matrice[poslig][poscol-1].getEstCassableblocmere()==true)
                poscol = poscol-1;
            m_matrice[poslig][poscol] = m_blocVide;
            poslig = m_Snoopy.getPosX(); //revenir aux coordonn�es de d�part
            poscol = m_Snoopy.getPosY();
            conso->gotoLigCol(12, 45);
            std::cout << "                 ";
        }
    }
}

///_________________________________________________________________________
void Matrice::boomShakaLaka(Console* conso, int& poslig, int& poscol) ///FONCTION BONUS : TOUT EXPLOSE
{
    int nivBoom=7;
    initialisationElements(nivBoom);
}

///_________________________________________________________________________
bool Matrice::pousser(Console* conso, char& touche) ///VA POUSSER UN BLOC POUSSABLE
{
    //D�claration de variables
    int i = m_Snoopy.getPosX(),j = m_Snoopy.getPosY(); //on r�cup�re la position de snoopy
    bool estpousse=false;//va tester si on peut pousser le bloc, et modifier cette valeur si on pousse pour ne pousser qu'une seule fois

    switch(touche)
    {
    ///Chez nous, Snoopy bouge en m�me temps que la bloc poussable
    case 's': ///Pousser "bloc" vers le bas
        if((i+2<=N_LIGNES-1)&&(m_matrice[i+2][j].getType()==' '))//Pas sortir de la matrice
        {
            estpousse = true;
            m_matrice[i][j]=m_blocVide;
            // m_matrice[i+1][j]=m_Snoopy; //fait
            m_matrice[i+2][j]=m_blocPoussable;
            ///Rendre ce bloc 'P' non-poussable
            m_matrice[i+2][j].setEstPoussableblocmere(false);
        }

        break;
    case 'q':///Pousser "bloc" vers gauche
        if((m_matrice[i][j-2].getType()==' ')&&(j-2>=0)) //Pas sortir de la matrice
        {
            estpousse = true;
            m_matrice[i][j]=m_blocVide;
            //m_matrice[i][j-1]=m_Snoopy; //fait
            m_matrice[i][j-2]=m_blocPoussable;
            ///Rendre ce bloc 'P' non-poussable
            m_matrice[i][j-2].setEstPoussableblocmere(false);
        }
        break;
    case 'd':///Pousser "bloc" vers droite
        if((j+2<=N_COLONNES)&&(m_matrice[i][j+2].getType()==' ')) //Pas sortir de la matrice
        {
            estpousse = true;
            m_matrice[i][j]=m_blocVide;
            //m_matrice[i][j+1]=m_Snoopy; //fait
            m_matrice[i][j+2]=m_blocPoussable;
            ///Rendre ce bloc 'P' non-poussable
            m_matrice[i][j+2].setEstPoussableblocmere(false);
        }
        break;
    case 'z':///Pousser "bloc" vers haut
        if((i-2>=0)&&(m_matrice[i-2][j].getType()==' ')) //Pas sortir de la matrice
        {
            estpousse = true;
            m_matrice[i][j]=m_blocVide;
            //m_matrice[i-1][j]=m_Snoopy; //fait
            m_matrice[i-2][j]=m_blocPoussable;
            ///Rendre ce bloc 'P' non-poussable
            m_matrice[i-2][j].setEstPoussableblocmere(false);
        }
        break;
    }
    return estpousse;
}

void Matrice::ecranMort(Console* conso)
{
    conso->gotoLigCol(20,30);       ///Cet �cran s'affiche lorsque Snoopy perd toutes ses vies :(
    conso->setColor(COLOR_RED);
    std::cout << "VOUS AVEZ PERDU ! QUEL DOMMAGE !";
    conso->gotoLigCol(25,30);
    std::cout << "VOTRE SCORE EST DE : " << m_Snoopy.getScore()<<std::endl<<std::endl;
    conso->gotoLigCol(30,30);
    system("pause");
    conso->setColor(COLOR_DEFAULT);

}

void Matrice::ecranVictoire(Console* conso,int& score)
{
    conso->gotoLigCol(20,30);
    conso->setColor(COLOR_YELLOW);          // Au contraire, cet �cran s'affiche lorsqu'on gagne un niveau !
    std::cout << "EXCELLENT ! VOUS AVEZ REMPORTE LA PARTIE !";
    conso->gotoLigCol(25,30);
    std::cout << "VOTRE SCORE EST DE : " << score<<std::endl<<std::endl;
    conso->gotoLigCol(30,30);
    system("pause");
    conso->setColor(COLOR_DEFAULT);
}

void Matrice::traduireMatrice() ///POUR LA SAUVGARDE : traduit la matrice de blocs (on r�cup�re les types avec getType) en tableau 2D de chars
{
    for(int i = 0; i < N_LIGNES; i++)
    {
        for(int j = 0; j < N_COLONNES; j++)
        {
            m_tableau_sauvegarde[i][j] = m_matrice[i][j].getType();
        }
    }
}

void Matrice::traduireTableau()///POUR LE CHARGEMENT : on initialise une matrice de blocs en fonction d'un tableau 2D de chars
{
    int i = 0;
    int j = 0;

    for(i = 0; i < N_LIGNES; i++)
    {
        for(j = 0; j < N_COLONNES; j++)
        {
            if((m_tableau_sauvegarde[i][j] == 'O'))     ///On associe a chaque char lu dans le fichier sauvegard� un bloc de la matrice de jeu
            {
                m_matrice[i][j] = m_Oiseau;
            }
            if((m_tableau_sauvegarde[i][j] = ' '))
            {
                m_matrice[i][j] = m_blocVide;
            }
            if((m_tableau_sauvegarde[i][j] = 'P'))
            {
                m_matrice[i][j] = m_blocPoussable;
            }
            if((m_tableau_sauvegarde[i][j] = 'T'))
            {
                m_matrice[i][j] = m_blocT;
            }
            if((m_tableau_sauvegarde[i][j] = 'C'))
            {
                m_matrice[i][j] = m_blocC;
            }
            if((m_tableau_sauvegarde[i][j] = 'S'))
            {
                m_Snoopy.setPosX(i);
                m_Snoopy.setPosY(j);
                m_matrice[m_Snoopy.getPosX()][m_Snoopy.getPosY()] = m_Snoopy;
            }
            if((m_tableau_sauvegarde[i][j] = 'B'))
            {
                m_balle.setPosX(i);
                m_balle.setPosY(j);
                m_matrice[m_balle.getPosX()][m_balle.getPosY()] = m_balle;
            }
        }
    }
}


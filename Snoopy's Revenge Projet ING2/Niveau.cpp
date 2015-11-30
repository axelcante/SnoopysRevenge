#include "Niveau.h"

///Niveau gère la partie
//Initialisation: constructeurs & Destructeurs
//Constructeur
Niveau::Niveau() {};

//Desctruteur
Niveau::~Niveau() {};

//Accesseurs
std::string Niveau::getMdp() const
{
    return m_mdp;
}

//Setters
void Niveau::setMdp(std::string mdp)
{
    m_mdp = mdp;
}

//Methods
int Niveau::lancerJeu(Console* conso, int& niveaumdp)
{
    int choix = 0;
    int niv=1;
    if((niveaumdp<=1)&&(niveaumdp>=3))
        niv=niveaumdp;
    int score=0;
    m_matriceDeJeu.getSnoopy().setVies(3);
    system("cls");
    do
    {
        m_matriceDeJeu.afficherCadre(conso);
        m_matriceDeJeu.bougerElements(conso,niv,score);
        conso->gotoLigCol(40,30);
        if(niv<3)
            std::cout<<"Niveau suivant : " << niv<< "\n";
        system("pause");
        system("cls");
        m_matriceDeJeu.getSnoopy().setOiseaux(0);

    }
    while (niv<=3);
    afficherMenu(conso);
    return choix;
}

void Niveau::effetMenu(int choix, Console* conso)
{
    switch(choix)
    {
    case 1 :
        conso->setColor(COLOR_DEFAULT);
        conso->gotoLigCol(POSLIGNE+8,POSCOLONNE+8);
        std::cout << "1. Nouvelle partie";
        conso->gotoLigCol(POSLIGNE+10,POSCOLONNE+8);
        std::cout << "2. Charger partie";
        conso->gotoLigCol(POSLIGNE+12,POSCOLONNE+8);
        std::cout << "3. High scores";
        conso->gotoLigCol(POSLIGNE+14,POSCOLONNE+8);
        std::cout << "4. Entrer un mot de passe";
        conso->gotoLigCol(POSLIGNE+16,POSCOLONNE+8);
        std::cout << "5. Quitter le jeu";
        conso->setColor(COLOR_RED);
        conso->gotoLigCol(POSLIGNE+8,POSCOLONNE+8);
        std::cout << "1. Nouvelle partie";
        break;

    case 2 :
        conso->setColor(COLOR_DEFAULT);
        conso->gotoLigCol(POSLIGNE+8,POSCOLONNE+8);
        std::cout << "1. Nouvelle partie";
        conso->gotoLigCol(POSLIGNE+10,POSCOLONNE+8);
        std::cout << "2. Charger partie";
        conso->gotoLigCol(POSLIGNE+12,POSCOLONNE+8);
        std::cout << "3. High scores";
        conso->gotoLigCol(POSLIGNE+14,POSCOLONNE+8);
        std::cout << "4. Entrer un mot de passe";
        conso->gotoLigCol(POSLIGNE+16,POSCOLONNE+8);
        std::cout << "5. Quitter le jeu";
        conso->setColor(COLOR_RED);
        conso->gotoLigCol(POSLIGNE+10,POSCOLONNE+8);
        std::cout << "2. Charger partie";
        break;

    case 3 :
        conso->setColor(COLOR_DEFAULT);
        conso->gotoLigCol(POSLIGNE+8,POSCOLONNE+8);
        std::cout << "1. Nouvelle partie";
        conso->gotoLigCol(POSLIGNE+10,POSCOLONNE+8);
        std::cout << "2. Charger partie";
        conso->gotoLigCol(POSLIGNE+12,POSCOLONNE+8);
        std::cout << "3. High scores";
        conso->gotoLigCol(POSLIGNE+14,POSCOLONNE+8);
        std::cout << "4. Entrer un mot de passe";
        conso->gotoLigCol(POSLIGNE+16,POSCOLONNE+8);
        std::cout << "5. Quitter le jeu";
        conso->setColor(COLOR_RED);
        conso->gotoLigCol(POSLIGNE+12,POSCOLONNE+8);
        std::cout << "3. High scores";
        break;

    case 4 :
        conso->setColor(COLOR_DEFAULT);
        conso->gotoLigCol(POSLIGNE+8,POSCOLONNE+8);
        std::cout << "1. Nouvelle partie";
        conso->gotoLigCol(POSLIGNE+10,POSCOLONNE+8);
        std::cout << "2. Charger partie";
        conso->gotoLigCol(POSLIGNE+12,POSCOLONNE+8);
        std::cout << "3. High scores";
        conso->gotoLigCol(POSLIGNE+14,POSCOLONNE+8);
        std::cout << "4. Entrer un mot de passe";
        conso->gotoLigCol(POSLIGNE+16,POSCOLONNE+8);
        std::cout << "5. Quitter le jeu";
        conso->setColor(COLOR_RED);
        conso->gotoLigCol(POSLIGNE+14,POSCOLONNE+8);
        std::cout << "4. Entrer un mot de passe";
        break;

    case 5 :
        conso->setColor(COLOR_DEFAULT);
        conso->gotoLigCol(POSLIGNE+8,POSCOLONNE+8);
        std::cout << "1. Nouvelle partie";
        conso->gotoLigCol(POSLIGNE+10,POSCOLONNE+8);
        std::cout << "2. Charger partie";
        conso->gotoLigCol(POSLIGNE+12,POSCOLONNE+8);
        std::cout << "3. High scores";
        conso->gotoLigCol(POSLIGNE+14,POSCOLONNE+8);
        std::cout << "4. Entrer un mot de passe";
        conso->gotoLigCol(POSLIGNE+16,POSCOLONNE+8);
        std::cout << "5. Quitter le jeu";
        conso->setColor(COLOR_RED);
        conso->gotoLigCol(POSLIGNE+16,POSCOLONNE+8);
        std::cout << "5. Quitter le jeu";
    }
}

void Niveau::afficherMenu(Console* conso)
{
    conso->setColor(COLOR_YELLOW);

    conso->gotoLigCol(15,60);       //affichage du titre stylé de Snoopy's Revenge
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

    conso->gotoLigCol(POSLIGNE,POSCOLONNE+3);       //affichage du menu normal des choix proposés
    std::cout << "Bienvenue dans l'incroyable monde de Snoopy !";
    conso->gotoLigCol(POSLIGNE+2,POSCOLONNE);
    std::cout << "Un jeu concu par Juliette HEUANGTHEP et Axel CANTE !";
    conso->gotoLigCol(POSLIGNE+4,POSCOLONNE+1);
    std::cout << "Utilisez les touches Z et S pour naviguer le menu.";
    conso->setColor(COLOR_DEFAULT);
    conso->gotoLigCol(POSLIGNE+8,POSCOLONNE+8);
    std::cout << "1. Nouvelle partie";
    conso->gotoLigCol(POSLIGNE+10,POSCOLONNE+8);
    std::cout << "2. Charger partie";
    conso->gotoLigCol(POSLIGNE+12,POSCOLONNE+8);
    std::cout << "3. High scores";
    conso->gotoLigCol(POSLIGNE+14,POSCOLONNE+8);
    std::cout << "4. Entrer un mot de passe";
    conso->gotoLigCol(POSLIGNE+16,POSCOLONNE+8);
    std::cout << "5. Quitter le jeu";
    conso->gotoLigCol(POSLIGNE+20,POSCOLONNE+8);
}

void Niveau::play(Console* conso)
{
    int menu_choix = 1;
    int niveaumdp = 0;
    bool quit = false;
    afficherMenu(conso);
    effetMenu(menu_choix,conso);

    while(!quit)
    {
        if(conso->ifKeyboardPressed())
        {
            int key = conso->getInputKey();
            if(key == 115)
            {
                menu_choix++;
                if(menu_choix == 6)
                    menu_choix = 5;

                effetMenu(menu_choix, conso);
            }
            if(key == 122)
            {
                menu_choix--;
                if(menu_choix == 0)
                    menu_choix = 1;

                effetMenu(menu_choix, conso);
            }

            if(menu_choix == 1 && key == 13)
            {
                menu_choix = lancerJeu(conso,niveaumdp);
            }
            if(menu_choix == 5 && key == 13)
            {
                quit = true;
            }
            if((menu_choix == 4)&&(key == 13))
            {
                niveaumdp=mdpNiveau(conso);
                if(niveaumdp<4)
                    lancerJeu(conso, niveaumdp);
                else
                {
                    system("cls");
                    afficherMenu(conso);
                    effetMenu(menu_choix, conso);
                }
            }
            if(key == 27)
            {
                quit = true;
            }
            if(menu_choix == 2 && key == 13)
            {
                std::string name;
                system("cls");
                conso->gotoLigCol(POSLIGNE,POSCOLONNE);
                std::cout << "Entrez votre nom de joueur : ";
                std::cin >> name;
                //name += ".txt";
                conso->readFile(name,m_matriceDeJeu.m_tableau_sauvegarde,m_matriceDeJeu.getSnoopy().getVies(),m_matriceDeJeu.getSnoopy().getScore(),m_matriceDeJeu.getSnoopy().getOiseaux(),m_matriceDeJeu.getDecalageX(),m_matriceDeJeu.getDecalageY(),niveaumdp); ///il faut envoyer la matrice de jeu d'une façon ou d'une autre pour la sauvegarde
            }
        }
    }
}

int Niveau::mdpNiveau(Console* conso)
{
    //Declaration des variables
    std::string mdp; //mot de passe
    std::string mdp1="dimsum"; //mot de passe
    std::string mdp2="seum"; //mot de passe
    std::string mdp3="chat"; //mot de passe
    system("cls");
    conso->gotoLigCol(POSLIGNE,POSCOLONNE+3);
    std::cout<<"Entrez un mot de passe : ";
    std::cin>>mdp;
    ///Si niveau 1
    if(mdp==mdp1)
        return 1;
    else if (mdp==mdp2) ///Sinon niveau 2
        return 2;
    else if (mdp==mdp3)///Et bah non, niveau 3
        return 3;
    else
    {
        conso->gotoLigCol(POSLIGNE+2,POSCOLONNE+3);
        std::cout<<"Incorrect.\n";
        conso->gotoLigCol(POSLIGNE+4,POSCOLONNE+3);
        system("pause");
        return 4;
    }
}
//void Niveau::sauvegarde(const std::string& name, char tableau[N_LIGNES][N_COLONNES], int vies, int score, int oiseaux, int time, int decalageX, int decalageY, Console* conso)
//{
//}


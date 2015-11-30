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
int Niveau::lancerJeu(Console* conso)
{
    int choix = 0;
    int niv=1;
    system("cls");
    do
    {
        Matrice MatriceDeJeu;
        MatriceDeJeu.afficherCadre(conso);
        MatriceDeJeu.bougerElements(conso,niv);
        conso->gotoLigCol(40,30);
        if(niv<=3)
        std::cout<<"Niveau suivant : " << niv+1 << "\n";
        system("pause");
        system("cls");
        ///juste: pas réinitialiser score à chaque niveau
    }while (niv<3);
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

void Niveau::play(Console* conso, Matrice matriceDeJeu)
{
    int menu_choix = 1;
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
                {
                    menu_choix = 5;
                }
                effetMenu(menu_choix, conso);
            }
            if(key == 122)
            {
                menu_choix--;
                if(menu_choix == 0)
                {
                    menu_choix = 1;
                }
                effetMenu(menu_choix, conso);
            }
            if(menu_choix == 1 && key == 13)
            {
                menu_choix = lancerJeu(conso);
            }
            if(menu_choix == 5 && key == 13)
            {
                quit = true;
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
                name += ".txt";
                conso->readFile(name,) ///il faut envoyer la matrice de jeu d'une façon ou d'une autre pour la sauvegarde
            }
        }
    }
}

//void Niveau::sauvegarde(const std::string& name, char tableau[N_LIGNES][N_COLONNES], int vies, int score, int oiseaux, int time, int decalageX, int decalageY, Console* conso)
//{
//}


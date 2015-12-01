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
int Niveau::lancerJeu(Console* conso, int& niveaumdp, bool partie)
{
    int choix = 0;  //variable qui va permettre au joueur de naviguer le menu
    int niv = 1;    //variable qui lancera le niveau de jeu correspondant
    int score = 0;  //variable qui initialisera le score

    if(!partie)     //test si une partie sauvegardée est lancée. Si non, on lance une nouvelle partie en fonction du mot de passe entré
    {
        niv=1;
        if(((niveaumdp>=1)&&(niveaumdp<=3))||(niveaumdp==6))
        niv=niveaumdp;
        m_matriceDeJeu.getSnoopy().setVies(3);
        system("cls");
    }
    else        //si une partie sauvegardée est détectée, on la lance ! Seul le temps n'est pas sauvegardé (fonction clock() difficile a manier)
    {
        niv = niveaumdp;
        score = m_matriceDeJeu.getSnoopy().getScore();  //a ce niveau ci le score a été chargé depuis la précédent partie
        system("cls");
    }
    do
    {
        m_matriceDeJeu.afficherCadre(conso);        //fonction qui affiche le cadre de la matrice et le titre !
        m_matriceDeJeu.bougerElements(conso,niv,score);     //fonction principale du jeu qui tourne tant qu'on ne quitte pas
        conso->gotoLigCol(20,30);
        if(niv<3)   //gestion de la progression des niveaux
        std::cout<<"Niveau suivant : " << niv<< "\n";
        system("pause");
        system("cls");
        m_matriceDeJeu.getSnoopy().setOiseaux(0);   //a chaque nouveau niveau, on réinitialise les oiseaux bien sur

    }
    while ((niv<=3)||(niv>6));
    afficherMenu(conso);
    return choix;
}

void Niveau::effetMenu(int choix, Console* conso) //fonction qui affiche un beau menu avec des effets de séléction !
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

void Niveau::afficherMenu(Console* conso) //idem
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
    int niveaumdp = 0; //variable qui va tester si on rentre le bon mot de passe
    bool quit = false; //tant qu'on ne quitte par le jeu, cette fonction tourne
    afficherMenu(conso);
    effetMenu(menu_choix,conso);

    while(!quit)
    {
        if(conso->ifKeyboardPressed())
        {
            int key = conso->getInputKey();
            if(key == 115)
            {
                menu_choix++;       //menu_choix permet de naviguer dans le menu avec les touches z et s, blindées entre 1 et 5
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

            if(menu_choix == 1 && key == 13) //on lance une nouvelle partie
            {
                menu_choix = lancerJeu(conso,niveaumdp,false);
            }
            if(menu_choix == 5 && key == 13) //on quite le jeu
            {
                quit = true;
            }
            if((menu_choix == 4)&&(key == 13))  //on rentre un mot de passe : s'il est bon, on lance le niveau correspondant
            {
                niveaumdp=mdpNiveau(conso);
                if((niveaumdp<4)||(niveaumdp==6))
                    lancerJeu(conso, niveaumdp,false);
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
            if(menu_choix == 2 && key == 13) //chargement d'une partie. On doit entrer le nom de joueur et, si le fichier existe, on lance la partie !
            {
                std::string name;
                system("cls");
                conso->gotoLigCol(POSLIGNE,POSCOLONNE);
                std::cout << "Entrez votre nom de joueur : ";
                std::cin >> name;
                readFile(name,m_matriceDeJeu.m_tableau_sauvegarde,m_matriceDeJeu.getSnoopy().getVies(),m_matriceDeJeu.getSnoopy().getScore(),m_matriceDeJeu.getSnoopy().getOiseaux(),m_matriceDeJeu.getDecalageX(),m_matriceDeJeu.getDecalageY(),niveaumdp, conso);
                lancerJeu(conso,niveaumdp,true); //si le nom coincide, on lance la partie chargée !
            }
        }
    }
}

int Niveau::mdpNiveau(Console* conso) //fonction qui va tester le mot de passe entré
{
    //Declaration des variables
    std::string mdp; //mot de passe
    std::string mdp1="dimsum"; //mot de passe
    std::string mdp2="seum"; //mot de passe
    std::string mdp3="chat"; //mot de passe
    std::string mdp4="chien"; //mot de passe
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
    ///Si niveau bonus
    else if (mdp==mdp4)
        return 6;
    else///Ou pas
    {
        conso->gotoLigCol(POSLIGNE+2,POSCOLONNE+3);
        std::cout<<"Incorrect.\n";
        conso->gotoLigCol(POSLIGNE+4,POSCOLONNE+3);
        system("pause");
        return 4;
    }
}

///FONCTION DE CHARGEMENT
///PLACEE DANS NIVEAU POUR EVITER DES POINTEURS INUTILES
///On charge la MATRICE puis les DONNEES de la matrice
void Niveau::readFile(std::string name, char tableau[N_LIGNES][N_COLONNES], int vies, int score, int oiseaux, int decalageX, int decalageY, int& niveau, Console* conso)
{
    std::ifstream ifs(name.c_str()); ///Premier chargement : LA MATRICE
    std::string line;
    int i = 0;
    if(ifs.is_open()) // test si le fichier est bien ouvert
    {
        while(getline(ifs,line))
        {
            for(int j = 0; j < N_COLONNES; j++)
            {
                tableau[i][j] = line[j];
            }
            i++;
        }
        ifs.close(); //fermeture du flux
        conso->gotoLigCol(POSLIGNE+2,POSCOLONNE);
        std::cout << "Le chargement de la matrice est termine !";
        conso->gotoLigCol(POSLIGNE+4,POSCOLONNE);
        system("pause");
    }
    else // en cas d'erreur...
    {
        conso->gotoLigCol(POSLIGNE+2,POSCOLONNE);
        std::cout << "ERREUR d'ouverture du fichier";
        conso->gotoLigCol(POSLIGNE+4,POSCOLONNE);
        system("pause");
    }
    name += "_donnees"; ///DEUXIEME CHARGEMENT : nom de joueur + _donnees pour trouver le fichier
    std::ifstream myFlux(name.c_str());
    if(myFlux.is_open())
    {
        while(myFlux >> vies >> score >> oiseaux >> decalageX >> decalageY >> niveau)
        {
        }
        myFlux.close();
        conso->gotoLigCol(POSLIGNE+6,POSCOLONNE);
        std::cout << "Le chargement des donnees est termine !";
        conso->gotoLigCol(POSLIGNE+8,POSCOLONNE);
        system("pause");
        conso->gotoLigCol(POSLIGNE+12,POSCOLONNE);      //on initialise les données de jeu avec les données chargées
        m_matriceDeJeu.getSnoopy().setVies(vies);
        m_matriceDeJeu.getSnoopy().setScore(score);
        m_matriceDeJeu.getSnoopy().setOiseaux(oiseaux);
        m_matriceDeJeu.setDecalageX(decalageX);
        m_matriceDeJeu.setDecalageY(decalageY);
    }
    else // en cas d'erreur...
    {
        conso->gotoLigCol(POSLIGNE+6,POSCOLONNE);
        std::cout << "ERREUR d'ouverture du fichier";
        conso->gotoLigCol(POSLIGNE+8,POSCOLONNE);
        system("pause");
    }
}


#include "Niveau.h"

///Niveau gère la partie
//Initialisation: constructeurs & Destructeurs
//Constructeur
Niveau::Niveau() {};
//Desctruteur
Niveau::~Niveau() {};

//Accesseurs
float Niveau::getTemps() const
{
    return m_temps;
}
Matrice Niveau::getMatrice() const
{
    return m_matriceDeJeu;
}
std::string Niveau::getMdp() const
{
    return m_mdp;
}

//Setters
void Niveau::setTemps(float temps)
{
    m_temps = temps;
}
void Niveau::setMatrice(Matrice matriceDeJeu)
{
    m_matriceDeJeu = matriceDeJeu;
}
void Niveau::setMdp(std::string mdp)
{
    m_mdp = mdp;
}

//Methods
int Niveau::lancerJeu(Console* conso)
{
    int choix = 0;
    system("cls");
    Matrice matrice_niveau_1;
    matrice_niveau_1.afficherCadre(conso);
    matrice_niveau_1.bougerElements(conso);
    conso->gotoLigCol(40,30);
    system("pause");
    system("cls");
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
    conso->gotoLigCol(30,30);       //affichage du titre stylé de Snoopy's Revenge

    /*std::ifstream lecture ("SnoopyTitle.txt");      //ouverture du fichier (s'il existe)
    std::string titre = lireFichier(lecture);
    std::cout << titre;
    lecture.close();*/

    conso->gotoLigCol(POSLIGNE,POSCOLONNE+3);       //affichage du menu normal des choix proposés
    std::cout << "Bienvenue dans l'incroyable monde de Snoopy !";
    conso->gotoLigCol(POSLIGNE+2,POSCOLONNE);
    std::cout << "Un jeu concu par Juliette HEUANGTHEP et Axel CANTE !";
    conso->gotoLigCol(POSLIGNE+4,POSCOLONNE+1);
    std::cout << "Utilisez les touches Z et S poaur naviguer le menu.";
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
        }
    }
}

/*std::string Niveau::lireFichier(std::ifstream& Fichier)
{
    std::string Lignes = "";

    if(Fichier)
    {
        while(Fichier.good())
        {
            std::string ligne_tmp;
            std::getline(Fichier,ligne_tmp);
            Lignes += ligne_tmp;
        }
        return Lignes;
    }
    else        //Erreur de lecture ou fichier n'existe pas
    {
        return "ERREUR : fichier n'existe pas";
    }
}*/

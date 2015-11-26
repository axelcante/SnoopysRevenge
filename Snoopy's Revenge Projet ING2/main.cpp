#include <iostream>
#include "Bloc.h"
#include "Matrice.h"
#include "Niveau.h"
#include "console.h"
#include <vector>
#include <windows.h>
#include "Constantes.h"
#include <time.h>
//Si décalage du tableau sur console

void effetMenu(int choix, Console* conso);
void lancerJeu(Console* conso);

int main()
{
    Console* conso = Console::getInstance(); //Allocation mémoire du pointeur sur console
    conso->ShowConsoleCursor(false); //On rend le curseur de la console invisible pour ne pas avoir de clignotements
    int menu_choix = 0;

    conso->setColor(COLOR_YELLOW);
    conso->gotoLigCol(POSLIGNE,POSCOLONNE+3);
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
    std::cout << "4. Comment jouer";
    conso->gotoLigCol(POSLIGNE+16,POSCOLONNE+8);
    std::cout << "5. Quitter le jeu";
    conso->gotoLigCol(POSLIGNE+20,POSCOLONNE+8);
    clock_t init, fin, timer;
    init = clock();


    bool quit = false;
    while(!quit)
    {
        fin = clock()-init;
        conso->gotoLigCol(POSLIGNE+16,POSCOLONNE+40);
        timer = fin / (CLOCKS_PER_SEC);
        if(timer%2 == 0)
        {
            std::cout << fin / (CLOCKS_PER_SEC);
        }
        if(conso->ifKeyboardPressed())
        {
            int key = conso->getInputKey();
            if(key == 115)
            {
                menu_choix++;
                if(menu_choix == 6){menu_choix = 5;}
                effetMenu(menu_choix, conso);
            }
            if(key == 122)
            {
                menu_choix--;
                if(menu_choix == 0){menu_choix = 1;}
                effetMenu(menu_choix, conso);
            }
            if(menu_choix == 1 && key == 13)
            {
                lancerJeu(conso);
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

    /*
     ___                        _   ___
    / __|_ _  ___ ___ _ __ _  _( __| _ \_____ _____ _ _  __ _ ___
    \__ | ' \/ _ / _ | '_ | || |(_-|   / -_\ V / -_| ' \/ _` / -_)
    |___|_||_\___\___| .__/\_, |/__|_|_\___|\_/\___|_||_\__, \___|
                     |_|   |__/                         |___/
    */

///Déclaration variables
//char var ='a';
//char& touche = var; //Touche utilisée pour les interactions avec l'utilisateur
//initialisation de la matrice et du premier niveau

///Menu


//matrice_niveau_1.bougerBalle();
//char touche; //touche appuyee par le joueur
//bool estPoussable;

// matrice_niveau_1.afficherMatrice();
    /* estPoussable = (matrice_niveau_1.getMatrice().getType()=='P');
     //réference
     int& posX= matrice_niveau_1.getMatrice().getPosX();
     int& posY= matrice_niveau_1.getMatrice().getPosY();*/


//conso->gotoLigCol(POSLIGNE,POSCOLONNE);
    conso->deleteInstance();
    return 0;

}

void lancerJeu(Console* conso)
{
    system("cls");
    Matrice matrice_niveau_1;
    matrice_niveau_1.afficherCadre(conso);
    matrice_niveau_1.bougerElements(conso);
}

void effetMenu(int choix, Console* conso)
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
        std::cout << "4. Comment jouer";
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
        std::cout << "4. Comment jouer";
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
        std::cout << "4. Comment jouer";
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
        std::cout << "4. Comment jouer";
        conso->gotoLigCol(POSLIGNE+16,POSCOLONNE+8);
        std::cout << "5. Quitter le jeu";
        conso->setColor(COLOR_RED);
        conso->gotoLigCol(POSLIGNE+14,POSCOLONNE+8);
        std::cout << "4. Comment jouer";
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
        std::cout << "4. Comment jouer";
        conso->gotoLigCol(POSLIGNE+16,POSCOLONNE+8);
        std::cout << "5. Quitter le jeu";
        conso->setColor(COLOR_RED);
        conso->gotoLigCol(POSLIGNE+16,POSCOLONNE+8);
        std::cout << "5. Quitter le jeu";
    }
}

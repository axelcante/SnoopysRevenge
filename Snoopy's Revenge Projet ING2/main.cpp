#include <iostream>
#include "Bloc.h"
#include "Matrice.h"
#include "Niveau.h"
#include "console.h"
#include <vector>
#include <windows.h>
//Si décalage du tableau sur console


int main()
{
    ///Déclaration variables
    //char var ='a';
    //char& touche = var; //Touche utilisée pour les interactions avec l'utilisateur

    ///Test
    Console* conso = Console::getInstance(); //Allocation mémoire du pointeur sur console
    conso->ShowConsoleCursor(false); //Ne pas montrer le curseur, c'est moche

    //initialisation de la matrice et du premier niveau
    Matrice matrice_niveau_1;
    matrice_niveau_1.afficherCadre(conso);
    matrice_niveau_1.bougerElements(conso);

    ///Menu



    //Désallocation mémoire
    conso->deleteInstance();
    return 0;

}

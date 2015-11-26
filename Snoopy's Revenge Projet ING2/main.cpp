#include <iostream>
#include "Bloc.h"
#include "Matrice.h"
#include "Niveau.h"
#include "console.h"
#include <vector>
#include <windows.h>
//Si d�calage du tableau sur console


int main()
{
    ///D�claration variables
    //char var ='a';
    //char& touche = var; //Touche utilis�e pour les interactions avec l'utilisateur

    ///Test
    Console* conso = Console::getInstance(); //Allocation m�moire du pointeur sur console
    conso->ShowConsoleCursor(false); //Ne pas montrer le curseur, c'est moche

    //initialisation de la matrice et du premier niveau
    Matrice matrice_niveau_1;
    matrice_niveau_1.afficherCadre(conso);
    matrice_niveau_1.bougerElements(conso);

    ///Menu



    //D�sallocation m�moire
    conso->deleteInstance();
    return 0;

}

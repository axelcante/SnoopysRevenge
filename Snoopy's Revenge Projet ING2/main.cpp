#include <iostream>
#include "Bloc.h"
#include "Matrice.h"
#include "Niveau.h"
#include "console.h"
#include <vector>
#include <windows.h>
#include "Constantes.h"
#include <time.h>

int main()
{
    //Réglage de la taille de la console
    console con( 170, 50 );
    //Création du pointeur conso pour gérer la console
    Console* conso = Console::getInstance(); //Allocation mémoire du pointeur sur console
    conso->ShowConsoleCursor(false); //On rend le curseur de la console invisible pour ne pas avoir de clignotements
    //Création du nivaeu
    Niveau niveau_1;
    //Jouer
    niveau_1.play(conso);
    //Désallocation du pointeur conso
    conso->deleteInstance();

    return 0;
}

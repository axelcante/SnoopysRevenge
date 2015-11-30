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
    //R�glage de la taille de la console
    console con( 170, 50 );
    //Cr�ation du pointeur conso pour g�rer la console
    Console* conso = Console::getInstance(); //Allocation m�moire du pointeur sur console
    conso->ShowConsoleCursor(false); //On rend le curseur de la console invisible pour ne pas avoir de clignotements
    //Cr�ation du nivaeu
    Niveau niveau_1;
    //Jouer
    niveau_1.play(conso);
    //D�sallocation du pointeur conso
    conso->deleteInstance();

    return 0;
}

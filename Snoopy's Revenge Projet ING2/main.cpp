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
    Console* conso = Console::getInstance(); //Allocation mémoire du pointeur sur console
    conso->ShowConsoleCursor(false); //On rend le curseur de la console invisible pour ne pas avoir de clignotements

    Niveau niveau_1;
    niveau_1.play(conso);

    conso->deleteInstance();

    return 0;

}

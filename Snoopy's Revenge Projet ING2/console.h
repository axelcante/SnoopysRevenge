#ifndef CONSOLE_H_INCLUDED
#define CONSOLE_H_INCLUDED
#include <windows.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#include "Constantes.h"

enum Color
{
    COLOR_BLACK = 0,
    COLOR_WHITE = 1,
    COLOR_RED = 2,
    COLOR_GREEN = 3,
    COLOR_BLUE = 4,
    COLOR_YELLOW = 5,
    COLOR_PURPLE = 6,
    COLOR_DEFAULT = 7, // gris couleur de base de la console
};

class Console
{
    private:
        // Empecher la création
        Console();
        ~Console();

        // Empecher la copie d'objet...
        Console& operator= (const Console&){ return *this;}
        Console (const Console&){}

        // Attributs
        static Console* m_instance;

        // Méthodes privées
        void _setColor(int front, int back);
    public:
        // Méthodes statiques (publiques)
        static Console* getInstance();
        static void deleteInstance();

        // Méthodes publiques
        void gotoLigCol(int lig, int col);
        bool ifKeyboardPressed();
        char getInputKey();
        void setColor(Color col);
        void ShowConsoleCursor(bool showFlag);
        void writeFile(const std::string& name, char tableau[N_LIGNES][N_COLONNES], int vies, int score, int oiseaux, int time, int decalageX, int decalageY);
};

#endif // CONSOLE_H_INCLUDED

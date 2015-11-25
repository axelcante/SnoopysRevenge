#include <iostream>
#include "console.h"

int main()
{
    bool quit = false;
    Console* pConsole = NULL;

    // Alloue la m�moire du pointeur
    pConsole = Console::getInstance();

    // Affichage avec gotoligcol et couleur
    pConsole->gotoLigCol(5, 10);
    pConsole->setColor(COLOR_GREEN);
    std::cout << "Hello World !" << std::endl;
    pConsole->setColor(COLOR_DEFAULT);

    // Boucle �v�nementielle
    while (!quit)
    {
        // Si on a appuy� sur une touche du clavier
        if (pConsole->isKeyboardPressed())
        {
            // R�cup�re le code ASCII de la touche
            int key = pConsole->getInputKey();
            std::cout << "touche = " << key << std::endl;

            if (key == 'a' || key == 27) // 27 = touche escape
            {
                quit = true;
            }
        }
    }

    // Lib�re la m�moire du pointeur !
    Console::deleteInstance();
    using namespace System;

    String^ m1 = "\nThe cursor is {0}.\nType any text then press Enter. "
                 "Type '+' in the first column to show \n"
                 "the cursor, '-' to hide the cursor, "
                 "or lowercase 'x' to quit:";
    String^ s;
    bool saveCursorVisibile;
    int saveCursorSize;

    //
    Console::CursorVisible = true; // Initialize the cursor to visible.
    saveCursorVisibile = Console::CursorVisible;
    saveCursorSize = Console::CursorSize;
    Console::CursorSize = 100; // Emphasize the cursor.
    for ( ; ;  )
    {
        Console::WriteLine( m1, ((Console::CursorVisible == true) ? (String^)"VISIBLE" : "HIDDEN") );
        s = Console::ReadLine();
        if ( String::IsNullOrEmpty( s ) == false )
            if ( s[ 0 ] == '+' )
                Console::CursorVisible = true;
            else if ( s[ 0 ] == '-' )
                Console::CursorVisible = false;
            else if ( s[ 0 ] == 'x' )
                break;

    }
    Console::CursorVisible = saveCursorVisibile;
    Console::CursorSize = saveCursorSize;

    return 0;
}

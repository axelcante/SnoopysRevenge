#include "console.h"

Console* Console::m_instance = NULL;

Console::Console()
{
    m_instance = NULL;
}

Console::~Console()
{

}

void Console::deleteInstance()
{
    delete m_instance;
    m_instance = NULL;
}

Console* Console::getInstance()
{
    if (!Console::m_instance)
    {
        m_instance = new Console();
    }

    return m_instance;
}

void Console::gotoLigCol(int lig, int col)
{
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), mycoord );
}

char Console::getInputKey()
{
    return getch();
}

bool Console::ifKeyboardPressed()
{
    return kbhit();
}

/*
0: noir
1: bleu fonc�
2: vert
3: bleu-gris
4: marron
5: pourpre
6: kaki
7: gris clair
8: gris
9: bleu
10: vert fluo
11: turquoise
12: rouge
13: rose fluo
14: jaune fluo
15: blanc
*/
void Console::_setColor(int back, int front)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,front*16+back);
}

//procedure qui �crit dans un fichier .txt
void writeFile(const std::string& name, char m_matrice[N_LIGNES][N_COLONNES], int vies, int score, int oiseaux, int time, int decalageX, int decalageY)
{
    // Ouverture fichier en mode "w"
    // Cette fonction recoit un tableau de chars qui sera repr�sentatif de la matrice de jeu
    std::ofstream ofs(name.c_str(), std::ios::out);
    if (ofs)
    {
        // Ecriture dans le fichier
        for(int i = 0; i < N_LIGNES; i++)
        {
            for(int j = 0; j < N_COLONNES; j++)
            {
                ofs << m_matrice[i][j];
            }
            ofs << std::endl;
        }
        ofs << vies << std::endl;
        ofs << score << std::endl;
        ofs << oiseaux << std::endl;
        ofs << time << std::endl;
        ofs.close(); // fermeture du flux
    }
}

void Console::ShowConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void Console::setColor(Color col)
{
    switch (col)
    {
    case COLOR_WHITE:
        this->_setColor(15, 0);
        break;
    case COLOR_BLACK:
        this->_setColor(0, 0);
        break;
    case COLOR_RED:
        this->_setColor(12, 0);
        break;
    case COLOR_GREEN:
        this->_setColor(10, 0);
        break;
    case COLOR_BLUE:
        this->_setColor(9, 0);
        break;
    case COLOR_YELLOW:
        this->_setColor(14, 0);
        break;
    case COLOR_PURPLE:
        this->_setColor(5, 0);
        break;
    default:
        this->_setColor(7, 0);
    }
}

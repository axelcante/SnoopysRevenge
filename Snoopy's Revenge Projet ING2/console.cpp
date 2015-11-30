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
1: bleu foncé
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

//procedure qui écrit dans un fichier .txt
void Console::writeFile(std::string name, char tableau[N_LIGNES][N_COLONNES], int vies, int score, int oiseaux, int decalageX, int decalageY, int niveau)
{
    // Ouverture fichier en mode "w"
    // Cette fonction recoit un tableau de chars qui sera représentatif de la matrice de jeu
    std::ofstream ofs(name.c_str(), std::ios::out);
    if (ofs)
    {
        // Ecriture dans le fichier
        for(int i = 0; i < N_LIGNES; i++)
        {
            for(int j = 0; j < N_COLONNES; j++)
            {
                ofs << tableau[i][j];
            }
            ofs << std::endl;
        }
        ofs << vies << std::endl;
        ofs << score << std::endl;
        ofs << oiseaux << std::endl;
        ofs << decalageX << std::endl;
        ofs << decalageY << std::endl;
        ofs.close(); // fermeture du flux
        gotoLigCol(POSLIGNE+2,POSCOLONNE);
        std::cout << "La sauvegarde est effectuee !";
        gotoLigCol(POSLIGNE+4,POSCOLONNE);
        system("pause");
    }
    else
    {
        gotoLigCol(POSLIGNE+2,POSCOLONNE);
        std::cout << "ERREUR d'ouverture du fichier";
        gotoLigCol(POSLIGNE+4,POSCOLONNE);
        system("pause");
    }
}

// Lire un fichier ligne par ligne
// Entrée : le chemin d'accès au fichier

void Console::readFile(std::string name, char tableau[N_LIGNES][N_COLONNES], int vies, int score, int oiseaux, int decalageX, int decalageY, int niveau)
{
    std::ifstream ifs(name.c_str());
    std::string line;
    int i = 0;
    if(ifs.is_open()) // test si le fichier est bien ouvert
    {
        while(getline(ifs,line))
        {
            for(int j = 0; j < N_COLONNES; j++)
            {
                tableau[i][j] = line[j];
            }
            i++;
        }
        /*vies = line;
        i++;
        score = line;
        i++;
        oiseaux = line;
        i++;
        decalageX = line;
        i++;
        decalageY = line;
        i++;*/
        ifs.close(); //fermeture du flux
        gotoLigCol(POSLIGNE+2,POSCOLONNE);
        std::cout << "Le chargement est termine !";
        gotoLigCol(POSLIGNE+4,POSCOLONNE);
        system("pause");
        system("cls");
        system("pause");

    }

    else // en cas d'erreur...
    {
        gotoLigCol(POSLIGNE+2,POSCOLONNE);
        std::cout << "ERREUR d'ouverture du fichier";
        gotoLigCol(POSLIGNE+4,POSCOLONNE);
        system("pause");
    }
    for(int i = 0; i < N_LIGNES; i++)
    {
        for(int j = 0; j < N_COLONNES; j++)
        {
            std::cout << tableau[i][j];
        }
        std::cout << std::endl;
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


/*void Console::readFile(std::string name, char tableau[N_LIGNES][N_COLONNES], int vies, int score, int oiseaux, double time, int decalageX, int decalage)
{
    std::string file("Sauvegardes/");
    file += name;
    file += ".txt";
    std::ifstream ifs(file.c_str());
    if (ifs) // test si le fichier est bien ouvert
    {
        std::string line;
        while (std::getline(ifs, line)) // lecture ligne par ligne
        {
            std::cout << line << std::endl;
        }
        std::cout << "Reading " << file << " => OK" << std::endl;
        ifs.close(); // fermeture du flux
    }
    else // en cas d'erreur...
    {
        gotoLigCol(POSLIGNE+2,POSCOLONNE);
        std::cout << "Cannot read " << file << std::endl;
        gotoLigCol(POSLIGNE+4,POSCOLONNE);
        system("pause");
        system("cls");
    }
}*/

#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED
#include <iostream>

class Bloc
{
protected:
    int m_pos_x;
    int m_pos_y;
    char m_type; //cet attribut permet de choisir quel type de bloc nous voulons créer

public:
    //constructeur
    Bloc(int posX, int posY, char type);
    //destructeur
    ~Bloc();
    //getters
    int getPosX();
    int getPosY();
    char getType();
    //setters
    void setPosX(int posX);
    void setPosY(int posY);
    void setType(char type);
};

#endif // BLOCK_H_INCLUDED

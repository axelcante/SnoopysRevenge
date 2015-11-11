#ifndef SNOOPY_H_INCLUDED
#define SNOOPY_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <string>
#include "Block.h"

class Snoopy
{
private:
    int m_pos_x;
    int m_pos_y;
    int m_vies;
    int m_score;
    int m_oiseaux;

public:
    ///Constructeurs & Destructeurs
    //Constructeur par défaut
    Snoopy();
    //Constructeur surchargé
    Snoopy(int posx,int posy,int vies,int score,int oiseaux);
    //Constructeur par copie
    //Non ?
    //Destructeur unique
    ~Snoopy();
    //getters
    int getPosX()const;
    int getPosY()const;
    int getVies()const;
    int getScore()const;
    int getOiseaux()const;

    //setters
    void setPosX(int posX);
    void setPosY(int posY);
    void setVies(int vies);
    void setScore(int score);
    void setOiseaux(int oiseaux);

    //methods
    void moveSnoopy();
    void breakBlock(Block &block); ///
    void saveGame();
    void loadGame();
};

#endif // SNOOPY_H_INCLUDED

#ifndef SNOOPY_H_INCLUDED
#define SNOOPY_H_INCLUDED
#include "Bloc.h"

///Bloc Snoopy
class Snoopy : public Bloc
{
private :
    int m_vies;
    int m_score;
    int m_oiseaux;

public :
    //Constructeurs
    Snoopy(int posX, int posY, char type,bool estPoussableblocmere, bool estCassableblocmere,int vies,int score,int oiseaux);
    //Destructeur
    ~Snoopy();
    //getters
    int getVies()const;
    int getScore()const;
    int getOiseaux()const;
//setters
    void setVies(int vies);
    void setScore(int score);
    void setOiseaux(int oiseaux);
};

#endif // SNOOPY_H_INCLUDED

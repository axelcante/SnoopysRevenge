#ifndef CASSABLE_H_INCLUDED
#define CASSABLE_H_INCLUDED
#include "Bloc.h"

///Bloc que Snoopy pourra casser
class Cassable : public Bloc
{
private :
    bool m_estPiege;
public:
    //constructeur surchargé
    Cassable(int posX, int posY, char type,bool estPoussableblocmere,bool estPiege);
    //destructeur
    ~Cassable();
    //getters
    bool getEstPiege()const;
    //setters
    void setEstPiege(bool estPiege);
};


#endif // CASSABLE_H_INCLUDED

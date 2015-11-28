#ifndef CASSABLE_H_INCLUDED
#define CASSABLE_H_INCLUDED
#include "Bloc.h"

///Bloc que Snoopy pourra casser
class Cassable : public Bloc
{
private :
    bool m_estCassable;
public:
    //constructeur surchargé
    Cassable(int posX, int posY, char type,bool estPoussableblocmere,bool estCassableblocmere,bool estCassable);
    //destructeur
    ~Cassable();
    //getters
    bool getEstCassable()const;
    //setters
    void setEstCassable(bool estCassable);
};


#endif // CASSABLE_H_INCLUDED

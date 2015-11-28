#ifndef PIEGE_H_INCLUDED
#define PIEGE_H_INCLUDED
#include "Bloc.h"

#ifndef POUSSABLE_H_INCLUDED
#define POUSSABLE_H_INCLUDED
#include "Bloc.h"

///Bloc qui tue !
class Piege : public Bloc
{
public:
    //constructeur surchargé
    Piege(int posX, int posY, char type,bool estPoussableblocmere);
    //destructeur
    ~Piege();
};


#endif // POUSSABLE_H_INCLUDED



#endif // PIEGE_H_INCLUDED

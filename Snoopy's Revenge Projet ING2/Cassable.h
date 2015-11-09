#ifndef CASSABLE_H_INCLUDED
#define CASSABLE_H_INCLUDED
#include "Bloc.h"

class Cassable : public Bloc
{
public:
    //constructeur surchargé
    Cassable(int posX, int posY, char type);
    //destructeur
    ~Cassable();

};

#endif // CASSABLE_H_INCLUDED

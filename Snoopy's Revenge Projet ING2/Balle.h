#ifndef BALLE_H_INCLUDED
#define BALLE_H_INCLUDED
#include "Bloc.h"

///Classe Balle
class Balle : public Bloc
{
public :
    //Constructeur surcharg�
    Balle(int posX, int posY, char type,bool estPoussableblocmere);
    //Destructeur
    ~Balle();
    //M�thodes
};


#endif // BALLE_H_INCLUDED

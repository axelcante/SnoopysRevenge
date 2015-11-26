#ifndef POUSSABLE_H_INCLUDED
#define POUSSABLE_H_INCLUDED
#include "Bloc.h"

///Bloc que Snoopy pourra pousser
class Poussable : public Bloc
{
private:
    bool m_estPoussable;
public:
    //constructeur surchargé
    Poussable(int posX, int posY, char type,bool estPoussableblocmere, bool estPoussable);
    //destructeur
    ~Poussable();
    //getters
    bool getEstPoussable()const;
    //setters
    void setEstPoussable(bool estPoussable);
    //méthodes (dans Snoopy ?)
};


#endif // POUSSABLE_H_INCLUDED

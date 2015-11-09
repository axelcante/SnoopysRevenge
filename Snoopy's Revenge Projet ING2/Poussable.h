#ifndef POUSSABLE_H_INCLUDED
#define POUSSABLE_H_INCLUDED
#include "Bloc.h"

class Poussable : public Bloc
{
private:
    bool m_estPoussable;
public:
    //constructeur surchargé
    Poussable(int posX, int posY, char type, bool estPoussable);
    //destructeur
    ~Poussable();
    //getters
    bool getEstPoussable();
    //setters
    void setEstPoussable(bool estPoussable);
    //méthodes
    void bougerBlocPoussable(int posX, int posY);

};

#endif // POUSSABLE_H_INCLUDED

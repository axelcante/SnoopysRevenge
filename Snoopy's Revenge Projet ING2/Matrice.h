#ifndef MATRICE_H_INCLUDED
#define MATRICE_H_INCLUDED
#include "Bloc.h"
#include <vector>

class Matrice
{
    class Bloc;
private :
    std::vector<std::vector<Bloc> > m_matrice;

public :
    //constructeur
    Matrice();
    //getters
<<<<<<< HEAD
    std::vector<std::vector<Bloc> > getMatrice()const;
    //setters

=======
    std::vector<std::vector<Bloc> > getMatrice();
>>>>>>> 483f22727128a3bce1355375e30a13c93d9650d1
    //methodes
    void afficherMatrice();
    //void changerBloc();
};

#endif // MATRICE_H_INCLUDED

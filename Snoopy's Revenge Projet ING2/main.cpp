#include <iostream>
#include "Bloc.h"
#include "Matrice.h"
#include "Niveau.h"
#include "console.h"
#include <vector>
//Si d�calage du tableau sur console

int main()
{
    ///D�claration variables
    //char var ='a';
    //char& touche = var; //Touche utilis�e pour les interactions avec l'utilisateur
    //initialisation de la matrice et du premier niveau
    Console* conso = Console::getInstance(); //Allocation m�moire du pointeur sur console
    Matrice matrice_niveau_1;
    matrice_niveau_1.bougerElements(conso);


    //matrice_niveau_1.bougerBalle();
    //char touche; //touche appuyee par le joueur
    //bool estPoussable;

    // matrice_niveau_1.afficherMatrice();
    /* estPoussable = (matrice_niveau_1.getMatrice().getType()=='P');
     //r�ference
     int& posX= matrice_niveau_1.getMatrice().getPosX();
     int& posY= matrice_niveau_1.getMatrice().getPosY();*/


    //conso->gotoLigCol(POSLIGNE,POSCOLONNE);
    conso->deleteInstance();
    return 0;

}

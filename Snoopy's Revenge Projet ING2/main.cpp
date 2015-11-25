#include <iostream>
#include "Bloc.h"
#include "Matrice.h"
#include "Niveau.h"
#include "console.h"
#include <vector>
//Si décalage du tableau sur console

int main()
{
    ///Déclaration variables
    //char var ='a';
    //char& touche = var; //Touche utilisée pour les interactions avec l'utilisateur
    //initialisation de la matrice et du premier niveau
    Console* conso = Console::getInstance(); //Allocation mémoire du pointeur sur console
    Matrice matrice_niveau_1;
    matrice_niveau_1.bougerElements(conso);


    //matrice_niveau_1.bougerBalle();
    //char touche; //touche appuyee par le joueur
    //bool estPoussable;

    // matrice_niveau_1.afficherMatrice();
    /* estPoussable = (matrice_niveau_1.getMatrice().getType()=='P');
     //réference
     int& posX= matrice_niveau_1.getMatrice().getPosX();
     int& posY= matrice_niveau_1.getMatrice().getPosY();*/


    //conso->gotoLigCol(POSLIGNE,POSCOLONNE);
    conso->deleteInstance();
    return 0;

}

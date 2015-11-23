#include <iostream>
#include "Bloc.h"
#include "Matrice.h"
#include "Niveau.h"
#include "console.h"
#include <vector>
//Si décalage du tableau sur console
#define POSLIGNE 0
#define POSCOLONNE 0

int main()
{
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

    /***********************
    deplacement
    ************************/
    /*  void deplacement()
      {

          //Ressources
          int poscol=POSCOLONNE, poslig=POSLIGNE; // position initiale du curseur
          int i=poslig-POSLIGNE,j=poscol-POSCOLONNE;//position de la ligne et de la colonne par rapport au tableau
          int nbl=10;
          int nbc = 20;
          do
          {
              if(ifKeyboardPressed()) //si le clavier est touche
              {
                  touche= getInputKey();//Saisie de la touche
                  switch(touche)
                  {
                  case '2'://descendre
                      if ((poslig+1>=POSLIGNE)&&(poslig+1<nbl+POSLIGNE)) //blindage
                      {
                          poslig++; //incrementer la position de la ligne
                      }
                      break;
                  case '4'://aller a gauche
                      if ((poscol-1<nbc+POSCOLONNE)&&(poscol-1>=POSCOLONNE))//blindage
                      {
                          poscol--; //decrementer la position de la colonne
                      }
                      break;
                  case '6'://aller a droite
                      if ((poscol+1<nbc+POSCOLONNE)&&(poscol+1>=POSCOLONNE))//blindage
                      {
                          poscol++;//incrementer la position colonnne
                      }
                      break;
                  case '8'://monter
                      if((poslig-1>=POSLIGNE)&&(poslig-1<nbl+POSLIGNE))//blindage
                      {
                          poslig--;//Decrementer la position de la ligne
                      }
                      break;
                  case 's': //Sauvegarder
                      break;
                  }
              }
              conso->gotoLigCol(poslig,poscol);//positionner le curseur a lendroit voulu
          }
          while (touche!=' '); //sortir
          i=poslig-POSLIGNE;//Reinitialiser les positions
          j=poscol-POSCOLONNE;

      }*/

}

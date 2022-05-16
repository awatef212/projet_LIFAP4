#include "MenuTxt.h"
#include "MenuSDL.h"

/**
 * @file mainRegression.cpp
 * @brief Implémentation de l'executable exe_regression
 */

int main()
{
    Coordonnees coordonnees;
    coordonnees.testRegression();
    Cellule cellule;
    cellule.testRegression();
    Grille3x3 g3;
    g3.testRegression();
    Grille9x9 g9;
    g9.testRegression();
    Jeu jeu;
    jeu.testRegression();
    return 0;
}
#ifndef _GRILLE3X3
#define _GRILLE3X3

#include <cassert>
#include <iostream>

#include "Cellule.h"

/**
 * @file Grille3x3.h
 * @brief Declaration de la classe Grille3x3
 * @class Grille3x3 Grille3x3.h _GRILLE3X3
 */

class Grille3x3
{
private:
/**
 * @brief tableau statique 3 par 3 de Cellule
 * 
 */
    Cellule tab[3][3];
   

public:

/**
 * @fn Grille3x3()
 * @brief constructeur par défaut de la classe
 * 
 */
    Grille3x3();

     /**
     * @fn test(int a) const
     * @brief test si la valeur a peut être ajoutée à la Grille3x3
     * i.e. si cette valeur est comprise entre [1;9] et
     * qu'elle n'est pas déjà présente dans la Grille3x3
     * @param[in] a entier
     * @return booléen
     */
    bool test(int a) const;

    /**
     * @fn Cellule getCase(int x, int y) const
     * @brief Mutateur
     * récupère le champs Cellule de tab[x][y]
     * @param[in] x entier
     * @param[in] y entier
     * @return Cellule de Coordonnees (x,y)
     */
    Cellule getCase(int x, int y) const;

     /**
     * @fn Cellule& getCase(int x, int y) 
     * @brief Mutateur
     * récupère une référence sur le champs Cellule de tab[x][y]
     * @param[in] x entier
     * @param[in] y entier
     * @return référence sur Cellule de Coordonnees (x,y)
     */
    Cellule& getCase(int x, int y);

    /**
     * @fn ~Grille3x3()
     * @brief Destructeur de la classe 
     */
    ~Grille3x3();

     /**
     *@fn void testRegression()
     *@brief Effectue une série de tests vérifiant que le module fonctionne et
     *que les données membres de l'objet sont conformes
     *@return void
     */
    void testRegression();
};
#endif // _GRILLE3X3
#ifndef _COORDONNEES
#define _COORDONNEES

#include <cassert>
#include <iostream>

/**
 * @file Coordonnees.h
 * @brief Les Coordonnees sont la position (x,y)
 * @class Coordonnees Coordonnees.h _COORDONNEES
 */
class Coordonnees
{
private:
    /**
     * @brief abscisse de la Coordonnees
     */
    int x;
    /**
     * @brief ordonnee de la Coordonnees
     */
    int y;

public:
   
     /**
     * @fn Coordonnees()
     * @brief Constructeur par défaut 
     * initialise les Coordonnees à (0,0)
     */
    Coordonnees();

    /**
     * @fn Coordonnees(int nx, int ny) const
     * @brief Constructeur par copie
     * initialise les Coordonnees avec les paramètres après vérification
     * @param[in] _x entier positif
     * @param[in] _y entier positif
     */
    Coordonnees(int _x, int _y);

    
    /**
     * @fn int getX()
     * @brief Accesseur
     * récupère le champs x
     * @return x entier
     */
    int getX() const;

    /**
     * @fn int getY()
     * @brief Accesseur
     * récupère le champs y
     * @return y entier
     */
    int getY() const;

    /**
     * @fn int setX(int _x)
     * @brief Mutateur
     * modifie le champs x
     * @param[in] _x entier
     * @return void
     */
    void setX(int _x);

    /**
     * @fn int setY(int _y)
     * @brief Mutateur
     * modifie le champs y
     * @param[in] _y entier
     * @return void
     */
    void setY(int _y);

    /**
     *@fn void testRegression()
     *@brief Effectue une série de tests vérifiant que le module fonctionne et
     *que les données membres de l'objet sont conformes
     *@return void
     */
    void testRegression();

    
};
#endif // _COORDONNEES
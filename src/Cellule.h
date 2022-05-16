#ifndef _CELLULE
#define _CELLULE

#include <cassert>
#include <iostream>

#include "Coordonnees.h"
/**
 * @file Cellule.h
 * @brief Declaration de la classe Cellule
 * @class Cellule Cellule.h _CELLULE
 * 
 
 */
class Cellule
{
private:
    /**
     * @brief valeur de type entier
     * valeur entre 1 et 9 que peut prendre la cellule
     */
    int valeur;
    /**
     * @brief visible de type booléen
     * définie si la valeur est visible par l'utilisateur ou non
     */
    bool visible;

public:
    /**
     * @brief position de type Coordonnees
     * position (x,y) de la cellule dans la Grille3x3
     */
    Coordonnees position;
    /**
     * @fn Cellule()
     * @brief Constructeur par defaut de la classe
     *
     */
    Cellule();

    /**
     * @fn Cellule(int _x, int _y, int _valeur)
     * @brief Constructeur par copie de la classe
     * Initialise les paramètre après vérification
     * @param[in] _x 
     * @param[in] _y
     * @param[in] _valeur entier positif
     */
    Cellule(int _x, int _y, int _valeur);

    /**
     * @fn Cellule(int _x, int _y, int _valeur, bool _visible)
     * @brief Constructeur par copie de la classe
     * Initialise les paramètre après vérification
     * @param[in] _x 
     * @param[in] _y
     * @param[in] _valeur entier positif
     * @param[in] _visible booleen
     */
    Cellule(int _x, int _y, int _valeur, bool _visible);

    /**
     * @fn ~Cellule()
     * @brief Destructeur 
     *
     */
    ~Cellule();

    /**
     * @fn int getValeur() const
     * @brief Accesseur
     * récupère le champs valeur
     * @return valeur entier
     */
    int getValeur() const;

    /**
     * @fn bool getVisible() const
     * @brief Accesseur
     * récupère le champs visible
     * @return un booléen
     */
    bool getVisible() const;

    /**
     * @fn void setVisible(bool _visible)
     * @brief Mutateur
     * modifie le champs visible après vérification
     * @param[in] _visible
     */
    void setVisible(bool _visible);

    /**
     * @fn setValeur(int _valeur)
     * @brief Mutateur
     * modifie le champs valeur après vérification
     * @param[in] _valeur entier
     * @return void
     */
    void setValeur(int _valeur);


    /**
     * @fn Coordonnees &getCoordonnees()
     * @brief Accesseur
     * récupère une référence sur le champs position
     * @return Coordonnees
     */
    Coordonnees &getCoordonnees();

    /**
     * @fn Coordonnees getCoordonnees() const
     * @brief Accesseur
     * récupère le champs position
     * @return &Coordonnees
     */
    Coordonnees getCoordonnees() const;

    /**
     *@fn void testRegression()
     *@brief Effectue une série de tests vérifiant que le module fonctionne et
     *que les données membres de l'objet sont conformes
     *@return void
     */
    void testRegression();
};
#endif //  _CELLULE
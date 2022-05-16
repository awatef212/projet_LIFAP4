#ifndef _MenuTxt
#define _MenuTxt

#include <cassert>
#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>
#include <stdlib.h>
#include <string.h>
#include <chrono>

#include "jeuTxt.h"

/**
 * @file MenuTxt.h
 * @brief Declaration de la classe MenuTxt
 * @class MenuTxt MenuTxt.h _MenuTxt
 */

class MenuTxt
{
    
    typedef enum
    {
        ACCUEIL,
        JEU,
        REGLE_DU_JEU,
        STATS,
        FIN_JEU
    } etat_t;

private:
    etat_t etatCourant = ACCUEIL;
    jeuTxt JouerTxt;
    int nbPrecedent = 0;

public:
    /** duree d'une partie en seconde */
    float duree_seconde;
    /** numéro de la partie */
    int nombre_partie = 0;
    /** mode de jeu: 0 = facile, 1 = intermediare, 2 = expert*/
    int mode;
    /**
     * @fn MenuTxt()
     * @brief  constructeur
     */
    MenuTxt();
    /**
     * @fn ~MenuTxt()
     * @brief destructeur
     */
    ~MenuTxt();
    /**
     * @fn changementEtat(etat_t etatSuivant)
     * @brief change l'etat de notre application parmis les etats définit dans l'enum
     * @param[in] etatSuivant 
     */
    void changementEtat(etat_t etatSuivant);
     /**
     * @fn void sortieEtat(etat_t etatActuel)
     * @brief action à faire lorsque l'on sort d'un etat
     * @param[in] etatActuel 
     */
    void sortieEtat(etat_t etatActuel);
    /**
     * @fn void doState(etat_t etatActuel)
     * @brief action à faire quand on est dans un etat
     * @param[in] etatActuel 
     */
    void doState(etat_t etatActuel);
     /**
     * @fn void entreeEtat(etat_t etatSuivant)
     * @brief action à faire lorsque l'on rentre dans un etat
     * @param[in] etatSuivant 
     */
    void entreeEtat(etat_t etatSuivant);
    /**
     * @fn void setEtatCourant(etat_t newEtat)
     * @brief change l'etat courant
     * @param[in] newEtat 
     */
    void setEtatCourant(etat_t newEtat);
     /**
     * @fn void run()
     * @brief lance l'application
     * 
     */
    void run();
     /**
     * @fn int getNbPrecedent()
     * @brief Acceseur
     * recupere le champs nb precedent
     * @return int 
     */
    int getNbPrecedent();
    /** difficulté choisi par l'utilisateur pour sa partie*/
    int difficulte;
    /**
     *@fn void testRegression()
     *@brief Effectue une série de tests vérifiant que le module fonctionne et
     *que les données membres de l'objet sont conformes
     *@return void
     */
    void testRegression();
};
#endif //_MenuTxt
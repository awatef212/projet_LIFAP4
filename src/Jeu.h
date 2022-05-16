#ifndef _JEU
#define _JEU

#include "Grille9x9.h"
#include "Pile.h"

#include <cassert>
#include <vector>
#include <iostream>

/**
 * @file Jeu.h
 * @brief Declaration de la classe Jeu
 * @class Jeu Jeu.h _JEU
 */

class Jeu
{
private:
    /**
     * @brief Nberreur de type entier
     * nombre d'erreur effectuée par l'utilisateur pendant la partie
     */
    int Nberreur = 0;
    /**
     * @brief grille de type Grille9x9
     */
    Grille9x9 grille;
    /**
     * @brief fin_partie de type booléen
     * initialisé à false
     */
    bool fin_partie = false;
    /**
     * @brief precedent de type Pile
     *  contenant toutes les valeurs entrées dans la Grille9x9
     */
    Pile precedent;
    /**
     * @brief flagErreur de type booléen
     *
     */
    bool flagErreur = false;
    /**
     * @brief mode_de_jeu de type entier
     * représentant le mode de jeu de la partie en cours
     */
    int mode_de_jeu = -1;

public:
    /**
     * @fn Jeu()
     * @brief constructeur
     */
    Jeu();

    /**
     * @fn ~Jeu()
     * @brief desctucteur
     */
    ~Jeu();

    /**
     * @fn bool ajout_valeur(int x, int y, int Nentier)
     * Vérifie si Nentier peut être la valeur de la Cellule de Coordonnees (x,y)
     * @param[in] x entier
     * @param[in] y entier
     * @param[in] Nentier entier
     * @return booléen
     */
    bool ajout_valeur(int x, int y, int Nentier);


    /**
     * @fn Grille9x9 &getGrille()
     * @brief Accesseur
     * recupère une référence sur Grille9x9
     * @return Grille9x9&
     */
    Grille9x9 &getGrille();

    /**
     * @fn Grille9x9 getGrille() const
     * @brief Accesseur
     * recupère sur Grille9x9
     * @return Grille9x9
     */
    Grille9x9 getGrille() const;

    /**
     * @fn bool getFin()
     * @brief Accesseur
     * recupère le champs fin_partie
     * @return booléen
     */
    bool getFin();

    /**
     * @fn setFin()
     * @brief Mutateur
     * modifie la valeur du champs fin_partie
     * @param[in] _fin_partie booléen
     * @return void
     */
    void setFin(bool _fin_partie);

    /**
     * @fn int getErreur()
     * @brief Accesseur
     * recupère le champs Nberreur
     * @return Nberreur entier
     */
    int getErreur();

    /**
     * @fn void setErreur(int erreur)
     * @brief Mutateur
     *  modifie la valeur du champs Nberreur
     * @param[in] erreur entier
     * @return void
     */
    void setErreur(int erreur);

    /**
     * @fn Coordonnees precedentValeur()
     * @brief revient en arriere
     * supprime la derniere valeur ajouté à la grille
     * @return Coordonnees
     */
    Coordonnees precedentValeur();

    /**
     * @fn Pile &getPile()
     * @brief Accesseur
     * recupère une reference sur la pile contenant toute les valeurs rentrées dans la Grille9x9
     * @return Pile&
     */
    Pile &getPile();

    /**
     * @fn bool getFlag()
     * @brief Accesseur
     * @return booléen
     */
    bool getFlag();

    /**
     * @fn void setFlag(bool etat)
     * @brief Mutateur
     * @param[in] etat booléen
     * @return void
     */
    void setFlag(bool etat);
    /**
     * @struct stat
     * @brief structure pour les statistiques de jeu
     */
    struct stat
    {
        /** numéro de la partie*/
        int numero;
        /** niveau de difficulté */
        int dif;
        /** nombre de retour en arrière*/
        int back;
        /** temps de la partie*/
        float temps;
        /** mode de jeu de la partie*/
        int mode_de_jeu;
    };

    /**
     * @fn void setMode_de_jeu(int mode)
     * @brief Mutateur
     * changement du mode de jeu
     * @param[in] mode entier
     * @return void
     */
    // void setMode_de_jeu(int mode);

    /**
     * @brief vector de stat
     *
     */
    std::vector<stat> tableau_stats;

    /**
     * @fn void setTableau_stat(int n, int d, int b, float t, int m)
     * @brief Mutateur
     * ajoute les statistiques d'une partie à la fin du vector
     * @param[in] n entier
     * @param[in] d entier
     * @param[in] b entier
     * @param[in] t réel
     * @param[in] m entier
     * @return void
     */
    void setTableau_stat(int n, int d, int b, float t, int m);

    /**
     *@fn void testRegression()
     *@brief Effectue une série de tests vérifiant que le module fonctionne et
     *que les données membres de l'objet sont conformes
     *@return void
     */
    void testRegression();
};
#endif // _JEU
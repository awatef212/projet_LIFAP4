#ifndef _GRILLE9X9
#define _GRILLE9X9

#include <cassert>
#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "Grille3x3.h"

/**
 * @file Grille9x9.h
 * @brief Declaration de la classe Grille9x9
 * @class Grille9x9 Grille9x9.h _GRILLE9X9
 */
class Grille9x9
{
private:
    /**
     * @brief niveau de difficulté
     *
     */
    int difficulte;
    /**
     * @brief tableau 3 par 3 de Grille3x3
     *
     */
    Grille3x3 tab[3][3];
    /**
     * @brief mode de jeu choisi parmis les 3 proposés
     * 
     */
    int mode; 

public:
    /**
     * @fn bool test_colonne(int x, int y, int valeur)
     * @brief test si valeur peut etre ajoutée à la Grille9x9 en fontion de la colonne
     * @param[in] x entier
     * @param[in] y entier
     * @param[in] valeur entier
     * @return booléen
     */
    bool test_colonne(int x, int y, int valeur);

    /**
     * @fn bool test_ligne(int x, int y, int valeur)
     * @brief test si valeur peut etre ajoutée à la Grille9x9 en fontion de la ligne
     * @param[in] x entier
     * @param[in] y entier
     * @param[in] valeur entie
     * @return booléen

     */
    bool test_ligne(int x, int y, int valeur);
void reinitialisation();
    /**
     * @fn Grille9x9()
     * @brief Constructeur
     */
    Grille9x9();

    /**
     * @fn ~Grille9x9()
     * @brief Destructeur
     */
    ~Grille9x9();

    /**
     * @fn bool grille_remplir() const
     * @brief teste si la Grille9x9 est rempli
     * i.e. si toutes les valeurs sont visibles par l'utilisateur
     * @return booléen
     */
    bool grille_remplir() const;

    /**
     * @fn bool test_integrale() const
     * @brief
     * @return booléen
     */
    bool test_integrale(int v);

    /**
     * @fn int getDifficulte() const
     * @brief Accesseur
     * récupère le champs diffculté
     * @return entier
     */
    int getDifficulte() const;

    /**
     * @fn void setDifficulte(int a)
     * @brief Mutateur
     * modifie le champs diffculte après vérification
     * @param[in] _Difficulte entier
     * @return void
     */
    void setDifficulte(int _Difficulte);

    /**
     * @fn Grille3x3 getTab(int x, int y) const
     * @brief Accesseur
     * récupère le champs tab[x][y]
     * @param[in] x entier
     * @param[in] y entier
     * @return  Grille3x3
     */
    Grille3x3 getTab(int x, int y) const;

    /**
     * @fn Grille3x3& getTab(int x, int y)
     * @brief Accesseur
     * récupère une référence sur tab[x][y]
     * @param[in] x entier
     * @param[in] y entier
     * @return &Grille3x3
     */
    Grille3x3 &getTab(int x, int y);

    // Coordonnees getCoordonneesGrille9x9()
    /**
     * @fn init_grille()
     * @brief enleve certaine valeur de la Grille9x9 initialisée
     * en foction de la difficulté
     * @return  void
     */
    void init_grille();

    /**
     * @fn bool test_carre(int x, int y, int v)
     * @brief test si v peut etre ajoitée au carré contenant la Cellule de position (x,y)
     * @param[in] x entier
     * @param[in] y entier
     * @param[in] v entier
     * @return booléen
     */
    bool test_carre(int x, int y, int v);

    /**
     * @fn bool verification(int x, int y, int valeur)
     * @brief vérifie que valeur peut être ajoutée à la Grille9x9
     * @param[in] x entier
     * @param[in] y entier
     * @param[in] valeur entier
     * @return booléen
     */
    bool verification(int x, int y, int valeur);

    /**
     * @fn bool grilleValide (int position)
     * @brief utilise la methode du backtracking pour pouvoir résoudre une grille.
     * @param[in] position entier
     * @return booléen
     */
    bool grilleValide(int position);
    // void genereGrille(); //genere et initialise une grille en fonctions de la difficulté choisi. Plus la difficulté sera élevé plus des 0 vont etre ajouté à l'instanciation de la grille
    // bool grilleValide2(int position); //utilise la methode du backtracking pour pouvoir résoudre une grille. Pour éviter que toute les grille soit les memes pour differentes partie on utilise rand() pour génerer des nombre au hasard et grace au backtracking testé si la grille ainsi généré sera réalisable.
    // void copieGrille(Grille9x9 grilleAcopier); //copie d'une grille 9x9 dans la données membre de l'instanciation en cours
    // int getMode(); //renvoie le mode de l'instanciation en cours
    // bool test_centre(int x, int y, int v); //test si un valeur est présente au centre d'une grille 3x3
    // void setMode(int newMode); //change le mode de jeu 
    bool test_diagonale_droite(int x, int y, int valeur);
    bool test_diagonale_gauche(int x, int y, int valeur);

    /**
     * @fn void genereGrille()
     * @brief genere et initialise une grille en fonctions de la difficulté choisi. 
     * Plus la difficulté sera élevé plus des 0 vont etre ajouté à l'instanciation de la grille
     * @return void
     */
    void genereGrille(); 

    /**
     * @fn bool grilleValide2(int position)
     * @brief utilise la methode du backtracking pour pouvoir résoudre une grille 
     * Pour éviter que toute les grille soit les memes pour differentes partie on utilise rand() pour génerer des nombre au hasard et grace au backtracking testé si la grille ainsi généré sera réalisable.
     * @param[in] position entier
     * @return booléen
     */
    bool grilleValide2(int position); 

    /**
     * @fn void copieGrille(Grille9x9 grilleAcopier)
     * @brief copie d'une Grille9x9 dans la données membre de l'instanciation en cours
     * @param[in,out] grilleAcopier 
     */
    void copieGrille(const Grille9x9 &grilleAcopier); 

    /**
     * @fn int getMode()
     * @brief renvoie le mode de l'instanciation en cours
     * @return entier entre [0;2]
     */
    int getMode(); 

    /**
     * @fn bool test_centre(int x, int y, int v)
     * @brief test si un valeur est présente au centre d'une Grille3x3
     * @param[in] x 
     * @param[in] y 
     * @param[in] v 
     * @return booléen
     */
    bool test_centre(int x, int y, int v); 

    /**
     * @fn void setMode(int newMode)
     * @brief Mutateur
     * change le mode de jeu 
     * @param[in] newMode 
     */
    void setMode(int newMode); 
    /**
     *@fn void testRegression()
     *@brief Effectue une série de tests vérifiant que le module fonctionne et
     *que les données membres de l'objet sont conformes
     *@return void
     */
    void testRegression();

};
#endif // _GRILLE9X9
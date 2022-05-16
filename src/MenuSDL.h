#ifndef _MenuSDL
#define _MenuSDL

#include <SDL2/SDL.h>
#include <string>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <vector>
#include <iostream>
#include <cassert>
#include <fstream>
#include <ctime>
#include <stdlib.h>
#include <time.h>
#include <chrono>

#include "jeuSDL.h"

/**
 * @file MenuSDL.h
 * @brief Declaration de la classe MenuSDL
 * @class MenuSDL MenuSDL.h _MenuSDL
 */

class MenuSDL
{
private:
    /**
     * @enum etat_t
     * @brief differents états
     * que va prendre la machine à etat qui représente les differents etats de notre appli
     */
    typedef enum
    {
        /** état Acceuil*/
        ACCUEIL,
        /** état jeu*/
        JEU,
        /** état regles du jeu*/
        REGLE_DU_JEU,
        /** état statistiques*/
        STATS,
        /** état fin du jeu*/
        FIN_JEU
    } etat_t;
    /**initialisation de l'etat par defaut */
    etat_t etatCourant = ACCUEIL;
    /**permet l'affichage de notre appli en sdl*/
    jeuSDL JouerSDL;

    /**compteur pour les stats du nb de precedents */
    int nbPrecedent = 0;
    SDL_Event events;
    /** indique si l'instanciation de grille en cours est réalisable */
    bool realisable = true;
    /** indique si nous avons selectionner un mode */
    bool modeSelectionne = false;
    /** indique si nous devons initialiser les stats */
    bool initStats = true;
    /** indique si nous pouvons initialiser une grille */
    bool pretAetreInit = false;
    bool accueil = false;
    /** indique si nous avons fait toute les initialisations préalable au lancement de notre applications */
    bool init = false;
    /**decompte pour la durée dans les stats */
    float duree_seconde;
    /** indique si un numero à été choisi par l'utilisateur*/
    bool numChoisi = false; // commente pas ca
    /** nombre de partie jouées*/
    int nombre_partie = 0;
    /** difficulté choisi par l'utilisateur pour sa partie*/
    int difficulte;
    int r, p, u, t;

public:
    /**
     * @fn MenuSDL()
     * @brief Constructeur
     */
    MenuSDL();
    /**
     * @fn ~MenuSDL()
     * @brief Destructeur
     */
    ~MenuSDL();

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

    /**
     * @fn void SDLboucleJeu();
     * @brief Boucle qui attend qu'un evenement se produise. Et execute du code en consequence.
     * va se charger de tout les evenements lorsque l'on est dans une partie (selection difficulte, mode etc)
     */
    void SDLboucleJeu();
    
    /**
     * @fn void SDLboucleStats()
     * @brief Boucle qui attend qu'un evenement se produise. Et execute du code en consequence.
     * va se charger de tout les evenements lorsque l'on est dans les statistiques (appuie sur la maison pour retourner à l'accueil)
     */
    void SDLboucleStats();
    /**
     * @fn void boucleActionGrille(Jeu &grille, Jeu &tampon)
     * @param[in,out] grille Jeu
     * @param[in,out] tampon Jeu
     * @brief Boucle qui attend qu'un evenement se produise. Et execute du code en consequence.
     * va se charger de tout les evenements lorsque l'on est en train de jouer, face à la grille que nous avons initialiser
     */
    void boucleActionGrille(Jeu &grille, Jeu &tampon);
    /**
     * @fn void boucleSelectionDIff(Jeu &grille)
     * @brief Boucle qui attend qu'un evenement se produise. Et execute du code en consequence.
     * @param[in,out] grille Jeu
     * va se charger de tout les evenements lorsque l'on veut choisir la difficulté d'une grille
     */
    void boucleSelectionDIff(Jeu &grille);
    /**
     * @fn void boucleSelectionMode(Jeu &grille)
     * @brief Boucle qui attend qu'un evenement se produise. Et execute du code en consequence.
     * @param[in,out] grille Jeu
     * va se charger de tout les evenements lorsque l'on veut choisir le mode d'une grille
     */
    void boucleSelectionMode(Jeu &grille);
    /**
     * @fn void SDLboucleAccueil()
     * @brief Boucle qui attend qu'un evenement se produise. Et execute du code en consequence.
     * va se charger de tout les evenements lorsque l'on est dans l'accueil pour choisir entre jouer, les regles ou les stats
     */
    void SDLboucleAccueil();
    /**
     * @fn void SDLboucleAccueil()
     * @brief Boucle qui attend qu'un evenement se produise. Et execute du code en consequence.
     * va se charger de tout les evenements lorsque l'on est dans les regles du jeu (revenir à l'accueil)
     */
    void SDLboucleRegle();
};

#endif

#ifndef _jeuSDL
#define _jeuSDL
#include <SDL2/SDL.h>
#include <string>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <cassert>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "Jeu.h"

/**
 * @file jeuSDL.h
 * @brief Declaration de la classe jeuSDL
 * @class jeuSDL jeuSDL.h _jeuSDL
 */

class jeuSDL
{
private:
    // Toute les surfaces et texture dont nous avons besoin dans l'applications. Toute les mettre en variable membre va nous
    // permettre de les initialiser dans une fonctions puis de faire directement des render copy lorsque l'on aura besoin des texture
    // cela va nous eviter de perdre en performance en rechargant à chaque fois les textures et surface.

    SDL_Surface *victoire = NULL;
    SDL_Texture *victoireT = NULL;
    SDL_Surface *perdu = NULL;
    SDL_Texture *perduT = NULL;
    SDL_Surface *iconeStats = NULL;
    SDL_Texture *iconeStatsT = NULL;
    SDL_Surface *titreStats = NULL;
    SDL_Texture *titreStatsT = NULL;
    SDL_Surface *cadreStats = NULL;
    SDL_Texture *cadreStatsT = NULL;
    SDL_Surface *regle = NULL;
    SDL_Texture *regleT = NULL;
    SDL_Surface *Return = NULL;
    SDL_Texture *ReturnT = NULL;
    SDL_Surface *boutonAccueil = NULL;
    SDL_Texture *boutonAccueilT = NULL;
    SDL_Surface *resolution = NULL;
    SDL_Texture *resolutionT = NULL;
    SDL_Surface *croix = NULL;
    SDL_Texture *croixT = NULL;
    SDL_Surface *coeurs = NULL;
    SDL_Texture *coeursT = NULL;
    SDL_Surface *boutonX = NULL;
    SDL_Texture *boutonXT = NULL;
    SDL_Surface *boutonCenterDot = NULL;
    SDL_Texture *boutonCenterDotT = NULL;
    SDL_Surface *boutonClassique = NULL;
    SDL_Texture *boutonClassiqueT = NULL;
    SDL_Surface *accueil = NULL;
    SDL_Texture *accueilT = NULL;
    SDL_Surface *titreDiff = NULL;
    SDL_Texture *titreDiffT = NULL;
    SDL_Surface *titreMode = NULL;
    SDL_Texture *titreModeT = NULL;
    SDL_Surface *boutonFacile = NULL;
    SDL_Texture *boutonFacileT = NULL;
    SDL_Surface *boutonDifficile = NULL;
    SDL_Texture *boutonDifficileT = NULL;
    SDL_Surface *boutonMoyen = NULL;
    SDL_Texture *boutonMoyenT = NULL;
    SDL_Surface *boutonStats = NULL;
    SDL_Texture *boutonStatsT = NULL;
    SDL_Surface *boutonRegle = NULL;
    SDL_Texture *boutonRegleT = NULL;
    SDL_Surface *boutonJouer = NULL;
    SDL_Texture *boutonJouerT = NULL;
    SDL_Surface *home = NULL;
    SDL_Texture *homeT = NULL;
    SDL_Surface *nb0 = NULL;
    SDL_Texture *nb0T = NULL;
    SDL_Surface *nb1 = NULL;
    SDL_Texture *nb1T = NULL;
    SDL_Surface *nb2 = NULL;
    SDL_Texture *nb2T = NULL;
    SDL_Surface *nb3 = NULL;
    SDL_Texture *nb3T = NULL;
    SDL_Surface *nb4 = NULL;
    SDL_Texture *nb4T = NULL;
    SDL_Surface *nb5 = NULL;
    SDL_Texture *nb5T = NULL;
    SDL_Surface *nb6 = NULL;
    SDL_Texture *nb6T = NULL;
    SDL_Surface *nb7 = NULL;
    SDL_Texture *nb7T = NULL;
    SDL_Surface *nb8 = NULL;
    SDL_Texture *nb8T = NULL;
    SDL_Surface *nb9 = NULL;
    SDL_Texture *nb9T = NULL;
    SDL_Surface *grille_classique = NULL;
    SDL_Texture *grille_classiqueT = NULL;
    SDL_Surface *grille_X = NULL;
    SDL_Texture *grille_XT = NULL;
    SDL_Surface *grille_centerDott = NULL;
    SDL_Texture *grille_centerDottT = NULL;
    SDL_Surface *fond = NULL;
    SDL_Texture *fondT = NULL;
    SDL_Surface *undo = NULL;
    SDL_Texture *undoT = NULL;
    SDL_Surface *irrea = NULL;
    SDL_Texture *irreaT = NULL;

public:
    /**
     * @brief grille de type Jeu
     * instanciation d'une fenetre
     */
    SDL_Window *screen = NULL;
        /**
     * @brief grille de type Jeu
     * instanciation d'un renderer
     */
    SDL_Renderer *renderer = NULL;
    /**
     * @brief grille de type Jeu
     * instanciation d'une données membre jeu necessaire au fonctionnement du jeu
     */
    Jeu grille;

    /**
     * @brief quit de type booléen
     * flag permettant de savoir si l'utilisateur veut quitter
     */
    bool quit = false;

    /**
     * @brief diffSelectionne de type booléen
     * flag permettant de savoir si l'utilisateur à choisie sa difficulté
     */
    bool diffSelectionne = false;

    /**
     * @brief dimx de type entier
     * dimension x de notre fenetre
     */
    int dimx;

    /**
     * @brief dimy de type entier
     * dimension y de notre fenetre
     */
    int dimy;

    /**
     * @fn initTexture_Surface()
     * @brief r de type SDL_Rect
     * va nous permettre d'initialiser toute les textures et surfaces une fois au début de l'application.
     * Puis elles nous serviront toute au long de l'utilisation.
     */
    void initTexture_Surface();
    /**
     * @brief r de type SDL_Rect
     * carré qui va nous permettre de dimensionner nos surfaces dans les textures créées
     */
    SDL_Rect r;
    jeuSDL();
    /**
     * @fn ~jeuSDL()
     * @brief destructeur qui va se charger de libérer et detruire toutes les surfaces créer à la fin du programme.
     */
    ~jeuSDL();
    /**
     * @fn void initSDL()
     * fait les initialisations necessaires au bon fonctionnement de SDL 2.0
     */
    void initSDL();
    /**
     * @fn remplissageStats(SDL_Rect positionStats, SDL_Rect destr, TTF_Font *font, SDL_Color font_color)
     * @param[in] positionStats SDL_Rect
     * @param[in] destr SDL_Rect
     * @param[in] font TTF_Font
     * @param[in] font_color SDL_Color
     * @brief remplis le tableau vector qui sert à la sauvegarde des statistiques de chaques parties
     */
    void remplissageStats(SDL_Rect positionStats, SDL_Rect destr, TTF_Font *font, SDL_Color font_color);
    /**
     * @fn void afficheGrille(Grille9x9 grille)
     * affiche la grille initialisée pour une partie en cours
     * @param[in] grille Grille9x9
     */
    void afficheGrille(Grille9x9 grille);

    /**
     * @fn void afficheAccueil()
     * affichage de la page d'accueil avec des boutons représentant les etats de l'application proposées (Stats,Jeu...)
     */
    void afficheAccueil();

    /**
     * @fn void afficheDifficulte()
     * affichage des boutons représentant les differentes difficultés proposées
     */
    void afficheDifficulte();

    /**
     * @fn void majGrille(SDL_Rect r, int i)
     * mise à jour de la grille en ajoutant et supprimant des nombres qui viennent d'etre modifié
     * @param[in] r SDL_Rect
     * @param[in] i entier
     */
    void majGrille(SDL_Rect r, int i);

    /**
     * @fn void affichePerdu(std::string file, SDL_Rect destr)
     *
     * @param[in] destr SDL_Rect
     */
    void affichePerdu(SDL_Rect destr);

    /**
     * @fn void afficheMode()
     * affiche des boutons qui représente les differents mode de jeu proposée
     */
    void afficheMode();

    /**
     * @fn void affiche_coeur()
     * affichage des coeurs coeurs représenant le nombre de vie restantes
     */
    void affiche_coeur();

    /**
     * @fn void barre_coeur(int i)
     * mets une croix sur un coeur si le joueur fais une erreur
     * @param[in] i entier
     */
    void barre_coeur(int i);
    /**
     * @fn void afficheStats()
     * affiche les statistiques de l'ensemble des parties
     */
    void afficheStats();
    /**
     * @fn void afficheVictoire()
     * affiche une texture qui indique la victoire
     */
    void afficheVictoire();
    /**
     * @fn void afficheRegle()
     * affiche une texture qui contient toute les regles du jeu
     */
    void afficheRegle();
};

#endif

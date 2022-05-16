#ifndef _JEUTXT
#define _JEUTXT

#include <cassert>
#include <fstream>
#include <iostream>

#include "Jeu.h"

/**
 * @file jeuTxt.h
 * @brief Declaration de la classe jeuTxt
 * @class jeuTxt jeuTxt.h _JEUTXT
 */
 class jeuTxt 
{
private:
    /**
     * @brief jeu_txt de type Jeu
     */
    Jeu jeu_txt;

public:
    /**
     * @fn jeuTxt()
     * @brief Constructeur
     */
    jeuTxt();

    /**
     * @fn ~jeuTxt()
     * @brief Destructeur
     */
    ~jeuTxt();

    /**
     * @fn void saisirDifficulte()
     * @brief saisie de la difficulté par l'utilisateur
     * @return void
     */
    void saisirDifficulte();

    /**
     * @fn void afficheTxt()
     * @brief affiche la Grille9x9 en mode texte
     * @return void
     */
    void afficheTxt();

    /**
     * @fn void boucleTxt()
     * @brief boucle de jeu en mode texte
     */
    void boucleTxt();

    /**
     * @fn int finJeu()
     * @brief lie le choix de l'utilisateur sur ce qu'il veut faire après avoir finit la partie
     * @return int
     */
    int finJeu();

    /**
     * @fn Jeu &getJeu_txt()
     * @brief Accesseur
     * récupère le champs jeu_txt
     * @return Jeu&
     */
    Jeu &getJeu_txt();

    /**
     * @fn void afficheMenuTxt()
     * @brief affichage du menu en mode texte
     * @return void
     */
    void afficheMenuTxt();

    /**
     * @fn void afficheMenuRetour(int result)
     * @brief affiche le menu de retour en arrière
     * @param[in] result 
     */
    void afficheMenuRetour(int result);

    /**
     * @fn void afficheMenuRetour()
     * @brief affiche le menu de retour en arrière
     */
    void afficheMenuRetour();

    /**
     * @fn void afficher_statistiques()
     * @brief affichage des statistques de jeu en mode texte
     */
    void afficher_statistiques();

    /**
     * @fn int afficheRegle(std::string mon_fichier)
     * @brief affichage des regles du jeu en mode texte
     * @param[in,out] mon_fichier 
     * @return int 
     */
    int afficheRegle(const std::string &mon_fichier);

    /**
     * @fn void saisirMode()
     * @brief saisie du mode de jeu
     */
    void saisirMode();


   
};
#endif // _JEUTXT
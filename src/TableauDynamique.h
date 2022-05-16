#ifndef _TAB_DYN
#define _TAB_DYN

#include "ElementTD.h"
#include <iostream>
#include <stdlib.h>

/**
 * @file TableauDynamique.h
 * @brief Declaration de la classe TableauDynamique
 * @class TableauDynamique TableauDynamique.h _TAB_DYN
 */

class TableauDynamique {
public:
   /** capacité du TableauDynamique*/
    unsigned int capacite;
    /**taille utilisée par le TableauDynamique*/
    unsigned int taille_utilisee;
    ElementTD * ad;

    /**
     * @fn TableauDynamique ()
     * @brief Constructeur
     */
    TableauDynamique (); 

    /**
     * @fn TableauDynamique (const TableauDynamique& t)
     * @brief Constructeur par copie
     * @param[in,out] t 
     */
    TableauDynamique (const TableauDynamique& t); 

    /**
     * @fn ~TableauDynamique ()
     * @brief Destructeur
     */
    ~TableauDynamique (); 
	
    /**
     * @fn void vider ()
     * @brief la mémoire allouée dynamiquement est libérée
     * le tableau a 1 emplacement allou� mais vide (taille utilis�e nulle)
     */
	void vider ();

    void ajouterElement (ElementTD e);
    /* Postcondition : l'�l�ment e est ajout� dans le premier emplacement inutilis� du tableau,
                       la taille est incr�ment�e de 1. Doublement de la capacit� si n�cessaire. */

    ElementTD valeurIemeElement (unsigned int indice) const;
    /* Precondition : 0 <= indice < taille_utilisee */
    /* Resultat : retourne l'ElementTD � l'indice en param�tre */

    void modifierValeurIemeElement (ElementTD e, unsigned int indice);
    /* Precondition : 0 <= indice < taille_utilisee */
    /* Postcondition : l'ElementTD � l'indice en param�tre vaut e */

    void afficher () const;
    /* Postcondition : les �l�ments du tableau sont affich�s sur la sortie standard (espacement entre les �l�ments)
                       en utilisant la proc�dure d'affichage de ElementTD */

    void supprimerElement (unsigned int indice);
    /* Precondition : le tableau est non vide, et 0 <= indice < taille_utilisee */
    /* Postcondition : la taille utilis�e du tableau est d�cr�ment�e de 1.
                       si taille_utilisee < capacite/3, alors on divise la capacit� par 2. */

    void insererElement (ElementTD e, unsigned int indice);
    /* Precondition : 0 <= indice < taille_utilisee */
    /* Postcondition : e est ins�r� � l'indice en param�tre et la taille utilis�e est incr�ment�e de 1 */

    void trier ();
    /* Postcondition : le tableau est tri� dans l'ordre croissant des valeurs des �l�ments */

    int rechercherElement (ElementTD e) const;
    /* Precondition : le tableau est tri� dans l'ordre croissant */
    /* R�sultat : indice de l'emplacement qui contient un ElementTD �gal � e,
                  -1 si le tableau ne contient pas d'�l�ment �gal � e */

};

#endif

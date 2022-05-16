#include "MenuTxt.h"

/**
 * @file MenuTxt.cpp
 * @brief Implémentation de la classe MenuTxt
 */

MenuTxt::MenuTxt()
{
}

MenuTxt::~MenuTxt()
{
}

void MenuTxt::run()
{
    changementEtat(ACCUEIL);
}

void MenuTxt::changementEtat(etat_t etatSuivant)
{
    sortieEtat(etatCourant);
    setEtatCourant(etatSuivant);
    entreeEtat(etatSuivant);
    doState(etatSuivant);
}

void MenuTxt::setEtatCourant(etat_t newEtat)
{
    etatCourant = newEtat;
}

void MenuTxt::sortieEtat(etat_t etatCourant)
{
    switch (etatCourant)
    {
    case ACCUEIL:

        break;
    case JEU:

        break;
    case REGLE_DU_JEU:

        break;
    case STATS:

        break;
    case FIN_JEU:
        // JouerTxt.getJeu_txt().setErreur(0);
        // JouerTxt.getJeu_txt().setFin(false);
        break;
    default:
        break;
    }
}

void MenuTxt::entreeEtat(etat_t etatSuivant)
{
    switch (etatSuivant)
    {
    case ACCUEIL:
        etatCourant = ACCUEIL;

        std::cout << "************************************************************" << std::endl;
        std::cout << "************************************************************" << std::endl;
        std::cout << "**      **  **  **      *****    **** ***  **  ****  *******" << std::endl;
        std::cout << "**   *****  **  **  ****  *** *** *** **  ***  ****  *******" << std::endl;
        std::cout << "**   *****  **  **  ****  *** *** *** * *****  ****  *******" << std::endl;
        std::cout << "**   *****  **  **  ****  *** *** *** **  ***  ****  *******" << std::endl;
        std::cout << "    ******      **      *****     *** ***  ****   **********" << std::endl;
        std::cout << "************************************************************" << std::endl;
        std::cout << "************************************************************" << std::endl;

        break;
    case JEU:
        nombre_partie++;
        etatCourant = JEU;

        // JouerTxt.saisirDifficulte();
        break;
    case REGLE_DU_JEU:
        etatCourant = REGLE_DU_JEU;

        break;
    case STATS:
        etatCourant = STATS;

        break;

    case FIN_JEU:
        etatCourant = FIN_JEU;

        break;
    default:
        break;
    }
}

void MenuTxt::doState(etat_t etatActuel)
{
    switch (etatActuel)
    {
    case ACCUEIL:
    {
        char nb;
        JouerTxt.afficheMenuTxt();
        do
        {

            std::cin >> nb;
            if (std::cin.fail() || nb < 49 || nb > 51)
            {
                std::cout << "Saisie incorrect, veuillez re saisir" << std::endl;
                std::cin.clear();
            }
        } while (nb < 49 || nb > 51);
        switch (nb)
        {
        case 49:
            changementEtat(JEU);
            break;
        case 50:
            changementEtat(REGLE_DU_JEU);
            break;
        case 51:
            changementEtat(STATS);
            break;

        default:
            break;
        }
        break;
    }

    case JEU:
    {
        using namespace std::chrono;
        jeuTxt j;
        int e;
        j.saisirMode();
        j.saisirDifficulte();
        mode = j.getJeu_txt().getGrille().getMode();
        difficulte = int(j.getJeu_txt().getGrille().getDifficulte());

        auto start = steady_clock::now();

        j.getJeu_txt().getGrille().init_grille();
        jeuTxt tampon;
        // tampon.getJeu_txt().getGrille().copieGrille(j.getJeu_txt().getGrille());
        j.afficheTxt();
        j.boucleTxt();
        while (!j.getJeu_txt().getFin())
        {
            tampon.getJeu_txt().getGrille().copieGrille(j.getJeu_txt().getGrille());
            j.afficheTxt();
            if (j.getJeu_txt().getFlag() == false)
            {
                int grilleRealisable = 0;
                if (j.getJeu_txt().getGrille().grilleValide(0))
                {
                    j.getJeu_txt().getGrille().copieGrille(tampon.getJeu_txt().getGrille());
                    grilleRealisable = 1;
                }
                j.afficheMenuRetour(grilleRealisable);
                std::cin >> e;
                if (e == 1)
                {
                    nbPrecedent++;
                    j.getJeu_txt().precedentValeur();
                    j.afficheTxt();
                }
                else
                {
                }
            }
            else
            {
            }
            j.boucleTxt();
        }
        if (j.getJeu_txt().getFin())
        {
            std::cout << "Vous avez fait trois erreur. Partie terminée. vous avez perdu :(" << std::endl;
            auto end = steady_clock::now();
            duree_seconde = duration_cast<milliseconds>(end - start).count();
            duree_seconde = duree_seconde / 1000; // on va stocker le temps en seconde dans les statistiques et au moment d'afficher le temps à l'utilisateur on convertira en min + sec.
            std::cout << "Tu as échoué en " << duree_seconde
                      << " Seconds\n";
            int nb1 = j.finJeu();
            JouerTxt.getJeu_txt().setTableau_stat(nombre_partie, difficulte, getNbPrecedent(), duree_seconde, mode);
            switch (nb1)
            {
            case 1:
                if (!j.getJeu_txt().getGrille().grilleValide(0))
                {
                    tampon.getJeu_txt().getGrille().grilleValide(0);
                    tampon.afficheTxt();
                }
                else
                {
                    j.afficheTxt();
                }

                changementEtat(ACCUEIL);
                break;
            case 2:
                changementEtat(ACCUEIL);
                break;
            }
        }
        else
        {
            std::cout << "Félicitation vous avez résolu cette grille. :)" << std::endl;
            auto end = steady_clock::now();
            duree_seconde = duration_cast<milliseconds>(end - start).count();
            duree_seconde = duree_seconde / 1000;
            JouerTxt.getJeu_txt().setTableau_stat(nombre_partie, difficulte, getNbPrecedent(), duree_seconde, mode);
        }

        break;
    }

    case REGLE_DU_JEU:
    {
        std::string nom_fichier = "data/regle_sudoku.txt";
        std::ofstream fichierEcriture(nom_fichier.c_str());
        if (!fichierEcriture.is_open())
        {
            std::cout << "Erreur dans l'ouverture en ecriture du fichier : " << nom_fichier << std::endl;
            return;
        }

        std::string regle = "******************************************************************************";
        regle.append("\n");
        regle.append("******************************************************************************");
        regle.append("\n");
        regle.append("****        **       **      ****  ******       ************      **  **  ****");
        regle.append("\n");
        regle.append("****  ****  **  *******  ********  ******  *****************  ***  **  **  ***");
        regle.append("\n");
        regle.append("****        **    *****  **    **  ******    ***************  ***  **  **  ***");
        regle.append("\n");
        regle.append("****  *   ****  *******  ***  ***  ******  *****************  ***  **  **  ***");
        regle.append("\n");
        regle.append("****  ***   **       **       ***      **       ************      **      ****");
        regle.append("\n");
        regle.append("******************************************************************************");
        regle.append("\n");
        regle.append("******************************************************************************");
        regle.append("\n");
        regle.append("*****************************      **       **  **  **************************");
        regle.append("\n");
        regle.append("*******************************  ****  *******  **  **************************");
        regle.append("\n");
        regle.append("*******************************  ****    *****  **  **************************");
        regle.append("\n");
        regle.append("*******************************  ****  *******  **  **************************");
        regle.append("\n");
        regle.append("*****************************    ****       **      **************************");
        regle.append("\n");
        regle.append("******************************************************************************");
        regle.append("\n");
        regle.append("******************************************************************************");
        regle.append("\n");
        regle.append("Sudoku est joué sur une grille de 9 x 9 espaces.");
        regle.append("\n");
        regle.append("Dans les lignes et les colonnes sont 9  carrés  (composé de 3 x 3 espaces).");
        regle.append("\n");
        regle.append("Chaque rangée, colonne et carré (9 espaces chacun) doit être rempli avec les numéros 1-9,");
        regle.append("\n");
        regle.append("sans répéter aucun nombre dans la meme rangée, la meme colonne ou le meme carré.");
        regle.append("\n");
        regle.append("\n");
        regle.append("En commencant le jeu, des cases sont préalablement entrés, il faut continuer à parcourir la grille ");
        regle.append("\n");
        regle.append("afin de la remplir entierement ");
        regle.append("\n");
        regle.append("Avant de jouer, on vous demandera le choix de difficulté");
        regle.append("\n");
        regle.append("elle representera le nombre de cases remplie en debut de partie");
        regle.append("\n");
        regle.append("Plus la difficulté est haute, moins il y aura de cases remplie");
        regle.append("\n");
        regle.append("\n");
        regle.append("Vous disposez de 3 vies. ");
        regle.append("\n");
        regle.append("A chaque fois que vous entrez un chiffre alors qu'il est déja present ");
        regle.append("\n");
        regle.append("sur le même carrée, la même rangée ou la même colonne, ");
        regle.append("\n");
        regle.append("une vie se supprime");
        regle.append("\n");
        regle.append("La partie se termine lorsque vous êtes mort, ou lorsque la grille est pleine");

        fichierEcriture << regle;
        fichierEcriture.close();
        //     fichierEcriture << regle;
        //     fichierEcriture.close();
        //    int mb = JouerTxt.afficheRegle(nom_fichier);
        //    if( mb == 0)
        //     {   std::cout<<" Sfzgjn";
        //         changementEtat(ACCUEIL);
        //     }
        break;
        int mb = JouerTxt.afficheRegle(nom_fichier);
        if (mb == 0)
        {
            std::cout << " Sfzgjn";
            changementEtat(ACCUEIL);
        }
        break;
    }
    case FIN_JEU:

        break;
    case STATS:
        std::cout << "entrée dans stats" << std::endl
                  << etatCourant;
        JouerTxt.afficher_statistiques();
        changementEtat(ACCUEIL);
        break;
    default:
        break;
    }
}

int MenuTxt::getNbPrecedent()
{
    return nbPrecedent;
}

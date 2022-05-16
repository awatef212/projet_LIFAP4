#include "jeuTxt.h"

/**
 * @file jeuTxt.cpp
 * @brief Implémentation de la classe jeuTxt
 */

jeuTxt::jeuTxt()
{
}

jeuTxt::~jeuTxt()
{
}

void jeuTxt::boucleTxt()
{
    int newNombre, x, y;

    do
    {
        std::cout << "veuillez entrer les coordonnées " << std::endl
                  << "x = ";
        std::cin >> x;
        if (!(x >= 0 && x < 9))
        {
            std::cout << "la valeur n'est pas entre 0 et 8 il va falloir recommencer la saisie" << std::endl;
        }
    } while (!(x >= 0 && x < 9));

    do
    {
        std::cout << "y = ";
        std::cin >> y;
        if (!(y >= 0 && y < 9))
        {
            std::cout << "la valeur n'est pas entre 0 et 8 il va falloir recommencer la saisie" << std::endl;
        }
    } while (!(y >= 0 && y < 9));

    do
    {
        std::cout << "valeur = ";
        std::cin >> newNombre;
        if (!(newNombre >= 1 && newNombre < 10))
        {
            std::cout << "la valeur n'est pas entre 1 et 9 il va falloir recommencer la saisie" << std::endl;
        }
    } while (!(newNombre >= 1 && newNombre < 10));
    switch (jeu_txt.getGrille().getMode())
    {
    case 0:
        if (jeu_txt.ajout_valeur(x, y, newNombre))
        {
            jeu_txt.setFlag(false);
        }
        else
        {
            std::cout << "vous  avez fait une erreur "
                      << "erreur : " << jeu_txt.getErreur() << std::endl;
            jeu_txt.setFlag(true);
        }
        break;

    case 1:
        if (jeu_txt.ajout_valeur(x, y, newNombre))
        {
            jeu_txt.setFlag(false);
        }
        else
        {
            std::cout << "vous  avez fait une erreur "
                      << "erreur : " << jeu_txt.getErreur() << std::endl;
            jeu_txt.setFlag(true);
        }
        break;
    case 2:
        if (jeu_txt.ajout_valeur(x, y, newNombre))
        {
            jeu_txt.setFlag(false);
        }
        else
        {
            std::cout << "vous  avez fait une erreur "
                      << "erreur : " << jeu_txt.getErreur() << std::endl;
            jeu_txt.setFlag(true);
        }
        break;
    default:
        break;
    }
}

void jeuTxt::afficheTxt()
{
    std::cout << std::endl;
    for (int j = 0; j < 3; j++)
    {

        for (int i = 0; i < 3; i++)
        {
            for (int f = 0; f < 3; f++)
            {
                for (int s = 0; s < 3; s++)
                {
                    if (s == 0)
                    {
                        std::cout << "|";
                    }
                    else
                    {
                    }
                    std::cout << jeu_txt.getGrille().getTab(j, f).getCase(i, s).getValeur();
                }
            }
            std::cout << "|" << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

Jeu &jeuTxt::getJeu_txt()
{
    return jeu_txt;
}

void jeuTxt::afficheMenuTxt()
{
    std::string accueil = "Menu Principal";

    std::cout << accueil << "\n";
    for (size_t size = 0; size < accueil.size(); ++size)
    {                     // pour chaque caractère du titre
        std::cout << '='; // on affiche un caractère de sous-lignage
    }

    std::cout << "\n"; // puis on va a la ligne
    std::cout << "1- Jouer" << std::endl;
    std::cout << "2- Règle du jeu" << std::endl;
    std::cout << "3- Statistiques" << std::endl;
    std::cout << "Quel est votre choix ? " << std::endl;
}

void jeuTxt::afficheMenuRetour(int result)
{
    if (result == 1)
    {
        std::cout << "1- Revenir en arrière " << std::endl;
        std::cout << "2- Continuer" << std::endl;
    }
    else
    {
        std::cout << "Ce choix va vous mener à une grille irréalisable, veuillez revenir en arrière." << std::endl;
        std::cout << "1- Revenir en arrière " << std::endl;
    }
}

void jeuTxt::saisirDifficulte()
{
    int nb;
    std::cout << "Veuillez saisir la difficulté que vous voulez entre 0 et 2" << std::endl;
    std::cout << "0 - Débutant" << std::endl;
    std::cout << "1 - Intermédiaire" << std::endl;
    std::cout << "2 - Expert" << std::endl;
    do
    {
        std::cin >> nb;
        if (nb < 0 || nb > 2)
        {
            std::cout << "Saisie incorrect, veuillez re saisir la difficulté" << std::endl;
        }
    } while (nb < 0 || nb > 2);
    jeu_txt.getGrille().setDifficulte(nb);
}

int jeuTxt::finJeu()
{
    char nb;
    std::cout << "Que souhaitez-vous faire ?" << std::endl;
    std::cout << "1 - Voir une possibilité de résolution de grille" << std::endl;
    std::cout << "2 - Retour au Menu Principal" << std::endl;
    do
    {
        std::cin >> nb;
        if (nb != '2' && nb != '1')
            std::cout << "erreur de valeur veuillez re saisir :" << std::endl;
    } while (nb != '2' && nb != '1');
    std::cout << +nb;
    return nb - '0';
}

void jeuTxt::afficher_statistiques()
{
    if (!jeu_txt.tableau_stats.empty())
    {
        for (const auto &arr : jeu_txt.tableau_stats)
        {
            std::cout << "numéro de la partie : " << arr.numero << std::endl;
            std::cout << "difficulté de la partie : " << arr.dif << std::endl;
            std::cout << "nombre de back de la partie : " << arr.back << std::endl;
            std::cout << "temps de la partie : " << arr.temps << std::endl;
            std::cout << "mode de la partie : " << arr.mode_de_jeu << std::endl;
            std::cout << std::endl;
        }
    }
}

void jeuTxt::saisirMode()
{
    int nb;
    std::cout << "Veuillez saisir le mode de jeu auquel vous voulez jouer" << std::endl;
    std::cout << "0 - Sudoku_classique" << std::endl;
    std::cout << "1 - Sudoku_X" << std::endl;
    std::cout << "2 - Center_Dot_Sudoku" << std::endl;
    do
    {
        std::cin >> nb;
        if (nb < 0 || nb > 2)
        {
            std::cout << "Saisie incorrect, veuillez re saisir la difficulté" << std::endl;
        }
    } while (nb < 0 || nb > 2);
    jeu_txt.getGrille().setMode(nb);
}
int jeuTxt::afficheRegle(const std::string &nom_fichier)
{
    int mb;
    std::ifstream fichierLecture(nom_fichier.c_str());
    if (fichierLecture)
    {
        std::string contenu;
        while (getline(fichierLecture, contenu))
        {
            std::cout << contenu << "\n";
        }
        fichierLecture.close();
    }
    else
    {
        std::cerr << "Erreur dans l'ouverture en lecture du fichier : " << nom_fichier << std::endl;
        return -1;
    }
    std::cout << " Pour revenir au menu principal, appuyer la touche 0 " << std::endl;
    std::cin >> mb;
    return mb;
}

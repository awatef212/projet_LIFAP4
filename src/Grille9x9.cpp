#include "Grille9x9.h"

/**
 * @file Grille9x9.cpp
 * @brief Implémentation de la classe Grille9x9
 */
using namespace std;

Grille9x9::Grille9x9()
{
    difficulte = -1;
    mode = -1;
}

Grille9x9::~Grille9x9()
{
}

bool Grille9x9::test_colonne(int x, int y, int valeur)
{

    assert(x >= 0 && x < 9);
    assert(y >= 0 && y < 9);
    assert(valeur > 0 && valeur < 10);
    int carre = ((3 * ((y) / 3)) + ((x) / 3));
    bool rep = true;
    for (unsigned int j = 0; j < 3; j++)
    {
        for (unsigned int i = 0; i < 3; i++)
        {
            if (getTab(i, carre % 3).getCase(j, x % 3).getValeur() == valeur)
            {
                rep = false;
            }
        }
    }

    return rep;
}

bool Grille9x9::test_ligne(int x, int y, int valeur)
{

    int carre = ((3 * ((y) / 3)) + ((x) / 3));

    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            if (getTab(carre / 3, i).getCase(y % 3, j).getValeur() == valeur)
            {
                return false;
            }
        }
    }

    return true;
}

/*
bool Grille9x9::test_integrale() const
{   Cellule c;
    return ( test_colonne(c) && test_ligne(c) ); // Probleme
}
*/

bool Grille9x9::grille_remplir() const
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)

        {
            if (!tab[i][j].getCase(i, j).getVisible() || tab[i][j].getCase(i, j).getValeur() != 0)
                return false;
        }
    }
    return true;
}

int Grille9x9::getDifficulte() const
{
    return difficulte;
}

int Grille9x9::getMode()
{
    return mode;
}

void Grille9x9::setMode(int newMode)
{
    assert(newMode >= 0 || newMode <= 2);
    mode = newMode;
}

void Grille9x9::setDifficulte(int a)
{
    assert(a >= 0 || a <= 3);
    difficulte = a;
}

Grille3x3 Grille9x9::getTab(int x, int y) const
{
    assert(x >= 0 && x < 9);
    assert(y >= 0 && y < 9);
    return tab[x][y];
}

Grille3x3 &Grille9x9::getTab(int x, int y)
{
    assert(x >= 0 && x < 9);
    assert(y >= 0 && y < 9);
    return tab[x][y];
}

void Grille9x9::init_grille()
{
    genereGrille();

    switch (difficulte)
    {
    case 0:
    {
        int nbgen;
        int nbgen2;
        srand(time(NULL));
        for (unsigned int i = 0; i < 3; i++)
        {
            for (unsigned int j = 0; j < 9; j++)
            {
                // for (unsigned int k = 0; k < nbgen3; k++)
                // {
                nbgen = rand() % 3 + 0;
                nbgen2 = rand() % 3 + 0;
                getTab(i / 3, j).getCase(nbgen, nbgen2).setValeur(0); // on passe trois fois dans chaque grille 3x3 et on change 1 case au hasard à chaque fois. donc au plus on met 3 zéro dans chaque grille 3x3 au moins 1 zéro
                // }
            }
        }
    }
    break;
    case 1:
    {
        int nbgen;
        int nbgen2;
        srand(time(NULL));
        for (unsigned int i = 0; i < 3; i++)
        {
            for (unsigned int j = 0; j < 18; j++)
            {
                nbgen = rand() % 3 + 0;
                nbgen2 = rand() % 3 + 0;
                getTab(i, j % 3).getCase(nbgen, nbgen2).setValeur(0);
            }
        }
    }
    break;
    case 2:
    {
        int nbgen;
        int nbgen2;
        srand(time(NULL));
        for (unsigned int i = 0; i < 3; i++)
        {
            for (unsigned int j = 0; j < 30; j++)
            {

                nbgen = rand() % 3 + 0;
                nbgen2 = rand() % 3 + 0;
                getTab(i % 3, j % 3).getCase(nbgen, nbgen2).setValeur(0);
            }
        }
    }
    break;
    default:
        break;
    }
}

bool Grille9x9::grilleValide(int position)
{
    int i = position / 9, j = position % 9;
    int carre = ((3 * ((j) / 3)) + ((i) / 3));
    if (position == 9 * 9)
        return true;

    if (getTab(carre / 3, carre % 3).getCase(j % 3, i % 3).getValeur() != 0)
        return grilleValide(position + 1);

    for (int k = 1; k <= 9; k++)
    {
        if (verification(i, j, k))
        {

            getTab(carre / 3, carre % 3).getCase(j % 3, i % 3).setValeur(k);
            if (grilleValide(position + 1))
            {
                return true;
            }
        }
    }
    getTab(carre / 3, carre % 3).getCase(j % 3, i % 3).setValeur(0);

    return false;
}

bool Grille9x9::grilleValide2(int position)
{
    int i = position / 9, j = position % 9;
    int carre = ((3 * ((j) / 3)) + ((i) / 3));
    if (position == 9 * 9)
        return true;

    if (getTab(carre / 3, carre % 3).getCase(j % 3, i % 3).getValeur() != 0)
        return grilleValide(position + 1);
    srand(time(NULL));
    for (int k = rand() % 10 + 1; k <= 9; k++)
    {
        if (verification(i, j, k))
        {

            getTab(carre / 3, carre % 3).getCase(j % 3, i % 3).setValeur(k);
            if (grilleValide(position + 1))
            {
                return true;
            }
        }
    }
    getTab(carre / 3, carre % 3).getCase(j % 3, i % 3).setValeur(0);

    return false;
}

bool Grille9x9::verification(int x, int y, int entier)
{
    if (mode == 0)
    {
        return (test_carre(x, y, entier) && test_colonne(x, y, entier) && test_ligne(x, y, entier));
    }
    else if (mode == 1)
    {
        return (test_carre(x, y, entier) && test_colonne(x, y, entier) && test_ligne(x, y, entier) && test_diagonale_droite(x, y, entier)&&test_diagonale_gauche(x, y, entier));
    }
    else if (mode == 2)
    {
        return (test_carre(x, y, entier) && test_colonne(x, y, entier) && test_ligne(x, y, entier) && test_centre(x, y, entier));
    }
    else
    {
        return 0;
    }
}

bool Grille9x9::test_carre(int x, int y, int v)
{
    assert(x >= 0 && x < 9);
    assert(y >= 0 && y < 9);
    assert(v > 0 && v < 10);

    return (getTab(y / 3, x / 3).test(v));
}

bool Grille9x9::test_centre(int x, int y, int v)
{
    assert(x >= 0 && x < 9);
    assert(y >= 0 && y < 9);
    // assert(valeur > 0 && valeur < 10);
    int rep = true;
    if ((x == 1 && y == 1) || (x == 4 && y == 4) || (x == 7 && y == 7) || (x == 4 && y == 7) || (x == 7 && y == 4) || (x == 1 && y == 7) || (x == 7 && y == 1) || (x == 1 && y == 4) || (x == 4 && y == 1))
    {
        for (unsigned int i = 0; i < 3; i++)
        {
            for (unsigned int j = 0; j < 3; j++)
            {
                if (getTab(i, j).getCase(1, 1).getValeur() == v)
                {
                    rep = false;
                }
            }
        }
    }
    return rep;
}

bool Grille9x9::test_diagonale_droite(int x, int y, int valeur)
{
    //int carre = ((3 * ((y) / 3)) + ((x) / 3));
    assert(x >= 0 && x < 9);
    assert(y >= 0 && y < 9);
    assert(valeur > 0 && valeur < 10);
    bool rep = true;
    if (x == y)
    {
        for (unsigned int i = 0; i < 3; i++)
        {
            for (unsigned int j = 0; j < 3; j++)
            {
                if ((getTab(i, i).getCase(j, j).getValeur() == valeur))
                {
                    rep = false;
                }
            }
        }
    }
    return rep;
}

bool Grille9x9::test_diagonale_gauche(int x, int y, int valeur)
{
    //int carre = ((3 * ((y) / 3)) + ((x) / 3));
    assert(x >= 0 && x < 9);
    assert(y >= 0 && y < 9);
    assert(valeur > 0 && valeur < 10);
    bool rep = true;
    if (int(x + y + 1) % 9 == 0)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            for (unsigned int l = 0; l < 3; l++)
            {
                int i = j - 2;
                int m = l - 2;
                if (getTab(abs(m), l).getCase(abs(i), j).getValeur() == valeur)
                {
                    rep = false;
                }
            }
        }
    }
    return rep;
}

void Grille9x9::genereGrille()
{
    int nbgen3;
    int nbgen4;
    int nbgen5;
    switch (mode)
    {
    case 0:
        srand(time(NULL));
        nbgen3 = rand() % 3 + 1;
        nbgen4 = rand() % 3 + 1;
        nbgen5 = rand() % 8 + 1;
        grilleValide2(nbgen3);
        grilleValide2(nbgen4);
        grilleValide2(nbgen5);
        break;
    case 1:
        srand(time(NULL));
        nbgen3 = rand() % 3 + 1;
        nbgen4 = rand() % 3 + 1;
        nbgen5 = rand() % 8 + 1;
        grilleValide2(nbgen3);
        grilleValide2(nbgen4);
        grilleValide2(nbgen5);
        break;
    case 2:

        srand(time(NULL));
        nbgen3 = rand() % 3 + 1;
        nbgen4 = rand() % 3 + 1;
        nbgen5 = rand() % 8 + 1;
        grilleValide2(nbgen3);
        grilleValide2(nbgen4);
        grilleValide2(nbgen5);
        break;
    default:
        break;
    }
}

void Grille9x9::copieGrille(const Grille9x9 &grilleAcopier)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            getTab(i / 3, i % 3).getCase(j / 3, j % 3).setValeur(grilleAcopier.getTab(i / 3, i % 3).getCase(j / 3, j % 3).getValeur());
        }
    }
}

void Grille9x9::testRegression()
{
    Grille9x9 g;
     assert(g.getDifficulte() == -1);
     assert(g.getMode() == -1);
     for (int j = 0; j < 9; j++)
    {
        for (int i = 0; i < 9; i++)
        {
            assert(g.getTab(i / 3, i % 3).getCase(j / 3, j % 3).getValeur() == 0);
            assert(g.getTab(i / 3, i % 3).getCase(j / 3, j % 3).getVisible() == 0);
            assert(g.getTab(i / 3, i % 3).getCase(j / 3, j % 3).getCoordonnees().getX() == j/3);
            assert(g.getTab(i / 3, i % 3).getCase(j / 3, j % 3).getCoordonnees().getY() == j%3);

            g.getTab(i / 3, i % 3).getCase(j / 3, j % 3).setValeur(i);
            g.getTab(i / 3, i % 3).getCase(j / 3, j % 3).setVisible(j%2);
            g.setDifficulte(i%3);
            g.setMode(j%3);
            assert(g.getTab(i / 3, i % 3).getCase(j / 3, j % 3).getValeur() == i);
            assert(g.getTab(i / 3, i % 3).getCase(j / 3, j % 3).getVisible() == j%2);
            assert(g.getDifficulte() == i%3);
            assert(g.getMode() == j%3);

            g.getTab(i / 3, i % 3).getCase(j / 3, j % 3).setValeur((i + j)%9);
            g.getTab(i / 3, i % 3).getCase(j / 3, j % 3).setVisible((i + j)%2);
            g.setDifficulte((i + j)%3);
            g.setMode((i + j)%3);
            assert(g.getTab(i / 3, i % 3).getCase(j / 3, j % 3).getValeur() == (i + j)%9);
            assert(g.getTab(i / 3, i % 3).getCase(j / 3, j % 3).getVisible() == (i + j)%2);
            assert(g.getDifficulte() == (i + j)%3);
            assert(g.getMode() == (i + j)%3);

        }
    }
}
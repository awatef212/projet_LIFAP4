#include "Grille3x3.h"

/**
 * @file Grille3x3.cpp
 * @brief Implémentation de la classe Grille3x3
 */
Grille3x3::Grille3x3()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tab[i][j].getCoordonnees().setX(i);
            tab[i][j].getCoordonnees().setY(j);
        }
    }
}

bool Grille3x3::test(int valeur_ajout) const
{
    assert(valeur_ajout < 10 && valeur_ajout >= 1);
    for (unsigned int i = 0; i < 3; i++)
    {
        for (unsigned int j = 0; j < 3; j++)
        {
            if (tab[i][j].getValeur() == valeur_ajout)
                return false;
        }
    }
    return true;
}


Cellule Grille3x3::getCase(int x, int y) const
{
    assert(x < 9 && x >= 0);
    assert(y < 9 && y >= 0);
    return tab[x][y];
}
Cellule &Grille3x3::getCase(int x, int y)
{
    assert(x < 9 && x >= 0);
    assert(y < 9 && y >= 0);
    return tab[x][y];
}

Grille3x3::~Grille3x3()
{
}

void Grille3x3::testRegression()
{
    Grille3x3 g;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            assert(g.tab[i][j].getCoordonnees().getX() == i);
            assert(g.tab[i][j].getCoordonnees().getY() == j);
            assert(g.tab[i][j].getValeur() == 0);
            assert(g.tab[i][j].getVisible() == 0);
        }
    }

    Grille3x3 g1, g2;
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            g1.tab[i%3][j%3].getCoordonnees().setX(i%3);
            g1.tab[i%3][j%3].getCoordonnees().setY(j%3);
            g1.tab[i%3][j%3].setValeur( (i*j) %9 );
            g1.tab[i%3][j%3].setVisible( (i+j) %2 );
           
            assert(g1.tab[i%3][j%3].getCoordonnees().getX() == i%3);
            assert(g1.tab[i%3][j%3].getCoordonnees().getY() == j%3);
            assert(g1.tab[i%3][j%3].getValeur() == ((i*j) %9));
            assert(g1.tab[i%3][j%3].getVisible() == ((i+j) %2));

            g2.tab[i%3][j%3].getCoordonnees().setX((i*j)%3);
            g2.tab[i%3][j%3].getCoordonnees().setY((i+j)%3);
            g2.tab[i%3][j%3].setValeur( (i+j) %9 );
            g2.tab[i%3][j%3].setVisible( (i*j) %2 );
           
            assert(g2.tab[i%3][j%3].getCoordonnees().getX() == (i*j)%3);
            assert(g2.tab[i%3][j%3].getCoordonnees().getY() == (i+j)%3);
            assert(g2.tab[i%3][j%3].getValeur() == ((i+j) %9));
            assert(g2.tab[i%3][j%3].getVisible() == ((i*j) %2));
        }
    }
}
#include "Cellule.h"

/**
 * @file Cellule.cpp
 * @brief Implémentation de la classe Cellule
 */

Cellule::Cellule()
{
    valeur = 0;
    visible = false;
}

Cellule::Cellule(int _x, int _y, int _valeur)
{
    assert(_valeur < 10 && _valeur >= 0);
    assert(_x < 9 && _x >= 0);
    assert(_y < 9 && _y >= 0);
    valeur = _valeur;
    visible = false;
    position.setX(_x);
    position.setY(_y);
}

Cellule::Cellule(int _x, int _y, int _valeur, bool _visible)
{
    assert(_valeur < 10 && _valeur >= 0);
    assert(_x < 9 && _x >= 0);
    assert(_y < 9 && _y >= 0);
    assert(_visible == 0 || _visible == 1);
    position.setX(_x);
    position.setY(_y);
    valeur = _valeur;
    visible = _visible;
}

Cellule::~Cellule()
{
}

int Cellule::getValeur() const
{
    return valeur;
}

bool Cellule::getVisible() const
{
    return visible;
}

void Cellule::setVisible(bool _visible)
{
    assert(_visible == true || _visible == false);
    visible = _visible;
}

void Cellule::setValeur(int _valeur)
{
    assert(_valeur < 10 && _valeur >= 0);
    valeur = _valeur;
}
Coordonnees Cellule::getCoordonnees() const
{
    return position;
}
Coordonnees &Cellule::getCoordonnees()
{
    return position;
}

void Cellule::testRegression()
{
    Cellule c1;
    assert(c1.getCoordonnees().getX() == 0);
    assert(c1.getCoordonnees().getY() == 0);
    assert(c1.getValeur() == 0);
    assert(c1.getVisible() == 0);

    Cellule c2(6, 5, 5);
    assert(c2.position.getX() == 6);
    assert(c2.position.getY() == 5);
    assert(c2.getValeur() == 5);
    assert(c2.getVisible() == 0);
    c2.setVisible(1);
    assert(c2.getVisible() == 1);

    for ( int i = 0; i < 9; i++)
        for ( int j = 0; j < 9; j++)
        {
            {
                c2.getCoordonnees().setX(i);
                c2.getCoordonnees().setY(j);
                c2.setValeur((i * j) % 9);
                c2.setVisible((i * j) % 2);

                assert(c2.getCoordonnees().getX() == i);
                assert(c2.getCoordonnees().getY() == j);
                assert(c2.getValeur() == ((i * j) % 9));
                assert(c2.getVisible() == ((i * j) % 2));
            }
        }
}
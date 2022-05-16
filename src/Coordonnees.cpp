#include "Coordonnees.h"

/**
 * @file Coordonnees.cpp
 * @brief Implémentation de la classe Coordonnees
 */

Coordonnees::Coordonnees()
{
    x = 0;
    y = 0;
}

Coordonnees::Coordonnees(int _x, int _y)
{
    assert(_x < 9 && _x >= 0);
    assert(_y < 9 && _y >= 0);
    x = _x;
    y = _y;
}

int Coordonnees::getX() const
{
    return x;
}

int Coordonnees::getY() const
{
    return y;
}

void Coordonnees::setX(int _x)
{
    assert(_x < 9 && _x >= 0);
    x = _x;
}
void Coordonnees::setY(int _y)
{
    assert(_y < 9 && _y >= 0);
    y = _y;
}
void Coordonnees::testRegression()
{
    Coordonnees c1;
    Coordonnees c2(1, 2);
    assert(c2.getX() == 1 && c2.getY() == 2);
    for ( int i = 0; i < 9; i++)
        for ( int j = 0; j < 9; j++)
        {
            {
                c1.setX(i);
                c1.setY(j);
                assert(c1.getX() == i);
                assert(c1.getY() == j);
                c2.setX(( (i*i) %9) );
                c2.setY(( (j*j) %9) );
                assert(c2.getX() == ( (i*i) %9) );
                assert(c2.getY() == ( (j*j) %9) );

            }
        }
}
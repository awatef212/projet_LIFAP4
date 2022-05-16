#include "Jeu.h"

/**
 * @file Jeu.cpp
 * @brief Implémentation de la classe Jeu
 */

Jeu::Jeu()
{
}

Jeu::~Jeu()
{
}

bool Jeu::ajout_valeur(int x, int y, int Nentier)
{
    assert(x >= 0 && x <= 9);
    assert(y >= 0 && y <= 9);
    assert(Nentier > 0 && Nentier < 10);
    int carre = ((3 * ((y) / 3)) + ((x) / 3));
    if (getGrille().verification(x, y, Nentier) )//&& getGrille().getTab(carre / 3, carre % 3).getCase(y % 3, x % 3).getValeur() == 0
    {

        assert(Nentier > 0 && Nentier <= 9);
        getGrille().getTab(carre / 3, carre % 3).getCase(y % 3, x % 3).setValeur(Nentier);
        Coordonnees dernierValeur(y, x);
        precedent.empiler(dernierValeur);
        return true;
    }
    else
    {
        Nberreur++;
        if (Nberreur == 3)
        {
            fin_partie = true;
        }
        return false;
    }
}



bool Jeu::getFin()
{

    return fin_partie;
}

void Jeu::setFin(bool _fin_partie)
{

    assert(_fin_partie == true || _fin_partie == false);
    fin_partie = _fin_partie;
}

Grille9x9 &Jeu::getGrille()
{
    return grille;
}

int Jeu::getErreur()
{
    return Nberreur;
}

void Jeu::setErreur(int erreur)
{

    assert(erreur >= 0 || erreur <= 3);
    Nberreur = erreur;
}

Coordonnees Jeu::precedentValeur()
{
    Coordonnees supprime;
    if (!precedent.estVide())
    {
        supprime = precedent.consulterSommet();
        precedent.depiler();
        int carre = ((3 * ((supprime.getX()) / 3)) + ((supprime.getY()) / 3));
        getGrille().getTab(carre / 3, carre % 3).getCase(supprime.getX() % 3, supprime.getY() % 3).setValeur(0);
    }
    std::cout<<supprime.getX()<<supprime.getY()<<"\n";
    return supprime;
}

Pile &Jeu::getPile()
{
    return precedent;
}

// void Jeu::setMode_de_jeu(int NewMode)
// {
//     mode_de_jeu=NewMode;
// }

// int Jeu::getMode_de_jeu()
// {
//     return mode_de_jeu;
// }

bool Jeu::getFlag()
{
    return flagErreur;
}

void Jeu::setFlag(bool ent)
{
    flagErreur = ent;
}

void Jeu::setTableau_stat(int n, int d, int b, float t, int m)
{
    tableau_stats.push_back({n, d, b, t, m});
}

void Jeu::testRegression()
{
    Jeu jeu;
    assert(jeu.getGrille().getDifficulte() == -1);
    assert(jeu.getGrille().getMode() == -1);
    assert(jeu.getFlag() == false);
    assert(jeu.getFin() == false);
    assert(jeu.getErreur() == 0);
    for (int j = 0; j < 9; j++)
    {
        for (int i = 0; i < 9; i++)
        {
            assert(jeu.getGrille().getTab(i / 3, i % 3).getCase(j / 3, j % 3).getValeur() == 0);
            assert(jeu.getGrille().getTab(i / 3, i % 3).getCase(j / 3, j % 3).getVisible() == 0);
            assert(jeu.getGrille().getTab(i / 3, i % 3).getCase(j / 3, j % 3).getCoordonnees().getX() == j / 3);
            assert(jeu.getGrille().getTab(i / 3, i % 3).getCase(j / 3, j % 3).getCoordonnees().getY() == j % 3);

            jeu.setFlag(i % 2);
            jeu.setFin(j % 2);
            jeu.setErreur(i % 3);
            assert(jeu.getFlag() == i % 2);
            assert(jeu.getFin() == j % 2);
            assert(jeu.getErreur() == i % 3);
        }
    }
    
}
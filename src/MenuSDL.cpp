#include "MenuSDL.h"

/**
 * @file MenuSDL.cpp
 * @brief Implémentation de la classe MenuSDL
 */

MenuSDL::MenuSDL()
{
}

MenuSDL::~MenuSDL()
{
}

void MenuSDL::run()
{
    // changementEtat(etatCourant);
    // while (!JouerSDL.quit)
    // {
    //     doState(etatCourant);
    // }
    entreeEtat(ACCUEIL);
    doState(ACCUEIL);
}

void MenuSDL::changementEtat(etat_t etatSuivant)
{
    sortieEtat(etatCourant);
    // setEtatCourant(etatSuivant);
    etatCourant = etatSuivant;
    entreeEtat(etatSuivant);
    // doState(etatSuivant);
}

void MenuSDL::setEtatCourant(etat_t newEtat)
{
    etatCourant = newEtat;
}

void MenuSDL::sortieEtat(etat_t etatCourant)
{
    switch (etatCourant)
    {
    case ACCUEIL:

        break;
    case JEU:
        // grille.getGrille().reinitialisation();
        modeSelectionne = false;
        JouerSDL.diffSelectionne = false;
        // pretAetreInit = false;
        numChoisi = false;
        initStats = true;
        // grille.setFin(false);
        // grille.setErreur(0);
        break;
    case REGLE_DU_JEU:

        break;
    case STATS:

        break;
    case FIN_JEU:

        break;
    default:
        break;
    }
}

void MenuSDL::entreeEtat(etat_t etatSuivant)
{
    switch (etatSuivant)
    {
    case ACCUEIL:
        if (!init)
        {
            JouerSDL.initSDL();
            JouerSDL.initTexture_Surface();
            init = true;
        }
        JouerSDL.afficheAccueil();
        break;
    case JEU:

        nombre_partie++;

        break;
    case REGLE_DU_JEU:

        break;
    case STATS:

        SDL_RenderClear(JouerSDL.renderer);

        break;

    case FIN_JEU:

        break;
    default:
        break;
    }
}

void MenuSDL::doState(etat_t etatActuel)
{

    switch (etatActuel)
    {
    case ACCUEIL:
    {
        SDLboucleAccueil();
        break;
    }

    case JEU:
    {
        SDLboucleJeu();
        break;
    }

    case REGLE_DU_JEU:
    {
        while (etatCourant == REGLE_DU_JEU && !JouerSDL.quit)
        {
            JouerSDL.afficheRegle();
            while (SDL_PollEvent(&events))
            {
                if (events.type == SDL_QUIT)
                    JouerSDL.quit = true; // Si l'utilisateur a clique sur la croix de fermeture, pas forcément demandé dans le td mais utile.
                else if (events.type == SDL_KEYDOWN)
                { // Si une touche est enfoncee
                    switch (events.key.keysym.scancode)
                    {
                        default:
                break;
                    }
                }
                else if (events.type == SDL_MOUSEBUTTONDOWN)
                {
                    int x = events.button.x; // récupération de la position de la souris
                    int y = events.button.y;
                    if (x > 20 && x < 60 && y > 20 && y < 35)
                    {
                        // accueil = true;
                        changementEtat(ACCUEIL);
                        doState(ACCUEIL);
                    }
                }
            }
            SDL_RenderPresent(JouerSDL.renderer);
        }
        break;
    }
    case FIN_JEU:
    {
    }
    break;
    case STATS:
    {
        SDLboucleStats();
    }
    break;
    default:
        break;
    }
}

int MenuSDL::getNbPrecedent()
{
    return nbPrecedent;
}

void MenuSDL::SDLboucleJeu()
{
    using namespace std::chrono;
    auto start = steady_clock::now();
    Jeu tampon;
    Jeu grille;
    while (etatCourant == JEU && !JouerSDL.quit)
    {
        if (!modeSelectionne && !JouerSDL.diffSelectionne)
        {
            SDL_RenderClear(JouerSDL.renderer);
            JouerSDL.afficheMode();
            boucleSelectionMode(grille);
        }
        if (!JouerSDL.diffSelectionne && modeSelectionne)
        {
            SDL_RenderClear(JouerSDL.renderer);
            JouerSDL.afficheDifficulte();
            boucleSelectionDIff(grille);
        }
        if (pretAetreInit == true)
        {
            
            SDL_RenderClear(JouerSDL.renderer);
            grille.getGrille().init_grille();
            JouerSDL.afficheGrille(grille.getGrille());
            JouerSDL.affiche_coeur();
            pretAetreInit = false;
        }
        else
        {
        }
        if (!grille.getFin() && !accueil && modeSelectionne && JouerSDL.diffSelectionne)
        {
            boucleActionGrille(grille, tampon);
            if (realisable == false)
            {
                SDL_Rect destr2{0, 0, JouerSDL.dimx, 90};
                SDL_Surface *fan = NULL;

                fan = IMG_Load("../data/irrealisable.png"); //"data/perdu.png"
                if (fan == NULL)
                {
                    std::cout << "error création page d'accueil" << std::endl;
                }
                SDL_Texture *texture = SDL_CreateTextureFromSurface(JouerSDL.renderer, fan);
                SDL_RenderCopy(JouerSDL.renderer, texture, NULL, &destr2);
                SDL_FreeSurface(fan);
                SDL_DestroyTexture(texture);
            }
        }
        if (grille.getFin() && grille.getErreur() == 3)
        {
            if (initStats)
            {
                auto end = steady_clock::now();
                duree_seconde = duration_cast<milliseconds>(end - start).count();
                duree_seconde = duree_seconde / 1000; // on va stocker le temps en seconde dans les statistiques et au moment d'afficher le temps à l'utilisateur on convertira en min + sec.
                JouerSDL.grille.setTableau_stat(nombre_partie, grille.getGrille().getDifficulte(), nbPrecedent, duree_seconde, grille.getGrille().getMode());
                initStats = false;
            }
            SDL_RenderClear(JouerSDL.renderer);
            SDL_Rect destr{0, 0, JouerSDL.dimx, 150};
            JouerSDL.affichePerdu(destr);
            if (!accueil)
            {
                while (SDL_PollEvent(&events))
                {
                    if (events.type == SDL_QUIT)
                        JouerSDL.quit = true; // Si l'utilisateur a clique sur la croix de fermeture, pas forcément demandé dans le td mais utile.
                    else if (events.type == SDL_KEYDOWN)
                    { // Si une touche est enfoncee
                        switch (events.key.keysym.scancode)
                        {
                            default:
                break;
                        }
                    }
                    else if (events.type == SDL_MOUSEBUTTONDOWN)
                    {
                        int x = events.button.x; // récupération de la position de la souris
                        int y = events.button.y;
                        if (x > JouerSDL.dimx / 2 - 250 && x < (JouerSDL.dimx / 2 - 250) + 500 && y > JouerSDL.dimy / 2 && y < (JouerSDL.dimy / 2) + 70)
                        {
                            grille.getGrille().grilleValide(0);
                            SDL_RenderClear(JouerSDL.renderer);
                            grille.setFin(false);
                            JouerSDL.afficheGrille(grille.getGrille());
                        }
                        if (x > JouerSDL.dimx / 2 - 250 && x < (JouerSDL.dimx / 2 - 250) + 500 && y > JouerSDL.dimy / 2 + 100 && y < (JouerSDL.dimy / 2 + 100) + 70)
                        {
                            changementEtat(ACCUEIL);
                        }
                    }
                }
            }
        }
        if (grille.getFin() && grille.getErreur() != 3)
        {
            JouerSDL.grille.setTableau_stat(nombre_partie, grille.getGrille().getDifficulte(), nbPrecedent, duree_seconde, grille.getGrille().getMode());
            // SDL_Rect destr{0, 0, JouerSDL.dimx, 150};
            JouerSDL.afficheVictoire();
            while (SDL_PollEvent(&events))
            {
                if (events.type == SDL_QUIT)
                    JouerSDL.quit = true; // Si l'utilisateur a clique sur la croix de fermeture, pas forcément demandé dans le td mais utile.
                else if (events.type == SDL_KEYDOWN)
                { // Si une touche est enfoncee
                    switch (events.key.keysym.scancode)
                    {
                        default:
                break;
                    }
                }
                else if (events.type == SDL_MOUSEBUTTONDOWN)
                {
                    int x = events.button.x; // récupération de la position de la souris
                    int y = events.button.y;
                    if (x > JouerSDL.dimx / 2 - 250 && x < (JouerSDL.dimx / 2 - 250) + 500 && y > JouerSDL.dimy / 2 && y < (JouerSDL.dimy / 2) + 70)
                    {
                        changementEtat(ACCUEIL);
                    }
                }
            }
        }
        if (accueil)
        {
            accueil = false;
            changementEtat(ACCUEIL);
        }
        SDL_RenderPresent(JouerSDL.renderer);
    }
}

void MenuSDL::SDLboucleStats()
{
    while (etatCourant == STATS && !JouerSDL.quit)
    {
        SDL_Rect destr;
        JouerSDL.afficheStats();
        TTF_Font *font = TTF_OpenFont("../data/DejaVuSansCondensed.ttf", 50);
        if (font == NULL)
        {
            std::cout << "error chargement font";
        }
        SDL_Color font_color;
        font_color.r = 50;
        font_color.g = 50;
        font_color.b = 255;
        SDL_Rect positionStats;
        positionStats.x = 95;
        positionStats.y = 65;
        positionStats.w = 50;
        positionStats.h = 30;
        destr.x = 40;
        destr.y = 110;
        destr.h = 250;
        destr.w = 40;
        JouerSDL.remplissageStats(positionStats, destr, font, font_color);
        while (SDL_PollEvent(&events))
        {
            if (events.type == SDL_QUIT)
                JouerSDL.quit = true; // Si l'utilisateur a clique sur la croix de fermeture, pas forcément demandé dans le td mais utile.
            else if (events.type == SDL_KEYDOWN)
            { // Si une touche est enfoncee
                switch (events.key.keysym.scancode)
                {default:
                break;
                }
            }
            else if (events.type == SDL_MOUSEBUTTONDOWN)
            {
                int x = events.button.x; // récupération de la position de la souris
                int y = events.button.y;
                if (x > 20 && x < 60 && y > 20 && y < 35)
                {
                    // accueil = true;
                    changementEtat(ACCUEIL);
                    doState(ACCUEIL);
                }
            }
        }
    }
}

void MenuSDL::boucleSelectionMode(Jeu &grille)
{
    while (SDL_PollEvent(&events))
    {
        if (events.type == SDL_QUIT)
            JouerSDL.quit = true; // Si l'utilisateur a clique sur la croix de fermeture, pas forcément demandé dans le td mais utile.
        else if (events.type == SDL_KEYDOWN)
        { // Si une touche est enfoncee
            switch (events.key.keysym.scancode)
            {
                default:
                break;
            }
        }
        else if (events.type == SDL_MOUSEBUTTONDOWN)
        {
            int x = events.button.x; // récupération de la position de la souris
            int y = events.button.y;

            if (x > JouerSDL.dimx / 2 - 250 && x < (JouerSDL.dimx / 2 - 250) + 500 && y > JouerSDL.dimy / 2 && y < (JouerSDL.dimy / 2) + 70)
            {
                grille.getGrille().setMode(0);
                modeSelectionne = true;
            }
            if (x > JouerSDL.dimx / 2 - 250 && x < (JouerSDL.dimx / 2 - 250) + 500 && y > JouerSDL.dimy / 2 + 100 && y < (JouerSDL.dimy / 2 + 100) + 70)
            {
                grille.getGrille().setMode(1);
                modeSelectionne = true;
            }
            if (x > JouerSDL.dimx / 2 - 250 && x < (JouerSDL.dimx / 2 - 250) + 500 && y > JouerSDL.dimy / 2 + 200 && y < (JouerSDL.dimy / 2 + 200) + 70)
            {
                grille.getGrille().setMode(2);
                modeSelectionne = true;
            }
        }
    }
}
void MenuSDL::boucleSelectionDIff(Jeu &grille)
{
    while (SDL_PollEvent(&events))
    {
        if (events.type == SDL_QUIT)
            JouerSDL.quit = true; // Si l'utilisateur a clique sur la croix de fermeture, pas forcément demandé dans le td mais utile.
        else if (events.type == SDL_KEYDOWN)
        { // Si une touche est enfoncee
            switch (events.key.keysym.scancode)
            {
                default:
                break;
            }
        }
        else if (events.type == SDL_MOUSEBUTTONDOWN)
        {
            int x = events.button.x; // récupération de la position de la souris
            int y = events.button.y;

            if (x > JouerSDL.dimx / 2 - 250 && x < (JouerSDL.dimx / 2 - 250) + 500 && y > JouerSDL.dimy / 2 && y < (JouerSDL.dimy / 2) + 70)
            {
                grille.getGrille().setDifficulte(0);
                JouerSDL.diffSelectionne = true;
                pretAetreInit = true;
            }
            if (x > JouerSDL.dimx / 2 - 250 && x < (JouerSDL.dimx / 2 - 250) + 500 && y > JouerSDL.dimy / 2 + 100 && y < (JouerSDL.dimy / 2 + 100) + 70)
            {
                grille.getGrille().setDifficulte(1);
                JouerSDL.diffSelectionne = true;
                pretAetreInit = true;
            }
            if (x > JouerSDL.dimx / 2 - 250 && x < (JouerSDL.dimx / 2 - 250) + 500 && y > JouerSDL.dimy / 2 + 200 && y < (JouerSDL.dimy / 2 + 200) + 70)
            {
                grille.getGrille().setDifficulte(2);
                JouerSDL.diffSelectionne = true;
                pretAetreInit = true;
            }
        }
    }
}

void MenuSDL::boucleActionGrille(Jeu &grille, Jeu &tampon)
{
    while (SDL_PollEvent(&events))
    {

        if (events.type == SDL_QUIT)
            JouerSDL.quit = true; // Si l'utilisateur a clique sur la croix de fermeture, pas forcément demandé dans le td mais utile.
        else if (events.type == SDL_KEYDOWN)
        { // Si une touche est enfoncee
            switch (events.key.keysym.scancode)
            {default:
                break;
            }
        }
        else if (events.type == SDL_MOUSEBUTTONDOWN)
        {
            int x = events.button.x; // récupération de la position de la souris
            int y = events.button.y;

            if (x > 10 && x < 40 && y > 635 && y < 665)
            {
                accueil = true;
            }
            if (x > 750 && x < 750 + 30 && y > 635 && y < 635 + 30)
            {
                Coordonnees supprime;
                nbPrecedent++;
                supprime = grille.precedentValeur();
                SDL_RenderClear(JouerSDL.renderer);
                JouerSDL.afficheGrille(grille.getGrille());
                JouerSDL.affiche_coeur();
                JouerSDL.barre_coeur(grille.getErreur());
                if (realisable == false)
                {
                    realisable = true;
                }
            }
            for (int j = 0; j < 3; j++)
            {

                for (int i = 0; i < 3; i++)
                {
                    for (int f = 0; f < 3; f++)
                    {
                        for (int s = 0; s < 3; s++)
                        {
                            if (x > ((JouerSDL.r.w / 9) * 3 * f + (JouerSDL.r.w / 9) * s) + 5 + JouerSDL.r.x && x < (((JouerSDL.r.w / 9) * 3 * f + (JouerSDL.r.w / 9) * s) + 5 + JouerSDL.r.x) + JouerSDL.r.w / 9 - 7 && y > ((JouerSDL.r.h / 9) * 3 * j + (JouerSDL.r.h / 9) * i) + 6 + JouerSDL.r.y && y < (((JouerSDL.r.h / 9) * 3 * j + (JouerSDL.r.h / 9) * i) + 6 + JouerSDL.r.y) + JouerSDL.r.h / 9 - 10)
                            {
                                if (grille.getGrille().getTab(j, f).getCase(i, s).getValeur() == 0)
                                {
                                    if (!numChoisi)
                                    {
                                        numChoisi = true;
                                        t = f;
                                        u = j;
                                        p = s;
                                        r = i;
                                    }
                                    else
                                    {
                                    }
                                }
                                else
                                {
                                }
                            }
                        }
                    }
                }
            }
            if (numChoisi)
            {
                for (int i2 = 1; i2 < 10; i2++)
                {
                    if (x > 70 * i2 + 15 && x < 70 * i2 + 15 + 50 && y > 700 && y < 700 + 70)
                    {
                        bool valide = grille.ajout_valeur(t * 3 + p, u * 3 + r, i2);
                        if (valide)
                        {
                            tampon.getGrille().copieGrille(grille.getGrille());
                            SDL_Rect destr;
                            destr.h = JouerSDL.r.h / 9 - 10;
                            destr.w = JouerSDL.r.w / 9 - 7;
                            destr.x = ((JouerSDL.r.w / 9) * 3 * t + (JouerSDL.r.w / 9) * p) + 5 + JouerSDL.r.x;
                            destr.y = ((JouerSDL.r.h / 9) * 3 * u + (JouerSDL.r.h / 9) * r) + 6 + JouerSDL.r.y;
                            if (grille.getGrille().grilleValide(0) == false)
                            {
                                realisable = false;
                            }
                            else
                            {
                                grille.getGrille().copieGrille(tampon.getGrille());
                            }
                            JouerSDL.majGrille(destr, i2);
                        }
                        else
                        {
                            JouerSDL.barre_coeur(grille.getErreur());
                        }
                        numChoisi = false;
                    }
                }
            }
        }
    }
}

void MenuSDL::SDLboucleAccueil()
{
    while (etatCourant == ACCUEIL && !JouerSDL.quit)
    {
        // SDL_Event events;
        while (SDL_PollEvent(&events))
        {
            if (events.type == SDL_QUIT)
                JouerSDL.quit = true; // Si l'utilisateur a clique sur la croix de fermeture, pas forcément demandé dans le td mais utile.
            else if (events.type == SDL_KEYDOWN)
            { // Si une touche est enfoncee
                switch (events.key.keysym.scancode)
                { default:
                break;
                }
            }
            else if (events.type == SDL_MOUSEBUTTONDOWN)
            {
                int x = events.button.x; // récupération de la position de la souris
                int y = events.button.y;

                if (x > JouerSDL.dimx / 2 - 100 && x < (JouerSDL.dimx / 2 - 100) + 180 && y > JouerSDL.dimy / 2 && y < (JouerSDL.dimy / 2) + 70)
                {
                    changementEtat(JEU);
                    doState(JEU);
                }
                if (x > JouerSDL.dimx / 2 - 100 && x < (JouerSDL.dimx / 2 - 100) + 180 && y > JouerSDL.dimy / 2 + 100 && y < (JouerSDL.dimy / 2 + 100) + 70)
                {
                    changementEtat(REGLE_DU_JEU);
                    doState(REGLE_DU_JEU);
                }
                if (x > JouerSDL.dimx / 2 - 100 && x < (JouerSDL.dimx / 2 - 100) + 180 && y > JouerSDL.dimy / 2 + 200 && y < (JouerSDL.dimy / 2 + 200) + 70)
                {
                    changementEtat(STATS);
                    doState(STATS);
                }
            }
            SDL_RenderPresent(JouerSDL.renderer);
        }
    }
}
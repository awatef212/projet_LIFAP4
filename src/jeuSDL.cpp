#include "jeuSDL.h"

/**
 * @file jeuSDL.cpp
 * @brief Implémentation de la classe jeuSDL
 */

jeuSDL::jeuSDL()
{
}

jeuSDL::~jeuSDL()
{
    SDL_FreeSurface(victoire);
    SDL_DestroyTexture(victoireT);
    SDL_FreeSurface(perdu);
    SDL_DestroyTexture(perduT);
    SDL_FreeSurface(iconeStats);
    SDL_DestroyTexture(iconeStatsT);
    SDL_FreeSurface(titreStats);
    SDL_DestroyTexture(titreStatsT);
    SDL_FreeSurface(cadreStats);
    SDL_DestroyTexture(cadreStatsT);
    SDL_FreeSurface(regle);
    SDL_DestroyTexture(regleT);
    SDL_FreeSurface(Return);
    SDL_DestroyTexture(ReturnT);
    SDL_FreeSurface(boutonAccueil);
    SDL_DestroyTexture(boutonAccueilT);
    SDL_FreeSurface(resolution);
    SDL_DestroyTexture(resolutionT);
    SDL_FreeSurface(croix);
    SDL_DestroyTexture(croixT);
    SDL_FreeSurface(coeurs);
    SDL_DestroyTexture(coeursT);
    SDL_FreeSurface(boutonX);
    SDL_DestroyTexture(boutonXT);
    SDL_FreeSurface(boutonCenterDot);
    SDL_DestroyTexture(boutonCenterDotT);
    SDL_FreeSurface(boutonClassique);
    SDL_DestroyTexture(boutonClassiqueT);
    SDL_FreeSurface(accueil);
    SDL_DestroyTexture(accueilT);
    SDL_FreeSurface(titreDiff);
    SDL_DestroyTexture(titreDiffT);
    SDL_FreeSurface(titreMode);
    SDL_DestroyTexture(titreModeT);
    SDL_FreeSurface(boutonFacile);
    SDL_DestroyTexture(boutonFacileT);
    SDL_FreeSurface(boutonDifficile);
    SDL_DestroyTexture(boutonDifficileT);
    SDL_FreeSurface(boutonMoyen);
    SDL_DestroyTexture(boutonMoyenT);
    SDL_FreeSurface(boutonStats);
    SDL_DestroyTexture(boutonStatsT);
    SDL_FreeSurface(boutonRegle);
    SDL_DestroyTexture(boutonRegleT);
    SDL_FreeSurface(boutonJouer);
    SDL_DestroyTexture(boutonJouerT);
    SDL_FreeSurface(home);
    SDL_DestroyTexture(homeT);
    SDL_FreeSurface(nb0);
    SDL_DestroyTexture(nb0T);
    SDL_FreeSurface(nb1);
    SDL_DestroyTexture(nb1T);
    SDL_FreeSurface(nb2);
    SDL_DestroyTexture(nb2T);
    SDL_FreeSurface(nb3);
    SDL_DestroyTexture(nb3T);
    SDL_FreeSurface(nb4);
    SDL_DestroyTexture(nb4T);
    SDL_FreeSurface(nb5);
    SDL_DestroyTexture(nb5T);
    SDL_FreeSurface(nb6);
    SDL_DestroyTexture(nb6T);
    SDL_FreeSurface(nb7);
    SDL_DestroyTexture(nb7T);
    SDL_FreeSurface(nb8);
    SDL_DestroyTexture(nb8T);
    SDL_FreeSurface(nb9);
    SDL_DestroyTexture(nb9T);
    SDL_FreeSurface(grille_classique);
    SDL_DestroyTexture(grille_classiqueT);
    SDL_FreeSurface(grille_X);
    SDL_DestroyTexture(grille_XT);
    SDL_FreeSurface(grille_centerDott);
    SDL_DestroyTexture(grille_centerDottT);
    SDL_FreeSurface(fond);
    SDL_DestroyTexture(fondT);
    SDL_FreeSurface(undo);
    SDL_DestroyTexture(undoT);
    SDL_FreeSurface(irrea);
    SDL_DestroyTexture(irreaT);
}

void jeuSDL::initSDL()
{
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() != 0)
    {
        std::cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
        std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }
    dimx = 800;
    dimy = 800;
    screen = SDL_CreateWindow("SUDOKUFAN", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (screen == NULL)
    {
        std::cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }
    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);
    assert(renderer != NULL);
    assert(SDL_RenderClear(renderer) == 0);
}
void jeuSDL::initTexture_Surface()
{
    perdu = IMG_Load("./data/perdu.png");
    perduT = SDL_CreateTextureFromSurface(renderer, perdu);
    grille_classique = IMG_Load("./data/fond3.png");
    grille_classiqueT = SDL_CreateTextureFromSurface(renderer, grille_classique);
    grille_X = IMG_Load("./data/fondX.png");
    grille_XT = SDL_CreateTextureFromSurface(renderer, grille_X);
    grille_centerDott = IMG_Load("./data/centerDott.png");
    grille_centerDottT = SDL_CreateTextureFromSurface(renderer, grille_centerDott);
    fond = IMG_Load("./data/fondGris.png");
    fondT = SDL_CreateTextureFromSurface(renderer, fond);
    undo = IMG_Load("./data/undo.png");
    undoT = SDL_CreateTextureFromSurface(renderer, undo);
    nb0 = IMG_Load("./data/chiffre_0.png");
    nb0T = SDL_CreateTextureFromSurface(renderer, nb0);
    nb1 = IMG_Load("./data/chiffre_1.png");
    nb1T = SDL_CreateTextureFromSurface(renderer, nb1);
    nb2 = IMG_Load("./data/chiffre_2.png");
    nb2T = SDL_CreateTextureFromSurface(renderer, nb2);
    nb3 = IMG_Load("./data/chiffre_3.png");
    nb3T = SDL_CreateTextureFromSurface(renderer, nb3);
    nb4 = IMG_Load("./data/chiffre_4.png");
    nb4T = SDL_CreateTextureFromSurface(renderer, nb4);
    nb5 = IMG_Load("./data/chiffre_5.png");
    nb5T = SDL_CreateTextureFromSurface(renderer, nb5);
    nb6 = IMG_Load("./data/chiffre_6.png");
    nb6T = SDL_CreateTextureFromSurface(renderer, nb6);
    nb7 = IMG_Load("./data/chiffre_7.png");
    nb7T = SDL_CreateTextureFromSurface(renderer, nb7);
    nb8 = IMG_Load("./data/chiffre_8.png");
    nb8T = SDL_CreateTextureFromSurface(renderer, nb8);
    nb9 = IMG_Load("./data/chiffre_9.png");
    nb9T = SDL_CreateTextureFromSurface(renderer, nb9);
    home = IMG_Load("./data/home.png");
    homeT = SDL_CreateTextureFromSurface(renderer, home);
    accueil = IMG_Load("./data/Accueil.png");
    accueilT = SDL_CreateTextureFromSurface(renderer, accueil);
    boutonRegle = IMG_Load("./data/boutonR.png");
    boutonRegleT = SDL_CreateTextureFromSurface(renderer, boutonRegle);
    boutonJouer = IMG_Load("./data/boutonJ.png");
    boutonJouerT = SDL_CreateTextureFromSurface(renderer, boutonJouer);
    boutonStats = IMG_Load("./data/boutonS.png");
    boutonStatsT = SDL_CreateTextureFromSurface(renderer, boutonStats);
    boutonFacile = IMG_Load("./data/boutonF.png");
    boutonFacileT = SDL_CreateTextureFromSurface(renderer, boutonFacile);
    boutonMoyen = IMG_Load("./data/boutonMoyen.png");
    boutonMoyenT = SDL_CreateTextureFromSurface(renderer, boutonMoyen);
    boutonDifficile = IMG_Load("./data/boutonD.png");
    boutonDifficileT = SDL_CreateTextureFromSurface(renderer, boutonDifficile);
    titreDiff = IMG_Load("./data/bar_title_diff.png");
    titreDiffT = SDL_CreateTextureFromSurface(renderer, titreDiff);
    boutonClassique = IMG_Load("./data/boutonSudoC.png");
    boutonClassiqueT = SDL_CreateTextureFromSurface(renderer, boutonClassique);
    boutonX = IMG_Load("./data/boutonSudoX.png");
    boutonXT = SDL_CreateTextureFromSurface(renderer, boutonX);
    boutonCenterDot = IMG_Load("./data/boutonSudoCenterDot.png");
    boutonCenterDotT = SDL_CreateTextureFromSurface(renderer, boutonCenterDot);
    coeurs = IMG_Load("./data/3coeurs.png");
    coeursT = SDL_CreateTextureFromSurface(renderer, coeurs);
    croix = IMG_Load("./data/cross.png");
    croixT = SDL_CreateTextureFromSurface(renderer, croix);
    titreMode = IMG_Load("./data/title_bar_Mode.png");
    titreModeT = SDL_CreateTextureFromSurface(renderer, titreMode);
    resolution = IMG_Load("./data/boutonRes.png");
    resolutionT = SDL_CreateTextureFromSurface(renderer, resolution);
    boutonAccueil = IMG_Load("./data/boutonReturnAccueil.png");
    boutonAccueilT = SDL_CreateTextureFromSurface(renderer, boutonAccueil);
    Return = IMG_Load("./data/ReturnS.png");
    ReturnT = SDL_CreateTextureFromSurface(renderer, Return);
    regle = IMG_Load("./data/regle_du_jeu.png");
    regleT = SDL_CreateTextureFromSurface(renderer, regle);
    cadreStats = IMG_Load("./data/cadreStats.png");
    cadreStatsT = SDL_CreateTextureFromSurface(renderer, cadreStats);
    titreStats = IMG_Load("./data/title_bar_stats.png");
    titreStatsT = SDL_CreateTextureFromSurface(renderer, titreStats);
    iconeStats = IMG_Load("./data/statsIcone.png");
    iconeStatsT = SDL_CreateTextureFromSurface(renderer, iconeStats);
    victoire = IMG_Load("./data/victoire.png");
    victoireT = SDL_CreateTextureFromSurface(renderer, iconeStats);
    irrea = IMG_Load("./data/irrealisable.png");
    irreaT = SDL_CreateTextureFromSurface(renderer, irrea);
}

void jeuSDL::afficheGrille(Grille9x9 grille)
{
    SDL_Rect destr{150, 100, dimx - 300, dimy - 300};
    if (grille.getMode() == 0)
    {
        SDL_RenderCopy(renderer, grille_classiqueT, NULL, &destr);
    }
    else if (grille.getMode() == 1)
    {
        SDL_RenderCopy(renderer, grille_XT, NULL, &destr);
    }
    else if (grille.getMode() == 2)
    {
        SDL_RenderCopy(renderer, grille_centerDottT, NULL, &destr);
    }
    r.x = 150;
    r.y = 100;
    r.h = dimx - 300;
    r.w = dimy - 300;
    for (int j = 0; j < 3; j++)
    {

        for (int i = 0; i < 3; i++)
        {
            for (int f = 0; f < 3; f++)
            {
                for (int s = 0; s < 3; s++)
                {
                    destr.h = r.h / 9 - 10;
                    destr.w = r.w / 9 - 7;
                    destr.x = ((r.w / 9) * 3 * f + (r.w / 9) * s) + 5 + r.x;
                    destr.y = ((r.h / 9) * 3 * j + (r.h / 9) * i) + 6 + r.y;
                    int valeur = grille.getTab(j, f).getCase(i, s).getValeur();
                    switch (valeur)
                    {
                    case 0:
                        SDL_RenderCopy(renderer, nb0T, NULL, &destr);
                        break;
                    case 1:
                        SDL_RenderCopy(renderer, nb1T, NULL, &destr);
                        break;
                    case 2:
                        SDL_RenderCopy(renderer, nb2T, NULL, &destr);
                        break;
                    case 3:
                        SDL_RenderCopy(renderer, nb3T, NULL, &destr);
                        break;
                    case 4:
                        SDL_RenderCopy(renderer, nb4T, NULL, &destr);
                        break;
                    case 5:
                        SDL_RenderCopy(renderer, nb5T, NULL, &destr);
                        break;
                    case 6:
                        SDL_RenderCopy(renderer, nb6T, NULL, &destr);
                        break;
                    case 7:
                        SDL_RenderCopy(renderer, nb7T, NULL, &destr);
                        break;
                    case 8:
                        SDL_RenderCopy(renderer, nb8T, NULL, &destr);
                        break;
                    case 9:
                        SDL_RenderCopy(renderer, nb9T, NULL, &destr);
                        break;
                    default:
                        break;
                    }
                }
            }
        }
    }
    destr.x = 0;
    destr.y = 625;
    destr.h = 175;
    destr.w = dimy;
    SDL_RenderCopy(renderer, fondT, NULL, &destr);
    destr.x = 750;
    destr.y = 635;
    destr.h = 30;
    destr.w = 30;
    SDL_RenderCopy(renderer, undoT, NULL, &destr);
    destr.x = 10;
    destr.y = 635;
    destr.h = 30;
    destr.w = 30;
    SDL_RenderCopy(renderer, homeT, NULL, &destr);

    // AFFiche Nombre
    for (int i = 1; i < 10; i++)
    {
        destr.x = 70 * i + 15;
        destr.y = 700;
        destr.h = 70;
        destr.w = 50;
        std::string baseFilename = "./data/chiffre_";
        std::string valeur = std::to_string(i);
        baseFilename.append(valeur);
        baseFilename.append(".png");
        SDL_Surface *s1 = IMG_Load(baseFilename.c_str());
        SDL_Texture *t2 = SDL_CreateTextureFromSurface(renderer, s1);
        if (t2 == NULL)
        {
            std::cout << "error texture";
        }
        SDL_RenderCopy(renderer, t2, NULL, &destr);
    }
}
void jeuSDL::afficheAccueil()
{
    SDL_Rect destr{0, 0, dimx, dimy};
    SDL_RenderCopy(renderer, accueilT, NULL, &destr);
    destr.x = dimx / 2 - 100;
    destr.y = dimy / 2 + 100;
    destr.h = 70;
    destr.w = 180;
    SDL_RenderCopy(renderer, boutonRegleT, NULL, &destr);
    destr.x = dimx / 2 - 100;
    destr.y = dimy / 2;
    destr.h = 70;
    destr.w = 180;
    SDL_RenderCopy(renderer, boutonJouerT, NULL, &destr);
    destr.x = dimx / 2 - 100;
    destr.y = dimy / 2 + 200;
    destr.h = 70;
    destr.w = 180;
    SDL_RenderCopy(renderer, boutonStatsT, NULL, &destr);
}

void jeuSDL::majGrille(SDL_Rect r, int i)
{
    switch (i)
    {
    case 0:
        SDL_RenderCopy(renderer, nb0T, NULL, &r);
        break;
    case 1:
        SDL_RenderCopy(renderer, nb1T, NULL, &r);
        break;
    case 2:
        SDL_RenderCopy(renderer, nb2T, NULL, &r);
        break;
    case 3:
        SDL_RenderCopy(renderer, nb3T, NULL, &r);
        break;
    case 4:
        SDL_RenderCopy(renderer, nb4T, NULL, &r);
        break;
    case 5:
        SDL_RenderCopy(renderer, nb5T, NULL, &r);
        break;
    case 6:
        SDL_RenderCopy(renderer, nb6T, NULL, &r);
        break;
    case 7:
        SDL_RenderCopy(renderer, nb7T, NULL, &r);
        break;
    case 8:
        SDL_RenderCopy(renderer, nb8T, NULL, &r);
        break;
    case 9:
        SDL_RenderCopy(renderer, nb9T, NULL, &r);
        break;
    default:
        break;
    }
}

void jeuSDL::afficheDifficulte()
{
    SDL_Rect destr;
    destr.x = dimx / 2 - 250;
    destr.y = dimy / 2;
    destr.h = 70;
    destr.w = 500;
    SDL_RenderCopy(renderer, boutonFacileT, NULL, &destr);
    destr.x = dimx / 2 - 250;
    destr.y = dimy / 2 + 100;
    destr.h = 70;
    destr.w = 500;
    SDL_RenderCopy(renderer, boutonMoyenT, NULL, &destr);
    destr.x = dimx / 2 - 250;
    destr.y = dimy / 2 + 200;
    destr.h = 70;
    destr.w = 500;
    SDL_RenderCopy(renderer, boutonDifficileT, NULL, &destr);
    destr.x = 75;
    destr.y = 5;
    destr.h = 45;
    destr.w = 725;
    SDL_RenderCopy(renderer, titreDiffT, NULL, &destr);
}

void jeuSDL::afficheMode()
{
    SDL_Rect destr;
    destr.x = dimx / 2 - 250;
    destr.y = dimy / 2;
    destr.h = 70;
    destr.w = 500;
    SDL_RenderCopy(renderer, boutonClassiqueT, NULL, &destr);
    destr.x = dimx / 2 - 250;
    destr.y = dimy / 2 + 100;
    destr.h = 70;
    destr.w = 500;
    SDL_RenderCopy(renderer, boutonXT, NULL, &destr);
    destr.x = dimx / 2 - 250;
    destr.y = dimy / 2 + 200;
    destr.h = 70;
    destr.w = 500;
    SDL_RenderCopy(renderer, boutonCenterDotT, NULL, &destr);
    destr.x = 75;
    destr.y = 5;
    destr.h = 45;
    destr.w = 725;
    SDL_RenderCopy(renderer, titreModeT, NULL, &destr);
}

void jeuSDL::affichePerdu(SDL_Rect destr)
{
    SDL_RenderCopy(renderer, perduT, NULL, &destr);
    destr.x = dimx / 2 - 250;
    destr.y = dimy / 2;
    destr.h = 70;
    destr.w = 500;
    SDL_RenderCopy(renderer, resolutionT, NULL, &destr);
    destr.x = dimx / 2 - 250;
    destr.y = dimy / 2 + 100;
    destr.h = 70;
    destr.w = 500;
    SDL_RenderCopy(renderer, boutonAccueilT, NULL, &destr);
}

void jeuSDL::affiche_coeur()
{

    SDL_Rect destr;
    // SDL_Surface *coeurs = NULL;
    destr.x = dimx / 2 - 100;
    destr.y = 25;
    destr.h = 50;
    destr.w = 200;
    SDL_RenderCopy(renderer, coeursT, NULL, &destr);
}

void jeuSDL::barre_coeur(int i)
{
    SDL_Rect destr;
    switch (i)
    {
    case 1:
        destr.x = dimx / 2 - 104;
        destr.y = 14;
        destr.h = 64;
        destr.w = 64;
        SDL_RenderCopy(renderer, croixT, NULL, &destr);
        break;

    case 2:
        destr.x = dimx / 2 - 104;
        destr.y = 14;
        destr.h = 64;
        destr.w = 64;
        SDL_RenderCopy(renderer, croixT, NULL, &destr);
        destr.x = dimx / 2 - 32;
        destr.y = 14;
        destr.h = 64;
        destr.w = 64;
        SDL_RenderCopy(renderer, croixT, NULL, &destr);
        break;

    default:
        break;
    }
}

void jeuSDL::afficheStats()
{
    SDL_Rect destr;
    destr.x = 20;
    destr.y = 70;
    destr.h = 720;
    destr.w = 760;
    SDL_RenderCopy(renderer, cadreStatsT, NULL, &destr);
    destr.x = 75;
    destr.y = 5;
    destr.h = 45;
    destr.w = 725;
    SDL_RenderCopy(renderer, titreStatsT, NULL, &destr);
    destr.x = 20;
    destr.y = 20;
    destr.h = 15;
    destr.w = 40;
    SDL_RenderCopy(renderer, ReturnT, NULL, &destr);
}

void jeuSDL::afficheVictoire()
{
    SDL_Rect destr{0, 0, dimx, 150};
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, victoireT, NULL, &destr);
    destr.x = dimx / 2 - 250;
    destr.y = dimy / 2;
    destr.h = 70;
    destr.w = 500;
    SDL_RenderCopy(renderer, boutonAccueilT, NULL, &destr);
    destr.x = dimx / 2 - 250;
    destr.y = dimy / 2;
    destr.h = 70;
    destr.w = 500;
    SDL_RenderCopy(renderer, boutonAccueilT, NULL, &destr);
}

void jeuSDL::afficheRegle()
{
    SDL_Rect destr;
    destr.x = 0;
    destr.y = 0;
    destr.h = 800;
    destr.w = 800;
    SDL_RenderCopy(renderer, regleT, NULL, &destr);
    destr.x = 20;
    destr.y = 20;
    destr.h = 15;
    destr.w = 40;
    SDL_RenderCopy(renderer, ReturnT, NULL, &destr);
}

void jeuSDL::remplissageStats(SDL_Rect positionStats, SDL_Rect destr, TTF_Font *font, SDL_Color font_color)
{
    for (const auto &arr :grille.tableau_stats)
    {
        SDL_Surface *font_im;
        font_im = TTF_RenderText_Solid(font, std::to_string(arr.numero).c_str(), font_color);
        SDL_Texture *r4 = SDL_CreateTextureFromSurface(renderer, font_im);
        positionStats.y = positionStats.y + 50;
        SDL_RenderCopy(renderer, r4, NULL, &positionStats);

        font_im = TTF_RenderText_Solid(font, std::to_string(arr.dif).c_str(), font_color);
        r4 = SDL_CreateTextureFromSurface(renderer, font_im);
        positionStats.y = positionStats.y + 50;
        SDL_RenderCopy(renderer, r4, NULL, &positionStats);

        font_im = TTF_RenderText_Solid(font, std::to_string(arr.back).c_str(), font_color);
        r4 = SDL_CreateTextureFromSurface(renderer, font_im);
        positionStats.y = positionStats.y + 50;
        SDL_RenderCopy(renderer, r4, NULL, &positionStats);

        font_im = TTF_RenderText_Solid(font, std::to_string(arr.temps).c_str(), font_color);
        r4 = SDL_CreateTextureFromSurface(renderer, font_im);
        positionStats.y = positionStats.y + 50;
        SDL_RenderCopy(renderer, r4, NULL, &positionStats);

        font_im = TTF_RenderText_Solid(font, std::to_string(arr.mode_de_jeu).c_str(), font_color);
        r4 = SDL_CreateTextureFromSurface(renderer, font_im);
        positionStats.y = positionStats.y + 50;
        SDL_RenderCopy(renderer, r4, NULL, &positionStats);

        SDL_RenderCopy(renderer, iconeStatsT, NULL, &destr);

        SDL_RenderPresent(renderer);

        if (positionStats.x + 100 < 800 && destr.x < 800)
        {
            destr.x = destr.x + 120;
            positionStats.x = positionStats.x + 120;
            positionStats.y = 65;
        }
        else if (positionStats.y + 270 < 800 && destr.y + 270 < 800)
        {
            destr.y = destr.y + 270;
            positionStats.y = positionStats.y + 270;
            positionStats.x = 95;
            destr.x = 50;
        }
    }
}

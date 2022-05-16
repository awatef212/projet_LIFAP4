# LIFAP4 Conception et Développement d'Applications : SudokuFAN

SudokuFan est un jeu basé sur la logique.

C'est un projet dans le cadre de l'UE de LIFAP4,
realisé par :   

    Flavien Gambin   - 11911331
                                
    Awatef  Ouahidi  - 11703755                                

    Nysrine Dira     - 11920112                                


![SudokuFanImage](data/SudokuFanImage.png)  



![GitLab] (https://forge.univ-lyon1.fr/p1703755/sudokufan)  


Structure des fichiers
----------------------

- / racine
    - src/ contient toutes les sources (*.cpp) et les fichiers d'en-têtes (*.h). 
        - Coordonnees.h :  Contient les en-têtes des fonctions présentes dans le fichier Coordonnees.cpp.
        - Coordonnees.cpp : Ce module permet d’identifier les coordonnées 2D(x, y).
        - Cellule.h :  Contient les en-têtes des fonctions présentes dans le fichier Cellule.cpp.
        - Cellule.cpp : Ce module permet d’identifier une cellule avec ses Coordonnées, sa valeur, et si sa valeur est visible ou non par l’utilisateur.
        - ElementTD.h:  Contient les en-têtes des fonctions présentes dans le fichier ElementTD.cpp.
        - ElementTD.cpp : Module qui nous permet d'afficher une cellule.
        - TableauDynamique.h :  Contient les en-têtes des fonctions présentes dans le fichier TableauDynamique.cpp.
        - TableauDynamique.cpp :  Module pour permettre de manipuler les éléments.
        - Pile.h :  Contient les en-têtes des fonctions présentes dans le fichier Pile.cpp.
        - Pile.cpp : Module qui permet de revenir en arrière en cas de besoin .
        - Grille3x3.h :  Contient les en-têtes des fonctions présentes dans le fichier Grille3x3.cpp.
        - Grille3x3.cpp : Ce module permettra de représenter un tableau 3 par 3 de cellules.
        - Grille9x9.h :  Contient les en-têtes des fonctions présentes dans le fichier Grille9x9.cpp.
        - Grille9x9.cpp : Ce module permettra de représenter un tableau 3 par 3 de Grille3x3. Ce qui créera une Grille9x9. Il testera si les valeurs respectent bien les contraintes des règles du Sudoku choisies, il n'affichera qu’un certain nombre de valeurs, en fonction de la difficulté choisie. Enfin il permettra de tester tout au long du jeu si la Grille9x9 est bien rempli par l’utilisateur. 
        - Jeu.h :  Contient les en-têtes des fonctions présentes dans le fichier Jeu.cpp.
        - Jeu.cpp : Ce module permettra de jouer : ajouter une valeur à la grille9x9, vérifier que la valeur saisie respecte les règles du Sudoku avec cette Grille9x9. Vérifier également si la partie est finie ou non.
        - jeuTxt.h :  Contient les en-têtes des fonctions présentes dans le fichier JeuTxt.cpp.
        - jeuTxt.cpp : Module pour jouer en mode texte, saisi de la difficulté, affichage de la grille9x9, boucle de gestion des événements, fonction d’affichage pour la fin de partie. 
        - jeuSDL.h :  Contient les en-têtes des fonctions présentes dans le fichier JeuSDL.cpp.
        - jeuSDL.cpp : Module pour jouer en mode graphique SDL, saisie de la difficulté, affichage de la grille9x9, boucle de gestion des événements, fonction d’affichage pour la fin de partie.
        - MenuTxt.h :  Contient les en-têtes des fonctions présentes dans le fichier MenuTxt.cpp.
        - MenuTxt.cpp : Menu de l'application en mode texte. Permet de choisir ce que l’on veut faire en arrivant dans l’application : jouer, voir les statistiques, voir les règles du jeu, quitter.
        - MenuSDL.h :  Contient les en-têtes des fonctions présentes dans le fichier MenuSDL.cpp.
        - MenuSDL.cpp :  Menu de l'application en mode graphique SDL. Permet de choisir ce que l’on veut faire en arrivant dans l’application : jouer, voir les statistiques, voir les règles du jeu, quitter.
        - mainSDL.cpp : lance l'application en mode graphique
        - mainTxt.cpp : lance l'application en mode texte

    - obj /  répertoire comportant les compilations intermédiaires (*.o)
    - bin / répertoire où les exécutables seront compilés 
    - data / répertoire contenant les assets (image, sons, etc.)
    - doc /  répertoire contenant la vidéo de présentation intermediaire, le Powerpoint, le diagramme des classes, diagramme de Gantt et la documentation. 
    - Makefile / fichier spécifiant comment construire les fichiers cibles.
    - README.md / ce readme.
    

    Commandes importantes
    ---------------------
~~~
make 
~~~
Make permet d’automatiser la compilation de tous les fichiers en deux exécutables (mode texte et mode graphique)

~~~
bin/exe_txt
~~~
lance l'application en mode texte

~~~
bin/exe_sdl
~~~
lance l'application en mode graphique

~~~
make clean 
~~~
Make clean permet d'effacer les fichiers objets et les exécutables 

~~~
make bin/exe_regression
~~~
Make bin/exe_regression permet de lancer les tests de régression de toutes les classes de notre projet

~~~
Valgrind bin/exe_txt 
Valgrind bin/exe_sdl
Valgrind bin/exe_regressions
~~~
Commandes qui permettent de vérifier la bonne utilisation de la mémoire 

~~~
make documentation
~~~
génére la documentation du code de l'application





    Règles du Jeu 
    ---------------------
La plateforme SUDOKUFAN contient 3 jeux du sudoku : 

        - Sudoku
        - SudokuX
        - SudokuCenterDot 
        
et chacun comprends trois niveaux de difficultés : 

        - Facile 
        - Moyen 
        - Difficile


Dans un premier temps les joueurs saisissent un jeu et un niveau de 
difficulté. 
Suite à cela, une grille plus ou moins remplie apparaît. 

Sudoku 
------------------------------ 
La grille de jeu est un carré de neuf cases de côté, subdivisées en carrés identiques de 3 cases de côtés. 

                            0 | 0 | 0     0 | 0 | 0    0 | 0 | 0 
                            0 | 0 | 0     0 | 0 | 0    0 | 0 | 0 
                            0 | 0 | 0     0 | 0 | 0    0 | 0 | 0 

                            0 | 0 | 0     0 | 0 | 0    0 | 0 | 0 
                            0 | 0 | 0     0 | 0 | 0    0 | 0 | 0 
                            0 | 0 | 0     0 | 0 | 0    0 | 0 | 0 

                            0 | 0 | 0     0 | 0 | 0    0 | 0 | 0 
                            0 | 0 | 0     0 | 0 | 0    0 | 0 | 0 
                            0 | 0 | 0     0 | 0 | 0    0 | 0 | 0 

Le principe du jeu est le suivant : 
Dans le cadre d'une ligne, une colonne ou une Grille3x3, chaque chiffre doit être présent exactement une fois.

                            1 | 0 | 0    0 | 7 | 0    0 | 0 | 3 
                            0 | 5 | 0    0 | 8 | 0    0 | 0 | 0 
                            9 | 0 | 0    0 | 0 | 9    5 | 0 | 0

                            0 | 0 | 3    0 | 6 | 0    0 | 5 | 0
                            0 | 0 | 0    0 | 1 | 0    0 | 6 | 0
                            0 | 0 | 0    8 | 0 | 5    9 | 0 | 0

                            0 | 0 | 5    0 | 0 | 8    0 | 0 | 0 
                            0 | 3 | 0    0 | 9 | 0    0 | 1 | 8
                            6 | 8 | 0    0 | 0 | 0    3 | 0 | 5

Au début de la partie, l’utilisateur dispose de 3 vies.

Lorsque le joueur entre un chiffre qui est déjà apparent sur la même ligne, la même colonne et/ou la même Grille3x3, l’utilisateur perd une vie.

La partie se termine lorsque le joueur n’a plus de vie ou lorsqu’il remplit entièrement la grille.


SudokuX
-------------------------------
Le principe du SudokuX est le même que celui du Sudoku. Cette variante ajoute une contrainte : 
Tous les chiffres présent sur les diagonales principales doivent être differents. 

                            _ | 0 | 0    0 | 0 | 0    0 | 0 | _ 
                            0 | _ | 0    0 | 0 | 0    0 | _ | 0
                            0 | 0 | _    0 | 0 | 0    _ | 0 | 0 

                            0 | 0 | 0    _ | 0 | _    0 | 0 | 0 
                            0 | 0 | 0    0 | _ | 0    0 | 0 | 0
                            0 | 0 | 0    _ | 0 | _    0 | 0 | 0 

                            0 | 0 | _   0 | 0 | 0    _ | 0 | 0 
                            0 | _ | 0   0 | 0 | 0    0 | _ | 0
                            _ | 0 | 0   0 | 0 | 0    0 | 0 | _ 



SudokuCenterDot
-------------------------------

Le principe du SudokuCenterDot est le même que celui du Sudoku. Cette variante ajoute une contrainte : 
Tous les chiffres présent au centre d'une Grille3x3 doit être différents des autres. 

                            0 | 0 | 0    0 | 0 | 0    0 | 0 | 0 
                            0 | _ | 0    0 | _ | 0    0 | _ | 0 
                            0 | 0 | 0    0 | 0 | 0    0 | 0 | 0 

                            0 | 0 | 0    0 | 0 | 0    0 | 0 | 0
                            0 | _ | 0    0 | _ | 0    0 | _ | 0
                            0 | 0 | 0    0 | 0 | 0    0 | 0 | 0 

                            0 | 0 | 0    0 | 0 | 0    0 | 0 | 0 
                            0 | _ | 0    0 | _ | 0    0 | _ | 0
                            0 | 0 | 0    0 | 0 | 0    0 | 0  | 0 







 Statistiques
---------------------
    
Dans le menu principal, l'utilisateur peut analyser ses statistiques. 
Elles sont répertoriées en fonction du numéro de la partie et sont composé du niveau de difficulté choisie, de nombre de retour arriere, du temps de la partie, et enfin du mode de jeu choisit. 
Ainsi, le joueur pourra comparer ses parties et analysé ses progression et ses regressions. 
Dans la version graphique des icones representent les données de l'utilisateurs. 


![NumPartie](data/NumPartie.png)  Numéro de la partie  

![Difficulté](data/Difficulté.png)   Difficulté choisie par l'utilisateur 

![NbRetourArriere](data/NbRetourArriere.png)  Nombre de retour arrière durant la partie 

![Temps](data/Temps.png)  Temps de la partie 

![modeDeJeu](data/modeDeJeu.png)   Mode de jeu choisi par l'utilisateur  






    

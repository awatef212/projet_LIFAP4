# Compiler settings - Can be customized.
GCC = g++
CFLAGS = -Wall -g -o 
CFLAGS_OBJ = -Wall -g -c 
RM = rm -rf
LIB = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer

# Makefile settings - Can be customized.
SRC_DIR = src
TARGET_EXEC = bin
OBJ_DIR = obj
DOC_DIR = doc

########################################################################
####################### Targets beginning here #########################
########################################################################

all: $(TARGET_EXEC)/exe_txt $(TARGET_EXEC)/exe_sdl 

$(TARGET_EXEC)/exe_txt:  $(OBJ_DIR)/mainTxt.o $(OBJ_DIR)/MenuTxt.o $(OBJ_DIR)/jeuTxt.o $(OBJ_DIR)/Jeu.o $(OBJ_DIR)/Grille9x9.o $(OBJ_DIR)/Pile.o $(OBJ_DIR)/TableauDynamique.o $(OBJ_DIR)/ElementTD.o $(OBJ_DIR)/Grille3x3.o $(OBJ_DIR)/Cellule.o $(OBJ_DIR)/Coordonnees.o
	$(GCC) $(CFLAGS) $(TARGET_EXEC)/exe_txt $(OBJ_DIR)/mainTxt.o $(OBJ_DIR)/MenuTxt.o $(OBJ_DIR)/jeuTxt.o $(OBJ_DIR)/Jeu.o $(OBJ_DIR)/Grille9x9.o $(OBJ_DIR)/Pile.o $(OBJ_DIR)/TableauDynamique.o $(OBJ_DIR)/ElementTD.o $(OBJ_DIR)/Grille3x3.o $(OBJ_DIR)/Cellule.o $(OBJ_DIR)/Coordonnees.o

$(TARGET_EXEC)/exe_sdl: $(OBJ_DIR)/mainSDL.o $(OBJ_DIR)/MenuSDL.o $(OBJ_DIR)/jeuSDL.o $(OBJ_DIR)/Jeu.o $(OBJ_DIR)/Grille9x9.o $(OBJ_DIR)/Pile.o $(OBJ_DIR)/TableauDynamique.o $(OBJ_DIR)/ElementTD.o $(OBJ_DIR)/Grille3x3.o $(OBJ_DIR)/Cellule.o $(OBJ_DIR)/Coordonnees.o
	$(GCC) $(CFLAGS) $(TARGET_EXEC)/exe_sdl $(OBJ_DIR)/mainSDL.o $(OBJ_DIR)/MenuSDL.o $(OBJ_DIR)/jeuSDL.o $(OBJ_DIR)/Jeu.o $(OBJ_DIR)/Grille9x9.o $(OBJ_DIR)/Pile.o $(OBJ_DIR)/TableauDynamique.o $(OBJ_DIR)/ElementTD.o $(OBJ_DIR)/Grille3x3.o $(OBJ_DIR)/Cellule.o $(OBJ_DIR)/Coordonnees.o $(LIB)

$(TARGET_EXEC)/exe_regression: $(OBJ_DIR)/mainRegression.o $(OBJ_DIR)/MenuSDL.o $(OBJ_DIR)/jeuSDL.o $(OBJ_DIR)/MenuTxt.o $(OBJ_DIR)/jeuTxt.o $(OBJ_DIR)/Jeu.o $(OBJ_DIR)/Grille9x9.o $(OBJ_DIR)/Pile.o $(OBJ_DIR)/TableauDynamique.o $(OBJ_DIR)/ElementTD.o $(OBJ_DIR)/Grille3x3.o $(OBJ_DIR)/Cellule.o $(OBJ_DIR)/Coordonnees.o
	$(GCC) $(CFLAGS) $(TARGET_EXEC)/exe_regression $(OBJ_DIR)/mainRegression.o $(OBJ_DIR)/MenuSDL.o $(OBJ_DIR)/jeuSDL.o $(OBJ_DIR)/MenuTxt.o $(OBJ_DIR)/jeuTxt.o $(OBJ_DIR)/Jeu.o $(OBJ_DIR)/Grille9x9.o $(OBJ_DIR)/Pile.o $(OBJ_DIR)/TableauDynamique.o $(OBJ_DIR)/ElementTD.o $(OBJ_DIR)/Grille3x3.o $(OBJ_DIR)/Cellule.o $(OBJ_DIR)/Coordonnees.o $(LIB)

# Building rule for .o files and its .cpp in combination with all .h
$(OBJ_DIR)/mainRegression.o: $(SRC_DIR)/mainRegression.cpp $(SRC_DIR)/MenuSDL.h $(SRC_DIR)/jeuSDL.h $(SRC_DIR)/MenuTxt.h $(SRC_DIR)/jeuTxt.h $(SRC_DIR)/Jeu.h $(SRC_DIR)/Grille9x9.h $(SRC_DIR)/Pile.h $(SRC_DIR)/TableauDynamique.h $(SRC_DIR)/ElementTD.h $(SRC_DIR)/Grille3x3.h $(SRC_DIR)/Cellule.h $(SRC_DIR)/Coordonnees.h
	$(GCC) $(CFLAGS_OBJ) $(SRC_DIR)/mainRegression.cpp -o $(OBJ_DIR)/mainRegression.o

$(OBJ_DIR)/mainTxt.o: $(SRC_DIR)/mainTxt.cpp $(SRC_DIR)/MenuTxt.h $(SRC_DIR)/jeuTxt.h $(SRC_DIR)/Jeu.h $(SRC_DIR)/Grille9x9.h $(SRC_DIR)/Pile.h $(SRC_DIR)/TableauDynamique.h $(SRC_DIR)/ElementTD.h $(SRC_DIR)/Grille3x3.h $(SRC_DIR)/Cellule.h $(SRC_DIR)/Coordonnees.h
	$(GCC) $(CFLAGS_OBJ) $(SRC_DIR)/mainTxt.cpp -o $(OBJ_DIR)/mainTxt.o

$(OBJ_DIR)/MenuTxt.o: $(SRC_DIR)/MenuTxt.cpp $(SRC_DIR)/MenuTxt.h $(SRC_DIR)/jeuTxt.h $(SRC_DIR)/Jeu.h $(SRC_DIR)/Grille9x9.h $(SRC_DIR)/Pile.h $(SRC_DIR)/TableauDynamique.h $(SRC_DIR)/ElementTD.h $(SRC_DIR)/Grille3x3.h $(SRC_DIR)/Cellule.h $(SRC_DIR)/Coordonnees.h
	$(GCC) $(CFLAGS_OBJ) $(SRC_DIR)/MenuTxt.cpp -o $(OBJ_DIR)/MenuTxt.o

$(OBJ_DIR)/jeuTxt.o: $(SRC_DIR)/jeuTxt.cpp $(SRC_DIR)/jeuTxt.h $(SRC_DIR)/Jeu.h $(SRC_DIR)/Grille9x9.h $(SRC_DIR)/Pile.h $(SRC_DIR)/TableauDynamique.h $(SRC_DIR)/ElementTD.h $(SRC_DIR)/Grille3x3.h $(SRC_DIR)/Cellule.h $(SRC_DIR)/Coordonnees.h
	$(GCC) $(CFLAGS_OBJ) $(SRC_DIR)/jeuTxt.cpp -o $(OBJ_DIR)/jeuTxt.o

$(OBJ_DIR)/mainSDL.o: $(SRC_DIR)/mainSDL.cpp $(SRC_DIR)/MenuSDL.h $(SRC_DIR)/jeuSDL.h $(SRC_DIR)/Jeu.h $(SRC_DIR)/Grille9x9.h $(SRC_DIR)/Pile.h $(SRC_DIR)/TableauDynamique.h $(SRC_DIR)/ElementTD.h $(SRC_DIR)/Grille3x3.h $(SRC_DIR)/Cellule.h $(SRC_DIR)/Coordonnees.h
	$(GCC) $(CFLAGS_OBJ) $(SRC_DIR)/mainSDL.cpp -o $(OBJ_DIR)/mainSDL.o -I/usr/include/SDL2

$(OBJ_DIR)/MenuSDL.o: $(SRC_DIR)/MenuSDL.cpp $(SRC_DIR)/MenuSDL.h $(SRC_DIR)/jeuSDL.h $(SRC_DIR)/Jeu.h $(SRC_DIR)/Grille9x9.h $(SRC_DIR)/Pile.h $(SRC_DIR)/TableauDynamique.h $(SRC_DIR)/ElementTD.h $(SRC_DIR)/Grille3x3.h $(SRC_DIR)/Cellule.h $(SRC_DIR)/Coordonnees.h
	$(GCC) $(CFLAGS_OBJ) $(SRC_DIR)/MenuSDL.cpp -o $(OBJ_DIR)/MenuSDL.o -I/usr/include/SDL2

$(OBJ_DIR)/jeuSDL.o: $(SRC_DIR)/jeuSDL.cpp $(SRC_DIR)/jeuSDL.h $(SRC_DIR)/Jeu.h $(SRC_DIR)/Grille9x9.h $(SRC_DIR)/Pile.h $(SRC_DIR)/TableauDynamique.h $(SRC_DIR)/ElementTD.h $(SRC_DIR)/Grille3x3.h $(SRC_DIR)/Cellule.h $(SRC_DIR)/Coordonnees.h
	$(GCC) $(CFLAGS_OBJ) $(SRC_DIR)/jeuSDL.cpp -o $(OBJ_DIR)/jeuSDL.o -I/usr/include/SDL2

$(OBJ_DIR)/Jeu.o: $(SRC_DIR)/Jeu.cpp $(SRC_DIR)/Jeu.h $(SRC_DIR)/Grille9x9.h $(SRC_DIR)/Pile.h $(SRC_DIR)/TableauDynamique.h $(SRC_DIR)/ElementTD.h $(SRC_DIR)/Grille3x3.h $(SRC_DIR)/Cellule.h $(SRC_DIR)/Coordonnees.h
	$(GCC) $(CFLAGS_OBJ) $(SRC_DIR)/Jeu.cpp -o $(OBJ_DIR)/Jeu.o

$(OBJ_DIR)/Grille9x9.o: $(SRC_DIR)/Grille9x9.cpp $(SRC_DIR)/Grille9x9.h $(SRC_DIR)/Grille3x3.h $(SRC_DIR)/Cellule.h $(SRC_DIR)/Coordonnees.h
	$(GCC) $(CFLAGS_OBJ) $(SRC_DIR)/Grille9x9.cpp -o $(OBJ_DIR)/Grille9x9.o

$(OBJ_DIR)/Grille3x3.o: $(SRC_DIR)/Grille3x3.cpp $(SRC_DIR)/Grille3x3.h $(SRC_DIR)/Cellule.h $(SRC_DIR)/Coordonnees.h
	$(GCC) $(CFLAGS_OBJ) $(SRC_DIR)/Grille3x3.cpp -o $(OBJ_DIR)/Grille3x3.o

$(OBJ_DIR)/Cellule.o: $(SRC_DIR)/Cellule.cpp $(SRC_DIR)/Cellule.h $(SRC_DIR)/Coordonnees.h
	$(GCC) $(CFLAGS_OBJ) $(SRC_DIR)/Cellule.cpp -o $(OBJ_DIR)/Cellule.o

$(OBJ_DIR)/Coordonnees.o: $(SRC_DIR)/Coordonnees.cpp $(SRC_DIR)/Coordonnees.h 
	$(GCC) $(CFLAGS_OBJ) $(SRC_DIR)/Coordonnees.cpp -o $(OBJ_DIR)/Coordonnees.o

$(OBJ_DIR)/Pile.o: $(SRC_DIR)/Pile.cpp $(SRC_DIR)/Pile.h $(SRC_DIR)/TableauDynamique.h $(SRC_DIR)/ElementTD.h $(SRC_DIR)/Cellule.h $(SRC_DIR)/Coordonnees.h
	$(GCC) $(CFLAGS_OBJ) $(SRC_DIR)/Pile.cpp -o $(OBJ_DIR)/Pile.o

$(OBJ_DIR)/TableauDynamique.o: $(SRC_DIR)/TableauDynamique.cpp $(SRC_DIR)/TableauDynamique.h $(SRC_DIR)/ElementTD.h $(SRC_DIR)/Cellule.h $(SRC_DIR)/Coordonnees.h
	$(GCC) $(CFLAGS_OBJ) $(SRC_DIR)/TableauDynamique.cpp -o $(OBJ_DIR)/TableauDynamique.o

$(OBJ_DIR)/ElementTD.o: $(SRC_DIR)/ElementTD.cpp $(SRC_DIR)/ElementTD.h $(SRC_DIR)/Cellule.h $(SRC_DIR)/Coordonnees.h
	$(GCC) $(CFLAGS_OBJ) $(SRC_DIR)/ElementTD.cpp -o $(OBJ_DIR)/ElementTD.o

documentation: $(SRC_DIR)/*
	doxygen $(DOC_DIR)/image.doxy 

clean:
	$(RM) $(TARGET_EXEC)/* $(OBJ_DIR)/*.o $(DOC_DIR)/html

	
	
	
	
	
	

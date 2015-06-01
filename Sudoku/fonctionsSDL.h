#ifndef SDL_H_INCLUDED
#define SDL_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "main.h"
void initialisationSDL(void);
void impressionEcran(SDL_Surface *ecran, int grilleSudoku[9][9][10]);
SDL_Surface* creationEcran(int hauteur, int largeur);
SDL_Surface* chargementBitmap(char *nomImage);
void afficherSolution(int grille[9][9][10], SDL_Surface *ecran);
void afficherGrilleVierge(SDL_Surface *ecran);
void afficherGrilleVierge2(SDL_Surface *ecran);

#endif // SDL_H_INCLUDED

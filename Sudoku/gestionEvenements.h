#ifndef GESTIONEVENEMENTS_H_INCLUDED
#define GESTIONEVENEMENTS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include "main.h"
#include "fonctionsSDL.h"
#include "..\Sudoku_Console\fonctionsDeBase.h"
#include "..\Sudoku_Console\resolveur.h"
void attenteEcranPrincipal(SDL_Surface *ecran, bool *finDuProgramme);
void attenteEcranChoix(SDL_Surface *ecran, bool *finDuProgramme);
void attenteEcranJouer(SDL_Surface *ecran, SDL_Surface *grille, int grilleSudoku[9][9][10], bool *finDuProgramme);
void attenteEcranResolveur(SDL_Surface *ecran, SDL_Surface *grille, bool *finDuProgramme);
void saisirChiffre(SDL_Surface *ecran, int positionX, int positionY, bool *finDuProgramme, int *caseChiffre);

#endif // GESTIONEVENEMENTS_H_INCLUDED

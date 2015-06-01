#ifndef ECRANS_H_INCLUDED
#define ECRANS_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#include "fonctionsSDL.h"
#include "gestionEvenements.h"
#include "..\Sudoku_Console\generateur.h"
void ecranPrincipal(SDL_Surface *ecran, bool *finDuProgramme);
void ecranJouer(SDL_Surface *ecran, bool *finDuProgramme, int niveau);
void ecranResolveur(SDL_Surface *ecran, bool *finDuProgramme);
void ecranChoixDifficulte(SDL_Surface *ecran, bool *finDuProgramme);
void ecranPerdu(SDL_Surface *ecran, bool *finDuProgramme);

#endif // ECRANS_H_INCLUDED

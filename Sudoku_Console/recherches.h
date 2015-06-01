#ifndef RECHERCHES_H_INCLUDED
#define RECHERCHES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "suppression.h"
int nombreCasesRestantes(int grille[9][9][10]);
void recherchePossibilitesGrille(int *compteurDeCases, int grille[9][9][10], int *niveau);
void recherchePossibilitesCase(int ligneCase, int colonneCase, int grille[9][9][10]);
void detectionBloc(int *ligneCase, int *colonneCase);

#endif // RECHERCHES_H_INCLUDED

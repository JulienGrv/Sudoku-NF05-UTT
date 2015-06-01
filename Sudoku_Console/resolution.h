#ifndef PROCEDURES_H_INCLUDED
#define PROCEDURES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tests.h"
void resolutionGrille(int *compteurDeCases, int grille[9][9][10], int *niveau, bool *stop);
void testerCase(int ligneCase, int colonneCase, int grille[9][9][10], int *compteurDeCases, int *niveau, bool *stop);

#endif // PROCEDURES_H_INCLUDED

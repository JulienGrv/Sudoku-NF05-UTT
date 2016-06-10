#ifndef RESOLVEUR_H_INCLUDED
#define RESOLVEUR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "recherches.h"
#include "resolution.h"
void resolveur(int  grille[9][9][10],
               int *niveau);
void importationGrille(FILE *fichier,
                       int   grille[9][9][10]);
void affichageGrille(int grille[9][9][10]);

#endif // RESOLVEUR_H_INCLUDED

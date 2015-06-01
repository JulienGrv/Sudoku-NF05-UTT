#ifndef GENERATEUR_H_INCLUDED
#define GENERATEUR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "backtracking.h"
#include "resolveur.h"
#include "fonctionsDeBase.h"
void generateur(int grille[9][9][10], int *niveau);
void vidage(int grille[9][9][10], int *niveauRequis);
void affichageGrille2(int grille[9][9]);
void exportationGrille(FILE* fichier, int grille[9][9][10]);

#endif // GENERATEUR_H_INCLUDED

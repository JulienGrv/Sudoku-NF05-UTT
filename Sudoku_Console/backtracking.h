#ifndef BACKTRACKING_H_INCLUDED
#define BACKTRACKING_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool absentSurLigne(int k,
                    int grille[9][9][10],
                    int i);
bool absentSurColonne(int k,
                      int grille[9][9][10],
                      int j);
bool absentSurBloc(int k,
                   int grille[9][9][10],
                   int i,
                   int j);
bool backtracking(int grille[9][9][10],
                  int position);

// Aléatoire
int* initSansDoublons(int a,
                      int b);
int  chiffreAleatoire(int borneInf,
                      int borneSup);
void melangeur(int *tableau,
               int  taille);

#endif // BACKTRACKING_H_INCLUDED

#ifndef TESTS_H_INCLUDED
#define TESTS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "suppression.h"
#include "backtracking.h"
#include "fonctionsDeBase.h"
// Niveau très facile (1)
void positionUnique(int ligneCase, int colonneCase, int grille[9][9][10], int *compteurDeCases, bool *stop); // singlePosition
// Niveau facile (2)
void possibiliteUnique(int ligneCase, int colonneCase, int grille[9][9][10], int *compteurDeCases, bool *stop); // singleCandidate
// Niveau moyen (3)
void possibiliteAlignee(int ligneCase, int colonneCase, int grille[9][9][10], bool *stop); // candidateLine
void plusieursAlignees(int ligneCase, int colonneCase, int grille[9][9][10], bool *stop); // multipleLines
// Niveau difficile (4)
void nakedTuple(int ligneCase, int colonneCase, int grille[9][9][10], bool *stop); // nakedTuple
void hiddenTuple(int ligneCase, int colonneCase, int grille[9][9][10], bool *stop); // hiddenTuple
// Niveau très difficile (5)
    // X-Wing
    // Swordfish
// Expert (6)
void forcingChains(int grille[9][9][10], int *compteurDeCases); // Forcing chains
// Autres
bool presencePossibilite(int possibilitesCase[10], int possibilite);
int compteurPossibilites(int possibilitesCase[10]);

#endif // TESTS_H_INCLUDED

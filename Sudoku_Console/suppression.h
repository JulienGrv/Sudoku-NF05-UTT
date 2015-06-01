#ifndef SUPPRESSION_H_INCLUDED
#define SUPPRESSION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "recherches.h"
#include "resolution.h"
// Procédure de suppression de possibiliteUnique et positionUnique
void supprimerPossibiliteZones(int ligneCase, int colonneCase, int possibilite, int grille[9][9][10]);
// Procédures de suppression de possibilitesAlignees
void supprimerPossibiliteLigneBloc(int ligneCase, int colonneBloc, int possibilite, int grille[9][9][10], bool *stop);
void supprimerPossibiliteColonneBloc(int colonneCase, int ligneBloc, int possibilite, int grille[9][9][10], bool *stop);
// Procédures de suppression de nakedTuple
void supprimerLigneNakedTuple(int ligneCase, int colonneCase, int grille[9][9][10], bool *stop);
void supprimerColonneNakedTuple(int ligneCase, int colonneCase, int grille[9][9][10], bool *stop);
void supprimerBlocNakedTuple(int ligneCase, int colonneCase, int grille[9][9][10], bool *stop);
// hiddentuple
void supprimerLigneHiddenTuple(int ligneCase, int colonneCase, int *listePossibilites, int indice, int grille[9][9][10], bool *stop);
void supprimerColonneHiddenTuple(int ligneCase, int colonneCase, int *listePossibilites, int indice, int grille[9][9][10], bool *stop);
// Autres
void reinitialisationProfondeur(int profondeurCase[10]);
bool supprimerPossibilite(int possibilitesCase[10], int possibilite);

#endif // SUPPRESSION_H_INCLUDED

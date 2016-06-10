#ifndef FONCTIONSDEBASE_H_INCLUDED
#define FONCTIONSDEBASE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_MAX 1000
void  saisieChaine(char chaine[TAILLE_MAX]);
void  nettoyeur(char *chaine);
void  vidageMemoireTampon(void);
FILE* lectureFichier(char nomDuFichier[TAILLE_MAX]);
FILE* ecritureFichier(char nomDuFichier[TAILLE_MAX]);
void  copierTableau(int tableauOrigine[9][9][10],
                    int tableauNouveau[9][9][10]);

#endif // FONCTIONSDEBASE_H_INCLUDED

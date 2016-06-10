#include "resolveur.h"

/// Proc�dure de r�solution d'une grille de Sudoku
void resolveur(int grille[9][9][10], int *niveau)
{
  // On compte le nombre de cases � r�soudre
  int  compteurDeCases = nombreCasesRestantes(grille);
  bool stop            = false;

  // Recherche les possibilit�s des cases � r�soudre de la grille
  recherchePossibilitesGrille(&compteurDeCases, grille, niveau);

  /* Une fois un premier tour complet de la grille effectu�e, toutes les
     possibilit�s de chaque case ont �t� d�termin�es.
     On passe donc � la r�solution de la grille jusqu'� ce que le compteur de
        cases restantes soit � z�ro.
     Si l'on s'aper�oit que la variable bool�enne stop ne varie plus alors cela
        signifie que les traitements li� au niveau en cours ne suffise pas, il
        faut donc passer au niveau suivant. */
  while ((compteurDeCases > 0) && (*niveau != 6))
  {
    // On initialise la variable stop comme "fausse"
    stop = false;

    // On lance la r�solution de la grille
    resolutionGrille(&compteurDeCases, grille, niveau, &stop);

    // Si la variable stop est toujours fausse en sortant de l'algorithme de
    // r�solution alors cela signifie qu'aucune des traitements effectu�s n'a
    // modifi� la grille, on passe donc au niveau suivant
    if (stop == false)
    {
      (*niveau)++;
    }
  }

  if (compteurDeCases > 0)
  {
    // Si le compteurs de cases n'est pas nul alors la grille n'est pas
    // r�soluble avec l'algorithme employ�
    printf("\nGrille non-r\202soluble !\n");
    affichageGrille(grille); // temporaire
    exit(EXIT_FAILURE);
  }
}

/// Proc�dure d'importation de la grille par lecture du fichier
void importationGrille(FILE *fichier, int grille[9][9][10])
{
  int ligne = 0, colonne = 0;

  for (ligne = 0; ligne < 9; ligne++)
  {
    for (colonne = 0; colonne < 9; colonne++)
    {
      fscanf(fichier, "%d,", &grille[ligne][colonne][0]);
    }
  }
}

/// Proc�dure d'affichage de la grille de Sudoku
void affichageGrille(int grille[9][9][10])
{
  int ligne = 0, colonne = 0;

  printf("-------------------\n");

  for (ligne = 0; ligne < 9; ligne++)
  {
    for (colonne = 0; colonne < 9; colonne++)
    {
      if (colonne == 0)
      {
        printf("|%d ", grille[ligne][colonne][0]);
      }
      else if (((colonne + 1) % 3))
      {
        printf("%d ", grille[ligne][colonne][0]);
      }
      else
      {
        printf("%d|", grille[ligne][colonne][0]);
      }
    }
    putchar('\n');

    if (!((ligne + 1) % 3))
    {
      printf("-------------------\n");
    }
  }
}

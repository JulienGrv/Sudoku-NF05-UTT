#include "resolution.h"

/// Proc�dure qui permet de parcourir toute la grille en qu�te des solutions de
// toutes les cases
void resolutionGrille(int  *compteurDeCases,
                      int   grille[9][9][10],
                      int  *niveau,
                      bool *stop)
{
  int ligne = 0, colonne = 0;

  // On parcourt toute la grille pour rechercher les solutions des cases
  for (ligne = 0; ligne < 9; ligne++)
  {
    for (colonne = 0; colonne < 9; colonne++)
    {
      if (grille[ligne][colonne][0] == 0)
      {
        // On effectue des tests concernant la case o� l'on se trouve
        testerCase(ligne, colonne, grille, compteurDeCases, niveau, stop);
      }
    }
  }
}

/// On effectue des tests sur la case en fonction du niveau de difficult� de la
// grille
void testerCase(int   ligneCase,
                int   colonneCase,
                int   grille[9][9][10],
                int  *compteurDeCases,
                int  *niveau,
                bool *stop)
{
  if (*niveau == 1) // Tr�s facile
  {
    positionUnique(ligneCase, colonneCase, grille, compteurDeCases, stop);
  }
  else if (*niveau == 2) // Facile
  {
    possibiliteUnique(ligneCase, colonneCase, grille, compteurDeCases, stop);
    positionUnique(ligneCase, colonneCase, grille, compteurDeCases, stop);
  }
  else if (*niveau == 3) // Moyen
  {
    possibiliteAlignee(ligneCase, colonneCase, grille, stop);
    positionUnique(ligneCase, colonneCase, grille, compteurDeCases, stop);
    possibiliteUnique(ligneCase, colonneCase, grille, compteurDeCases, stop);
  }
  else if (*niveau == 4) // Difficile
  {
    hiddenTuple(ligneCase, colonneCase, grille, stop);
    nakedTuple(ligneCase, colonneCase, grille, stop);
    possibiliteAlignee(ligneCase, colonneCase, grille, stop);
    positionUnique(ligneCase, colonneCase, grille, compteurDeCases, stop);
    possibiliteUnique(ligneCase, colonneCase, grille, compteurDeCases, stop);
  }
  else if (*niveau == 5)
  {
    forcingChains(grille, compteurDeCases);
    *stop = true;
  }
}

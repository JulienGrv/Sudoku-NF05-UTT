#include "recherches.h"

/// Fonction qui retourne le nombre de cases � r�soudre
int nombreCasesRestantes(int grille[9][9][10])
{
  int ligne = 0, colonne = 0, compteurDeCases = 0;

  // On parcourt toute la grille pour rechercher le nombre de cases � r�soudre
  for (ligne = 0; ligne < 9; ligne++)
  {
    for (colonne = 0; colonne < 9; colonne++)
    {
      if (grille[ligne][colonne][0] == 0)
      {
        compteurDeCases++;
      }
    }
  }
  return compteurDeCases;
}

/// Proc�dure qui permet de rechercher toutes les possibilit�s de toutes les
// cases de la grille de Sudoku
void recherchePossibilitesGrille(int *compteurDeCases,
                                 int  grille[9][9][10],
                                 int *niveau)
{
  int ligne = 0, colonne = 0;

  // On parcourt toute la grille pour rechercher les possibilit�s des cases
  for (ligne = 0; ligne < 9; ligne++)
  {
    for (colonne = 0; colonne < 9; colonne++)
    {
      if (grille[ligne][colonne][0] == 0)
      {
        // Si une case est � r�soudre et n'a pas d�j� des possibilit�s alors on
        // recherche ses possibilit�s
        recherchePossibilitesCase(ligne, colonne, grille);
      }
    }
  }
}

/// Proc�dure de recherche des possibilit�s d'une case � r�soudre
void recherchePossibilitesCase(int ligneCase,
                               int colonneCase,
                               int grille[9][9][10])
{
  int possibilite = 1, curseur = 0, ligne = 0, colonne = 0, profondeur = 1;

  // On r�initialise � z�ro toutes les possibilit�s de la case � r�soudre avant
  // de rechercher � nouveau ses possibilit�s
  reinitialisationProfondeur(grille[ligneCase][colonneCase]);

  // On recherche pour toutes les valeurs de 1 � 9 celles qui sont des
  // possibilit�s pour la case � r�soudre
  for (possibilite = 1; possibilite < 10; possibilite++)
  {
    curseur = 0;

    // On regarde si la possibilit� n'est ni pr�sente sur la ligne ni sur la
    // colonne de la case � r�soudre
    while ((grille[ligneCase][curseur][0] != possibilite) &&
           (grille[curseur][colonneCase][0] != possibilite) && (curseur < 9))
    {
      curseur++;
    }

    // Si la possibilit� n'est ni pr�sente sur la ligne ni sur la colonne de la
    // case � r�soudre alors on regarde au sein du bloc o� elle se situe
    if (curseur == 9)
    {
      // On initialise les variables qui nous permettront de conna�tre la
      // position de la case en haut � gauche du bloc o� se situe la case �
      // r�soudre
      int ligneBloc = ligneCase, colonneBloc = colonneCase;

      // On recherche la premi�re case en haut � gauche du bloc o� se situe la
      // case � r�soudre
      detectionBloc(&ligneBloc, &colonneBloc);

      // On parcourt le bloc � partir de la premi�re case en haut � gauche pour
      // regarder si la possibilit� est pr�sente dans le bloc
      ligne   = ligneBloc;
      colonne = colonneBloc;

      while ((grille[ligne][colonne][0] != possibilite) &&
             (ligne != ligneBloc + 3))
      {
        colonne++;

        if (colonne == colonneBloc + 3)
        {
          ligne++;
          colonne = colonneBloc;
        }
      }

      if (ligne == ligneBloc + 3)
      {
        // On place la possibilit� dans la profondeur de la case � r�soudre puis
        // on incr�mente la profondeur avant de passer � la prochaine
        // possibilit�
        grille[ligneCase][colonneCase][profondeur] = possibilite;
        profondeur++;
      }
    }
  }
}

/// Proc�dure permettant de se placer � la premi�re case en haut � gauche du
// bloc o� se situe la case envoy�e
void detectionBloc(int *ligneCase, int *colonneCase)
{
  // On recherche la ligne
  if (*ligneCase <= 2)
  {
    *ligneCase = 0;
  }
  else if (*ligneCase >= 6)
  {
    *ligneCase = 6;
  }
  else
  {
    *ligneCase = 3;
  }

  // On recherche la colonne
  if (*colonneCase <= 2)
  {
    *colonneCase = 0;
  }
  else if (*colonneCase >= 6)
  {
    *colonneCase = 6;
  }
  else
  {
    *colonneCase = 3;
  }
}

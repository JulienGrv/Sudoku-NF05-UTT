#include "backtracking.h"

/// Fonction qui retourne 1 si le chiffre est bien le seul sur sa ligne
bool absentSurLigne(int k, int grille[9][9][10], int i)
{
  int j = 0;

  for (j = 0; j < 9; j++)
    if (grille[i][j][0] == k) return false;

  return true;
}

/// Fonction qui retourne 1 si le chiffre est bien le seul sur sa colonne
bool absentSurColonne(int k, int grille[9][9][10], int j)
{
  int i = 0;

  for (i = 0; i < 9; i++)
    if (grille[i][j][0] == k) return false;

  return true;
}

/// Fonction qui retourne 1 si le chiffre est bien le seul sur son bloc
bool absentSurBloc(int k, int grille[9][9][10], int i, int j)
{
  int _i = i - (i % 3), _j = j - (j % 3);

  for (i = _i; i < _i + 3; i++)
    for (j = _j; j < _j + 3; j++)
      if (grille[i][j][0] == k) return false;

  return true;
}

/// Fonction qui remplie une grille case par case.
bool backtracking(int grille[9][9][10], int position)
{
  // Si la grille est complétement remplie alors on a terminé et on retourne
  // true
  if (position == 81)
  {
    return true;
  }

  int i = position / 9, j = position % 9;

  // Si la case est déjà remplie on passe à la suivante
  if (grille[i][j][0] != 0)
  {
    return backtracking(grille, position + 1);
  }

  int k = 0, *possibilites = initSansDoublons(1, 10);

  // On test les possibilités de manière aléatoire et sans doublons
  melangeur(possibilites, 9);

  // On teste toutes les possibilit�s que peut prendre une case
  for (k = 0; k < 9; k++)
  {
    if (absentSurLigne(possibilites[k], grille,
                       i) &&
        absentSurColonne(possibilites[k], grille,
                         j) && absentSurBloc(possibilites[k], grille, i, j))
    {
      grille[i][j][0] = possibilites[k];

      // Si le tableau se remplie en entier toutes les cases sont justes et on
      // retourne true
      if (backtracking(grille, position + 1))
      {
        return true;
      }
    }
  }

  free(possibilites);

  // Si une case ne peut prendre aucune possibilit�s alors on retourne false et
  // on passe � la possibilit� suivante de la case pr�c�dente
  grille[i][j][0] = 0;
  return false;
}

/// Fonction qui retourne un tableau rempli dans l'ordre de borneInf inclus �
// borneSup exclus
int* initSansDoublons(int borneInf, int borneSup)
{
  int taille = borneSup - borneInf, *tableau = malloc((taille) * sizeof(int)),
      valeur = 0;

  // On remplit le tableau de mani�re � ce qu'il soit tri�
  for (valeur = 0; valeur < taille; valeur++)
  {
    tableau[valeur] = valeur + borneInf;
  }
  return tableau;
}

/// Fonction qui retourne un chiffre al�atoire entre borneInf et borneSup exclus
int chiffreAleatoire(int borneInf, int borneSup)
{
  return rand() % (borneSup - borneInf) + borneInf;
}

/// Proc�dure qui permet de m�langer les valeurs contenu dans un tableau
void melangeur(int *tableau, int taille)
{
  int i = 0, nombreTire = 0, temp = 0;

  for (i = 0; i < taille; i++)
  {
    nombreTire = chiffreAleatoire(0, taille);

    // On �change les contenus des cases i et nombre_tire
    temp                = tableau[i];
    tableau[i]          = tableau[nombreTire];
    tableau[nombreTire] = temp;
  }
}

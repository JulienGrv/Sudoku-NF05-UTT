#include "suppression.h"

/// Proc�dure qui permet de supprimer une possibilit� des zones adjacentes � une
// case ayant �t� r�solue
void supprimerPossibiliteZones(int ligneCase,
                               int colonneCase,
                               int possibilite,
                               int grille[9][9][10])
{
  int curseur = 0, ligneBloc = ligneCase, colonneBloc = colonneCase, ligne = 0,
      colonne = 0;

  // On r�initialise la case r�solue, celle-ci n'a plus besoin de contenir de
  // possibilit�s
  reinitialisationProfondeur(grille[ligneCase][colonneCase]);

  // On parcourt la ligne et la colonne pour supprimer la possibilit� devenu
  // solution
  for (curseur = 0; curseur < 9; curseur++)
  {
    if (grille[ligneCase][curseur][0] == 0)
    {
      supprimerPossibilite(grille[ligneCase][curseur], possibilite);
    }

    if (grille[curseur][colonneCase][0] == 0)
    {
      supprimerPossibilite(grille[curseur][colonneCase], possibilite);
    }
  }

  // On recherche la position de la premi�re case en haut � gauche du bloc o� se
  // trouve la case r�solue
  detectionBloc(&ligneBloc, &colonneBloc);

  // On parcourt le bloc de la case r�solue
  for (ligne = ligneBloc; ligne < ligneBloc + 3; ligne++)
  {
    for (colonne = colonneBloc; colonne < colonneBloc + 3; colonne++)
    {
      if (grille[ligne][colonne][0] == 0)
      {
        supprimerPossibilite(grille[ligne][colonne], possibilite);
      }
    }
  }
}

/// Proc�dure qui permet de supprimer une possibilit� d'une ligne en excluant
// l'un des blocs
void supprimerPossibiliteLigneBloc(int   ligneCase,
                                   int   colonneBloc,
                                   int   possibilite,
                                   int   grille[9][9][10],
                                   bool *stop)
{
  int colonne = 0;

  for (colonne = 0; colonne < 9; colonne++)
  {
    if ((grille[ligneCase][colonne][0] == 0) &&
        ((colonne < colonneBloc) || (colonne > colonneBloc + 2)))
    {
      if (supprimerPossibilite(grille[ligneCase][colonne], possibilite))
      {
        *stop = true;
      }
    }
  }
}

/// Proc�dure qui permet de supprimer une possibilit� d'une colonne en excluant
// l'un des blocs
void supprimerPossibiliteColonneBloc(int   colonneCase,
                                     int   ligneBloc,
                                     int   possibilite,
                                     int   grille[9][9][10],
                                     bool *stop)
{
  int ligne = 0;

  for (ligne = 0; ligne < 9; ligne++)
  {
    if ((grille[ligne][colonneCase][0] == 0) &&
        ((ligne < ligneBloc) || (ligne > ligneBloc + 2)))
    {
      if (supprimerPossibilite(grille[ligne][colonneCase], possibilite))
      {
        *stop = true;
      }
    }
  }
}

/// Proc�dure qui supprime les possibilit� d'une ligne apr�s un test du naked
// tuple r�ussi
void supprimerLigneNakedTuple(int   ligneCase,
                              int   colonneCase,
                              int   grille[9][9][10],
                              bool *stop)
{
  int profondeur = 1, colonne = 0, nombrePossibilites = compteurPossibilites(
    grille[ligneCase][colonneCase]);

  for (colonne = 0; colonne < 9; colonne++)
  {
    if (grille[ligneCase][colonne][0] == 0)
    {
      profondeur = 1;

      while (grille[ligneCase][colonne][profondeur] ==
             grille[ligneCase][colonneCase][profondeur] &&
             grille[ligneCase][colonneCase][profondeur] != 0)
      {
        profondeur++;
      }

      if ((compteurPossibilites(grille[ligneCase][colonne]) !=
           nombrePossibilites) ||
          (grille[ligneCase][colonne][profondeur] !=
           grille[ligneCase][colonneCase][profondeur]))
      {
        profondeur = 1;

        while (grille[ligneCase][colonneCase][profondeur] != 0)
        {
          if (supprimerPossibilite(grille[ligneCase][colonne],
                                   grille[ligneCase][colonneCase][profondeur]))
          {
            *stop = true;
          }
          profondeur++;
        }
      }
    }
  }
}

/// Proc�dure qui supprime les possibilit� d'un bloc apr�s un test du naked
// tuple r�ussi
void supprimerBlocNakedTuple(int   ligneCase,
                             int   colonneCase,
                             int   grille[9][9][10],
                             bool *stop)
{
  int profondeur         = 1, ligne = 0, colonne = 0, ligneBloc = ligneCase,
      colonneBloc        = colonneCase,
      nombrePossibilites = compteurPossibilites(grille[ligneCase][colonneCase]);

  detectionBloc(&ligneBloc, &colonneBloc);

  for (ligne = ligneBloc; ligne < ligneBloc + 3; ligne++)
  {
    for (colonne = colonneBloc; colonne < colonneBloc + 3; colonne++)
    {
      if (grille[ligne][colonne][0] == 0)
      {
        profondeur = 1;

        while (grille[ligne][colonne][profondeur] ==
               grille[ligneCase][colonneCase][profondeur] &&
               grille[ligneCase][colonneCase][profondeur] != 0)
        {
          profondeur++;
        }

        if ((compteurPossibilites(grille[ligne][colonne]) !=
             nombrePossibilites) ||
            (grille[ligne][colonne][profondeur] !=
             grille[ligneCase][colonneCase][profondeur]))
        {
          profondeur = 1;

          while (grille[ligneCase][colonneCase][profondeur] != 0)
          {
            if (supprimerPossibilite(grille[ligne][colonne],
                                     grille[ligneCase][colonneCase][profondeur]))
            {
              *stop = true;
            }
            profondeur++;
          }
        }
      }
    }
  }
}

/// Proc�dure qui supprime les possibilit� d'une colonne apr�s un test du naked
// tuple r�ussi
void supprimerColonneNakedTuple(int   ligneCase,
                                int   colonneCase,
                                int   grille[9][9][10],
                                bool *stop)
{
  int profondeur         = 1, ligne = 0,
      nombrePossibilites = compteurPossibilites(grille[ligneCase][colonneCase]);

  for (ligne = 0; ligne < 9; ligne++)
  {
    if (grille[ligne][colonneCase][0] == 0)
    {
      profondeur = 1;

      while (grille[ligne][colonneCase][profondeur] ==
             grille[ligneCase][colonneCase][profondeur] &&
             grille[ligneCase][colonneCase][profondeur] != 0)
      {
        profondeur++;
      }

      if ((compteurPossibilites(grille[ligne][colonneCase]) !=
           nombrePossibilites) ||
          (grille[ligne][colonneCase][profondeur] !=
           grille[ligneCase][colonneCase][profondeur]))
      {
        profondeur = 1;

        while (grille[ligneCase][colonneCase][profondeur] != 0)
        {
          if (supprimerPossibilite(grille[ligne][colonneCase],
                                   grille[ligneCase][colonneCase][profondeur]))
          {
            *stop = true;
          }
          profondeur++;
        }
      }
    }
  }
}

/// Proc�dure qui supprime les possibilit� d'une ligne apr�s un test du hidden
// tuple r�ussi
void supprimerLigneHiddenTuple(int   ligneCase,
                               int   colonneCase,
                               int  *listePossibilites,
                               int   indice,
                               int   grille[9][9][10],
                               bool *stop)
{
  int profondeur = 1, colonne = 0, i = 0, compteur = 0;

  for (colonne = 0; colonne < 9; colonne++)
  {
    if (grille[ligneCase][colonne][0] == 0)
    {
      for (i = 0; i < indice; i++)
      {
        profondeur = 1;

        while (grille[ligneCase][colonne][profondeur] != 0)
        {
          if (listePossibilites[i] == grille[ligneCase][colonne][profondeur])
          {
            compteur++;
          }
          profondeur++;
        }
      }

      if (compteur == indice)
      {
        profondeur = 1;

        while (grille[ligneCase][colonne][profondeur] != 0)
        {
          compteur = 1;

          for (i = 0; i < indice; i++)
          {
            if (listePossibilites[i] == grille[ligneCase][colonne][profondeur])
            {
              compteur = 0;
            }
          }

          if (compteur == 1)
          {
            supprimerPossibilite(grille[ligneCase][colonne],
                                 grille[ligneCase][colonne][profondeur]);
            *stop = true;
          }
          profondeur++;
        }
      }
    }
  }
}

/// Proc�dure qui supprime les possibilit� d'une colonne apr�s un test du hidden
// tuple r�ussi
void supprimerColonneHiddenTuple(int   ligneCase,
                                 int   colonneCase,
                                 int  *listePossibilites,
                                 int   indice,
                                 int   grille[9][9][10],
                                 bool *stop)
{
  int profondeur = 1, ligne = 0, i = 0, compteur = 0;

  for (ligne = 0; ligne < 9; ligne++)
  {
    if (grille[ligne][colonneCase][0] == 0)
    {
      for (i = 0; i < indice; i++)
      {
        profondeur = 1;

        while (grille[ligne][colonneCase][profondeur] != 0)
        {
          if (listePossibilites[i] == grille[ligne][colonneCase][profondeur])
          {
            compteur++;
          }
          profondeur++;
        }
      }

      if (compteur == indice)
      {
        profondeur = 1;

        while (grille[ligne][colonneCase][profondeur] != 0)
        {
          compteur = 1;

          for (i = 0; i < indice; i++)
          {
            if (listePossibilites[i] == grille[ligne][colonneCase][profondeur])
            {
              compteur = 0;
            }
          }

          if (compteur == 1)
          {
            supprimerPossibilite(grille[ligne][colonneCase],
                                 grille[ligne][colonneCase][profondeur]);
            *stop = true;
          }
          profondeur++;
        }
      }
    }
  }
}

/// Proc�dure permettant de r�initialiser la profondeur d'une case dont on
// recherche � nouveau les possibilit�s
void reinitialisationProfondeur(int profondeurCase[10])
{
  int profondeur = 0;

  // On parcourt toute la profondeur de la case et on r�initialise � z�ro
  // partout
  for (profondeur = 1; profondeur < 10; profondeur++)
  {
    profondeurCase[profondeur] = 0;
  }
}

/// Fonction qui supprime une possibilit� d'une case et retourne 1 si
// l'op�ration s'est effectu�e ou non
bool supprimerPossibilite(int possibilitesCase[10], int possibilite)
{
  int  profondeur = 1;
  bool stop       = false;

  while (possibilitesCase[profondeur] != possibilite &&
         possibilitesCase[profondeur] != 0)
  {
    profondeur++;
  }

  if (possibilitesCase[profondeur] == possibilite)
  {
    stop = true;

    while (possibilitesCase[profondeur] != 0)
    {
      possibilitesCase[profondeur] = possibilitesCase[profondeur + 1];
      profondeur++;
    }
  }
  return stop;
}

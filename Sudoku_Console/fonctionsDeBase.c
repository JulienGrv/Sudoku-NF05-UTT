#include "fonctionsDeBase.h"

/// Proc�dure de saisie d'une cha�ne de caract�re par l'utilisateur
void saisieChaine(char chaine[TAILLE_MAX])
{
  // Si la saisie s'est effectu�e correctement on nettoie le flux stdin
  if (fgets(chaine, TAILLE_MAX, stdin) != NULL)
  {
    nettoyeur(chaine);
  }
}

/// Proc�dure qui permet de retirer le retour � la ligne lors de la saisie de
// fgets
void nettoyeur(char *chaine)
{
  char *positionEntree = strchr(chaine, '\n'); // On recherche la position du

  // retour � la ligne

  if (positionEntree != NULL) // Si on a trouv� le retour � la ligne
  {
    *positionEntree = '\0'; // On le remplace par \0
  }
  else // Sinon on vide la m�moire tampon
  {
    vidageMemoireTampon();
  }
}

/// Proc�dure permettant de vider la m�moire tampon du flux stdin
void vidageMemoireTampon(void)
{
  int caractere = 0;

  // On "avale" un � un les caract�res du flux stdin tant qu'on a pas rencontr�
  // le dernier caract�re \n ou que stdin n'est pas vide.
  while ((caractere = getchar()) != '\n' && caractere != EOF)
  {}
}

/// Fonction d'ouverture d'un fichier en mode lecture
FILE* lectureFichier(char nomDuFichier[TAILLE_MAX])
{
  FILE *fichier = NULL;

  fichier = fopen(nomDuFichier, "r");

  if (fichier == NULL) // V�rification de l'ouverture du fichier
  {
    printf("\220chec de l'ouverture du fichier : le fichier %s n'existe pas !\n",
           nomDuFichier);
    exit(EXIT_FAILURE); // On arr�te tout
  }
  else
  {
    return fichier;
  }
}

/// Fonction d'ouverture d'un fichier en mode �criture
FILE* ecritureFichier(char nomDuFichier[TAILLE_MAX])
{
  FILE *fichier = NULL;

  fichier = fopen(nomDuFichier, "w");

  if (fichier == NULL) // V�rification de l'ouverture du fichier
  {
    printf("\220chec de l'ouverture du fichier %s !\n", nomDuFichier);
    exit(EXIT_FAILURE); // On arr�te tout
  }
  else
  {
    return fichier;
  }
}

/// Proc�dure permettant de copier un tableau dans une autre
void copierTableau(int tableauOrigine[9][9][10], int tableauNouveau[9][9][10])
{
  int ligne = 0, colonne = 0;

  for (ligne = 0; ligne < 9; ligne++)
  {
    for (colonne = 0; colonne < 9; colonne++)
    {
      tableauNouveau[ligne][colonne][0] = tableauOrigine[ligne][colonne][0];
    }
  }
}

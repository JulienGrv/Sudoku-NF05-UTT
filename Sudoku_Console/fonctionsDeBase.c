#include "fonctionsDeBase.h"

/// Procédure de saisie d'une chaîne de caractère par l'utilisateur
void saisieChaine(char chaine[TAILLE_MAX])
{
    if(fgets(chaine, TAILLE_MAX, stdin)!=NULL) // Si la saisie s'est effectuée correctement on nettoie le flux stdin
    {
        nettoyeur(chaine);
    }
}

/// Procédure qui permet de retirer le retour à la ligne lors de la saisie de fgets
void nettoyeur(char *chaine)
{
    char *positionEntree = strchr(chaine, '\n'); // On recherche la position du retour à la ligne
    if (positionEntree!=NULL) // Si on a trouvé le retour à la ligne
    {
        *positionEntree = '\0'; // On le remplace par \0
    }
    else // Sinon on vide la mémoire tampon
    {
        vidageMemoireTampon();
    }
}

/// Procédure permettant de vider la mémoire tampon du flux stdin
void vidageMemoireTampon(void)
{
    int caractere = 0;
    while ((caractere=getchar())!='\n'&&caractere!=EOF) // On "avale" un à un les caractères du flux stdin tant qu'on a pas rencontré le dernier caractère \n ou que stdin n'est pas vide.
    {}
}

/// Fonction d'ouverture d'un fichier en mode lecture
FILE* lectureFichier(char nomDuFichier[TAILLE_MAX])
{
    FILE* fichier = NULL;
    fichier = fopen(nomDuFichier,"r");
    if(fichier==NULL) // Vérification de l'ouverture du fichier
    {
        printf("\220chec de l'ouverture du fichier : le fichier %s n'existe pas !\n", nomDuFichier);
        exit(EXIT_FAILURE); // On arrête tout
    }
    else
    {
        return fichier;
    }
}

/// Fonction d'ouverture d'un fichier en mode écriture
FILE* ecritureFichier(char nomDuFichier[TAILLE_MAX])
{
    FILE* fichier = NULL;
    fichier = fopen(nomDuFichier,"w");
    if(fichier==NULL) // Vérification de l'ouverture du fichier
    {
        printf("\220chec de l'ouverture du fichier %s !\n", nomDuFichier);
        exit(EXIT_FAILURE); // On arrête tout
    }
    else
    {
        return fichier;
    }
}

/// Procédure permettant de copier un tableau dans une autre
void copierTableau(int tableauOrigine[9][9][10], int tableauNouveau[9][9][10])
{
    int ligne=0, colonne=0;
    for(ligne=0; ligne<9; ligne++)
    {
        for(colonne=0; colonne<9; colonne++)
        {
            tableauNouveau[ligne][colonne][0]=tableauOrigine[ligne][colonne][0];
        }
    }
}

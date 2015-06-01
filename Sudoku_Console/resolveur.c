#include "resolveur.h"

/// Procédure de résolution d'une grille de Sudoku
void resolveur(int grille[9][9][10], int *niveau)
{
    // On compte le nombre de cases à résoudre
    int compteurDeCases=nombreCasesRestantes(grille);
    bool stop=false;
    // Recherche les possibilités des cases à résoudre de la grille
    recherchePossibilitesGrille(&compteurDeCases, grille, niveau);
    /* Une fois un premier tour complet de la grille effectuée, toutes les possibilités de chaque case ont été déterminées.
    On passe donc à la résolution de la grille jusqu'à ce que le compteur de cases restantes soit à zéro.
    Si l'on s'aperçoit que la variable booléenne stop ne varie plus alors cela signifie que les traitements lié au niveau en cours ne suffise pas, il faut donc passer au niveau suivant. */
    while((compteurDeCases>0)&&(*niveau!=6))
    {
        // On initialise la variable stop comme "fausse"
        stop=false;
        // On lance la résolution de la grille
        resolutionGrille(&compteurDeCases, grille, niveau, &stop);
        // Si la variable stop est toujours fausse en sortant de l'algorithme de résolution alors cela signifie qu'aucune des traitements effectués n'a modifié la grille, on passe donc au niveau suivant
        if(stop==false)
        {
            (*niveau)++;
        }
    }
    if(compteurDeCases>0)
    {
        // Si le compteurs de cases n'est pas nul alors la grille n'est pas résoluble avec l'algorithme employé
        printf("\nGrille non-r\202soluble !\n");
        affichageGrille(grille); // temporaire
        exit(EXIT_FAILURE);
    }
}

/// Procédure d'importation de la grille par lecture du fichier
void importationGrille(FILE* fichier, int grille[9][9][10])
{
    int ligne=0, colonne=0;
    for(ligne=0; ligne<9; ligne++)
    {
        for(colonne=0; colonne<9; colonne++)
        {
            fscanf(fichier, "%d,", &grille[ligne][colonne][0]);
        }
    }
}


/// Procédure d'affichage de la grille de Sudoku
void affichageGrille(int grille[9][9][10])
{
    int ligne=0, colonne=0;
    printf("-------------------\n");
    for(ligne=0; ligne<9; ligne++)
    {
        for(colonne=0; colonne<9; colonne++)
        {
            if(colonne==0)
            {
                printf("|%d ", grille[ligne][colonne][0]);
            }
            else if(((colonne+1)%3))
            {
                printf("%d ", grille[ligne][colonne][0]);
            }
            else
            {
                printf("%d|", grille[ligne][colonne][0]);
            }
        }
        putchar('\n');
        if (!((ligne+1)%3))
        {
            printf("-------------------\n");
        }
    }
}

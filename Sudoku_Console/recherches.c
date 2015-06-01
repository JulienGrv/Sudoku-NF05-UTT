#include "recherches.h"

/// Fonction qui retourne le nombre de cases à résoudre
int nombreCasesRestantes(int grille[9][9][10])
{
    int ligne=0, colonne=0, compteurDeCases=0;
    // On parcourt toute la grille pour rechercher le nombre de cases à résoudre
    for(ligne=0; ligne<9; ligne++)
    {
        for(colonne=0; colonne<9; colonne++)
        {
            if(grille[ligne][colonne][0]==0)
            {
                compteurDeCases++;
            }
        }
    }
    return compteurDeCases;
}

/// Procédure qui permet de rechercher toutes les possibilités de toutes les cases de la grille de Sudoku
void recherchePossibilitesGrille(int *compteurDeCases, int grille[9][9][10], int *niveau)
{
    int ligne=0, colonne=0;
    // On parcourt toute la grille pour rechercher les possibilités des cases
    for(ligne=0; ligne<9; ligne++)
    {
        for(colonne=0; colonne<9; colonne++)
        {
            if(grille[ligne][colonne][0]==0)
            {
                // Si une case est à résoudre et n'a pas déjà des possibilités alors on recherche ses possibilités
                recherchePossibilitesCase(ligne, colonne, grille);
            }
        }
    }
}

/// Procédure de recherche des possibilités d'une case à résoudre
void recherchePossibilitesCase(int ligneCase, int colonneCase, int grille[9][9][10])
{
    int possibilite=1, curseur=0, ligne=0, colonne=0, profondeur=1;
    // On réinitialise à zéro toutes les possibilités de la case à résoudre avant de rechercher à nouveau ses possibilités
    reinitialisationProfondeur(grille[ligneCase][colonneCase]);
    // On recherche pour toutes les valeurs de 1 à 9 celles qui sont des possibilités pour la case à résoudre
    for(possibilite=1; possibilite<10; possibilite++)
    {
        curseur=0;
        // On regarde si la possibilité n'est ni présente sur la ligne ni sur la colonne de la case à résoudre
        while((grille[ligneCase][curseur][0]!=possibilite)&&(grille[curseur][colonneCase][0]!=possibilite)&&(curseur<9))
        {
            curseur++;
        }
        // Si la possibilité n'est ni présente sur la ligne ni sur la colonne de la case à résoudre alors on regarde au sein du bloc où elle se situe
        if(curseur==9)
        {
            // On initialise les variables qui nous permettront de connaître la position de la case en haut à gauche du bloc où se situe la case à résoudre
            int ligneBloc=ligneCase, colonneBloc=colonneCase;
            // On recherche la première case en haut à gauche du bloc où se situe la case à résoudre
            detectionBloc(&ligneBloc, &colonneBloc);
            // On parcourt le bloc à partir de la première case en haut à gauche pour regarder si la possibilité est présente dans le bloc
            ligne=ligneBloc;
            colonne=colonneBloc;
            while((grille[ligne][colonne][0]!=possibilite)&&(ligne!=ligneBloc+3))
            {
                colonne++;
                if(colonne==colonneBloc+3)
                {
                    ligne++;
                    colonne=colonneBloc;
                }
            }
            if(ligne==ligneBloc+3)
            {
                // On place la possibilité dans la profondeur de la case à résoudre puis on incrémente la profondeur avant de passer à la prochaine possibilité
                grille[ligneCase][colonneCase][profondeur]=possibilite;
                profondeur++;
            }
        }
    }
}

/// Procédure permettant de se placer à la première case en haut à gauche du bloc où se situe la case envoyée
void detectionBloc(int *ligneCase, int *colonneCase)
{
    // On recherche la ligne
    if(*ligneCase<=2)
    {
        *ligneCase=0;
    }
    else if(*ligneCase>=6)
    {
        *ligneCase=6;
    }
    else
    {
        *ligneCase=3;
    }
    // On recherche la colonne
    if(*colonneCase<=2)
    {
        *colonneCase=0;
    }
    else if(*colonneCase>=6)
    {
        *colonneCase=6;
    }
    else
    {
        *colonneCase=3;
    }
}

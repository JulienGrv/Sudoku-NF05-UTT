#include "main.h"

/* Barème des niveaux de difficultés :
 * 1=Très facile : SinglePosition
 * 2=Facile : SingleCandidate
 * 3=Moyen : CandidateLines ou DoublePairs ou MultipleLines
 * 4=Difficile : NakedPairs ou HiddenPairs ou NakedTriples ou HiddenTriples
 * 5=Très difficile : X-Wing ou SwordFish
 * 6=Expert : Forcing Chains
 */

int main(int argc, char *argv[])
{
    printf("------- Sudoku -------\n\n1 : R\202soudre une grille\n2 : G\202n\202rer une grille\n\nQue voulez-vous faire ?\n");
    char chaine[TAILLE_MAX] = "";
    while(chaine[0]!='1'&&chaine[0]!='2')
    {
        saisieChaine(chaine);
    }
    system("cls");
    if(chaine[0]=='1')
    {
        // Initialisation des variables et de la grille de Sudoku
        int grille[9][9][10] = {{{0}}}, niveau=1;
        char nomDuFichier[TAILLE_MAX] = "";
        // Demande du nom du fichier contenant la grille de Sudoku
        printf("Qu'elle est le nom du fichier texte contenant la grille ?\n");
        saisieChaine(nomDuFichier);
        // Ouverture du fichier en mode lecture
        FILE* fichier = lectureFichier(nomDuFichier);
        // Importation de la grille depuis le fichier
        importationGrille(fichier, grille);
        // Fermeture du fichier
        fclose(fichier);
        // Affichage de la grille importée
        printf("\n");
        affichageGrille(grille);
        // On résout la grille
        resolveur(grille, &niveau);
        // Sinon on affiche la grille résolue
        printf("\nGrille r\202solue :\n");
        affichageGrille(grille);
        printf("Niveau de difficult\202 = %d\n",niveau);
    }
    else
    {
        char choix[TAILLE_MAX] = "";
        int grille[9][9][10] = {{{0}}};
        do
        {
            int niveauRequis=0;
            printf("Quel doit \210tre son niveau de difficult\202 ? [1;5]\n");
            do
            {
                scanf("%d", &niveauRequis);
                vidageMemoireTampon();
            }
            while(niveauRequis<1||niveauRequis>6);
            generateur(grille, &niveauRequis);
            affichageGrille(grille);
            printf("G\202n\202rer une autre grille ? (0=non/1=oui)\n");
            saisieChaine(choix);
        }
        while(choix[0]=='1');
        printf("Voulez-vous exporter la grille dans un fichier texte ? (0=non/1=oui)\n");
        saisieChaine(choix);
        if(choix[0]=='1')
        {
            char nomDuFichier[TAILLE_MAX] = "";
            printf("Saisissez le nom du fichier d'enregistrement :\n");
            saisieChaine(nomDuFichier);
            FILE *fichier = ecritureFichier(nomDuFichier);
            exportationGrille(fichier, grille);
            fclose(fichier);
        }
    }
    return EXIT_SUCCESS;
}

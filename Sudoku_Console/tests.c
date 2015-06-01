#include "tests.h"

/// singlePosition : procédure déterminant si l'une des possibilités de la case à résoudre est l'unique possibilité présente sur sa ligne ou sur sa colonne ou son bloc
void positionUnique(int ligneCase, int colonneCase, int grille[9][9][10], int *compteurDeCases, bool *stop)
{
    // En ligne
    int ligne=0, colonne=0, profondeurCase=1, profondeur=1;
    // On effectue le test pour toutes les possibilités de la case à résoudre tant qu'il y a une possibilité et que la case n'a pas été résolue
    while((grille[ligneCase][colonneCase][profondeurCase]!=0)&&(grille[ligneCase][colonneCase][0]==0))
    {
        colonne=0;
        profondeur=1;
        // On recherche la case suivante de la ligne qui soit sans solution et qui ne soit pas la case à résoudre
        while((grille[ligneCase][colonne][0]!=0||colonne==colonneCase)&&(colonne<9))
        {
            colonne++;
        }
        // On parcourt la profondeur de la case tant qu'on ne rencontre pas une possibilité identique à celle de la case à résoudre et que l'on a pas atteint le bout de la ligne
        while((colonne<9)&&(grille[ligneCase][colonne][profondeur]!=grille[ligneCase][colonneCase][profondeurCase]))
        {
            profondeur++;
            // Si l'on a terminé de parcourir la profondeur de la case on passe à la suivante
            if(grille[ligneCase][colonne][profondeur]==0)
            {
                // On se replace à la première profondeur de la case suivante
                profondeur=1;
                colonne++;
                // Tant qu'on est pas sur une case sans solution on parcourt la ligne ou si on est sur la case à résoudre on la saute
                while((grille[ligneCase][colonne][0]!=0||colonne==colonneCase)&&(colonne<9))
                {
                    colonne++;
                }
            }
        }
        // Si l'on a parcouru toute la ligne sans rencontrer une seule fois la même possibilité alors elle est solution de la case à résoudre
        if(colonne>8)
        {
            grille[ligneCase][colonneCase][0]=grille[ligneCase][colonneCase][profondeurCase];
            // On décrémente le compteur de cases restantes
            (*compteurDeCases)--;
            // On actualise les zones adjacentes de la case résolue
            supprimerPossibiliteZones(ligneCase, colonneCase, grille[ligneCase][colonneCase][0], grille);
            *stop=true;
        }
        // Sinon on passe à la prochaine possibilité de la case à résoudre
        else
        {
            profondeurCase++;
        }
    }
    // En colonne
    profondeurCase=1;
    // On effectue le test pour toutes les possibilités de la case à résoudre tant qu'il y a une possibilité et que la case n'a pas été résolue
    while(grille[ligneCase][colonneCase][profondeurCase]!=0&&grille[ligneCase][colonneCase][0]==0)
    {
        ligne=0;
        profondeur=1;
        // On recherche la première case de la colonne qui soit sans solution et qui ne soit pas la case à résoudre
        while((grille[ligne][colonneCase][0]!=0||ligne==ligneCase)&&(ligne<9))
        {
            ligne++;
        }
        // On parcourt la profondeur de la case tant qu'on ne rencontre pas une possibilité identique à celle de la case à résoudre et que l'on a pas atteint le bout de la colonne
        while((ligne<9)&&(grille[ligne][colonneCase][profondeur]!=grille[ligneCase][colonneCase][profondeurCase]))
        {
            profondeur++;
            // Si l'on a terminé de parcourir la profondeur de la case on passe à la suivante
            if(grille[ligne][colonneCase][profondeur]==0)
            {
                // On se replace à la première profondeur de la case suivante
                profondeur=1;
                ligne++;
                // Tant qu'on est pas sur une case sans solution on parcourt la colonne ou si on est sur la case à résoudre à la saute
                while((grille[ligne][colonneCase][0]!=0||ligne==ligneCase)&&(ligne<9))
                {
                    ligne++;
                }
            }
        }
        // Si l'on a parcouru toute la colonne sans rencontrer une seule fois la même possibilité alors elle est solution de la case à résoudre
        if(ligne>8)
        {
            grille[ligneCase][colonneCase][0]=grille[ligneCase][colonneCase][profondeurCase];
            // On décrémente le compteur de cases restantes
            (*compteurDeCases)--;
            // On actualise les zones adjacentes de la case résolue
            supprimerPossibiliteZones(ligneCase, colonneCase, grille[ligneCase][colonneCase][0], grille);
            *stop=true;
        }
        // Sinon on passe à la prochaine possibilité de la case à résoudre
        else
        {
            profondeurCase++;
        }
    }
    // En bloc
    int ligneBloc=ligneCase, colonneBloc=colonneCase;
    profondeurCase=1;
    detectionBloc(&ligneBloc, &colonneBloc);
    // On effectue le test pour toutes les possibilités de la case à résoudre tant qu'il y a une possibilité et que la case n'a pas été résolue
    while(grille[ligneCase][colonneCase][profondeurCase]!=0&&grille[ligneCase][colonneCase][0]==0)
    {
        colonne=colonneBloc;
        ligne=ligneBloc;
        profondeur=1;
        // On recherche la première case du bloc qui soit sans solution et qui ne soit pas la case à résoudre
        while((grille[ligne][colonne][0]!=0||(ligne==ligneCase&&colonne==colonneCase))&&(ligne<ligneBloc+3))
        {
            colonne++;
            if(colonne==colonneBloc+3)
            {
                ligne++;
                colonne=colonneBloc;
            }
        }
        // On parcourt la profondeur de la case tant qu'on ne rencontre pas une possibilité identique à celle de la case à résoudre et que l'on a pas atteint la fin du bloc
        while((ligne<ligneBloc+3)&&(grille[ligne][colonne][profondeur]!=grille[ligneCase][colonneCase][profondeurCase]))
        {
            profondeur++;
            // Si l'on a terminé de parcourir la profondeur de la case on passe à la suivante
            if(grille[ligne][colonne][profondeur]==0)
            {
                // On se replace à la première profondeur de la case suivante
                profondeur=1;
                colonne++;
                if(colonne==colonneBloc+3)
                {
                    ligne++;
                    colonne=colonneBloc;
                }
                // Tant qu'on est pas sur une case sans solution on parcourt le bloc ou si on est sur la case à résoudre on la saute
                while((grille[ligne][colonne][0]!=0||(ligne==ligneCase&&colonne==colonneCase))&&(ligne<ligneBloc+3))
                {
                    colonne++;
                    if(colonne==colonneBloc+3)
                    {
                        ligne++;
                        colonne=colonneBloc;
                    }
                }
            }
        }
        // Si l'on a parcouru toute la colonne sans rencontrer une seule fois la même possibilité alors elle est solution de la case à résoudre
        if(ligne>ligneBloc+2)
        {
            grille[ligneCase][colonneCase][0]=grille[ligneCase][colonneCase][profondeurCase];
            // On décrémente le compteur de cases restantes
            (*compteurDeCases)--;
            // On actualise les zones adjacentes de la case résolue
            supprimerPossibiliteZones(ligneCase, colonneCase, grille[ligneCase][colonneCase][0], grille);
            *stop=true;
        }
        // Sinon on passe à la prochaine possibilité de la case à résoudre
        else
        {
            profondeurCase++;
        }
    }
}

/// singleCandidate : procédure qui teste si la case ne contient qu'une seule possibilité
void possibiliteUnique(int ligneCase, int colonneCase, int grille[9][9][10], int *compteurDeCases, bool *stop)
{
    if(grille[ligneCase][colonneCase][2]==0&&grille[ligneCase][colonneCase][1]!=0)
    {
        // Si la case n'a qu'une possibilité alors c'est sa solution
        grille[ligneCase][colonneCase][0]=grille[ligneCase][colonneCase][1];
        // On décrémente le compteur de cases restantes à résoudre
        (*compteurDeCases)--;
        // On actualise les zones adjacentes de la case résolue
        supprimerPossibiliteZones(ligneCase, colonneCase, grille[ligneCase][colonneCase][0], grille);
        // On indique qu'une modification a été apportée
        *stop=true;
    }
}

/// candidateLine : si au sein d'un bloc, les possibilités identiques sont toutes alignés alors on peut supprimer cette possibilité du restant de la ligne
void possibiliteAlignee(int ligneCase, int colonneCase, int grille[9][9][10], bool *stop)
{
    int ligneBloc=ligneCase, colonneBloc=colonneCase, ligne=0, colonne=0, profondeurCase=1, profondeur=0;
    detectionBloc(&ligneBloc, &colonneBloc);
    // On effectue le test pour toutes les possibilités de la case à résoudre tant qu'il y a une possibilité
    while(grille[ligneCase][colonneCase][profondeurCase]!=0)
    {
        colonne=colonneBloc;
        ligne=ligneBloc;
        profondeur=1;
        // On recherche la première case du bloc qui soit sans solution et qui ne soit pas la case à résoudre
        while((grille[ligne][colonne][0]!=0||(ligne==ligneCase&&colonne==colonneCase))&&(ligne<ligneBloc+3))
        {
            colonne++;
            if(colonne==colonneBloc+3)
            {
                ligne++;
                colonne=colonneBloc;
            }
        }
        do
        {
            if(ligne==ligneCase&&grille[ligne][colonne][profondeur]==grille[ligneCase][colonneCase][profondeurCase])
            {
                profondeur=1;
                colonne++;
                if(colonne==colonneBloc+3)
                {
                    ligne++;
                    colonne=colonneBloc;
                }
                // Tant qu'on est pas sur une case sans solution on parcourt le bloc ou si on est sur la case à résoudre on la saute
                while((grille[ligne][colonne][0]!=0||(ligne==ligneCase&&colonne==colonneCase))&&(ligne<ligneBloc+3))
                {
                    colonne++;
                    if(colonne==colonneBloc+3)
                    {
                        ligne++;
                        colonne=colonneBloc;
                    }
                }
            }
            // On parcourt la profondeur de la case tant qu'on ne rencontre pas une possibilité identique à celle de la case à résoudre et que l'on a pas atteint la fin du bloc
            while((ligne<ligneBloc+3)&&(grille[ligne][colonne][profondeur]!=grille[ligneCase][colonneCase][profondeurCase]))
            {
                profondeur++;
                // Si l'on a terminé de parcourir la profondeur de la case on passe à la suivante
                if(grille[ligne][colonne][profondeur]==0)
                {
                    // On se replace à la première profondeur de la case suivante
                    profondeur=1;
                    colonne++;
                    if(colonne==colonneBloc+3)
                    {
                        ligne++;
                        colonne=colonneBloc;
                    }
                    // Tant qu'on est pas sur une case sans solution on parcourt le bloc ou si on est sur la case à résoudre on la saute
                    while((grille[ligne][colonne][0]!=0||(ligne==ligneCase&&colonne==colonneCase))&&(ligne<ligneBloc+3))
                    {
                        colonne++;
                        if(colonne==colonneBloc+3)
                        {
                            ligne++;
                            colonne=colonneBloc;
                        }
                    }
                }
            }
        }
        while((ligne<ligneBloc+3)&&(ligne==ligneCase));
        if(ligne>ligneBloc+2)
        {
            supprimerPossibiliteLigneBloc(ligneCase, colonneBloc, grille[ligneCase][colonneCase][profondeurCase], grille, stop);
        }
        colonne=colonneBloc;
        ligne=ligneBloc;
        profondeur=1;
        // On recherche la première case du bloc qui soit sans solution et qui ne soit pas la case à résoudre
        while((grille[ligne][colonne][0]!=0||(ligne==ligneCase&&colonne==colonneCase))&&(ligne<ligneBloc+3))
        {
            colonne++;
            if(colonne==colonneBloc+3)
            {
                ligne++;
                colonne=colonneBloc;
            }
        }
        do
        {
            if(colonne==colonneCase&&grille[ligne][colonne][profondeur]==grille[ligneCase][colonneCase][profondeurCase])
            {
                profondeur=1;
                colonne++;
                if(colonne==colonneBloc+3)
                {
                    ligne++;
                    colonne=colonneBloc;
                }
                // Tant qu'on est pas sur une case sans solution on parcourt le bloc ou si on est sur la case à résoudre on la saute
                while((grille[ligne][colonne][0]!=0||(ligne==ligneCase&&colonne==colonneCase))&&(ligne<ligneBloc+3))
                {
                    colonne++;
                    if(colonne==colonneBloc+3)
                    {
                        ligne++;
                        colonne=colonneBloc;
                    }
                }
            }
            // On parcourt la profondeur de la case tant qu'on ne rencontre pas une possibilité identique à celle de la case à résoudre et que l'on a pas atteint la fin du bloc
            while((ligne<ligneBloc+3)&&(grille[ligne][colonne][profondeur]!=grille[ligneCase][colonneCase][profondeurCase]))
            {
                profondeur++;
                // Si l'on a terminé de parcourir la profondeur de la case on passe à la suivante
                if(grille[ligne][colonne][profondeur]==0)
                {
                    // On se replace à la première profondeur de la case suivante
                    profondeur=1;
                    colonne++;
                    if(colonne==colonneBloc+3)
                    {
                        ligne++;
                        colonne=colonneBloc;
                    }
                    // Tant qu'on est pas sur une case sans solution on parcourt le bloc ou si on est sur la case à résoudre on la saute
                    while((grille[ligne][colonne][0]!=0||(ligne==ligneCase&&colonne==colonneCase))&&(ligne<ligneBloc+3))
                    {
                        colonne++;
                        if(colonne==colonneBloc+3)
                        {
                            ligne++;
                            colonne=colonneBloc;
                        }
                    }
                }
            }
        }
        while((ligne<ligneBloc+3)&&(colonne==colonneCase));
        if(ligne>ligneBloc+2)
        {
            supprimerPossibiliteColonneBloc(colonneCase, ligneBloc, grille[ligneCase][colonneCase][profondeurCase], grille, stop);
        }
        // Sinon on passe à la prochaine possibilité de la case à résoudre
        profondeurCase++;
    }
}

/// nakedTuple : terminé.
void nakedTuple(int ligneCase, int colonneCase, int grille[9][9][10], bool *stop)
{
    int nombrePossibilites=compteurPossibilites(grille[ligneCase][colonneCase]);
    if(nombrePossibilites>1)
    {
        int  ligne=0, colonne=0, profondeur=1, nombreDeCases=0;
        // En colonne
        for(ligne=0; ligne<9; ligne++)
        {
            if(grille[ligne][colonneCase][0]==0)
            {
                profondeur=1;
                while(grille[ligne][colonneCase][profondeur]==grille[ligneCase][colonneCase][profondeur]&&grille[ligne][colonneCase][profondeur]!=0)
                {
                    profondeur++;
                }
                if(grille[ligne][colonneCase][profondeur]==0&&profondeur-1==nombrePossibilites)
                {
                    nombreDeCases++;
                }
            }
        }
        if(nombreDeCases==nombrePossibilites)
        {
            supprimerColonneNakedTuple(ligneCase, colonneCase, grille, stop);
        }
        // En ligne
        nombreDeCases=0;
        for(colonne=0; colonne<9; colonne++)
        {
            if(grille[ligneCase][colonne][0]==0)
            {
                profondeur=1;
                while(grille[ligneCase][colonne][profondeur]==grille[ligneCase][colonneCase][profondeur]&&grille[ligneCase][colonne][profondeur]!=0)
                {
                    profondeur++;
                }
                if(grille[ligneCase][colonne][profondeur]==0&&profondeur-1==nombrePossibilites)
                {
                    nombreDeCases++;
                }
            }
        }
        if(nombreDeCases==nombrePossibilites)
        {
            supprimerLigneNakedTuple(ligneCase, colonneCase, grille, stop);
        }
        // En bloc
        int ligneBloc=ligneCase, colonneBloc=colonneCase;
        detectionBloc(&ligneBloc, &colonneBloc);
        nombreDeCases=0;
        for(ligne=ligneBloc; ligne<ligneBloc+3; ligne++)
        {
            for(colonne=colonneBloc; colonne<colonneBloc+3; colonne++)
            {
                if(grille[ligne][colonne][0]==0)
                {
                    profondeur=1;
                    while(grille[ligne][colonne][profondeur]==grille[ligneCase][colonneCase][profondeur]&&grille[ligne][colonne][profondeur]!=0)
                    {
                        profondeur++;
                    }
                    if(grille[ligne][colonne][profondeur]==0&&profondeur-1==nombrePossibilites)
                    {
                        nombreDeCases++;
                    }
                }
            }
        }
        if(nombreDeCases==nombrePossibilites)
        {
            supprimerBlocNakedTuple(ligneCase, colonneCase, grille, stop);
        }
    }
}

/// hiddenTuple : reste "en bloc" et supprimerHiddenTuple à faire.
void hiddenTuple(int ligneCase, int colonneCase, int grille[9][9][10], bool *stop)
{
    int profondeurCase=1, ligne=0, colonne=0, nombre1=0, indice=0, profondeur=0, nombreDeCases=0, *listePossibilites=NULL, nombre2=0;
    // En colonne
    while(grille[ligneCase][colonneCase][profondeurCase]!=0&&grille[ligneCase][colonneCase][profondeurCase+1]!=0)
    {
        nombre1=0;
        for(ligne=0; ligne<9; ligne++)
        {
            if(grille[ligne][colonneCase][0]==0)
            {
                if(presencePossibilite(grille[ligne][colonneCase], grille[ligneCase][colonneCase][profondeurCase]))
                {
                    nombre1++;
                }
            }
        }
        if(nombre1>1&&compteurPossibilites(grille[ligneCase][colonneCase])>=nombre1)
        {
            indice=0, profondeur=profondeurCase+1, nombreDeCases=0, listePossibilites=NULL;
            listePossibilites = (int*)malloc(nombre1*sizeof(int));
            listePossibilites[indice]=grille[ligneCase][colonneCase][profondeurCase];
            indice++;
            while(grille[ligneCase][colonneCase][profondeur]!=0)
            {
                nombre2=0;
                for(ligne=0; ligne<9; ligne++)
                {
                    if(grille[ligne][colonneCase][0]==0)
                    {
                        if(presencePossibilite(grille[ligne][colonneCase],grille[ligneCase][colonneCase][profondeur])&&!presencePossibilite(grille[ligne][colonneCase],grille[ligneCase][colonneCase][profondeurCase]))
                        {
                            nombre2=0;
                            break;
                        }
                        else if(presencePossibilite(grille[ligne][colonneCase],grille[ligneCase][colonneCase][profondeur])&&presencePossibilite(grille[ligne][colonneCase],grille[ligneCase][colonneCase][profondeurCase]))
                        {
                            nombre2++;
                        }
                    }
                }
                if(nombre2==nombre1)
                {
                    nombreDeCases++;
                    listePossibilites[indice]=grille[ligneCase][colonneCase][profondeur];
                    indice++;
                }
                profondeur++;
            }
            if(nombreDeCases+1==nombre1)
            {
                supprimerColonneHiddenTuple(ligneCase, colonneCase, listePossibilites, nombre1, grille, stop);
            }
            free(listePossibilites);
        }
        profondeurCase++;
    }
    // En ligne
    profondeurCase=1;
    nombre1=0;
    while(grille[ligneCase][colonneCase][profondeurCase]!=0&&grille[ligneCase][colonneCase][profondeurCase+1]!=0)
    {
        nombre1=0;
        for(colonne=0; colonne<9; colonne++)
        {
            if(grille[ligneCase][colonne][0]==0)
            {
                if(presencePossibilite(grille[ligneCase][colonne], grille[ligneCase][colonneCase][profondeurCase]))
                {
                    nombre1++;
                }
            }
        }
        if(nombre1>1&&compteurPossibilites(grille[ligneCase][colonneCase])>=nombre1)
        {
            indice=0, profondeur=profondeurCase+1, nombreDeCases=0, listePossibilites=NULL;
            listePossibilites = (int*)malloc(nombre1*sizeof(int));
            listePossibilites[indice]=grille[ligneCase][colonneCase][profondeurCase];
            indice++;
            while(grille[ligneCase][colonneCase][profondeur]!=0)
            {
                nombre2=0;
                for(colonne=0; colonne<9; colonne++)
                {
                    if(grille[ligneCase][colonne][0]==0)
                    {
                        if(presencePossibilite(grille[ligneCase][colonne],grille[ligneCase][colonneCase][profondeur])&&!presencePossibilite(grille[ligneCase][colonne],grille[ligneCase][colonneCase][profondeurCase]))
                        {
                            nombre2=0;
                            break;
                        }
                        else if(presencePossibilite(grille[ligneCase][colonne],grille[ligneCase][colonneCase][profondeur])&&presencePossibilite(grille[ligneCase][colonne],grille[ligneCase][colonneCase][profondeurCase]))
                        {
                            nombre2++;
                        }
                    }
                }
                if(nombre2==nombre1)
                {
                    nombreDeCases++;
                    listePossibilites[indice]=grille[ligneCase][colonneCase][profondeur];
                    indice++;
                }
                profondeur++;
            }
            if(nombreDeCases+1==nombre1)
            {
                supprimerLigneHiddenTuple(ligneCase, colonneCase, listePossibilites, nombre1, grille, stop);
            }
            free(listePossibilites);
        }
        profondeurCase++;
    }
    // En bloc : à faire
}

/// forcingChains : mis en place d'un backtracking.
void forcingChains(int grille[9][9][10], int *compteurDeCases)
{
    int sauvegarde[9][9][10] = {{{0}}}, ligne=0, colonne=0;
    copierTableau(grille, sauvegarde);
    backtracking(grille,0);
    for(ligne=0; ligne<9; ligne++)
    {
        for(colonne=0; colonne<9; colonne++)
        {
            if(sauvegarde[ligne][colonne][0]==0)
            {
                reinitialisationProfondeur(grille[ligne][colonne]);
                (*compteurDeCases)--;
            }
        }
    }
}

/// Fonction qui permet de savoir si une possibilité est présente dans la profondeur d'une case
bool presencePossibilite(int possibilitesCase[10], int possibilite)
{
    int profondeur=1;
    while(possibilitesCase[profondeur]!=possibilite&&possibilitesCase[profondeur]!=0)
    {
        profondeur++;
    }
    return possibilitesCase[profondeur]==possibilite;
}

/// Fonction qui permet de connaitre le nombre de possibilités contenu dans la profondeur d'une case
int compteurPossibilites(int possibilitesCase[10])
{
    int profondeur=1;
    while(possibilitesCase[profondeur]!=0&&profondeur<10)
    {
        profondeur++;
    }
    return profondeur-1;
}

#include "gestionEvenements.h"

/// Procédure qui attend qu'un événement se produise à l'écran principal
void attenteEcranPrincipal(SDL_Surface *ecran, bool *finDuProgramme)
{
    SDL_Event event;
    Uint8 *etatTouche;
    // Tant que la fermeture du programme n'a pas été demandée on récupère les événements
    while(*finDuProgramme==false)
    {
        // Récupération des événements
        SDL_WaitEvent(&event);
        etatTouche = SDL_GetKeyState(NULL);
        // Vérification des événements
        switch(event.type)
        {
            // Arrêt du programme si la fenêtre est fermée
        case SDL_QUIT:
            *finDuProgramme = true;
            break;
            // Cas des touches enfoncées
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE: // Echap : arrêt du programme
                *finDuProgramme = true;
                break;
            case SDLK_F4: // Alt + F4 : arrêt du programme
                if(etatTouche[SDLK_LALT]&&etatTouche[SDLK_F4])
                {
                    *finDuProgramme = true;
                }
                break;
            }
            break;
            // Cas des clics de souris relâchés
        case SDL_MOUSEBUTTONUP:
            // Bouton "Nouvelle partie"
            if(event.button.x>=(ecran->w-332)/2&&event.button.x<=(ecran->w+332)/2&&event.button.y>=225&&event.button.y<=254)
            {
                ecranChoixDifficulte(ecran, finDuProgramme);
            }
            // Bouton "Reprendre une partie"
            else if(event.button.x>=(ecran->w-332)/2&&event.button.x<=(ecran->w+332)/2&&event.button.y>=285&&event.button.y<=314)
            {
                ecranJouer(ecran, finDuProgramme, 0);
            }
            // Bouton "Résoudre une grille"
            else if(event.button.x>=(ecran->w-332)/2&&event.button.x<=(ecran->w+332)/2&&event.button.y>=345&&event.button.y<=374)
            {
                ecranResolveur(ecran, finDuProgramme);
            }
            break;
        }
    }
}

/// Procédure qui attend qu'un événement se produise à l'écran de choix de difficulté
void attenteEcranChoix(SDL_Surface *ecran, bool *finDuProgramme)
{
    SDL_Event event;
    Uint8 *etatTouche;
    // Tant que la fermeture du programme n'a pas été demandée on récupère les événements
    while(*finDuProgramme==false)
    {
        // Récupération des événements
        SDL_WaitEvent(&event);
        etatTouche = SDL_GetKeyState(NULL);
        // Vérification des événements
        switch(event.type)
        {
            // Arrêt du programme si la fenêtre est fermée
        case SDL_QUIT:
            *finDuProgramme = true;
            break;
            // Cas des touches enfoncées
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE: // Echap : arrêt du programme
                *finDuProgramme = true;
                break;
            case SDLK_F4: // Alt + F4 : arrêt du programme
                if(etatTouche[SDLK_LALT]&&etatTouche[SDLK_F4])
                {
                    *finDuProgramme = true;
                }
                break;
            }
            break;
            // Cas des clics de souris relâchés
        case SDL_MOUSEBUTTONUP:
            // Bouton "Retour"
            if(event.button.x>=19&&event.button.x<=76&&event.button.y>=19&&event.button.y<=45)
            {
                ecranPrincipal(ecran, finDuProgramme);
            }
            // Bouton niveau facile
            else if(event.button.x>=328&&event.button.x<=493&&event.button.y>=110&&event.button.y<=173)
            {
                ecranJouer(ecran, finDuProgramme, 2);
            }
            // niveau moyen
            else if(event.button.x>=328&&event.button.x<=493&&event.button.y>=241&&event.button.y<=304)
            {
                ecranJouer(ecran, finDuProgramme, 3);
            }
            // niveau difficile
            else if(event.button.x>=328&&event.button.x<=493&&event.button.y>=372&&event.button.y<=435)
            {
                ecranJouer(ecran, finDuProgramme, 4);
            }
            break;
        }
    }
}

/// Procédure qui attend qu'un événement se produise à l'écran de jeu
void attenteEcranJouer(SDL_Surface *ecran, SDL_Surface *grille, int grilleSudoku[9][9][10], bool *finDuProgramme)
{
    SDL_Event event;
    Uint8 *etatTouche;
    int positionX = 0, positionY = 0, i = 0, grilleDepart[9][9][10] = {{{0}}}, decalage = 0, colonne = 0, ligne = 0;
    char nomDuFichier[TAILLE_MAX] = "";
    copierTableau(grilleSudoku, grilleDepart);
    // Tant que la fermeture du programme n'a pas été demandée on récupère les événements
    while(*finDuProgramme==false)
    {
        // Récupération des événements
        SDL_WaitEvent(&event);
        etatTouche = SDL_GetKeyState(NULL);
        // Vérification des événements
        switch(event.type)
        {
            // Arrêt du programme si la fenêtre est fermée
        case SDL_QUIT:
            *finDuProgramme = true;
            break;
            // Cas des touches enfoncées
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE: // Echap : arrêt du programme
                *finDuProgramme = true;
                break;
            case SDLK_F4: // Alt + F4 : arrêt du programme
                if(etatTouche[SDLK_LALT]&&etatTouche[SDLK_F4])
                {
                    *finDuProgramme = true;
                }
                break;
            }
            break;
            // Cas des clics de souris relâchés
        case SDL_MOUSEBUTTONUP:
            // Clic effectué sur une case
            if((event.button.x>(ecran->w-grille->w)/2)&&(event.button.x<(ecran->w+grille->w)/2)&&(event.button.y>(ecran->h-grille->h)/2)&&(event.button.y<(ecran->h+grille->h)/2))
            {
                // Recherche de la ligne et de la colonne de la case cliquée
                while(positionX==0||positionY==0)
                {
                    if(event.button.x<256+i*40+decalage&&positionX==0)
                    {
                        positionX = 217+i*40+decalage;
                        colonne = i;
                    }
                    if(event.button.y<156+i*40+decalage&&positionY==0)
                    {
                        positionY = 117+i*40+decalage;
                        ligne = i;
                    }
                    if(i==2)
                    {
                        decalage += 3;
                    }
                    else if(i==5)
                    {
                        decalage += 3;
                    }
                    i++;
                }
                // Procédure de saisie d'un chiffre dans la case
                saisirChiffre(ecran, positionX, positionY, finDuProgramme, &(grilleSudoku[ligne][colonne][0]));
                // On efface le cadre rouge
                afficherGrilleVierge2(ecran);
                // On ré-affiche les solutions
                afficherSolution(grilleSudoku, ecran);
                event.button.x = 0;
                event.button.y = 0;
                positionX = 0;
                positionY = 0;
                decalage = 0;
                i = 0;
            }
            // Bouton "Valider"
            else if(event.button.x>ecran->w-170&&event.button.x<ecran->w-20&&event.button.y>ecran->h-40&&event.button.y<ecran->h-20)
            {
                int niveau=1, ligne=0, colonne=0;
                // On résout la grille de départ
                resolveur(grilleDepart, &niveau);
                // On compare la grille de départ résolue à celle proposée par l'utilisateur
                while(grilleDepart[ligne][colonne][0]==grilleSudoku[ligne][colonne][0]&&colonne<9)
                {
                    ligne++;
                    if(ligne==9)
                    {
                        ligne=0;
                        colonne++;
                    }
                }
                // Si gagné
                if(colonne==9)
                {
                    SDL_Surface *victoire = chargementBitmap("img/victoire.bmp");
                    SDL_Rect positionVictoire;
                    positionVictoire.x = (ecran->w-victoire->w)/2;
                    positionVictoire.y = (ecran->h-victoire->h)/2;
                    SDL_BlitSurface(victoire, NULL, ecran, &positionVictoire);
                    SDL_Flip(ecran);
                    SDL_FreeSurface(victoire);
                }
                // Sinon perdu
                else
                {
                    ecranPerdu(ecran, finDuProgramme);
                }
            }
            // Bouton "réinitialiser"
            else if(event.button.x>ecran->w-340&&event.button.x<ecran->w-20&&event.button.y>ecran->h-40&&event.button.y<ecran->h-20)
            {
                for(ligne=0; ligne<9; ligne++)
                {
                    for(colonne=0; colonne<9; colonne++)
                    {
                        grilleSudoku[ligne][colonne][0] = 0;
                    }
                }
                afficherGrilleVierge2(ecran);
                afficherSolution(grilleDepart, ecran);
                copierTableau(grilleDepart, grilleSudoku);
            }
            // Bouton "imprimante"
            else if(event.button.x>=737&&event.button.x<=785&&event.button.y>=12&&event.button.y<=60)
            {
                impressionEcran(ecran, grilleSudoku);
                afficherGrilleVierge2(ecran);
                afficherSolution(grilleSudoku, ecran);
            }
            // Bouton "Retour"
            else if(event.button.x>=19&&event.button.x<=76&&event.button.y>=19&&event.button.y<=45)
            {
                // Si retour à l'écran de choix alors on enregistre la grille
                strcpy(nomDuFichier,"sauvegarde.sdk");
                FILE *fichier = ecritureFichier(nomDuFichier);
                exportationGrille(fichier, grilleSudoku);
                fclose(fichier);
                ecranChoixDifficulte(ecran, finDuProgramme);
            }
            break;
        }
        // Si le programme est arrêté on enregistre la grille
        if(*finDuProgramme==true)
        {
            strcpy(nomDuFichier,"sauvegarde.sdk");
            FILE *fichier = ecritureFichier(nomDuFichier);
            exportationGrille(fichier, grilleSudoku);
            fclose(fichier);
        }
    }
}

/// Procédure qui attend qu'un événement se produise à l'écran de résolution de grille
void attenteEcranResolveur(SDL_Surface *ecran, SDL_Surface *grille, bool *finDuProgramme)
{
    SDL_Event event;
    Uint8 *etatTouche;
    int positionX = 0, positionY = 0, i = 0, decalage = 0, grilleSudoku[9][9][10] = {{{0}}}, colonne = 0, ligne = 0;
    // Tant que la fermeture du programme n'a pas été demandée on récupère les événements
    while(*finDuProgramme==false)
    {
        // Récupération des événements
        SDL_WaitEvent(&event);
        etatTouche = SDL_GetKeyState(NULL);
        // Vérification des événements
        switch(event.type)
        {
            // Arrêt du programme si la fenêtre est fermée
        case SDL_QUIT:
            *finDuProgramme = true;
            break;
            // Cas des touches enfoncées
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE: // Echap : arrêt du programme
                *finDuProgramme = true;
                break;
            case SDLK_F4: // Alt + F4 : arrêt du programme
                if(etatTouche[SDLK_LALT]&&etatTouche[SDLK_F4])
                {
                    *finDuProgramme = true;
                }
                break;
            }
            break;
            // Cas des clics de souris relâchés
        case SDL_MOUSEBUTTONUP:
            // Clic sur une case de la grille
            if((event.button.x>(ecran->w-grille->w)/2)&&(event.button.x<(ecran->w+grille->w)/2)&&(event.button.y>(ecran->h-grille->h)/2)&&(event.button.y<(ecran->h+grille->h)/2))
            {
                // recherche de la ligne et de la colonne de la case cliquée
                while(positionX==0||positionY==0)
                {
                    if(event.button.x<256+i*40+decalage&&positionX==0)
                    {
                        positionX = 217+i*40+decalage;
                        colonne = i;
                    }
                    if(event.button.y<156+i*40+decalage&&positionY==0)
                    {
                        positionY = 117+i*40+decalage;
                        ligne = i;
                    }
                    if(i==2)
                    {
                        decalage += 3;
                    }
                    else if(i==5)
                    {
                        decalage += 3;
                    }
                    i++;
                }
                // Saisie du chiffre
                saisirChiffre(ecran, positionX, positionY, finDuProgramme, &(grilleSudoku[ligne][colonne][0]));
                // On efface le cadre rouge
                afficherGrilleVierge(ecran);
                // On ré-affiche les solutions
                afficherSolution(grilleSudoku, ecran);
                event.button.x = 0;
                event.button.y = 0;
                positionX = 0;
                positionY = 0;
                decalage = 0;
                i = 0;
            }
            // On résout la grille
            else if(event.button.x>ecran->w-170&&event.button.x<ecran->w-20&&event.button.y>ecran->h-40&&event.button.y<ecran->h-20)
            {
                int niveau=1;
                resolveur(grilleSudoku, &niveau);
                afficherSolution(grilleSudoku, ecran);
            }
            // Réinitialisation
            else if(event.button.x>ecran->w-340&&event.button.x<ecran->w-20&&event.button.y>ecran->h-40&&event.button.y<ecran->h-20)
            {
                for(ligne=0; ligne<9; ligne++)
                {
                    for(colonne=0; colonne<9; colonne++)
                    {
                        grilleSudoku[ligne][colonne][0] = 0;
                    }
                }
                afficherGrilleVierge(ecran);
            }
            // imprimante
            else if(event.button.x>=737&&event.button.x<=785&&event.button.y>=12&&event.button.y<=60)
            {
                impressionEcran(ecran, grilleSudoku);
                afficherGrilleVierge(ecran);
                afficherSolution(grilleSudoku, ecran);
            }
            // Retour à l'écran principal
            else if(event.button.x>=19&&event.button.x<=76&&event.button.y>=19&&event.button.y<=45)
            {
                ecranPrincipal(ecran, finDuProgramme);
            }
            break;
        }
    }
}

/// Procédure qui permet de saisir un chiffre dans la grille
void saisirChiffre(SDL_Surface *ecran, int positionX, int positionY, bool *finDuProgramme, int *caseChiffre)
{
    // Déclaration des variables
    char nomImage[17] = {'i','m','g','\\','c','h','i','f','f','r','e','0','.','b','m','p','\0'};
    SDL_Event event;
    Uint8 *etatTouche;
    char numero = 0;
    // On créé les surfaces pour le cadre rouge de la case
    SDL_Surface *cadreLargeur = SDL_CreateRGBSurface(SDL_HWSURFACE, 39, 3, 32, 0, 0, 0, 0);
    SDL_Surface *cadreHauteur = SDL_CreateRGBSurface(SDL_HWSURFACE, 3, 39, 32, 0, 0, 0, 0);
    // On remplit les surfaces par du rouge
    SDL_FillRect(cadreLargeur, NULL, SDL_MapRGB(cadreLargeur->format, 255, 0, 0));
    SDL_FillRect(cadreHauteur, NULL, SDL_MapRGB(cadreHauteur->format, 255, 0, 0));
    // Position du cadre
    SDL_Rect positionCadre1;
    positionCadre1.x = positionX;
    positionCadre1.y = positionY;
    SDL_Rect positionCadre2;
    positionCadre2.x = positionX;
    positionCadre2.y = positionY+36;
    SDL_Rect positionCadre3;
    positionCadre3.x = positionX+36;
    positionCadre3.y = positionY;
    // On affiche le cadre
    SDL_BlitSurface(cadreLargeur, NULL, ecran, &positionCadre1);
    SDL_BlitSurface(cadreHauteur, NULL, ecran, &positionCadre1);
    SDL_BlitSurface(cadreLargeur, NULL, ecran, &positionCadre2);
    SDL_BlitSurface(cadreHauteur, NULL, ecran, &positionCadre3);
    // On actualise l'écran
    SDL_Flip(ecran);
    // On libère la mémoire
    SDL_FreeSurface(cadreLargeur);
    SDL_FreeSurface(cadreHauteur);
    //
    while(numero==0&&*finDuProgramme==false)
    {
        // Récupération des événements
        SDL_WaitEvent(&event);
        etatTouche = SDL_GetKeyState(NULL);
        // Vérification des événements
        switch(event.type)
        {
            // Arrêt du programme si la fenêtre est fermée
        case SDL_QUIT:
            *finDuProgramme = true;
            break;
            // Cas des touches enfoncées
        case SDL_KEYDOWN:
            switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE: // Echap : arrêt du programme
                *finDuProgramme = true;
                break;
            case SDLK_F4:
                if(etatTouche[SDLK_LALT]&&etatTouche[SDLK_F4]) // Alt + F4 : arrêt du programme
                {
                    *finDuProgramme = true;
                }
                break;
            case SDLK_KP1:
                numero = '1';
                break;
            case SDLK_KP2:
                numero = '2';
                break;
            case SDLK_KP3:
                numero = '3';
                break;
            case SDLK_KP4:
                numero = '4';
                break;
            case SDLK_KP5:
                numero = '5';
                break;
            case SDLK_KP6:
                numero = '6';
                break;
            case SDLK_KP7:
                numero = '7';
                break;
            case SDLK_KP8:
                numero = '8';
                break;
            case SDLK_KP9:
                numero = '9';
                break;
            case SDLK_KP0:
                numero = '0';
                break;
            }
            break;
            // Cas des cliques de souris enfoncés
        case SDL_MOUSEBUTTONDOWN:
            numero = 1;
            break;
        }
    }
    if(numero!='0'&&numero!=1)
    {
        // Modification
        nomImage[11] = numero;
        *caseChiffre = numero-48;
        // Chargement de l'image du chiffre
        SDL_Surface *chiffre = chargementBitmap(nomImage);
        // Position du chiffre
        SDL_Rect positionChiffre;
        positionChiffre.x = positionX;
        positionChiffre.y = positionY;
        // Transparence de la couleur noir
        SDL_SetColorKey(chiffre, SDL_SRCCOLORKEY, SDL_MapRGB(chiffre->format, 255, 255, 255));
        // On affiche l'image du chiffre
        SDL_BlitSurface(chiffre, NULL, ecran, &positionChiffre);
        // On actualise l'écran
        SDL_Flip(ecran);
        // On libère la mémoire
        SDL_FreeSurface(chiffre);
    }
    else if(numero=='0')
    {
        // On réinitialise la case à 0
        *caseChiffre = 0;
    }
}

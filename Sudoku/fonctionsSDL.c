#include "fonctionsSDL.h"

/// Procédure qui initialise la SDL
void initialisationSDL(void)
{
    // On initialise le système vidéo de la SDL
    if(SDL_Init(SDL_INIT_VIDEO)<0) // Si l'initialisation a échouée alors :
    {
        fprintf(stderr, "Impossible d'initialiser la SDL : %s\n", SDL_GetError()); // On écrit l'erreur dans un fichier
        exit(EXIT_FAILURE); // On quitte le programme
    }
    // make sure SDL cleans up before exit
    atexit(SDL_Quit);
}

/// Fonction qui retourne la création d'une fenêtre en 640x480 32bits/pixel utilisant la RAM de la carte graphique et le double buffering
SDL_Surface* creationEcran(int hauteur, int largeur)
{
    // Création d'une nouvelle fenêtre à l'écran
    SDL_Surface *ecran = SDL_SetVideoMode(hauteur, largeur, 32, SDL_HWSURFACE|SDL_DOUBLEBUF);
    if (ecran==NULL) // Si la fenêtre n'existe pas alors :
    {
        fprintf(stderr, "Impossible de charger le mode vidéo : %s\n", SDL_GetError()); // On écrit l'erreur dans un fichier
        exit(EXIT_FAILURE); // On quitte le programme
    }
    return ecran;
}

/// On effectue une impression de l'écran en affichant temporairement à l'écran seulement la grille et un fond blanc que l'on enregistre ensuite dans un fichier bmp
void impressionEcran(SDL_Surface *ecran, int grilleSudoku[9][9][10])
{
    // fond blanc
    SDL_Surface *fondBlanc = SDL_CreateRGBSurface(SDL_HWSURFACE, 800, 600, 32, 0, 0, 0, 0);
    // On remplit le fond par du blanc
    SDL_FillRect(fondBlanc, NULL, SDL_MapRGB(fondBlanc->format, 255, 255, 255));
    // Position du fond
    SDL_Rect positionFond;
    positionFond.x = 0;
    positionFond.y = 0;
    // Chargement de la grille
    SDL_Surface *grille = chargementBitmap("img/grilleVierge.bmp");
    // Position de la grille
    SDL_Rect positionGrille;
    positionGrille.x = (ecran->w-grille->w)/2;
    positionGrille.y = (ecran->h-grille->h)/2;
    // affichage
    SDL_BlitSurface(fondBlanc, NULL, ecran, &positionFond);
    SDL_BlitSurface(grille, NULL, ecran, &positionGrille);
    SDL_Flip(ecran);
    SDL_FreeSurface(fondBlanc);
    SDL_FreeSurface(grille);
    afficherSolution(grilleSudoku, ecran);
    // On enregistre la grille dans un fichier bitmap
    SDL_SaveBMP(ecran, "impression_grille.bmp");
}

/// Fonction qui retourne une surface contenant une image chargée au format bitmap
SDL_Surface* chargementBitmap(char *nomImage)
{
    SDL_Surface *image = SDL_LoadBMP(nomImage);
    if (image==NULL) // Si le chargement de l'image a échoué alors :
    {
        fprintf(stderr, "Impossible de charger l'image : %s\n", SDL_GetError()); // On écrit l'erreur dans un fichier
        exit(EXIT_FAILURE); // On quitte le programme
    }
    return image;
}

/// Procédure qui permet d'afficher au centre de l'écran une grille de sudoku vierge sur l'écran du résolveur
void afficherGrilleVierge(SDL_Surface *ecran)
{
    // Chargement de l'image du fond d'écran
    SDL_Surface *fondEcran = chargementBitmap("img/fondGrille.bmp");
    // Position du fond d'écran
    SDL_Rect positionFond;
    positionFond.x = 0;
    positionFond.y = 0;
    // Chargement de l'image du bouton retour
    SDL_Surface *retour = chargementBitmap("img/retour.bmp");
    // Position
    SDL_Rect positionRetour;
    positionRetour.x = 10;
    positionRetour.y = 10;
    // Chargement de l'image du bouton imprimante
    SDL_Surface *imprimante = chargementBitmap("img/imprimante.bmp");
    // Position du bouton
    SDL_Rect positionImprimante;
    positionImprimante.x = 785-imprimante->w;
    positionImprimante.y = 12;
    // Chargement de la grille
    SDL_Surface *grille = chargementBitmap("img/grilleVierge.bmp");
    // Position de la grille
    SDL_Rect positionGrille;
    positionGrille.x = (ecran->w-grille->w)/2;
    positionGrille.y = (ecran->h-grille->h)/2;
    // Chargement du bouton résoudre
    SDL_Surface *resoudre = chargementBitmap("img/resoudre.bmp");
    // Position du bouton résoudre
    SDL_Rect positionResoudre;
    positionResoudre.x = ecran->w-170;
    positionResoudre.y = ecran->h-40;
    // Chargement du bouton réinitialise
    SDL_Surface *reinitialiser = chargementBitmap("img/reinitialiser.bmp");
    // Position du bouton réinitialise
    SDL_Rect positionReinitialiser;
    positionReinitialiser.x = ecran->w-340;
    positionReinitialiser.y = ecran->h-40;
    // Transparence du fond rose
    SDL_SetColorKey(resoudre, SDL_SRCCOLORKEY, SDL_MapRGB(resoudre->format, 255, 0, 255));
    SDL_SetColorKey(reinitialiser, SDL_SRCCOLORKEY, SDL_MapRGB(reinitialiser->format, 255, 0, 255));
    SDL_SetColorKey(retour, SDL_SRCCOLORKEY, SDL_MapRGB(retour->format, 255, 0, 255));
    SDL_SetColorKey(imprimante, SDL_SRCCOLORKEY, SDL_MapRGB(imprimante->format, 255, 0, 255));
    // Opacité de la grille
    SDL_SetAlpha(grille, SDL_SRCALPHA, 190);
    // On affiche les images
    SDL_BlitSurface(fondEcran, NULL, ecran, &positionFond);
    SDL_BlitSurface(grille, NULL, ecran, &positionGrille);
    SDL_BlitSurface(retour, NULL, ecran, &positionRetour);
    SDL_BlitSurface(imprimante, NULL, ecran, &positionImprimante);
    SDL_BlitSurface(resoudre, NULL, ecran, &positionResoudre);
    SDL_BlitSurface(reinitialiser, NULL, ecran, &positionReinitialiser);
    // Mise à jour de l'écran
    SDL_Flip(ecran);
    // On libère les surfaces
    SDL_FreeSurface(fondEcran);
    SDL_FreeSurface(grille);
    SDL_FreeSurface(retour);
    SDL_FreeSurface(imprimante);
    SDL_FreeSurface(resoudre);
    SDL_FreeSurface(reinitialiser);
}

/// Procédure qui permet d'afficher au centre de l'écran une grille de sudoku vierge sur l'écran de jeu
void afficherGrilleVierge2(SDL_Surface *ecran)
{
    // Chargement de l'image du fond d'écran
    SDL_Surface *fondEcran = chargementBitmap("img/fondGrille.bmp");
    // Position du fond d'écran
    SDL_Rect positionFond;
    positionFond.x = 0;
    positionFond.y = 0;
    // Chargement de l'image du bouton retour
    SDL_Surface *retour = chargementBitmap("img/retour.bmp");
    // Position
    SDL_Rect positionRetour;
    positionRetour.x = 10;
    positionRetour.y = 10;
    // Chargement du bouton imprimante
    SDL_Surface *imprimante = chargementBitmap("img/imprimante.bmp");
    // Position
    SDL_Rect positionImprimante;
    positionImprimante.x = 785-imprimante->w;
    positionImprimante.y = 12;
    // Chargement de la grille
    SDL_Surface *grille = chargementBitmap("img/grilleVierge.bmp");
    // Position de la grille
    SDL_Rect positionGrille;
    positionGrille.x = (ecran->w-grille->w)/2;
    positionGrille.y = (ecran->h-grille->h)/2;
    // Chargement du bouton valider
    SDL_Surface *resoudre = chargementBitmap("img/valider.bmp");
    // Position du bouton valider
    SDL_Rect positionResoudre;
    positionResoudre.x = ecran->w-170;
    positionResoudre.y = ecran->h-40;
    // Chargement du bouton réinitialiser
    SDL_Surface *reinitialiser = chargementBitmap("img/reinitialiser.bmp");
    // Position du bouton réinitialiser
    SDL_Rect positionReinitialiser;
    positionReinitialiser.x = ecran->w-340;
    positionReinitialiser.y = ecran->h-40;
    // Transparence du fond rose
    SDL_SetColorKey(resoudre, SDL_SRCCOLORKEY, SDL_MapRGB(resoudre->format, 255, 0, 255));
    SDL_SetColorKey(reinitialiser, SDL_SRCCOLORKEY, SDL_MapRGB(reinitialiser->format, 255, 0, 255));
    SDL_SetColorKey(retour, SDL_SRCCOLORKEY, SDL_MapRGB(retour->format, 255, 0, 255));
    SDL_SetColorKey(imprimante, SDL_SRCCOLORKEY, SDL_MapRGB(retour->format, 255, 0, 255));
    // Opacité de la grille
    SDL_SetAlpha(grille, SDL_SRCALPHA, 190);
    // On affiche les images
    SDL_BlitSurface(fondEcran, NULL, ecran, &positionFond);
    SDL_BlitSurface(grille, NULL, ecran, &positionGrille);
    SDL_BlitSurface(retour, NULL, ecran, &positionRetour);
    SDL_BlitSurface(resoudre, NULL, ecran, &positionResoudre);
    SDL_BlitSurface(reinitialiser, NULL, ecran, &positionReinitialiser);
    SDL_BlitSurface(imprimante, NULL, ecran, &positionImprimante);
    // Mise à jour de l'écran
    SDL_Flip(ecran);
    // On libère les surfaces
    SDL_FreeSurface(fondEcran);
    SDL_FreeSurface(grille);
    SDL_FreeSurface(retour);
    SDL_FreeSurface(resoudre);
    SDL_FreeSurface(reinitialiser);
    SDL_FreeSurface(imprimante);
}

/// Procédure qui affiche l'ensemble des chiffres d'une grille à l'écran de jeu
void afficherSolution(int grille[9][9][10], SDL_Surface *ecran)
{
    int ligne = 0, colonne = 0, decalageX = 0, decalageY = 0;
    char nomImage[17] = {'i','m','g','\\','c','h','i','f','f','r','e','0','.','b','m','p','\0'};
    SDL_Surface *chiffre = NULL;
    SDL_Rect positionChiffre;
    for(ligne=0; ligne<9; ligne++)
    {
        if(ligne>=6)
        {
            decalageY += 6;
        }
        else if(ligne>=3)
        {
            decalageY += 3;
        }
        for(colonne=0; colonne<9; colonne++)
        {
            if(grille[ligne][colonne][0]!=0)
            {
                nomImage[11] = grille[ligne][colonne][0]+48;
                chiffre = chargementBitmap(nomImage);
                if(colonne>=6)
                {
                    decalageX += 6;
                }
                else if(colonne>=3)
                {
                    decalageX += 3;
                }
                positionChiffre.x = 217+colonne*40+decalageX;
                positionChiffre.y = 117+ligne*40+decalageY;
                SDL_SetColorKey(chiffre, SDL_SRCCOLORKEY, SDL_MapRGB(chiffre->format, 255, 255, 255));
                SDL_BlitSurface(chiffre, NULL, ecran, &positionChiffre);
                SDL_Flip(ecran);
                decalageX = 0;
            }
        }
        decalageY = 0;
    }
    SDL_FreeSurface(chiffre);
}

#include "ecrans.h"

/// Écran principal
void ecranPrincipal(SDL_Surface *ecran, bool *finDuProgramme)
{
    // Chargement de l'image du fond d'écran
    SDL_Surface *fondEcran = chargementBitmap("img/fondEcran1.bmp");
    // Position du fond d'écran
    SDL_Rect positionFond;
    positionFond.x = 0;
    positionFond.y = 0;
    // Chargement de l'illustration de la Kafra
    SDL_Surface *kafraZoom = chargementBitmap("img/kafraZoom.bmp");
    // Position de l'illustration de la Kafra
    SDL_Rect positionKafraZoom;
    positionKafraZoom.x = ecran->w-kafraZoom->w;
    positionKafraZoom.y = ecran->h-kafraZoom->h;
    // Chargement de l'illustration de la bulle
    SDL_Surface *bulle = chargementBitmap("img/bulleAccueil.bmp");
    // Position de l'illustration de la bulle
    SDL_Rect positionBulle;
    positionBulle.x = ecran->w-bulle->w-kafraZoom->w;
    positionBulle.y = ecran->h-bulle->h;
    // Chargement du bouton "nouvelle partie"
    SDL_Surface *nouvellePartie = chargementBitmap("img/nouvellePartie.bmp");
    // Position du bouton
    SDL_Rect positionNouvellePartie;
    positionNouvellePartie.x = (ecran->w-nouvellePartie->w)/2;
    positionNouvellePartie.y = (ecran->h-5*nouvellePartie->h)/2;
    // Chargement du bouton "Reprendre une partie"
    SDL_Surface *chargerPartie = chargementBitmap("img/reprendrePartie.bmp");
    // Position du bouton
    SDL_Rect positionChargerPartie;
    positionChargerPartie.x = (ecran->w-chargerPartie->w)/2;
    positionChargerPartie.y = (ecran->h-chargerPartie->h)/2;
    // Chargement du bouton "Résoudre une grille"
    SDL_Surface *resoudreGrille = chargementBitmap("img/resoudreGrille.bmp");
    // Position du bouton
    SDL_Rect positionResoudreGrille;
    positionResoudreGrille.x = (ecran->w-resoudreGrille->w)/2;
    positionResoudreGrille.y = (ecran->h+3*resoudreGrille->h)/2;
    // Transparences
    SDL_SetColorKey(kafraZoom, SDL_SRCCOLORKEY, SDL_MapRGB(kafraZoom->format, 255, 0, 255));
    SDL_SetColorKey(nouvellePartie, SDL_SRCCOLORKEY, SDL_MapRGB(nouvellePartie->format, 255, 0, 255));
    SDL_SetColorKey(chargerPartie, SDL_SRCCOLORKEY, SDL_MapRGB(chargerPartie->format, 255, 0, 255));
    SDL_SetColorKey(resoudreGrille, SDL_SRCCOLORKEY, SDL_MapRGB(resoudreGrille->format, 255, 0, 255));
    SDL_SetColorKey(bulle, SDL_SRCCOLORKEY, SDL_MapRGB(bulle->format, 255, 0, 255));
    // On affiche les images dans cet ordre
    SDL_BlitSurface(fondEcran, NULL, ecran, &positionFond);
    SDL_BlitSurface(kafraZoom, NULL, ecran, &positionKafraZoom);
    SDL_BlitSurface(bulle, NULL, ecran, &positionBulle);
    SDL_BlitSurface(nouvellePartie, NULL, ecran, &positionNouvellePartie);
    SDL_BlitSurface(chargerPartie, NULL, ecran, &positionChargerPartie);
    SDL_BlitSurface(resoudreGrille, NULL, ecran, &positionResoudreGrille);
    // Mise à jour de l'écran
    SDL_Flip(ecran);
    // En attente d'événements
    attenteEcranPrincipal(ecran, finDuProgramme);
    // On libère les surfaces
    SDL_FreeSurface(fondEcran);
    SDL_FreeSurface(kafraZoom);
    SDL_FreeSurface(bulle);
    SDL_FreeSurface(nouvellePartie);
    SDL_FreeSurface(chargerPartie);
    SDL_FreeSurface(resoudreGrille);
}

/// Choix difficulté
void ecranChoixDifficulte(SDL_Surface *ecran, bool *finDuProgramme)
{
    // Chargement de l'image du fond d'écran
    SDL_Surface *fondEcran = chargementBitmap("img/fondEcranChoix.bmp");
    // Position du fond d'écran
    SDL_Rect positionFond;
    positionFond.x = 0;
    positionFond.y = 0;
    // Chargement de l'illustration de la Kafra
    SDL_Surface *kafraZoom = chargementBitmap("img/kafraZoom.bmp");
    // Position de l'illustration de la Kafra
    SDL_Rect positionKafraZoom;
    positionKafraZoom.x = ecran->w-kafraZoom->w;
    positionKafraZoom.y = ecran->h-kafraZoom->h;
    // Chargement de l'image du bouton retour
    SDL_Surface *retour = chargementBitmap("img/retour.bmp");
    // Position du bouton retour
    SDL_Rect positionRetour;
    positionRetour.x = 10;
    positionRetour.y = 10;
    // Chargement de la bulle
    SDL_Surface *bulle = chargementBitmap("img/bulleDifficulte.bmp");
    // Position de la bulle
    SDL_Rect positionBulle;
    positionBulle.x = ecran->w-bulle->w-kafraZoom->w;
    positionBulle.y = ecran->h-bulle->h;
    // Chargement du perso Facile
    SDL_Surface *persoFacile = chargementBitmap("img/persoFacile.bmp");
    // Position
    SDL_Rect positionPersoFacile;
    positionPersoFacile.x = 260;
    positionPersoFacile.y = 0.9*(ecran->h-persoFacile->h)/5;
    // Chargement du perso Moyen
    SDL_Surface *persoMoyen = chargementBitmap("img/persoMoyen.bmp");
    // Position
    SDL_Rect positionPersoMoyen;
    positionPersoMoyen.x = 260;
    positionPersoMoyen.y = 2.3*(ecran->h-persoMoyen->h)/5;
    // Chargement du perso Difficile
    SDL_Surface *persoDifficile = chargementBitmap("img/persoDifficile.bmp");
    // Position
    SDL_Rect positionPersoDifficile;
    positionPersoDifficile.x = 260;
    positionPersoDifficile.y = 3.5*(ecran->h-persoDifficile->h)/5;
    // Chargement du bouton facile
    SDL_Surface *facile = chargementBitmap("img/facile.bmp");
    // Position
    SDL_Rect positionFacile;
    positionFacile.x = 325;
    positionFacile.y = (ecran->h-facile->h)/5;
    // Chargement du bouton difficile
    SDL_Surface *difficile = chargementBitmap("img/difficile.bmp");
    // Position
    SDL_Rect positionDifficile;
    positionDifficile.x = 325;
    positionDifficile.y = 3.5*(ecran->h-difficile->h)/5;
    // Chargement du bouton moyen
    SDL_Surface *moyen = chargementBitmap("img/moyen.bmp");
    // Position
    SDL_Rect positionMoyen;
    positionMoyen.x = 325;
    positionMoyen.y = 2.25*(ecran->h-moyen->h)/5;
    // Transparences
    SDL_SetColorKey(kafraZoom, SDL_SRCCOLORKEY, SDL_MapRGB(kafraZoom->format, 255, 0, 255));
    SDL_SetColorKey(bulle, SDL_SRCCOLORKEY, SDL_MapRGB(bulle->format, 255, 0, 255));
    SDL_SetColorKey(retour, SDL_SRCCOLORKEY, SDL_MapRGB(retour->format, 255, 0, 255));
    SDL_SetColorKey(persoDifficile, SDL_SRCCOLORKEY, SDL_MapRGB(persoDifficile->format, 255, 0, 255));
    SDL_SetColorKey(persoFacile, SDL_SRCCOLORKEY, SDL_MapRGB(persoFacile->format, 255, 0, 255));
    SDL_SetColorKey(persoMoyen, SDL_SRCCOLORKEY, SDL_MapRGB(persoMoyen->format, 255, 0, 255));
    SDL_SetColorKey(difficile, SDL_SRCCOLORKEY, SDL_MapRGB(difficile->format, 255, 0, 255));
    SDL_SetColorKey(facile, SDL_SRCCOLORKEY, SDL_MapRGB(facile->format, 255, 0, 255));
    SDL_SetColorKey(moyen, SDL_SRCCOLORKEY, SDL_MapRGB(moyen->format, 255, 0, 255));
    // On affiche les images
    SDL_BlitSurface(fondEcran, NULL, ecran, &positionFond);
    SDL_BlitSurface(kafraZoom, NULL, ecran, &positionKafraZoom);
    SDL_BlitSurface(bulle, NULL, ecran, &positionBulle);
    SDL_BlitSurface(retour, NULL, ecran, &positionRetour);
    SDL_BlitSurface(persoDifficile, NULL, ecran, &positionPersoDifficile);
    SDL_BlitSurface(persoFacile, NULL, ecran, &positionPersoFacile);
    SDL_BlitSurface(persoMoyen, NULL, ecran, &positionPersoMoyen);
    SDL_BlitSurface(difficile, NULL, ecran, &positionDifficile);
    SDL_BlitSurface(facile, NULL, ecran, &positionFacile);
    SDL_BlitSurface(moyen, NULL, ecran, &positionMoyen);
    // Mise à jour de l'écran
    SDL_Flip(ecran);
    // En attente d'événements
    attenteEcranChoix(ecran, finDuProgramme);
    // On libère les surfaces
    SDL_FreeSurface(retour);
    SDL_FreeSurface(fondEcran);
    SDL_FreeSurface(kafraZoom);
    SDL_FreeSurface(bulle);
    SDL_FreeSurface(persoDifficile);
    SDL_FreeSurface(persoFacile);
    SDL_FreeSurface(persoMoyen);
    SDL_FreeSurface(difficile);
    SDL_FreeSurface(facile);
    SDL_FreeSurface(moyen);
}

/// Écran de jeu
void ecranJouer(SDL_Surface *ecran, bool *finDuProgramme, int niveau)
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
    // Soit on créer une nouvelle partie si un niveau a été choisi soit on reprend la partie précédente
    int grilleSudoku[9][9][10] = {{{0}}};
    if(niveau!=0)
    {
        generateur(grilleSudoku, &niveau);
    }
    else
    {
        char nomDuFichier[TAILLE_MAX] = "sauvegarde.sdk";
        FILE *fichier = lectureFichier(nomDuFichier);
        importationGrille(fichier, grilleSudoku);
    }
    // On affiche les solutions à l'écran
    afficherSolution(grilleSudoku, ecran);
    // En attente d'événements
    attenteEcranJouer(ecran, grille, grilleSudoku, finDuProgramme);
    // On libère les surfaces
    SDL_FreeSurface(fondEcran);
    SDL_FreeSurface(grille);
    SDL_FreeSurface(retour);
    SDL_FreeSurface(resoudre);
    SDL_FreeSurface(reinitialiser);
    SDL_FreeSurface(imprimante);
}

/// Écran de "Résoudre une grille"
void ecranResolveur(SDL_Surface *ecran, bool *finDuProgramme)
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
    // En attente d'événements
    attenteEcranResolveur(ecran, grille, finDuProgramme);
    // On libère les surfaces
    SDL_FreeSurface(fondEcran);
    SDL_FreeSurface(grille);
    SDL_FreeSurface(retour);
    SDL_FreeSurface(imprimante);
    SDL_FreeSurface(resoudre);
    SDL_FreeSurface(reinitialiser);
}

// Écran de la défaite
void ecranPerdu(SDL_Surface *ecran, bool *finDuProgramme)
{
    // Chargement de l'image du bouton retour
    SDL_Surface *retour = chargementBitmap("img/retour.bmp");
    // Position du bouton
    SDL_Rect positionRetour;
    positionRetour.x = 10;
    positionRetour.y = 10;
    // Chargement du fond
    SDL_Surface *defaite = chargementBitmap("img/defaite.bmp");
    // Position
    SDL_Rect positionDefaite;
    positionDefaite.x = 0;
    positionDefaite.y = 0;
    // Transparence
    SDL_SetColorKey(retour, SDL_SRCCOLORKEY, SDL_MapRGB(retour->format, 255, 0, 255));
    // Affichage
    SDL_BlitSurface(defaite, NULL, ecran, &positionDefaite);
    SDL_BlitSurface(retour, NULL, ecran, &positionRetour);
    // mise à jour écran
    SDL_Flip(ecran);
    // Libération des surfaces
    SDL_FreeSurface(defaite);
    SDL_FreeSurface(retour);
    // Attente événements
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
            // Bouton "retour"
            if(event.button.x>=19&&event.button.x<=76&&event.button.y>=19&&event.button.y<=45)
            {
                ecranPrincipal(ecran, finDuProgramme);
            }
            break;
        }
    }
}

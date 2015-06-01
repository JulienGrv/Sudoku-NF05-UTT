#include "main.h"

int main(int argc, char* argv[])
{
    // On initialise la SDL
    initialisationSDL();
    // Chargement de l'icône de la fenêtre
    SDL_WM_SetIcon(SDL_LoadBMP("img/icone.bmp"), NULL);
    // On charge la fenêtre à l'écran
    SDL_Surface *ecran = creationEcran(800, 600);
    // On donne un titre à notre fenêtre
    SDL_WM_SetCaption("Sudok'utt !", NULL);
    // Booléen qui permet de savoir s'il faut arrêter le programme ou non
    bool finDuProgramme = false;
    // On charge l'écran principal
    ecranPrincipal(ecran, &finDuProgramme);
    // Arrêt de la SDL
    SDL_Quit();
    return EXIT_SUCCESS;
}

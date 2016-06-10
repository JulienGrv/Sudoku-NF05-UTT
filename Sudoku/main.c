#include "main.h"

int main(int argc, char *argv[])
{
  // On initialise la SDL
  initialisationSDL();

  // Chargement de l'ic�ne de la fen�tre
  SDL_WM_SetIcon(SDL_LoadBMP("img/icone.bmp"), NULL);

  // On charge la fen�tre � l'�cran
  SDL_Surface *ecran = creationEcran(800, 600);

  // On donne un titre � notre fen�tre
  SDL_WM_SetCaption("Sudok'utt !", NULL);

  // Bool�en qui permet de savoir s'il faut arr�ter le programme ou non
  bool finDuProgramme = false;

  // On charge l'�cran principal
  ecranPrincipal(ecran, &finDuProgramme);

  // Arr�t de la SDL
  SDL_Quit();
  return EXIT_SUCCESS;
}

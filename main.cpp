#include "SDL.H"
#include <string>

using namespace std:string;

int main(int argc, char* args[])
{
	//images
	SDL_Surface* hello = NULL;
	SDL_Surface* screen = NULL;

	//Start SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//setup screen
	screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);

	//load image
	hello = SDL_LoadBMP("Hello.bmp");

	//apply image to the screen
	SDL_BlitSurface(hello, NULL, screen, NULL);

	//update the screen
	SDL_Flip(screen);

	//pause
	SDL_Delay(5000);

	//free the loaded image
	SDL_FreeSurface(hello);

	//Quit SDL
	SDL_Quit();

	return 0;
}
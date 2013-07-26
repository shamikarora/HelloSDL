#include "SDL.H"

const float ASPECT_RATIO = 16.0f / 9.0f;
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = ((float) WINDOW_WIDTH) / ASPECT_RATIO;

int main(int argc, char* args[])
{
	//images
	SDL_Surface* hello = NULL;
	SDL_Surface* screen = NULL;

	//Start SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//setup screen
	screen = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32, SDL_SWSURFACE);

	// Load the background image
	hello = SDL_LoadBMP("Resources/gameBackground.bmp");

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

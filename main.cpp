#include "SDL.H"

const float ASPECT_RATIO = 16.0f / 9.0f;
const int WINDOW_WIDTH = 1200;
const int WINDOW_HEIGHT = ((float) WINDOW_WIDTH) / ASPECT_RATIO;

const char* backgroundImageLocation = "Resources/gameBackground.bmp";
const char* paddleImageLocation = "Resources/paddle.bmp";

SDL_Rect paddleOneDestRect = {100, 100, 0, 0};
SDL_Rect paddleTwoDestRect = {(WINDOW_WIDTH - 100), 100, 0, 0};

int main(int argc, char* args[])
{
	//Start SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	//setup screen
	SDL_Surface* screen = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32, SDL_SWSURFACE);

	// Load the background image
	SDL_Surface* hello = SDL_LoadBMP(backgroundImageLocation);

	// Load the paddle
	SDL_Surface* paddleOne = SDL_LoadBMP(paddleImageLocation);
	SDL_Surface* paddleTwo = SDL_LoadBMP(paddleImageLocation);

	//apply image to the screen
	SDL_BlitSurface(hello, NULL, screen, NULL);
	
	//apply paddle to the screen
	SDL_BlitSurface(paddleOne, NULL, screen, &paddleOneDestRect);
	SDL_BlitSurface(paddleTwo, NULL, screen, &paddleTwoDestRect);

	//update the screen
	SDL_Flip(screen);

	//pause
	SDL_Delay(5000);

	//free the loaded image
	SDL_FreeSurface(hello);
	SDL_FreeSurface(paddleOne);
	SDL_FreeSurface(paddleTwo);

	//Quit SDL
	SDL_Quit();

	return 0;
}

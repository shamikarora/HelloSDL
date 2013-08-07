#include "SDL.h"
#include "SDL_image.h"
#include "Paddle.h"
#include "Background.h"
#include "Constants.h"

using namespace PaddleGame;
SDL_Surface* screen = NULL;

void InitializeGame()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_SWSURFACE);
}

void EndGame()
{
	SDL_Quit();
}

int main(int argc, char* argv[])
{
	InitializeGame();
	
	Paddle *paddle = new Paddle("Resources/paddle.bmp");
	Background *background = new Background("Resources/gameBackground.bmp");
	
	background->Display(0,0,screen);
	paddle->Display(50,50,screen);
	paddle->Display(590,50,screen);

	SDL_Flip(screen);
	SDL_Delay(2000);
	
	EndGame();

	
		return 0;
}

#include "SDL.h"
#include "SDL_image.h"
#include "Paddle.h"
#include "Background.h"
#include "Constants.h"
#include "Timer.h"

using namespace PaddleGame;
SDL_Surface* screen = NULL;

void InitializeGame()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	screen = SDL_SetVideoMode(SCREEN_WIDTH,SCREEN_HEIGHT,SCREEN_BPP,SDL_SWSURFACE);
	SDL_WM_SetCaption("PaddleGame", NULL);
}

void EndGame()
{
	SDL_Quit();
}

int main(int argc, char* argv[])
{
	bool play = true;

	//Setup game screen
	InitializeGame();
	
	//Load sprite images
	Paddle *paddle1 = new Paddle("Resources/paddle.bmp");
	Paddle *paddle2 = new Paddle("Resources/paddle.bmp");
	Background *background = new Background("Resources/gameBackground.bmp");
	background->Display(0,0,screen);
	
	Timer frameRateRegulator;
	SDL_Event event;

	while(play == true)
	{
		frameRateRegulator.start();

		//while there are events to handle
		while(SDL_PollEvent(&event))
		{
			paddle1->HandleInput(&event);

			//If the user has Xed out the window
            if( event.type == SDL_QUIT )
            {
                //Quit the program
                play = false;
            }
		}
		
		//Move the paddle
		paddle1->Move();

		background->Display(0,0,screen);
		//SDL_FillRect( screen, &screen->clip_rect, SDL_MapRGB( screen->format, 0xFF, 0xFF, 0xFF ) );

		//Show the paddle
		paddle1->Display(paddle1->CurrentPosX(), paddle1->CurrentPosY(), screen);

		//Update the screen
        if( SDL_Flip( screen ) == -1 )
        {
            return 1;
        }

        //Cap the frame rate
      
  if( frameRateRegulator.get_ticks() < 1000 / FRAMES_PER_SECOND )
        {
            SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - 
frameRateRegulator.get_ticks() );
        }
	}
	
	//Quit game
	EndGame();

	
		return 0;
}

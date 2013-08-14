#include "GameEngine.h"

namespace PaddleGame
{
	GameEngine::GameEngine()
	{
		play = true;
		screenDisplay = NULL;
	}

	bool GameEngine::Init()
	{
		//Set the window screen
		if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
			return false;

		screenDisplay = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

		if(screenDisplay == NULL)
			return false;

		SDL_WM_SetCaption("PaddleGame", NULL);

		//Load sprite images
		paddle1 = new Paddle("Resources/paddle.bmp");
		background = new Background("Resources/gameBackground.bmp");

		return true;
	}

	void GameEngine::HandleEvents(SDL_Event * event)
	{
		paddle1->HandleInput(event);

		if(event->type == SDL_QUIT)
			play = false;
	}

	void GameEngine::GameLoop()
	{
		paddle1->Move();
	}

	void GameEngine::Render()
	{
		background->Display(screenDisplay);
		paddle1->Display(screenDisplay);

		SDL_Flip(screenDisplay);
	}

	void GameEngine::CleanUp()
	{
		SDL_FreeSurface(screenDisplay);
		SDL_Quit();
	}

	int GameEngine::Execute()
	{
		if(Init() == false)
			return -1;

		while(play)
		{
			//Start the frame timer
			fps.start();

			while(SDL_PollEvent(&myEvent))
			{
				HandleEvents(&myEvent);
			}

			GameLoop();
			Render();

			//Cap the frame rate
			if( fps.get_ticks() < 1000 / FRAMES_PER_SECOND )
			{
				SDL_Delay( ( 1000 / FRAMES_PER_SECOND ) - fps.get_ticks() );
			}
		}

		CleanUp();

	}
}
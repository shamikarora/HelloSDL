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
		paddle1 = new Paddle("Resources/paddle.bmp", 50, 50);
		paddle2 = new Paddle("Resources/paddle.bmp",SCREEN_WIDTH - (PADDLE_WIDTH + 50), 50);
		ball = new Ball("Resources/ball.bmp", (SCREEN_WIDTH - BALL_WIDTH)/2, (SCREEN_HEIGHT - BALL_HEIGHT)/2);
		background = new Background("Resources/gameBackground.bmp");

		return true;
	}

	void GameEngine::HandleEvents(SDL_Event * event)
	{
		switch(event->type)
		{

		case SDL_KEYDOWN : 
			switch(event->key.keysym.sym)
			{
			//Controls for first paddle
			case SDLK_w : paddle1->HandleInput(event);
						  break;
			case SDLK_s : paddle1->HandleInput(event);
						  break;

			//Controls for second paddle
			case SDLK_UP : paddle2->HandleInput(event);
						   break;
			case SDLK_DOWN : paddle2->HandleInput(event);
						   break;
			}
			break;

		case SDL_KEYUP : 
			switch(event->key.keysym.sym)
			{
			//Controls for first paddle
			case SDLK_w : paddle1->HandleInput(event);
						  break;
			case SDLK_s : paddle1->HandleInput(event);
						  break;

			//Controls for second paddle
			case SDLK_UP : paddle2->HandleInput(event);
						   break;
			case SDLK_DOWN : paddle2->HandleInput(event);
			}
			break;
		
		case SDL_QUIT : play = false;
						break;
		}
	}

	void GameEngine::GameLoop()
	{
		paddle1->Move();
		paddle2->Move();
		ball->Move();
	}

	void GameEngine::HandleCollisions()
	{
		ball->HandleCollisionWrapper(paddle1, paddle2);
	}

	void GameEngine::Render()
	{
		background->Display(screenDisplay);
		paddle1->Display(screenDisplay);
		paddle2->Display(screenDisplay);
		ball->Display(screenDisplay);

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
			HandleCollisions();
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

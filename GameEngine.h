#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Paddle.h"
#include "Background.h"
#include "Constants.h"
#include "Timer.h"

namespace PaddleGame
{
	class GameEngine
	{

		private:
			//Game play variable
			bool play;

			//SDL Surfaces
			SDL_Surface* screenDisplay;

			//Handle Events
			SDL_Event myEvent;

			//Sprites
			Paddle* paddle1;
			Background* background;


		private: 
			bool Init();
			void HandleEvents(SDL_Event*);
			void GameLoop();
			void Render();
			void CleanUp();

		public:
			GameEngine();
			int Execute();

			
	};
}
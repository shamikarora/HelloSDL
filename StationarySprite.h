#pragma once

#include "Sprite.h"

namespace PaddleGame
{
	class StationarySprite : public Sprite
	{
		public:

			StationarySprite()
			{
				x = 0;
				y = 0;
			
				xVel = 0;
				yVel = 0;
			}
<<<<<<< HEAD

			virtual void HandleInput(SDL_Event*) {}
=======
			virtual void HandleInput(SDL_Event *) {}

>>>>>>> Crap
			virtual void Display(SDL_Surface*) {}
	};
}
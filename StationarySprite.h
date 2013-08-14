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
			virtual void HandleInput(SDL_Event *) {}

			virtual void Display(SDL_Surface*) {}
	};
}
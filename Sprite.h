#pragma once
#include "RenderImage.h"

namespace PaddleGame
{
	class Sprite
	{
		protected: 
			RenderImage *renderImage;

			//Current position of a sprite
			int x;
			int y;

			//Velocity of a sprite
			int xVel;
			int yVel;

		public:

			//Display a sprite at a particular position
			virtual void Display(SDL_Surface*) = 0;
					virtual void HandleInput(SDL_Event *) = 0;

			//Get the current x co-ordinate of the sprite
			int GetXPosition()
			{
				return x;
			}

			//Get the current y co-ordinate of the sprite
			int GetYPosition()
			{
				return y;
			}

	};
}
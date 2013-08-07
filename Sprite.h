#pragma once
#include "RenderImage.h"

namespace PaddleGame
{
	class Sprite
	{
		protected: 
			RenderImage *renderImage;

		public:
			//Sprite can move or be stationary
			virtual void Move() = 0;

			//Display a sprite at a particular position
			virtual void Display(int, int,SDL_Surface*) = 0;

	};
}
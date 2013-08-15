#pragma once

#include "MoveableSprite.h"
#include <iostream>

namespace PaddleGame
{
	class Paddle : public MoveableSprite
	{

	protected:

	public:
		Paddle(std::string imageFileName, int x = 0, int y = 0)
		{
			this->x = x;
			this->y = y;
			renderImage = new RenderImage(imageFileName);
			renderImage->LoadImage();
		}

		virtual void HandleInput(SDL_Event*);
		virtual void Move();
		virtual void Display(SDL_Surface*);

		~Paddle()
		{
			delete renderImage;
		}
	};
}
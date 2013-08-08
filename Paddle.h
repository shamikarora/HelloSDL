#pragma once

#include "MoveableSprite.h"
#include <iostream>

namespace PaddleGame
{
	class Paddle : public MoveableSprite
	{
	
	protected:

	public:
		Paddle(std::string imageFileName)
		{
			renderImage = new RenderImage(imageFileName);
			renderImage->LoadImage();
		}

		virtual void HandleInput(SDL_Event *);
		virtual void Move();
		virtual void Display(SDL_Surface*);

		~Paddle()
		{
			delete renderImage;
		}
	};
}
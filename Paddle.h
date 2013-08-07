#pragma once

#include "Sprite.h"
#include <iostream>

namespace PaddleGame
{
	class Paddle : public Sprite
	{
	
	protected:

	public:
		Paddle(std::string imageFileName)
		{
			renderImage = new RenderImage(imageFileName);
			renderImage->LoadImage();
		}

		void Move();
		void Display(int, int,SDL_Surface*);

		~Paddle()
		{
			delete renderImage;
		}
	};
}
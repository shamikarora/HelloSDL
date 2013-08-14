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
<<<<<<< HEAD

		virtual void HandleInput(SDL_Event *);
=======
		
		virtual void HandleInput(SDL_Event*);
>>>>>>> Crap
		virtual void Move();
		virtual void Display(SDL_Surface*);

		~Paddle()
		{
			delete renderImage;
		}
	};
}
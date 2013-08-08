#pragma once

#include "MoveableSprite.h"
#include <iostream>

namespace PaddleGame
{
	class Paddle : public MoveableSprite
	{
	
	protected:
		MoveableSprite * moveSprite;

	public:
		Paddle(std::string imageFileName)
		{
			renderImage = new RenderImage(imageFileName);
			renderImage->LoadImage();
			moveSprite = new MoveableSprite();
		}

		virtual void HandleInput(SDL_Event *);
		virtual void Move();
		virtual void Display(int, int,SDL_Surface*);

		int CurrentPosX();
		int CurrentPosY();
		
		~Paddle()
		{
			delete renderImage;
			delete moveSprite;
		}
	};
}
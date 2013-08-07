#pragma once

#include "StationarySprite.h"
#include <iostream>

namespace PaddleGame
{
	class Background : public StationarySprite
	{
	
	protected:

	public:
		Background(std::string imageFileName)
		{
			renderImage = new RenderImage(imageFileName);
			renderImage->LoadImage();
		}

		virtual void HandleInput(SDL_Event&);
		virtual void Move();
		virtual void Display(int, int,SDL_Surface*);

		~Background()
		{
			delete renderImage;
		}
	};
}
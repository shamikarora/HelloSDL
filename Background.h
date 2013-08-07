#pragma once

#include "Sprite.h"
#include <iostream>

namespace PaddleGame
{
	class Background : public Sprite
	{
	
	protected:

	public:
		Background(std::string imageFileName)
		{
			renderImage = new RenderImage(imageFileName);
			renderImage->LoadImage();
		}

		void Move();
		void Display(int, int,SDL_Surface*);

		~Background()
		{
			delete renderImage;
		}
	};
}
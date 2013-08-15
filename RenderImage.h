#pragma once
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

namespace PaddleGame
{
	class RenderImage
	{
		protected:
			std::string imageFileName;

			//Optimized image that will be used
			SDL_Surface* optimizedImage;

		public:
			//Load an image
			SDL_Surface* LoadImage();

			//Get the loaded image
			SDL_Surface* GetImage();

			//Apply an image on a surface
			void ApplyImage(int x, int y,SDL_Surface * source, SDL_Surface * destination, SDL_Rect * clip = NULL);

			RenderImage(std::string imageFileName) : imageFileName(imageFileName){}

			~RenderImage(){}
	};
}

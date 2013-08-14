#include "RenderImage.h"

namespace PaddleGame
{

		SDL_Surface* RenderImage::LoadImage()
		{
			//Image that will be loaded
			SDL_Surface* loadedImage = NULL;

			optimizedImage = NULL;

			loadedImage = IMG_Load(imageFileName.c_str());

			//If the image loaded
			if(loadedImage != NULL)
			{
				//create an optimized image
				optimizedImage = SDL_DisplayFormat(loadedImage);

				//Free the old image
				SDL_FreeSurface(loadedImage);
			}

			return optimizedImage;
		}
		

		void RenderImage::ApplyImage(int x, int y ,SDL_Surface* source,SDL_Surface*destination, SDL_Rect* clip)
		{
			//holds offsets
			SDL_Rect offset;

			offset.x = x;
			offset.y = y;

			SDL_BlitSurface(source, clip, destination, &offset);
		}

		SDL_Surface* RenderImage::GetImage()
		{
			return optimizedImage;
		}
}
#include "Paddle.h"
#include "Constants.h"

namespace PaddleGame
{
	void Paddle::Display(int x, int y, SDL_Surface* destination)
	{
		SDL_Surface* loadedImage = renderImage->GetImage();

		renderImage->ApplyImage(x,y,loadedImage,destination);
	}

	void Paddle::Move()
	{
	
	}
}
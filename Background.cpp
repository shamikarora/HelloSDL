#include "Background.h"
#include "Constants.h"

namespace PaddleGame
{
	void Background::Display(int x, int y, SDL_Surface* destination)
	{
		SDL_Surface* loadedImage = renderImage->GetImage();

		renderImage->ApplyImage(x,y,loadedImage,destination);
	}

	void Background::Move()
	{
		
	}

	void Background::HandleInput(SDL_Event *)
	{
	
	}
}
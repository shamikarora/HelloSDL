#include "Paddle.h"
#include "Constants.h"

namespace PaddleGame
{
	void Paddle::Display(SDL_Surface* destination)
	{
		SDL_Surface* loadedImage = renderImage->GetImage();

		renderImage->ApplyImage(x,y,loadedImage,destination);
	}

	void Paddle::HandleInput(SDL_Event *event)
	{
		//If a key was pressed
		if( event->type == SDL_KEYDOWN )
		{
			//Adjust the velocity
			switch( event->key.keysym.sym )
			{
				case SDLK_w: yVel -= UPWARD_VELOCITY; break;
				case SDLK_s: yVel += DOWNWARD_VELOCITY; break;
				
				case SDLK_UP    : yVel -= UPWARD_VELOCITY; break;
				case SDLK_DOWN  : yVel += DOWNWARD_VELOCITY; break;
			}
		}
		//If a key was released
		else if( event->type == SDL_KEYUP )
		{
			//Adjust the velocity
			switch( event->key.keysym.sym )
			{
				case SDLK_w: yVel += UPWARD_VELOCITY; break;
				case SDLK_s: yVel -= DOWNWARD_VELOCITY; break;

				case SDLK_UP    : yVel += UPWARD_VELOCITY; break;
				case SDLK_DOWN  : yVel -= DOWNWARD_VELOCITY; break;
			}
		}
	}

	void Paddle::Move()
	{
		//Move the dot left or right
				x += xVel;

		//If the dot went too far to the left or right
		if( ( x < 0 ) || ( (x + PADDLE_WIDTH) > SCREEN_WIDTH ) )
		{
			//move back
			if(x < 0)
				x = 0;

			if(x + PADDLE_WIDTH > SCREEN_WIDTH)
				x = SCREEN_WIDTH - PADDLE_WIDTH;
		}

		//Move the dot up or down
		y += yVel;

		//If the dot went too far up or down
		if( ( y < 0 ) || ( (y + PADDLE_HEIGHT) > SCREEN_HEIGHT ) )
		{
			//move back
			if(y < 0)
				y = 0;

			if(y + PADDLE_HEIGHT > SCREEN_HEIGHT)
				y = SCREEN_HEIGHT - PADDLE_HEIGHT;
		}
	}
}
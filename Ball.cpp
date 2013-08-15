#include "Ball.h"

namespace PaddleGame
{
	void Ball::Display(SDL_Surface* destination)
	{
		SDL_Surface* loadedImage = renderImage->GetImage();

		renderImage->ApplyImage(x,y,loadedImage,destination);
	}

	void Ball::Move()
	{
		x += xVel;
		y += yVel;
	}

	void Ball::HandleCollisions()
	{
		//Bounce the ball off the top/bottom screen
		if(y <= 0 || (y+BALL_HEIGHT) >= SCREEN_HEIGHT)
		{
			yVel*= -1;
			y+= yVel;
		}

		//Bounce the ball off the left/right screen
		if(x <=0 || (x + BALL_WIDTH) >= SCREEN_WIDTH)
		{
			xVel *= -1;
			x += xVel;
		}
	}
}
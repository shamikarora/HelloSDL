#include "Ball.h"
#include <iostream>

using namespace std;

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

	void Ball::HandleCollisionWithScreen()
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

	void Ball::HandleCollisionWithPaddles(Paddle* paddleOne, Paddle* paddleTwo)
	{
		if ((((x - (paddleOne->GetXPosition() + PADDLE_WIDTH)) <= 1) && (y > paddleOne->GetYPosition()) && (y < (paddleOne->GetYPosition() + PADDLE_HEIGHT))) ||
			(((paddleTwo->GetXPosition() - (x + BALL_WIDTH)) <= 1) && (y > paddleTwo->GetYPosition()) && (y < (paddleTwo->GetYPosition() + PADDLE_HEIGHT))))	
		{
			xVel *= -1;
			x += xVel;
		}
	}

	void Ball::HandleCollisionWrapper(Paddle* paddleOne, Paddle* paddleTwo)
	{
		Ball::HandleCollisionWithScreen();
		Ball::HandleCollisionWithPaddles(paddleOne, paddleTwo);
	}
}

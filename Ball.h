#pragma once
#include "MoveableSprite.h"
#include "Constants.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include "Paddle.h"

namespace PaddleGame
{
	class Ball : public MoveableSprite
	{

		private : 

			float direction; //in degrees 
			void HandleCollisionWithScreen();
			void HandleCollisionWithPaddles(Paddle* paddleOne, Paddle* paddleTwo);
			 
		public:
			Ball(std::string imageFileName, int x = 0, int y = 0 )
			{
				this->x = x;
				this->y = y;
				renderImage = new RenderImage(imageFileName);
				renderImage->LoadImage();

				//Assign a random direction everytime a ball is created
				srand(time(0));
				direction =(float) (rand() % 360 + 30);

				//Get the horizontal and vertical component of the ball velocity
				xVel = BALL_SPEED * cos(direction);
				yVel = BALL_SPEED * sin(direction);
			}

			void HandleCollisionWrapper(Paddle* paddleOne, Paddle* paddleTwo);
			virtual void HandleInput(SDL_Event*) {}
			virtual void Move();
			virtual void Display(SDL_Surface*);

			~Ball()
			{
				delete renderImage;
			}
	};
}

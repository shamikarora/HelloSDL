#pragma once

#include "Sprite.h"
#include "Timer.h"

namespace PaddleGame
{
	class MoveableSprite : public Sprite
	{
	protected:
		//Current position of a sprite
			int x;
			int y;

		//Velocity of a sprite
		int xVel;
		int yVel;

	public:
		MoveableSprite() 
		{
			x = 0;
			y = 0;
			
			xVel = 0;
			yVel = 0;
		}

		virtual void Move() {}
		virtual void Display(int, int, SDL_Surface*) {}
		virtual void HandleInput(SDL_Event *) {}

		int GetXPosition()
		{
			return x;
		}

		int GetYPosition()
		{
			return y;
		}

		virtual ~MoveableSprite()
		{}
	};
}
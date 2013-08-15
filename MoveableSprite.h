#pragma once

#include "StationarySprite.h"
#include "Timer.h"

namespace PaddleGame
{
	class MoveableSprite : public StationarySprite
	{
	protected:

	public:

		virtual void Move() = 0;
		virtual void Display(SDL_Surface*) {}
		virtual void HandleInput(SDL_Event *) {}

		virtual ~MoveableSprite()
		{}
	};
}
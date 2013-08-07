#pragma once

#include "Sprite.h"

namespace PaddleGame
{
	class StationarySprite : public Sprite
	{
		public:
			virtual void Move() {}
			virtual void Display(int, int ,SDL_Surface*) {}
	};
}
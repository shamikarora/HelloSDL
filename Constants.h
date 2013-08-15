#pragma once
#include "SDL.h"

namespace PaddleGame
{
		enum ScreenAttributes
		{
			SCREEN_WIDTH = 640,
			SCREEN_HEIGHT = 480,
			SCREEN_BPP = 32,
			FRAMES_PER_SECOND = 30,
			PADDLE_HEIGHT = 90,
			PADDLE_WIDTH = 30,
			UPWARD_VELOCITY = 10,
			DOWNWARD_VELOCITY = 10,
			LEFT_VELOCITY = 10,
			RIGHT_VELOCITY = 10
		};
}
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
			PADDLE_SPEED = 10,
			BALL_WIDTH = 20,
			BALL_HEIGHT = 20,
			BALL_SPEED = 10
		};
}
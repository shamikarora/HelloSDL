#pragma once
#include "GameEngine.h"

namespace PaddleGame
{
	class Game
	{
		GameEngine *gameEngine;
		public:
			Game()
			{
				gameEngine = new GameEngine();
			}

			int Start()
			{
				return gameEngine->Execute();
			}

			~Game()
			{
				delete gameEngine;
			}
	};
}
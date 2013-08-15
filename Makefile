SDLMain.o :
	g++ -c SDLMain.m

Game.o : Game.h GameEngine.h
	g++ -c -I/Library/Frameworks/SDL.Framework/Versions/A/Headers/ -I/Library/Frameworks/SDL_image.Framework/Versions/A/Headers/ Game.cpp

GameEngine.o : Paddle.h Background.h Constants.h Timer.h 
	g++ -c -I/Library/Frameworks/SDL.Framework/Versions/A/Headers/ -I/Library/Frameworks/SDL_image.Framework/Versions/A/Headers/ GameEngine.cpp

Background.o : Background.h Constants.h StationarySprite.h
	g++ -c -I/Library/Frameworks/SDL.Framework/Versions/A/Headers/ -I/Library/Frameworks/SDL_image.Framework/Versions/A/Headers/ Background.cpp

Paddle.o : Paddle.h Constants.h MoveableSprite.h StationarySprite.h Timer.h RenderImage.h
	g++ -c -I/Library/Frameworks/SDL.Framework/Versions/A/Headers/ -I/Library/Frameworks/SDL_image.Framework/Versions/A/Headers/ Paddle.cpp

RenderImage.o : RenderImage.h
	g++ -c -I/Library/Frameworks/SDL.Framework/Versions/A/Headers/ -I/Library/Frameworks/SDL_image.Framework/Versions/A/Headers/ RenderImage.cpp

Timer.o : Timer.h
	g++ -c -I/Library/Frameworks/SDL.Framework/Versions/A/Headers/ Timer.cpp

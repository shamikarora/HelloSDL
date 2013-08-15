program: Game.o SDLMain.o GameEngine.o Background.o Paddle.o RenderImage.o Timer.o 
	g++ Game.o SDLMain.o GameEngine.o Background.o Paddle.o RenderImage.o Timer.o -o SDLGame -framework SDL -framework Cocoa -framework SDL_image

Game.o : Game.h GameEngine.h
	g++ -c -I/Library/Frameworks/SDL.Framework/Versions/A/Headers/ -I/Library/Frameworks/SDL_image.Framework/Versions/A/Headers/ Game.cpp

SDLMain.o :
	g++ -c -I/Library/Frameworks/SDL.Framework/Versions/A/Headers/ SDLMain.m

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

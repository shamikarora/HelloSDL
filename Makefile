CC = g++
CFLAGS = -c

INCLUDE_SDL_PATH = -I/Library/Frameworks/SDL.Framework/Versions/A/Headers/
INCLUDE_SDL_IMAGE_PATH = -I/Library/Frameworks/SDL_image.Framework/Versions/A/Headers/

FRAMEWORKS = -framework SDL -framework Cocoa -framework SDL_image

EXECUTABLE_NAME = SDLGame

program: Game.o SDLMain.o GameEngine.o Background.o Paddle.o RenderImage.o Timer.o Ball.o
	$(CC) Game.o SDLMain.o GameEngine.o Background.o Paddle.o RenderImage.o Timer.o Ball.o -o $(EXECUTABLE_NAME) $(FRAMEWORKS)

Ball.o : Ball.h MoveableSprite.h Constants.h
	$(CC) $(CFLAGS) $(INCLUDE_SDL_PATH) $(INCLUDE_SDL_IMAGE_PATH) Ball.cpp

Game.o : Game.h GameEngine.h
	$(CC) $(CFLAGS) $(INCLUDE_SDL_PATH) $(INCLUDE_SDL_IMAGE_PATH) Game.cpp

SDLMain.o :
	$(CC) $(CFLAGS) $(INCLUDE_SDL_PATH) SDLMain.m

GameEngine.o : Paddle.h Background.h Constants.h Timer.h Ball.h
	$(CC) $(CFLAGS) $(INCLUDE_SDL_PATH) $(INCLUDE_SDL_IMAGE_PATH) GameEngine.cpp

Background.o : Background.h Constants.h StationarySprite.h
	$(CC) $(CFLAGS) $(INCLUDE_SDL_PATH) $(INCLUDE_SDL_IMAGE_PATH) Background.cpp

Paddle.o : Paddle.h Constants.h MoveableSprite.h StationarySprite.h Timer.h RenderImage.h
	$(CC) $(CFLAGS) $(INCLUDE_SDL_PATH) $(INCLUDE_SDL_IMAGE_PATH) Paddle.cpp

RenderImage.o : RenderImage.h
	$(CC) $(CFLAGS) $(INCLUDE_SDL_PATH) $(INCLUDE_SDL_IMAGE_PATH) RenderImage.cpp

Timer.o : Timer.h
	$(CC) $(CFLAGS) $(INCLUDE_SDL_PATH) Timer.cpp

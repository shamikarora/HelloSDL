default:
	g++ -c -I/Library/Frameworks/SDL.Framework/Versions/A/Headers/ main.cpp SDLMain.m
	g++ main.o SDLMain.o -o SDLTest -framework SDL -framework Cocoa

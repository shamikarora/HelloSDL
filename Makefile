default: clean program

clean:
	-rm -f main.o
	-rm -f SDLMain.o
	-rm -f SDLTest

program:
	g++ -c -I/Library/Frameworks/SDL.Framework/Versions/A/Headers/ main.cpp SDLMain.m
	g++ main.o SDLMain.o -o SDLTest -framework SDL -framework Cocoa

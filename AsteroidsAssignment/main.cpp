#include<iostream>

#include "SDL.h"
#include "src/Game.h"
#include "src/Actor.h"


int main(int argc, char* argv[])
{
	Game game = Game();
	std::cout << "created game" << std::endl;

	std::cout << "starting loop" << std::endl;
	game.GameLoop();
	std::cout << "ended loop" << std::endl;

	game.Cleanup();
	std::cout << "finished cleanup" << std::endl;

	return 0;
}


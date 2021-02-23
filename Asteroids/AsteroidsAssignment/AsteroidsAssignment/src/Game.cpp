//
// Created by Vilhelm Stokstad on 2021-02-17.
//


#include "Game.h"
#include "Player.h"

Game::Game()
{

	SDL_Init(SDL_INIT_EVERYTHING);


	_screenSize = new Vector2Int(800, 600);

	player = Player();

	SDL_CreateWindowAndRenderer(_screenSize->x, _screenSize->y, SDL_WINDOW_ALLOW_HIGHDPI, &_window, &_renderer);

	if (_window == nullptr) {
		// In the case that the window could not be made...
		std::cout << "Could not create window: " << SDL_GetError() << std::endl;

	}

	SDL_SetRenderDrawColor(_renderer, 100, 100, 100, 250);
	SDL_RenderClear(_renderer);

	SDL_RenderPresent(_renderer);

	appRunning = true;


}


void Game::GameLoop()
{


	while (appRunning) {
		//Check for input;
		HandleEvents();

		//Render the screen
		Render();


	}

}


void Game::HandleEvents()
{
	//Colors just for fun//
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;
//get the current color//
	SDL_GetRenderDrawColor(_renderer, &r, &g, &b, &a);

	while (SDL_PollEvent(&_events)) {
		if (_events.type==SDL_KEYDOWN){
		player.Input(_events);
		}
		if (_events.button.type == SDL_MOUSEBUTTONDOWN) {
			r = _events.button.x;
			b = _events.button.y;
			SDL_SetRenderDrawColor(_renderer, r, g, b, a);
			//Set and render a new color//
			SDL_RenderClear(_renderer);
		}
		//check if app is closing to quit.
		if (SDL_QUIT == _events.type) {
			std::cout << "SDL_QUIT" << std::endl;
			SDL_Log("Program quit after %i ticks", _events.quit.timestamp);
			appRunning = false;

		}
	}


}

void Game::Render()
{



	SDL_RenderPresent(_renderer);


}


void Game::Cleanup()
{

	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_WasInit(SDL_INIT_EVERYTHING);
	SDL_Quit();

}


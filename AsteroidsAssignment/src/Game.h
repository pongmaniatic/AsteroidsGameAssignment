//
// Created by Vilhelm Stokstad on 2021-02-17.
//

#ifndef ASTEROIDS_GAME_H
#define ASTEROIDS_GAME_H

#include "SDL.h"
#include <iostream>
#include "Library.h"
#include "Player.h"
//added for images
#include "SDL_image.h"


class Game
{
public:
	Game();

	bool appRunning = true;

	void GameLoop();

	void HandleEvents();

	void Render();

	void Update();

	void Cleanup();

	Player player;

private:
	SDL_Window* _window = nullptr;
	SDL_Renderer* _renderer = nullptr;

	SDL_Event _events{};
	Vector2Int* _screenSize = nullptr;
	int cnt = 0;
};


#endif //ASTEROIDS_GAME_H

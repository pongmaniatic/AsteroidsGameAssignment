//
// Created by Vilhelm Stokstad on 2021-02-22.
//

#ifndef ASTEROIDS_PLAYER_H
#define ASTEROIDS_PLAYER_H

#include "Game.h"
#include <SDL.h>
#include "Library.h"

class Player
{
public:
	SDL_Texture* playerTex;
	SDL_Rect srcR, destR;
	void Update();
	
	Player(SDL_Renderer* _renderer);

	void Rendering();
	void Input(SDL_Event event);

private:

	SDL_KeyCode _up;
	SDL_KeyCode _down;
	SDL_KeyCode _left;
	SDL_KeyCode _right;
	SDL_Renderer* _rendererPlayer;
	SDL_KeyCode _space;
	Vector2 _position;
	Vector2 _direction;

	void _Fire();
	void _Move(Vector2 direction);


	void _DebugMove(Vector2 direction);

};


#endif //ASTEROIDS_PLAYER_H

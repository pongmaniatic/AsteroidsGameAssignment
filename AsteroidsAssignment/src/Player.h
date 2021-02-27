//
// Created by Vilhelm Stokstad on 2021-02-22.
//

#ifndef ASTEROIDS_ASSIGNMENT_PLAYER_H
#define ASTEROIDS_ASSIGNMENT_PLAYER_H


#include "Actor.h"


class Player : Actor
{
public:
	SDL_Texture* playerTex;
	SDL_Rect srcR{};
	SDL_FRect destR{};

	Player(SDL_Renderer* renderer);

	Player();

	void Update();

	void Rendering();

	void HandleInput(SDL_Event event);

private:

	SDL_KeyCode _up;
	SDL_KeyCode _down;
	SDL_KeyCode _left;
	SDL_KeyCode _right;
	SDL_Renderer* _rendererPlayer;
	SDL_KeyCode _space;
	Vector2 _position;
	Vector2 _direction;

	virtual int OnCollision();

	void _Fire();

	void _Move();



};


#endif //ASTEROIDS_ASSIGNMENT_PLAYER_H

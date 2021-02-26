//
// Created by Vilhelm Stokstad on 2021-02-22.
//


#include "Player.h"
#include <iostream>

using namespace std;


void Player::Input(SDL_Event event)
{
		if (event.key.keysym.sym == _up) {
			_direction.y = Library::Lerp(_direction.y, 1.0f, 1.0f);
			cout << "moveUp" << endl;
		}
		if (event.key.keysym.sym == _down) {
			_direction.y = Library::Lerp(_direction.y, -1.0f, 1.0f);
			cout << "moveDown" << endl;
		}
		if (event.key.keysym.sym == _left) {
			_direction.x = Library::Lerp(_direction.x, -1.0f, 1.0f);
			cout << "moveLeft" << endl;
		}
		if (event.key.keysym.sym == _right) {
			_direction.x = Library::Lerp(_direction.x, 1.0f, 1.0f);
			cout << "moveRight" << endl;
		}
		if (event.key.keysym.sym == _space) {
			_Fire();
		}
	_Move(_direction);

}


void Player::_Move(Vector2 direction)
{
	this->_position.x = Library::Lerp(this->_position.x, direction.x, 0.2F);
	this->_position.y = Library::Lerp(this->_position.y, direction.y, 0.2F);

}

void Player::_Fire()
{
	
}
void Player::Rendering()
{
	SDL_RenderCopy(_rendererPlayer, playerTex, NULL, &destR);
}

void Player::Update()
{
	
	destR.h = 32;
	destR.w = 32;
	//destR.x = cnt;

}


Player::Player(SDL_Renderer* _renderer)
{
	_rendererPlayer = _renderer;
	destR.h = 32;
	destR.w = 32;
	_direction = Vector2(0.0f, 0.0f);
	_position = Vector2(0.0f, 0.0f);
	_up =  SDLK_UP;
	_down = SDLK_DOWN;
	_left = SDLK_LEFT;
	_right = SDLK_RIGHT;
	_space = SDLK_SPACE;
	SDL_Surface* tmpSurface = IMG_Load("assets/playeWhite.png");
	playerTex = SDL_CreateTextureFromSurface(_renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
}








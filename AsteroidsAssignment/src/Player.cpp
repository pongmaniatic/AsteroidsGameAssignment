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


Player::Player()
{
	_direction = Vector2(0.0f, 0.0f);
	_position = Vector2(0.0f, 0.0f);
	_up =  SDLK_UP;
	_down = SDLK_DOWN;
	_left = SDLK_LEFT;
	_right = SDLK_RIGHT;
	_space = SDLK_SPACE;
}








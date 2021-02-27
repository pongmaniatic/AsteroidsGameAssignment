//
// Created by Vilhelm Stokstad on 2021-02-22.
//


#include "Player.h"
#include <iostream>

using namespace std;

int Player::OnCollision()
{
	return 0;

}




void Player::HandleInput(SDL_Event event)
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

	_Move();
}


void Player::_Move()
{
	cout << "direction :" << "X " << _direction.x << "Y" << _direction.y << endl;
	cout << "position :" << "X " << _position.x << "Y" << _position.y << endl;
	srcR.x = _position.x;
	srcR.y = _position.y;
	this->_position.x = Library::Lerp(this->_position.x, _direction.x, 0.2F);
	this->_position.y = Library::Lerp(this->_position.y, _direction.y, 0.2F);
	destR.x = _position.x;
	destR.y = _position.y;

	cout << "After _Move position :" << "X " << _position.x << "Y" << _position.y << endl;
}

void Player::_Fire()
{
	cout << "FIRE" << endl;
}

void Player::Rendering()
{
	auto dirDeg = std::cos(Vector2::Dot(_direction.normalized(), _position.normalized()));
	SDL_RendererFlip flip = dirDeg > 180 ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE;

	SDL_RenderCopyExF(_rendererPlayer, playerTex, &srcR, &destR, dirDeg, nullptr, flip);
}

void Player::Update()
{


	//destR.x = cnt;


}

Player::Player(SDL_Renderer* renderer)
{
	_rendererPlayer = renderer;

	srcR = {};
	destR = {};

	srcR.h = 32;
	srcR.w = 32;

	destR.h = 32;
	destR.w = 32;

	_direction = Vector2(0.0f, 0.0f);
	_position = Vector2(0.0f, 0.0f);

	_up = SDLK_UP;
	_down = SDLK_DOWN;
	_left = SDLK_LEFT;
	_right = SDLK_RIGHT;
	_space = SDLK_SPACE;

	SDL_Surface* tmpSurface = IMG_Load("./assets/playerWhite.png");
	playerTex = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
}








//
// Created by Vilhelm Stokstad on 2021-02-22.
//

#ifndef ASTEROIDS_ASSIGNMENT_ACTOR_H
#define ASTEROIDS_ASSIGNMENT_ACTOR_H

#include "SDL_image.h"
#include "SDL.h"
#include "Library.h"

class Actor
{public:
	virtual int OnCollision() = 0;
};

#endif //ASTEROIDS_ASSIGNMENT_ACTOR_H


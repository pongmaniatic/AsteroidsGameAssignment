//
// Created by Vilhelm Stokstad on 2021-02-22.
//

#ifndef ASTEROIDS_ACTOR_H
#define ASTEROIDS_ACTOR_H

#include "Game.h"

class Actor
{public:
	virtual int OnCollision() = 0;
};

#endif //ASTEROIDS_ACTOR_H


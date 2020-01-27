#ifndef COLLISION_H
#define COLLISION_H

#include "Entity.h"
#include "SFML/Graphics.hpp"

class Collision {
private:

public:
	Collision() {}

	bool solidCollision(Entity& entity, sf::RectangleShape* hitbox);
};

#endif // !COLLISION_H

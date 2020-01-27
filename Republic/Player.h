#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Gravity.h"

class Player {
private:
	Entity playerEntity;

public:
	Player();

	void update(double dt);
	void render(sf::RenderWindow& window, double dt);

	Entity* getEntity();
};

#endif
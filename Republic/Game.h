#ifndef EDITOR_H
#define EDITOR_H

#include "State.h"
#include "Map.h"
#include "Player.h"
#include "Collision.h"

class Game : public State {
private:
	Map* map;
	Player player;

	Collision collision;

public:
	Game();
	~Game();

	void run(sf::RenderWindow& window, double dt);
	void render(sf::RenderWindow& window, double dt);
};

#endif // !EDITOR_H

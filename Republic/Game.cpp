#include "Game.h"

Game::~Game()
{
	delete map;
}

Game::Game()
{
	map = new Map(32, 32);
	
}

void Game::run(sf::RenderWindow& window, double dt)
{
	player.update(dt);
	for(int i = 0; i < 4; i++)
		collision.solidCollision(*player.getEntity(), map->getTerrain(i));

	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window.close();

		player.controll(event);
	}
}

void Game::render(sf::RenderWindow& window, double dt)
{
	map->render(window);
	player.render(window, dt);
}

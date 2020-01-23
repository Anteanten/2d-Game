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
}

void Game::render(sf::RenderWindow& window, double dt)
{
	map->render(window);
	player.render(window, dt);
}

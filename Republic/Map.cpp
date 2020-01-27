#include "Map.h"

Map::Map(int sizeX, int sizeY)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	
	terrain.push_back(new sf::RectangleShape);
	terrain.at(0)->setPosition(0, 400);
	terrain.at(0)->setSize(sf::Vector2f(300, 200));
	terrain.at(0)->setFillColor(sf::Color::White);
	
	terrain.push_back(new sf::RectangleShape);
	terrain.at(1)->setPosition(0, 0);
	terrain.at(1)->setSize(sf::Vector2f(500, 100));
	terrain.at(1)->setFillColor(sf::Color::White);

	terrain.push_back(new sf::RectangleShape);
	terrain.at(2)->setPosition(300, 500);
	terrain.at(2)->setSize(sf::Vector2f(800, 100));
	terrain.at(2)->setFillColor(sf::Color::White);
}

void Map::render(sf::RenderWindow& window)
{
	for (int i = 0; i < terrain.size(); i++) {
		window.draw(*terrain.at(i));
	}
}

sf::RectangleShape* Map::getTerrain(int index)
{
	return terrain.at(index);
}

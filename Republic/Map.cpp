#include "Map.h"

Map::Map(int sizeX, int sizeY)
{
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			tiles.push_back(nullptr);
		}
	}
	for (int j = 14; j < 20; j++) {
		for (int i = 0; i < 25; i++) {
			tiles.at(j * sizeX + i) = new sf::RectangleShape;

			tiles.at(j * sizeX + i)->setPosition(sf::Vector2f(i * 32, j * 32));
			tiles.at(j * sizeX + i)->setTexture(TextureManager::getInstance()->getTexture("tile.png"));
			tiles.at(j * sizeX + i)->setSize(sf::Vector2f(32, 32));
		}
	}

}

void Map::render(sf::RenderWindow& window)
{
	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			if (tiles.at(i * sizeX + j) != nullptr)
				window.draw(*tiles.at(i * sizeX + j));
		}
	}
}

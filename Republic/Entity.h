#ifndef ENTITY_H
#define ENTITY_H

#include "SFML/Graphics.hpp"
#include <string.h>
#include "TextureManager.h"
#include "EntityComponent.h"

class Entity {
private:
	sf::Sprite sprite;
	sf::RectangleShape hitbox;

	sf::Vector2f velocity;
	sf::Vector2f position;
	sf::Vector2f oldPosition;

	std::vector<EntityComponent*> components;
public:
	Entity();
	Entity(std::string texturePath);
	
	//Update the enity with all the attached components
	void update(double dt);

	void render(sf::RenderWindow& window, double dt);

	//Attach a component to entity
	void addComponent(EntityComponent* component);

	void setTexture(std::string texturePath);

	void setVelocity(sf::Vector2f velocity);
	sf::Vector2f getVelocity() const;

	void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition() const;
	sf::Vector2f getOldPosition() const;

	void setHitboxSize(sf::Vector2f size);
	sf::Vector2f getHitboxSize() const;

};

#endif // !ENTITY_H

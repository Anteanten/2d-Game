#ifndef GRAVITY_H
#define GRAVITY_H

#include "SFML/Graphics.hpp"
#include "EntityComponent.h"
#include "Entity.h"

class Gravity : public EntityComponent{
private:
	sf::Vector2f direction;
public:
	Gravity();
	Gravity(sf::Vector2f direction);

	void update(double dt, Entity& entity);

	//Set the direction of gravity including scale
	void setDirection(sf::Vector2f direction);
	//Get the direction of gravity including scale
	sf::Vector2f getDirection() const;
};

#endif // !GRAVITY_H

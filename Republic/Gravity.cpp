#include "Gravity.h"

Gravity::Gravity()
{
	direction = sf::Vector2f(0, 10);
}

Gravity::Gravity(sf::Vector2f direction)
{
	this->direction = direction;
}

void Gravity::update(double dt, Entity& entity)
{
	entity.setVelocity(entity.getVelocity() + direction * (float)dt);
}

void Gravity::setDirection(sf::Vector2f direction)
{
	this->direction = direction;
}

sf::Vector2f Gravity::getDirection() const
{
	return direction;
}

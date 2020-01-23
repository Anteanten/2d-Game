#include "Entity.h"

Entity::Entity()
{
}

Entity::Entity(std::string texturePath)
{
	sprite.setTexture(*TextureManager::getInstance()->getTexture(texturePath));
}

void Entity::update(double dt)
{
	for (int i = 0; i < components.size(); i++) {
		components.at(i)->update(dt, *this);
	}

	sprite.setPosition(sprite.getPosition() + velocity * (float)dt);
}

void Entity::render(sf::RenderWindow& window, double dt)
{
	window.draw(sprite);
}

void Entity::addComponent(EntityComponent* component)
{
	components.push_back(component);
}

void Entity::setTexture(std::string texturePath)
{
	sprite.setTexture(*TextureManager::getInstance()->getTexture(texturePath));
}

void Entity::setVelocity(sf::Vector2f velocity)
{
	this->velocity = velocity;
}

sf::Vector2f Entity::getVelocity() const
{
	return velocity;
}

void Entity::setPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
}

sf::Vector2f Entity::getPosition() const
{
	return sprite.getPosition();
}

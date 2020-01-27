#include "Entity.h"

Entity::Entity()
{
	velocity = sf::Vector2f(0, 0);
	position = sf::Vector2f(0, 0);
}

Entity::Entity(std::string texturePath)
{
	sprite.setTexture(*TextureManager::getInstance()->getTexture(texturePath));
}

void Entity::update(double dt)
{
	oldPosition = position;
	position += velocity * (float)dt;
	hitbox.setPosition(position);
	sprite.setPosition(position);

	for (int i = 0; i < components.size(); i++) {
		components.at(i)->update(dt, *this);
	}
}

void Entity::render(sf::RenderWindow& window, double dt)
{
	sprite.setPosition(sprite.getPosition() + velocity * (float)dt);
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
	this->position = position;
}

sf::Vector2f Entity::getPosition() const
{
	return position;
}

sf::Vector2f Entity::getOldPosition() const
{
	return oldPosition;
}

void Entity::setHitboxSize(sf::Vector2f size)
{
	hitbox.setSize(size);
}

sf::Vector2f Entity::getHitboxSize() const
{
	return hitbox.getSize();
}

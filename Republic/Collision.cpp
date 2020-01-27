#include "Collision.h"
#include <iostream>

bool Collision::solidCollision(Entity& entity, sf::RectangleShape* hitbox)
{
	if (entity.getPosition().x < hitbox->getPosition().x + hitbox->getSize().x &&
		entity.getPosition().x + entity.getHitboxSize().x > hitbox->getPosition().x &&
		entity.getPosition().y < hitbox->getPosition().y + hitbox->getSize().y &&
		entity.getPosition().y + entity.getHitboxSize().y > hitbox->getPosition().y) {
		//Collision detected

		//Top Collision
		if (entity.getOldPosition().y + entity.getHitboxSize().y <= hitbox->getPosition().y) {
			entity.setVelocity(sf::Vector2f(entity.getVelocity().x, 0));
			entity.setPosition(sf::Vector2f(entity.getPosition().x, hitbox->getPosition().y - entity.getHitboxSize().y));
		}
		//Left Collision
		if (entity.getOldPosition().x + entity.getHitboxSize().x <= hitbox->getPosition().x) {
			entity.setVelocity(sf::Vector2f(0, entity.getVelocity().y));
			entity.setPosition(sf::Vector2f(hitbox->getPosition().x - entity.getHitboxSize().x, entity.getPosition().y));
		}
		//Right Collision
		if (entity.getOldPosition().x >= hitbox->getPosition().x + hitbox->getSize().x) {
			entity.setVelocity(sf::Vector2f(0, entity.getVelocity().y));
			entity.setPosition(sf::Vector2f(hitbox->getPosition().x + hitbox->getSize().x, entity.getPosition().y));
		}
		//Bottom Collision
		if (entity.getOldPosition().y >= hitbox->getPosition().y + hitbox->getSize().y) {
			entity.setVelocity(sf::Vector2f(entity.getVelocity().x, 0));
			entity.setPosition(sf::Vector2f(entity.getPosition().x, hitbox->getPosition().y + hitbox->getSize().y));
		}
		return true;
	}
	//No collision detected
	return false;
}

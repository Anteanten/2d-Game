#include "Player.h"

Player::Player()
{
	playerEntity.addComponent(new Gravity(sf::Vector2f(-5, 10)));
	playerEntity.setTexture("player.png");
	playerEntity.setPosition(sf::Vector2f(505, 105));
	playerEntity.setHitboxSize(sf::Vector2f(32, 64));
}

void Player::update(double dt)
{
	playerEntity.update(dt);
}

void Player::render(sf::RenderWindow& window, double dt)
{
	playerEntity.render(window, dt);
}

Entity* Player::getEntity()
{
	return &playerEntity;
}

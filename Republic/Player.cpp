#include "Player.h"

Player::Player()
{
	playerEntity.addComponent(new Gravity(sf::Vector2f(0, 10)));
	playerEntity.setTexture("player.png");
	playerEntity.setPosition(sf::Vector2f(100, 100));
}

void Player::update(double dt)
{
	playerEntity.update(dt);
}

void Player::render(sf::RenderWindow& window, double dt)
{
	playerEntity.render(window, dt);
}

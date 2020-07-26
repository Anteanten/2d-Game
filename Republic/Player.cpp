#include "Player.h"

Player::Player()
{
	playerEntity.addComponent(new Gravity(sf::Vector2f(0, 400)));
	playerEntity.setTexture("player.png");
	playerEntity.setPosition(sf::Vector2f(505, 105));
	playerEntity.setHitboxSize(sf::Vector2f(32, 32));
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

void Player::controll(sf::Event key)
{
	switch (key.type) {
		case sf::Event::KeyPressed: {
			if (key.key.code == sf::Keyboard::A) {
				playerEntity.setVelocity(sf::Vector2f(-100, playerEntity.getVelocity().y));
			}
			if (key.key.code == sf::Keyboard::D) {
				playerEntity.setVelocity(sf::Vector2f(100, playerEntity.getVelocity().y));
			}
			
			break;
		}
		case sf::Event::KeyReleased: {
			if (key.key.code == sf::Keyboard::A || key.key.code == sf::Keyboard::D) {
				playerEntity.setVelocity(sf::Vector2f(0, playerEntity.getVelocity().y));
			}
			if (key.key.code == sf::Keyboard::Space) {
				playerEntity.setVelocity(sf::Vector2f(playerEntity.getVelocity().x, -300));
			}
			break;
		}

	}
}

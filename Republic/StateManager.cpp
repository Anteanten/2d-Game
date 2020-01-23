#include "StateManager.h"

StateManager::StateManager()
{
}

void StateManager::addState(State* state)
{
	states.push_back(state);
}

void StateManager::removeState(State* state)
{
	for (int i = 0; i < states.size(); i++) {
		if (states.at(i) == state) {
			states.erase(states.begin() + i);
			break;
		}
	}
}

void StateManager::run(sf::RenderWindow& window, double dt)
{
	states.at(0)->run(window, dt);
}

void StateManager::render(sf::RenderWindow& window, double dt)
{
	states.at(0)->render(window, dt);
}

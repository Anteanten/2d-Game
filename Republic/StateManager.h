#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include "SFML/Graphics.hpp"
#include "State.h"

class StateManager {
private:
	std::vector<State*> states;

public:
	StateManager();


	void addState(State* state);
	void removeState(State* state);

	//Calls the run function on state on top of stack
	void run(sf::RenderWindow& window, double dt);
	//Calls the render function on state on top of stack
	void render(sf::RenderWindow& window, double dt);

};


#endif
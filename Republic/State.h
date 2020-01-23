#ifndef STATE_H
#define STATE_H

#include "SFML/Graphics.hpp"
#include <string>

class State {
private:
	int logicTickRate; //How many logic updates per second

public:
	State();

	virtual void run(sf::RenderWindow& window, double dt) = 0;
	virtual void render(sf::RenderWindow& window, double dt) = 0;

	void setTickRate(int tickRate);
	int getTickRate() const;
};

inline State::State() {
	logicTickRate = 30;
}

inline void State::setTickRate(int tickRate) {
	logicTickRate = tickRate;
}

inline int State::getTickRate() const {
	return logicTickRate;
}

#endif // !STATE_H

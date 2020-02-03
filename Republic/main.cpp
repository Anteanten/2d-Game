#include <SFML/Graphics.hpp>
#include "StateManager.h"
#include "Game.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");


	//TIME
	sf::Clock time;
	int fps = 0;
	double timer = 0;
	double dt;

	//FPS COUNTER
	sf::Text fpsCounter;
	fpsCounter.setPosition(sf::Vector2f(5, 5));
	sf::Font font;
	font.loadFromFile("arial.ttf");
	fpsCounter.setFont(font);
	fpsCounter.setString("init");
	fpsCounter.setCharacterSize(14);

	//STATES
	StateManager stateManager;
	Game game;
	stateManager.addState(&game);


	//MAIN LOOP
	while (window.isOpen())
	{
		
		dt = time.restart().asSeconds();

		//GAME LOOP
		window.clear();

		stateManager.run(window, dt);
		stateManager.render(window, dt);

		window.draw(fpsCounter);
		window.display();

		//FPS COUNTER
		timer += dt;
		fps++;
		if (timer >= 1) {
			fpsCounter.setString("fps: " + std::to_string(fps));
			fps = 0;
			timer = 0;
		}

	}

	return 0;
}
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Ground.h"
#include "Score.h"


int main() {
	sf::RenderWindow window(sf::VideoMode(600, 150), "Mihir's Dino Game", sf::Style::Close);
	Player dino;
	Ground ground;
	Score score;
	sf::Clock clock;
	int dinoTexture = 0;

	dino.setTexture(1);
	window.setFramerateLimit(60);

	//Game Loop
	while (window.isOpen()) {
		//Poll window events
		sf::Event evnt;
		while (window.pollEvent(evnt)) {

			switch (evnt.type) {

			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		//Updating
		dino.update();
		ground.update();
		score.update();
		
		//Drawing
		window.clear(sf::Color::White);
		score.draw(window);
		dino.draw(window);
		ground.draw(window);
		window.display();
	}

	return 0;
}
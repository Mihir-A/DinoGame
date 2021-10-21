#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Ground.h"
#include "Score.h"
#include "Enemy.h"


int main() {
	sf::RenderWindow window(sf::VideoMode(600, 150), "Mihir's Dino Game", sf::Style::Close);
	Player dino;
	Ground ground;
	Score score;
	Enemy enemy;

	sf::Clock clock;
	int dinoTexture = 0;


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
		enemy.update();

		dino.checkCollisons(enemy);
		
		//Drawing
		window.clear(sf::Color::White);
		score.draw(window);
		dino.draw(window);
		ground.draw(window);
		enemy.draw(window);
		window.display();
	}

	return 0;
}
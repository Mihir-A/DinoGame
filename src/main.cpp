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

	bool killed = false;
	bool spaceReset = 0;

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
		if (dino.checkCollisons(enemy) == false and killed == false) {
			dino.update();
			ground.update();
			if (score.update() == true) {
				ground.speed--;
				enemy.speed--;
			}
			enemy.update();
		}
		else if (killed == false) {
			dino.kill();
			killed = true;
		}
		else if (spaceReset != 2){//All to check if space has been released before reseting
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) == false) {
				spaceReset = 1;
			}
			else if (spaceReset == 1 and sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
				dino.reset();
				ground.reset();
				score.reset();
				enemy.reset();
				killed = false;
				spaceReset = 0;
			}
		}


		//Drawing
		window.clear(sf::Color::White);
		score.draw(window);
		ground.draw(window);
		enemy.draw(window);
		dino.draw(window);
		window.display();
	}

	return 0;
}
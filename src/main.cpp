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

	sf::Texture gameOverTexture;
	gameOverTexture.loadFromFile("res/game_over.png");

	sf::Sprite gameOverSprite(gameOverTexture);

	gameOverSprite.setScale(0.75f, 0.75f);

	gameOverSprite.setPosition(160.0f, 50.0f);

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
				score.writeHs();
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
			score.writeHs();
			
		}
		else//All to check if space has been released before reseting
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

		//Drawing
		window.clear(sf::Color::White);
		score.draw(window);
		ground.draw(window);
		enemy.draw(window);
		dino.draw(window);

		if (spaceReset != 0) {
			window.draw(gameOverSprite);
		}

		window.display();
	}

	return 0;
}
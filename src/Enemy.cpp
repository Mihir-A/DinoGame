#include "Enemy.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>
Enemy::Enemy()
{
	srand(time(NULL));

	textures.resize(7);
	textures[0].loadFromFile("res/cactus-1b.png");
	textures[1].loadFromFile("res/cactus-1s.png");
	textures[2].loadFromFile("res/cactus-2b.png");
	textures[3].loadFromFile("res/cactus-2s.png");
	textures[4].loadFromFile("res/cactus-3b.png");
	textures[5].loadFromFile("res/cactus-3s.png");
	textures[6].loadFromFile("res/cactus-4b.png");
	
	enemy1.setScale(0.5f, 0.5f);
	enemy1.setTexture(textures[0], true);

	enemy2.setScale(0.5f, 0.5f);
	enemy2.setTexture(textures[1], true);

	enemy1.setPosition(648, 144 - enemy1.getGlobalBounds().height);
	enemy2.setPosition(1248, 144 - enemy2.getGlobalBounds().height);
}

void Enemy::update()
{
	if (enemy1.getPosition().x <= -(enemy1.getGlobalBounds().height)) {
		enemy1.setTexture(textures[rand() % 6 + 0], true);
		enemy1.setPosition(1248, 144 - enemy1.getGlobalBounds().height);
	}

	if (enemy2.getPosition().x <= -(enemy2.getGlobalBounds().height)) {
		enemy2.setTexture(textures[rand() % 6 + 0], true);
		enemy2.setPosition(1248, 144 - enemy2.getGlobalBounds().height);
	}

	enemy1.move(speed, 0);
	enemy2.move(speed, 0);
}

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(enemy1);
	window.draw(enemy2);
}

void Enemy::reset()
{
	enemy1.setScale(0.5f, 0.5f);
	enemy1.setTexture(textures[0], true);

	enemy2.setScale(0.5f, 0.5f);
	enemy2.setTexture(textures[1], true);

	enemy1.setPosition(648, 144 - enemy1.getGlobalBounds().height);
	enemy2.setPosition(1248, 144 - enemy2.getGlobalBounds().height);
	
	speed = -6;
}

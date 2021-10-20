#include "Enemy.h"
Enemy::Enemy()
{
	textures.resize(7);
	textures[0].loadFromFile("res/cactus-1b.png");
	textures[1].loadFromFile("res/cactus-1s.png");
	textures[2].loadFromFile("res/cactus-2b.png");
	textures[3].loadFromFile("res/cactus-2s.png");
	textures[4].loadFromFile("res/cactus-3b.png");
	textures[5].loadFromFile("res/cactus-3s.png");
	textures[6].loadFromFile("res/cactus-4b.png");

	enemy1.setTexture(textures[0]);
	enemy1.setScale(0.5f, 0.5f);

	enemy1.setPosition(648, 80);
}

void Enemy::update()
{
	enemy1.move(speed, 0);
}

void Enemy::draw(sf::RenderWindow& window)
{
	window.draw(enemy1);
	window.draw(enemy2);
}

#pragma once
#include <vector>
#include "SFML/Graphics.hpp"
class Enemy
{
private:
	std::vector<sf::Texture> textures;
	int speed = -6;
public:
	Enemy();
	void update();
	void draw(sf::RenderWindow& window);
	sf::Sprite enemy1;
	sf::Sprite enemy2;
	void reset();

};


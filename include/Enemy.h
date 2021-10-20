#pragma once
#include <vector>
#include "SFML/Graphics.hpp"
class Enemy
{
private:
	sf::Sprite enemy1;
	sf::Sprite enemy2;
	std::vector<sf::Texture> textures;
	int speed = -6;
public:
	Enemy();
	void update();
	void draw(sf::RenderWindow& window);

};


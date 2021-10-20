#pragma once
#include "SFML/Graphics.hpp"
class Ground
{
private:
	sf::Texture groundTexture;
	sf::Sprite ground1;
	sf::Sprite ground2;
	int speed = -6;
public:
	Ground();
	void draw(sf::RenderWindow &window);
	void update();
};


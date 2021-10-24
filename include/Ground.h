#pragma once
#include "SFML/Graphics.hpp"
class Ground
{
private:
	sf::Texture groundTexture;
	sf::Sprite ground1;
	sf::Sprite ground2;
public:
	int speed = -6;
	Ground();
	void draw(sf::RenderWindow &window);
	void update();
	void reset();
};


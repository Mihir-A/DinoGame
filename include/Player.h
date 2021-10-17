#pragma once
#include "SFML/Graphics.hpp"
#include <vector>


class Player
{
private:
	int animationFrame = 0;
	int textureNum = 0;
	bool jumping = false;
	float velocity = 0;
	std::vector<sf::Texture> textures;
public:
	sf::Sprite dino;
	Player();
	void setTexture(int number);
	void draw(sf::RenderWindow &window);
	void setPos(float x, float y);
	void movePos(float x, float y);
	void update();

};


#include <iostream>
#include "Ground.h"

Ground::Ground()
{
	groundTexture.loadFromFile("res/ground.png");
	ground1.setTexture(groundTexture);
	ground2.setTexture(groundTexture);
	ground1.setPosition(0.0f, 131.0f);
	ground2.setPosition(1200.0f, 131.0f);
}

void Ground::draw(sf::RenderWindow& window)
{
	window.draw(ground1);
	window.draw(ground2);
}

void Ground::update()
{
	if (ground1.getPosition().x < -1200) {
		ground1.setPosition(1194.0f, 131.0f);
	}
	else if (ground2.getPosition().x < -1200) {
		ground2.setPosition(1194.0f, 131.0f);
	}
	

	ground1.move(speed, 0.0f);
	ground2.move(speed, 0.0f);
}

void Ground::reset()
{
	speed = -6;
}



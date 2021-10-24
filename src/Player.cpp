#include "Player.h"
#include "Collision.h"
#include <iostream>
#include <SFML/Audio.hpp>

Player::Player()
{
	textures.resize(6);
	textures[0].loadFromFile("res/dino_1.png");
	textures[1].loadFromFile("res/dino_2.png");
	textures[2].loadFromFile("res/dino_death.png");
	textures[3].loadFromFile("res/dino_ducking_1.png");
	textures[4].loadFromFile("res/dino_ducking_2.png");
	textures[5].loadFromFile("res/dino_jump.png");

	jumpBuffer.loadFromFile("res/jump.wav");
	jumpSound.setBuffer(jumpBuffer);

	deathBuffer.loadFromFile("res/death.wav");
	deathSound.setBuffer(deathBuffer);

	setPos(40.0f, 95.0f);
	setTexture(1);
}

void Player::setTexture(int number)
{
	dino.setTexture(textures[number]);
	dino.setScale(0.5f, 0.5f);
	textureNum = number;
}

void Player::draw(sf::RenderWindow& window)
{
	window.draw(dino);
}

void Player::setPos(float x, float y)
{
	dino.setPosition(x, y);
}

void Player::movePos(float x, float y)
{
	dino.move(x, y);
}

void Player::update()
{
	if (animationFrame >= 4 && jumping == false) {
 		switch (textureNum) {
		case 0:
			setTexture(1);
			break;
		case 1:
			setTexture(0);
			break;
		default:
			setTexture(1);
			break;
		}
		animationFrame = 0;
	}
	else {
		animationFrame++;
	}
	 
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && (dino.getPosition().y == 95)) {
		velocity = -13;
		jumping = true;
		setTexture(5);
		jumpSound.play();
	}

	if (((float)dino.getPosition().y + velocity) >= 95.0f){
		dino.setPosition((float)dino.getPosition().x, 95);
		velocity = 0;
		jumping = false;
	}
	else {
		dino.setPosition((float)dino.getPosition().x, (float)dino.getPosition().y + velocity);
		velocity+= 1;
	}
}

bool Player::checkCollisons(Enemy& e)
{
	if (e.enemy1.getPosition().x < 125){
		if (Collision::PixelPerfectTest(dino, e.enemy1)) {
			return 1;
		}
	}
	if (e.enemy2.getPosition().x < 125) {
		if (Collision::PixelPerfectTest(dino, e.enemy2)) {
			return 1;
		}
	}
	return 0;
}

void Player::kill() {
	setTexture(2);
	deathSound.play();
}

void Player::reset()
{
	setPos(40.0f, 95.0f);
	setTexture(1);
}

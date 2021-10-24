#include "Score.h"
#include <math.h>
#include <iostream>

Score::Score()
{
	numberTextures.resize(10);
	numbers.resize(5);

	numberTextures[0].loadFromFile("res/0.png");
	numberTextures[1].loadFromFile("res/1.png");
	numberTextures[2].loadFromFile("res/2.png");
	numberTextures[3].loadFromFile("res/3.png");
	numberTextures[4].loadFromFile("res/4.png");
	numberTextures[5].loadFromFile("res/5.png");
	numberTextures[6].loadFromFile("res/6.png");
	numberTextures[7].loadFromFile("res/7.png");
	numberTextures[8].loadFromFile("res/8.png");
	numberTextures[9].loadFromFile("res/9.png");



	for (int j = 0; j < numbers.size(); j++) {
		numbers[j].setPosition((float)(580.0f - (13.0f * j)), 5.0f);
		numbers[j].setTexture(numberTextures[0]);
		numbers[j].setScale(sf::Vector2f(0.5f, 0.5f));
	}

	speedUpBuffer.loadFromFile("res/speedUp.wav");
	speedUp.setBuffer(speedUpBuffer);

	highScoreFile.open("res/file.txt", );

}

bool Score::update()
{
	if (scoreUpdater == 6){
		scoreUpdater = 0;
		int digit;
		score ++;

		for (int i = 0; i < 5; i ++) {
			digit = pow(10, i);
			numbers[i].setTexture(numberTextures[(score/digit) % 10]);
		}
		if (score % 100 == 0 and score != 0) {
			speedUp.play();
			return 1;
		}
	}
	else {
		scoreUpdater++;
	}
	return 0;
}

void Score::draw(sf::RenderWindow& window)
{
	for (sf::Sprite &i : numbers) {
		window.draw(i);
	}
}

void Score::reset()
{
	score = 0;
	scoreUpdater = 0;
}

#include "Score.h"

Score::Score()
{
	hsTexture.loadFromFile("res/hi.png");
	hsImage.setTexture(hsTexture);
	hsImage.setScale(0.5, 0.5);
	hsImage.setPosition(20.0f, 5.0f);

	numberTextures.resize(25);
	numbers.resize(5);
	highScoreSprites.resize(5);

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

	highScoreFile.open("res/highscore.data", std::fstream::in);
	std::string highScoreStr;
	highScoreFile >> highScoreStr;

	if (highScoreStr.length() == 0) {
		highScore = 0;
	}
	else {
		try {
			highScore = std::stoi(highScoreStr);
		}
		catch (...) {
			highScore = 0;
		}

	}
	highScoreFile.close();

	int digit;
	for (int j = 0; j < highScoreSprites.size(); j++) {
		digit = pow(10, j);

		highScoreSprites[j].setPosition((float)(100.0f - (13.0f * j)), 5.0f);
		highScoreSprites[j].setTexture(numberTextures[(highScore / digit) % 10]);
		highScoreSprites[j].setScale(sf::Vector2f(0.5f, 0.5f));
	}

	speedUpBuffer.loadFromFile("res/speedUp.wav");
	speedUp.setBuffer(speedUpBuffer);
}

bool Score::update()
{
	if (scoreUpdater == 6){
		scoreUpdater = 0;
		int digit;
		score ++;

		if (score >= highScore) {
			highScore = score;
			for (int i = 0; i < 5; i++) {
				digit = pow(10, i);
				highScoreSprites[i].setTexture(numberTextures[(highScore / digit) % 10]);
			}
		}

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
	for (int i = 0; i < numbers.size(); i++) {
		window.draw(numbers[i]);
		window.draw(highScoreSprites[i]);
	}
	window.draw(hsImage);
}

void Score::reset()
{
	score = 0;
	scoreUpdater = 0;
}

void Score::writeHs()
{
	if (score >= highScore) {
		highScoreFile.open("res/highscore.data", std::fstream::out);
		highScoreFile << highScore;
		highScoreFile.close();
	}
}


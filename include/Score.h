#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <vector>
#include <fstream>
#include <math.h>
#include <iostream>

class Score
{
private:
	std::vector<sf::Sprite> numbers;
	std::vector<sf::Sprite> highScoreSprites;
	std::vector<sf::Texture> numberTextures;
	int score = 0;
	int scoreUpdater = 0;
	sf::SoundBuffer speedUpBuffer;
	sf::Sound speedUp;
	std::fstream highScoreFile;
	int highScore;

public:
	Score();
	bool update();
	void draw(sf::RenderWindow& window);
	void reset();
};


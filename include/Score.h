#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
class Score
{
private:
	std::vector<sf::Sprite> numbers;
	std::vector<sf::Sprite> highScore;
	std::vector<sf::Texture> numberTextures;
	int score = 0;
	int scoreUpdater = 0;

public:
	Score();
	void update();
	void draw(sf::RenderWindow& window);
	void reset();
};


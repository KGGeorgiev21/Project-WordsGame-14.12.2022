#pragma once
#include "precompile.hpp"

class field {
protected:
	string answer;
	
	sf::Text text;
	sf::RectangleShape background;

public:
	field(sf::Color bgColor, int sizeX, int sizeY, int posX, int posY, sf::Font& font, string text);

	void setAnswer(string answer);
	void draw(sf::RenderWindow& window);

	bool checkAnswer(string input);

	~field();
};
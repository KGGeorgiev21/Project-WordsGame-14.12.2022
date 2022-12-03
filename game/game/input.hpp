#pragma once
#include "precompile.hpp"

class field {
protected:
	struct QNA{
		string question;
		string answer;
	};

	vector<QNA> QNAV;
	
	sf::Text question;
	sf::Sprite background;

public:
	field(sf::Color bgColor, int sizeX, int sizeY, int posX, int posY, float scaleX, float scaleY, sf::Font& font, sf::Texture& backgroundTexture);
	sf::Text input;

	void draw(sf::RenderWindow& window);

	void setQuestion(int row);

	bool checkAnswer(int row);

	~field();
};
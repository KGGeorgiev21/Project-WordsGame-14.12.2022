#pragma once
#include "precompile.hpp"

class field {
protected:
	string answer;
	
	struct QNA{
		string question;
		string answer;
	};

	vector<QNA> QNAV;
	
	sf::Text question;
	sf::Sprite background;

public:
	field(sf::Color bgColor, int sizeX, int sizeY, int posX, int posY, float scaleX, float scaleY, sf::Font& font, string text, sf::Texture& backgroundTexture);
	sf::Text input;

	void setAnswer(string answer);
	void draw(sf::RenderWindow& window);

	bool checkAnswer();

	~field();
};
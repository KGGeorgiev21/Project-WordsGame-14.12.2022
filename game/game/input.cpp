#include "precompile.hpp"
#include "input.hpp"

field::field(sf::Color bgColor, int sizeX, int sizeY, int posX, int posY, float scaleX, float scaleY, sf::Font& font, string text, sf::Texture& backgroundTexture) 
{
	this->background.setTexture(backgroundTexture);
	this->background.setPosition(sf::Vector2f(posX, posY));
	this->background.setScale(scaleX, scaleY);
	this->question.setFont(font);
	this->question.setCharacterSize(24);
	this->question.setFillColor(sf::Color(255,255,255));
	this->question.setString(text);
	this->question.setPosition(sf::Vector2f(posX + sizeX / 10, posY + sizeY / 8));
	this->input.setFont(font);
	this->input.setCharacterSize(20);
	this->input.setFillColor(sf::Color(255, 255, 255));
	this->input.setPosition(posX + sizeX / 10, (posY + sizeY) - sizeY / 3 + sizeY / 7);

	this->QNAV = {
		{"", ""},
		{"", ""},
		
	};
}

field::~field() 
{

}

void field::setAnswer(string answer) {
	this->answer = answer;
}

void field::draw(sf::RenderWindow& window) {
	window.draw(this->background);
	window.draw(this->question);
	window.draw(this->input);
}

bool field::checkAnswer() {
	return this->answer == this->input.getString();
}
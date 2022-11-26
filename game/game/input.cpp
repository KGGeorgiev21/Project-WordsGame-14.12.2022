#include "precompile.hpp"
#include "input.hpp"

field::field(sf::Color bgColor, int sizeX, int sizeY, int posX, int posY, sf::Font& font, string text) 
{
	this->background.setFillColor(bgColor);
	this->background.setSize(sf::Vector2f(sizeX, sizeY));
	this->background.setPosition(sf::Vector2f(posX, posY));
	this->text.setFont(font);
	this->text.setCharacterSize(16);
	this->text.setFillColor(sf::Color(255,255,255));
	this->text.setString(text);
	this->text.setPosition(sf::Vector2f(posX, posY));
}

field::~field() 
{

}

void field::setAnswer(string answer) {
	this->answer = answer;
}

void field::draw(sf::RenderWindow& window) {
	window.draw(this->background);
	window.draw(this->text);
}

bool field::checkAnswer(string input) {
	return this->answer == input;
}
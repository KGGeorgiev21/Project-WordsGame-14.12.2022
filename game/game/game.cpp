#include "game.h"
#include "input.h"

game::game(int height, int width, string title) {
	this->windowHeight = height;
	this->windowWidth = width;
	this->title = title;
}

game::~game() {

}

void game::initWindow() {
	this->window.create(sf::VideoMode(this->windowWidth, this->windowHeight), this->title);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	field test('f');

	updateWindow(shape);
}

void game::updateWindow(sf::CircleShape& shape) {
	while (this->window.isOpen()) {
		sf::Event event;
		while (this->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->window.close();
		}

		this->window.clear();
		this->window.draw(shape);
		this->window.display();
	}
}
#include "game.hpp"
#include "input.hpp"

game::game(int height, int width, string title) {
	this->windowHeight = height;
	this->windowWidth = width;
	this->title = title;
}

game::~game() {

}

void game::initWindow() {
	this->window.create(sf::VideoMode(this->windowWidth, this->windowHeight), this->title);
	updateWindow();
}

void game::updateWindow() {
	sf::Font font;

	if (!font.loadFromFile("Roboto-Medium.ttf")) {
		cout << "failed to load font" << endl;
	}

	field test(sf::Color(255, 255, 255, 128), 400, 275, 1280 / 2 - 400 / 2, 720 / 2 - 275 / 2, font, "Test string");

	while (this->window.isOpen()) {
		sf::Event event;
		while (this->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->window.close();
		}

		this->window.clear();

		test.draw(this->window);
		
		
		
		this->window.display();
	}
}
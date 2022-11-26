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
	sf::Texture inputBgT;
	string answer;
	bool shouldDisplayField = false;

	if (!font.loadFromFile("Roboto-Medium.ttf")) {
		cout << "failed to load font" << endl;
	}

	if (!inputBgT.loadFromFile("assets/crate1.png")) {
		cout << "failed to load crate1.png" << endl;
	}

	field test(sf::Color(255, 255, 255, 128), 400, 275, 1280 / 2 - 400 / 2, 720 / 2 - 275 / 2, 1.0f, 1.0f, font, "Test string", inputBgT);

	test.setAnswer("test");

	while (this->window.isOpen()) {
		sf::Event event;
		while (this->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->window.close();

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code >= 0 && event.key.code < 26) {
					answer += (char)(event.key.code + 97);
				}
				else if (event.key.code >= 26 && event.key.code < 36) {
					answer += (char)(event.key.code + 22);
				}
				else if (event.key.code == sf::Keyboard::Backspace) {
					if (!answer.empty()) {
						answer.pop_back();
					}
				}
				else if (event.key.code == sf::Keyboard::Enter) {
					cout << test.checkAnswer() << endl;
					answer = "";
				}
				cout << event.key.code << endl;
				test.input.setString(answer);
			}
		}

		this->window.clear();

		if (shouldDisplayField) {
			test.draw(this->window);
		}
		
		this->window.display();
	}
}
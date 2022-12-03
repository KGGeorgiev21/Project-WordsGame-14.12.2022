#include "game.hpp"

// set variables for window details
gameClass::gameClass(int height, int width, string title) {
	this->windowHeight = height;
	this->windowWidth = width;
	this->title = title;
}

gameClass::~gameClass() {

}

// draw the fight scene
void gameClass::drawFight(player& plr, sf::Event& event, field& inputField) {
	// vars for fight
	// fight logic
	// win/loss condition
	// rewards
	// animations

	bool fightEnded = false;
	bool shouldDisplayField = true;
	int row = 0;
	string answer;

	plr.setPos(sf::Vector2f(167, 539));

	inputField.setQuestion(row);

	while (this->window.isOpen() && !fightEnded) {
		this->window.pollEvent(event);

		if (event.type == sf::Event::KeyPressed) {

			if (shouldDisplayField) {
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
					if (inputField.checkAnswer(row)) {
						fightEnded = true;
					}
					answer = "";
				}
				inputField.input.setString(answer);
			}
		}
		this->window.clear();

		plr.draw(this->window);

		if (shouldDisplayField)
			inputField.draw(this->window);

		this->window.display();
	}

}

// initialize the window with given values
void gameClass::initWindow() {
	this->window.create(sf::VideoMode(this->windowWidth, this->windowHeight), this->title, sf::Style::Close);
	this->window.setFramerateLimit(240);
	updateWindow();
}

// update the window
// handles main game logic and stores variables
void gameClass::updateWindow() {
	sf::Text confirmation;
	sf::Font font;
	sf::Sprite gameMap;
	sf::Sprite npc;
	sf::Texture inputBgT;
	sf::Texture gameMapT;
	sf::Texture npcT;
	sf::Clock clock;
	sf::Time dt;

	if (!font.loadFromFile("Roboto-Medium.ttf")) {
		cout << "failed to load font" << endl;
	}
	else if (!inputBgT.loadFromFile("assets/crate1.png")) {
		cout << "failed to load crate1.png" << endl;
	}
	else if (!gameMapT.loadFromFile("assets/map.png")) {
		cout << "failed to load map.png" << endl;
	}
	else if (!npcT.loadFromFile("assets/npc1.png")) {
		cout << "failed to load Nestashev.png" << endl;
	}

	gameMap.setTexture(gameMapT);
	npc.setTexture(npcT);
	npc.setOrigin(46/2, 112);
	npc.setPosition(794, 539);

	field inputField(sf::Color(255, 255, 255, 128), 400, 275, 1280 / 2 - 400 / 2, 720 / 2 - 275 / 2, 1.0f, 1.0f, font, inputBgT);
	player plr(1280 / 2, 539, 0, 20, 100);


	while (this->window.isOpen()) {
		sf::Event event;
		while (this->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->window.close();

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::E && (plr.getPos().x > npc.getPosition().x - 63 && plr.getPos().x < npc.getPosition().x + 63)) {
					this->drawFight(plr, event, inputField);
				}
			}
		}

		this->window.clear();

		this->window.draw(gameMap);
		this->window.draw(npc);

		plr.update(event, dt.asSeconds());
		plr.draw(this->window);
		
		this->window.display();

		dt = clock.restart();
	}
}

#include "game.hpp"
#include <random>
#include <time.h>

// set variables for window details
gameClass::gameClass(int height, int width, string title) {
	this->windowHeight = height;
	this->windowWidth = width;
	this->title = title;
}

gameClass::~gameClass() {

}

// draw the fight scene
void gameClass::fightScene(player& plr, field& inputField, sf::Time& dt, sf::Clock& clock, int npcNum) {
	// vars for fight - done
	// fight logic - done
	// win/loss condition - done
	// rewards - done
	// animations - 

	// set random rand seed
	srand((int)time(0));

	bool fightEnded = false;
	bool shouldDisplayField = false;
	bool inPos = false;
	//char animateRotation = 'f';
	//int rotation = 0;
	int row = rand() % 15;
	wstring answer;

	enemy enemy(npcNum * npcNum * 100, npcNum * 20);

	plr.setPos(sf::Vector2f(62.5 / 2, 539));
	plr.setSize(sf::Vector2f(62.5 * 2, 100 * 2));

	// set the question
	inputField.setQuestion(row);

	sf::Event event;

	// while window is open and fight hasn't ended
	while (this->window.isOpen() && !fightEnded) {
		// enter animation
		if (plr.getPos().x < 240) {
			plr.move(sf::Vector2f(240 * 3 * dt.asSeconds(), 0));
			enemy.move(sf::Vector2f(-275 * 3 * dt.asSeconds(), 0));
		}
		else if (inPos == false) {
			inPos = true;
			shouldDisplayField = true;
		}

		//if (animateRotation != 'f') {
		//	rotation = 45 * dt.asSeconds();

		//	plr.rotate(rotation);

		//}

		// while looking through event list
		while (this->window.pollEvent(event)) {
			// if any text is entered
			if (event.type == event.TextEntered) {
				cout << event.text.unicode << endl;

				// if enter is pressed
				if (event.text.unicode == 13) {
					if (answer != L"пропуск") {
						if (inputField.checkAnswer(row)) {
							bool dead = enemy.takeDamage(plr.attack);

							if (dead) {
								plr.money += npcNum * npcNum * 25;
							}
							else {
								//animateRotation = 'e';
							}
						}
						else {
							bool dead = plr.takeDamage(enemy.attack);
							if (dead) {
								fightEnded = true;
								plr.setSize(sf::Vector2f(62.5, 100));

							}
							else {
								//animateRotation = 'p';
							}
						}
					}
					else {
						enemy.takeDamage(100000);
						plr.money += npcNum * npcNum * 25;
					}
					row = 15;
					inputField.setQuestion(row);
					answer = L"";
				}

				// if backspace is pressed
				else if (event.text.unicode == 8) {
					if (!answer.empty()) {
						answer.pop_back();
					}
				}
				// if ([А-я] || [0-9] || space || minus) is pressed
				else if ((event.text.unicode >= 1040 && event.text.unicode <= 1117) || (event.text.unicode <= 57 && event.text.unicode >= 48) || event.text.unicode == 32 || event.text.unicode == 45) {
					// convert from upper to lower case
					if (event.text.unicode >= 1040 && event.text.unicode <= 1071) {
						answer += event.text.unicode + 32;
					}
					else {
						answer += event.text.unicode;
					}
				}
				inputField.input.setString(answer);
			}

			else if (event.type == sf::Event::Closed) {
				this->window.close();
			}

		}

		this->window.clear();

		plr.draw(this->window);
		enemy.draw(this->window);


		if (shouldDisplayField)
			inputField.draw(this->window);

		this->window.display();

		dt = clock.restart();
	}

}

// initialize the window with given values
void gameClass::initWindow() {
	this->window.create(sf::VideoMode(this->windowWidth, this->windowHeight), this->title, sf::Style::Close);
	this->window.setFramerateLimit(240);
	mainScene();
}

// update the window
// handles main game logic and stores variables
void gameClass::mainScene() {
	sf::Text confirmation;
	sf::Font font;
	sf::Sprite gameMap;
	sf::Sprite npc;
	sf::Texture inputBgT;
	sf::Texture gameMapT;
	sf::Texture npcT;
	sf::Clock clock;
	sf::Time dt;

	if (!font.loadFromFile("font.ttf")) {
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
	npc.setOrigin(46 / 2, 112);
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
					this->fightScene(plr, inputField, dt, clock, 1);
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

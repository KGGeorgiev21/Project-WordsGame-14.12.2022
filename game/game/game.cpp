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
void gameClass::fightScene(player& plr, field& inputField, sf::Time& dt, sf::Clock& clock, int npcNum, sf::Text& money, sf::Texture& texture) {
	// vars for fight - done
	// fight logic - done
	// win/loss condition - done
	// rewards - done
	// animations - almost done

	// set random rand seed
	srand((int)time(0));

	bool fightEnded = false;
	bool shouldDisplayField = false;
	bool inPos = false;
	char animateRotation = 'f';
	int rotatePart = 1;
	int row = rand() % 16;
	wstring answer;



	enemy enemy(npcNum * npcNum * 100, npcNum * 20, texture);

	plr.setPos(sf::Vector2f(62.5 / 2, 539));
	plr.setSize(sf::Vector2f(62.5 * 2, 100 * 2));

	// set the question
	inputField.setQuestion(row);

	sf::Event event;

	// while window is open and fight hasn't ended
	while (this->window.isOpen() && !fightEnded) {
		// enter animation
		if (plr.getPos().x < 240) {
			plr.move(sf::Vector2f(240 * 5 * dt.asSeconds(), 0));
			enemy.move(sf::Vector2f(-275 * 5 * dt.asSeconds(), 0));
		}
		else if (inPos == false) {
			inPos = true;
			cout << enemy.getPos().x;
			plr.setPos(sf::Vector2f(240, 539));
			enemy.setPos(sf::Vector2f(990, 334));
			shouldDisplayField = true;
		}

		while (animateRotation != 'f') {
			if (animateRotation == 'e') {
				switch (rotatePart) {
				case 1:
					plr.rotate(dt.asSeconds() * 45 * 20);
					if (plr.getRotation() > 45) {
						plr.setRotation(45);
						rotatePart = 2;
					}
					break;
				case 2:
					plr.rotate(dt.asSeconds() * -45 * 16);
					if (plr.getRotation() > 100) {
						plr.setRotation(0);
						rotatePart = 1;
						animateRotation = 'f';
					}
					break;
				}
			}
			if (animateRotation == 'p') {
				switch (rotatePart) {
				case 1:
					enemy.rotate(dt.asSeconds() * -45 * 20);
					if (enemy.getRotation() > 315) {
						enemy.setRotation(315);
						rotatePart = 2;
					}
					break;
				case 2:
					enemy.rotate(dt.asSeconds() * 45 * 16);
					if (enemy.getRotation() > 0 && enemy.getRotation() < 180) {
						enemy.setRotation(0);
						rotatePart = 1;
						animateRotation = 'f';
					}
					break;
				}
			}

			this->window.clear();

			plr.draw(this->window, dt,true);
			enemy.draw(this->window, true);
			this->window.draw(money);

			if (shouldDisplayField)
				inputField.draw(this->window);

			this->window.display();

			dt = clock.restart();
		}

		// while looking through event list
		while (this->window.pollEvent(event)) {
			// if any text is entered
			if (event.type == event.TextEntered) {

				// if enter is pressed
				if (event.text.unicode == 13) {
					if (answer != L"пропуск") {
						if (inputField.checkAnswer(row)) {
							bool dead = enemy.takeDamage(plr.attack);

							if (dead) {
								plr.money += npcNum * npcNum * 25;
								money.setString("$" + to_string(plr.money));
							}
							animateRotation = 'e';
						}
						else {
							bool dead = plr.takeDamage(enemy.attack);
							if (dead) {
								fightEnded = true;
								plr.setSize(sf::Vector2f(62.5, 100));
							}
							animateRotation = 'p';
						}
					}
					else {
						enemy.takeDamage(100000);
						plr.money += npcNum * npcNum * 25;
						money.setString("$" + to_string(plr.money));
						animateRotation = 'e';
					}
					row = rand() % 16;
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

		plr.draw(this->window, dt,true);
		enemy.draw(this->window, true);
		this->window.draw(money);

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
	sf::Text money;
	sf::Font font;
	sf::Sprite gameMap;
	sf::Sprite keyboardE;
	sf::Texture inputBgT;
	sf::Texture gameMapT;
	sf::Texture npcT;
	sf::Texture bossT;
	sf::Texture eKeyT;
	sf::Clock clock;
	sf::Time dt;

	if (!font.loadFromFile("font.ttf")) {
		cout << "failed to load font" << endl;
	}
	if (!inputBgT.loadFromFile("assets/crate1.png")) {
		cout << "failed to load crate1.png" << endl;
	}
	if (!gameMapT.loadFromFile("assets/map.png")) {
		cout << "failed to load map.png" << endl;
	}
	if (!npcT.loadFromFile("assets/npc1.png")) {
		cout << "failed to load npc1.png" << endl;
	}
	if (!bossT.loadFromFile("assets/boss.png")) {
		cout << "failed to load boss.png" << endl;
	}
	if (!eKeyT.loadFromFile("assets/key.png")) {
		cout << "failed to load key.png" << endl;
	}

	gameMap.setTexture(gameMapT);
	keyboardE.setTexture(eKeyT);
	money.setFont(font);
	money.setPosition(60,30);
	money.setCharacterSize(34);
	money.setFillColor(sf::Color(255, 220, 0));

	field inputField(sf::Color(255, 255, 255, 128), 400, 275, 1280 / 2 - 400 / 2, 720 / 2 - 275 / 2, 1.0f, 1.0f, font, inputBgT);
	player plr(sf::Vector2f(1280/2, 539), 0, 20, 100, 2, 0.3);
	npc npc1(npcT, 2, 0.3, sf::Vector2f(794, 539));
	npc npc2(npcT, 2, 0.3, sf::Vector2f(994, 539));
	npc boss(bossT, 2, 0.3, sf::Vector2f(1194, 539));

	money.setString("$" + to_string(plr.money));

	while (this->window.isOpen()) {
		sf::Event event;
		while (this->window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				this->window.close();

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::E) {
					if (plr.getPos().x > npc1.body.getPosition().x - 63 && plr.getPos().x < npc1.body.getPosition().x + 63) {
						this->fightScene(plr, inputField, dt, clock, 1, money, npcT);
					}
					else if (plr.getPos().x > npc2.body.getPosition().x - 63 && plr.getPos().x < npc2.body.getPosition().x + 63) {
						this->fightScene(plr, inputField, dt, clock, 2, money, npcT);
					}
					else if (plr.getPos().x > boss.body.getPosition().x - 63 && plr.getPos().x < boss.body.getPosition().x + 63) {
						this->fightScene(plr, inputField, dt, clock, 3, money, bossT);
					}
				}
			}
		}


		this->window.clear();

		this->window.draw(gameMap);

		if (plr.getPos().x > npc1.body.getPosition().x - 63 && plr.getPos().x < npc1.body.getPosition().x + 63) {
			keyboardE.setPosition(sf::Vector2f(npc1.body.getPosition().x + 30, npc1.body.getPosition().y - 116 - 19));
			window.draw(keyboardE);
		}
		else if (plr.getPos().x > npc2.body.getPosition().x - 63 && plr.getPos().x < npc2.body.getPosition().x + 63) {
			keyboardE.setPosition(sf::Vector2f(npc2.body.getPosition().x + 30, npc2.body.getPosition().y - 116 - 19));
			window.draw(keyboardE);
		}
		else if (plr.getPos().x > boss.body.getPosition().x - 63 && plr.getPos().x < boss.body.getPosition().x + 63) {
			keyboardE.setPosition(sf::Vector2f(boss.body.getPosition().x + 30, boss.body.getPosition().y - 116 - 19));
			window.draw(keyboardE);
		}
		else if (plr.getPos().x > 34 && plr.getPos().x < 259) {
			keyboardE.setPosition(sf::Vector2f(205, 372));
			window.draw(keyboardE);
		}


		npc1.update(dt);
		npc2.update(dt);
		boss.update(dt);

		npc1.draw(this->window);
		npc2.draw(this->window);
		boss.draw(this->window);
		this->window.draw(money);

		plr.update(event, dt);
		plr.draw(this->window, dt, false);

		this->window.display();

		dt = clock.restart();
	}
}

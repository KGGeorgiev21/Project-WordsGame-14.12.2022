#include "game.hpp"
#include <random>
#include <time.h>

// set variables for window details
gameClass::gameClass(int height, int width, string title) {
	this->windowHeight = height;
	this->windowWidth = width;
	this->title = title;
}

void gameClass::mainMenu() {
	sf::Sprite menu;
	sf::Sprite play;
	sf::Sprite quit;
	sf::Texture menuT;
	sf::Texture playT;
	sf::Texture quitT;
	sf::Event event;

	menuT.loadFromFile("assets/menuBackground.png");
	playT.loadFromFile("assets/playButton.png");
	quitT.loadFromFile("assets/quitButton.png");
	menu.setTexture(menuT);
	play.setTexture(playT);
	quit.setTexture(quitT);

	play.setOrigin(sf::Vector2f(110, 29));
	play.setPosition(sf::Vector2f(1280 / 2, 720 / 2 - 58));
	quit.setOrigin(sf::Vector2f(110, 29));
	quit.setPosition(sf::Vector2f(1280 / 2, 720 / 2 + 58));

	while (this->window.isOpen()) {
		while (this->window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				this->window.close();

			if (event.type == sf::Event::MouseButtonPressed) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					if ((event.mouseButton.x > play.getPosition().x - 110 && event.mouseButton.x < play.getPosition().x + 110) && (event.mouseButton.y > play.getPosition().y - 29 && event.mouseButton.y < play.getPosition().y + 29)) {
						this->mainScene();
					}
					if ((event.mouseButton.x > quit.getPosition().x - 110 && event.mouseButton.x < quit.getPosition().x + 110) && (event.mouseButton.y > quit.getPosition().y - 29 && event.mouseButton.y < quit.getPosition().y + 29)) {
						this->window.close();
					}
				}
			}
		}

		this->window.clear();
		this->window.draw(menu);
		this->window.draw(play);
		this->window.draw(quit);
		this->window.display();
	}
}

// draw the shop
void gameClass::drawShop(sf::Event& event, sf::Text& money, player& plr) {
	sf::Sprite shop;
	sf::Texture shopT;
	sf::Text title;
	sf::Text damageUpgrade;
	sf::Text healthUpgrade;
	sf::Text priceDamageText;
	sf::Text priceHealthText;
	sf::Text quitText;
	sf::Font font;
	sf::RectangleShape button1;
	sf::RectangleShape button2;
	sf::RectangleShape quitButton;

	font.loadFromFile("font.ttf");
	title.setFont(font);
	damageUpgrade.setFont(font);
	healthUpgrade.setFont(font);
	priceDamageText.setFont(font);
	priceHealthText.setFont(font);
	quitText.setFont(font);

	shopT.loadFromFile("assets/shop.png");
	shop.setTexture(shopT);
	title.setString("S h o p");
	title.setCharacterSize(100);
	title.setPosition(sf::Vector2f(465, 4));
	damageUpgrade.setString("Damage +50");
	damageUpgrade.setCharacterSize(48);
	damageUpgrade.setPosition(sf::Vector2f(392, 250));
	healthUpgrade.setString("Health +60");
	healthUpgrade.setCharacterSize(48);
	healthUpgrade.setPosition(sf::Vector2f(392, 350));
	button1.setFillColor(sf::Color::Green);
	button1.setSize(sf::Vector2f(150, 75));
	button1.setOrigin(0, 75 / 2);
	button1.setPosition(sf::Vector2f(713, 285));
	button2.setFillColor(sf::Color::Green);
	button2.setSize(sf::Vector2f(150, 75));
	button2.setOrigin(0, 75 / 2);
	button2.setPosition(sf::Vector2f(713, 383));
	quitButton.setSize(sf::Vector2f(200, 88));
	quitButton.setOrigin(100, 0);
	quitButton.setPosition(sf::Vector2f(1280 / 2, 553));
	quitButton.setFillColor(sf::Color::Red);
	priceDamageText.setString("$" + to_string(plr.priceDamage));
	priceDamageText.setCharacterSize(40);
	priceDamageText.setPosition(753, 257);
	priceHealthText.setString("$" + to_string(plr.priceHealth));
	priceHealthText.setCharacterSize(40);
	priceHealthText.setPosition(753, 355);
	quitText.setString("close");
	quitText.setCharacterSize(40);
	quitText.setOrigin(sf::Vector2f(12 * 5, 20));
	quitText.setPosition(1280 / 2, 553 + 40);

	this->window.setTitle("Shop");

	while (this->window.isOpen()) {
		while (this->window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				this->window.close();
			}

			if (event.type == sf::Event::MouseButtonPressed) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					if ((event.mouseButton.x >= button1.getPosition().x && event.mouseButton.x <= button1.getPosition().x + 150) && (event.mouseButton.y <= button1.getPosition().y + 75 / 2 && event.mouseButton.y >= button1.getPosition().y - 75 / 2)) {
						if (plr.money >= plr.priceDamage) {
							plr.attack += 50;
							plr.money -= plr.priceDamage;
							plr.priceDamage *= 2;
							money.setString("$" + to_string(plr.money));
							priceDamageText.setString("$" + to_string(plr.priceDamage));
							if (priceDamageText.findCharacterPos(100).x >= 850) {
								priceDamageText.move(-abs(priceDamageText.findCharacterPos(100).x - 850) * 1.5, 0);
							}
						}
					}
					else if ((event.mouseButton.x >= button2.getPosition().x && event.mouseButton.x <= button2.getPosition().x + 150) && (event.mouseButton.y <= button2.getPosition().y + 75 / 2 && event.mouseButton.y >= button2.getPosition().y - 75 / 2)) {
						if (plr.money >= plr.priceHealth) {
							plr.maxHp += 60;
							plr.hp = plr.maxHp;
							cout << plr.hp << endl;
							plr.money -= plr.priceHealth;
							plr.priceHealth *= 2;
							money.setString("$" + to_string(plr.money));
							priceHealthText.setString("$" + to_string(plr.priceHealth));
							if (priceHealthText.findCharacterPos(100).x >= 850) {
								priceHealthText.move(-abs(priceHealthText.findCharacterPos(100).x - 850) * 1.5, 0);
							}
						}
					}
					else if ((event.mouseButton.x >= quitButton.getPosition().x - 100 && event.mouseButton.x <= quitButton.getPosition().x + 100) && (event.mouseButton.y >= quitButton.getPosition().y && event.mouseButton.y <= quitButton.getPosition().y + 88)) {
						this->window.setTitle("Main");
						return;
					}
				}
			}
		}

		this->window.clear();
		this->window.draw(shop);
		this->window.draw(title);
		this->window.draw(damageUpgrade);
		this->window.draw(healthUpgrade);
		this->window.draw(button1);
		this->window.draw(button2);
		this->window.draw(priceDamageText);
		this->window.draw(priceHealthText);
		this->window.draw(quitButton);
		this->window.draw(quitText);
		this->window.draw(money);
		this->window.display();
	}
}

void gameClass::drawCutscene(sf::Event& event, sf::Sprite& background, enemy& enemy) {
	sf::Sprite endScreen;
	sf::Texture endScreenT;
	sf::Text endTitle;
	sf::Text endText;
	sf::Font font;
	sf::Time dt;
	sf::Clock clock;
	sf::RectangleShape cinematicBar1;
	sf::RectangleShape cinematicBar2;
	bool displayCredits = false;
	float scale = 1.0;
	float transparency = 255;

	endScreenT.loadFromFile("assets/shop.png");
	font.loadFromFile("font.ttf");
	endScreen.setTexture(endScreenT);
	endTitle.setFont(font);
	endText.setFont(font);
	endTitle.setCharacterSize(72);
	endText.setCharacterSize(68);
	endTitle.setString(L"Край");
	endText.setString(L"Благодаря, че играхте!");
	endTitle.setPosition(sf::Vector2f(1280 / 2 - 77, 20));
	endText.setPosition(sf::Vector2f(1280 / 2 - 400, 720 / 2 - 72));
	cinematicBar1.setSize(sf::Vector2f(1280, 100));
	cinematicBar2.setSize(sf::Vector2f(1280, 100));
	cinematicBar2.setPosition(0, 620);
	cinematicBar1.setFillColor(sf::Color::Black);
	cinematicBar2.setFillColor(sf::Color::Black);

	while (this->window.isOpen()) {
		while (this->window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				this->window.close();
		}

		if (scale < 1.5) {
			scale += 1 * dt.asSeconds();
			background.setScale(scale, scale);
			enemy.setScale(scale, scale);
			background.move(-840 * dt.asSeconds(), -240 * dt.asSeconds());
			enemy.move(sf::Vector2f(-100 * dt.asSeconds(), 240 * dt.asSeconds()));
		}
		else {
			if (enemy.getRotation() < 90) {
				enemy.rotate(90 * dt.asSeconds());
			}
			else {
				if (transparency > 0) {
					transparency -= 255 * dt.asSeconds();
					enemy.setFill(sf::Color(255, 255, 255, transparency));
				}
				else {
					displayCredits = true;
				}
			}
		}

		this->window.clear();
		if (displayCredits) {
			this->window.draw(endScreen);
			this->window.draw(endTitle);
			this->window.draw(endText);
		}
		else {
			this->window.draw(background);
			enemy.draw(this->window, false);
			this->window.draw(cinematicBar1);
			this->window.draw(cinematicBar2);
			dt = clock.restart();
		}
		this->window.display();
	}
}

// draw the fight scene
void gameClass::fightScene(player& plr, field& inputField, sf::Time& dt, sf::Clock& clock, int npcNum, sf::Text& money, sf::Texture& texture) {
	this->window.setTitle("Fight");

	// set random rand seed
	srand((int)time(0));

	sf::Sprite background;
	sf::Texture backgroundT;

	backgroundT.loadFromFile("assets/fightBg.png");
	background.setTexture(backgroundT);

	background.setPosition(0, 0);

	bool fightEnded = false;
	bool shouldDisplayField = false;
	bool inPos = false;
	char animateRotation = 'f';
	int rotatePart = 1;
	int row = rand() % 16;
	wstring answer;

	enemy enemy(npcNum * npcNum * 100, npcNum * 20, texture);

	plr.setPos(sf::Vector2f(62.5 / 2, 539));
	plr.setSize(sf::Vector2f(80 * 1.5, 103 * 1.5));

	// set the question
	inputField.setQuestion(row);

	sf::Event event;

	// while window is open and fight hasn't ended
	while (this->window.isOpen() && !fightEnded) {
		// enter animation
		if (plr.getPos().x < 340) {
			plr.move(sf::Vector2f(340 * 5 * dt.asSeconds(), 0));
			enemy.move(sf::Vector2f(-275 * 5 * dt.asSeconds(), 0));
		}
		else if (inPos == false) {
			inPos = true;
			plr.setPos(sf::Vector2f(240, 539));
			enemy.setPos(sf::Vector2f(990, 354));
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
						enemy.setFill(sf::Color::Red);
					}
					break;
				case 2:
					plr.rotate(dt.asSeconds() * -45 * 16);
					if (plr.getRotation() > 100) {
						plr.setRotation(0);
						rotatePart = 1;
						animateRotation = 'f';
						enemy.setFill(sf::Color::White);
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
						plr.setFill(sf::Color::Red);
					}
					break;
				case 2:
					enemy.rotate(dt.asSeconds() * 45 * 16);
					if (enemy.getRotation() > 0 && enemy.getRotation() < 180) {
						enemy.setRotation(0);
						rotatePart = 1;
						animateRotation = 'f';
						plr.setFill(sf::Color::White);
					}
					break;
				}
			}

			this->window.clear();

			this->window.draw(background);
			plr.draw(this->window, dt, true);
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
								if (npcNum == 3) {
									this->drawCutscene(event, background, enemy);
									break;
								}
								fightEnded = true;
								plr.setSize(sf::Vector2f(88, 111));
								this->window.setTitle("Main");
							}
							animateRotation = 'p';
						}
					}
					else {
						if (npcNum == 3) {
							this->drawCutscene(event, background, enemy);
							break;
						}
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

		this->window.draw(background);
		plr.draw(this->window, dt, true);
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
	mainMenu();
}

// update the window
// handles main game logic and stores variables
void gameClass::mainScene() {
	this->window.setTitle("Main");

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

	font.loadFromFile("font.ttf");
	inputBgT.loadFromFile("assets/crate1.png");
	gameMapT.loadFromFile("assets/map.png");
	npcT.loadFromFile("assets/npc1.png");
	bossT.loadFromFile("assets/boss.png");
	eKeyT.loadFromFile("assets/key.png");

	gameMap.setTexture(gameMapT);
	keyboardE.setTexture(eKeyT);
	money.setFont(font);
	money.setPosition(60, 30);
	money.setCharacterSize(34);
	money.setFillColor(sf::Color(255, 220, 0));

	field inputField(sf::Color(255, 255, 255, 128), 400, 275, 1280 / 2 - 400 / 2, 720 / 2 - 275 / 2, 1.0f, 1.0f, font, inputBgT);
	player plr(sf::Vector2f(1280 / 2, 539), 0, 20, 100, 2, 0.3);
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
					else if (plr.getPos().x > 34 && plr.getPos().x < 259) {
						this->drawShop(event, money, plr);
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
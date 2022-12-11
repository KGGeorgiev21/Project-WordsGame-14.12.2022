#include "player.hpp"

// initialize the player with given values
player::player(sf::Vector2f pos, int money, int attack, int maxHp, int imageCount, float switchTime) {
	this->priceDamage = 30;
	this->priceHealth = 45;
	this->money = money;
	this->attack = attack;
	this->maxHp = maxHp;
	this->hp = maxHp;
	this->speed = 250;

	this->textureLeft.loadFromFile("assets/left.png");
	this->textureRight.loadFromFile("assets/right.png");
	this->textureIdle.loadFromFile("assets/idle.png");

	this->imageCount = imageCount;
	this->switchTime = switchTime;
	this->totalTime = 0.f;
	this->currentImage = 0;
	this->uvRect.width = this->textureIdle.getSize().x / float(imageCount);
	this->uvRect.height = this->textureIdle.getSize().y - 8;
	this->uvRect.top = 0;
	this->plrBod.setSize(sf::Vector2f(88, 111));
	this->plrBod.setOrigin(88 / 2, 111);
	this->plrBod.setPosition(pos);
	this->plrBod.setTexture(&this->textureIdle);

	this->healthBar.setFillColor(sf::Color(0, 252, 36));
	this->healthBar.setSize(sf::Vector2f(-200, 24));
	this->healthBar.setOrigin(100, 12);
	this->healthBar.setPosition(sf::Vector2f((150 + 80/2) * 2, 505));
	this->healthBar.setOutlineThickness(5);
	this->healthBar.setOutlineColor(sf::Color::Black);
}

// handle input logic for player
void player::update(sf::Event& event, sf::Time dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->plrBod.move(-1 * dt.asSeconds() * this->speed, 0);
		if (this->plrBod.getTexture() != &this->textureLeft) {
			this->plrBod.setTexture(&this->textureLeft);
		}
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->plrBod.move(1 * dt.asSeconds() * this->speed, 0);
		if (this->plrBod.getTexture() != &this->textureRight) {
			this->plrBod.setTexture(&this->textureRight);
		}
	}
	else {
		if (this->plrBod.getTexture() != &this->textureIdle) {
			this->plrBod.setTexture(&this->textureIdle);
		}
	}
}

// draw the player to the screen
void player::draw(sf::RenderWindow& window, sf::Time dt, bool inFight) {
	if (inFight) {
		window.draw(this->healthBar);
		if (this->plrBod.getTexture() != &this->textureIdle) {
			this->plrBod.setTexture(&this->textureIdle);
		}
	}
	else {
		this->totalTime += dt.asSeconds();

		if (this->totalTime >= this->switchTime)
		{
			this->totalTime -= this->switchTime;
			this->currentImage++;

			if (this->currentImage >= this->imageCount)
			{
				this->currentImage = 0;
			}
		}

		this->uvRect.left = this->currentImage * this->uvRect.width;
		this->uvRect.width = abs(this->uvRect.width);

		this->plrBod.setTextureRect(this->uvRect);
	}
	window.draw(this->plrBod);
}

// set position of player sprite
void player::setPos(sf::Vector2f pos) {
	this->plrBod.setPosition(pos.x, pos.y);
}

// move player
void player::move(sf::Vector2f offset) {
	this->plrBod.move(offset);
}

// set rotation of player sprite
// 0 to reset
void player::setRotation(float degrees) {
	this->plrBod.setRotation(degrees);
}

// rotate player
void player::rotate(float degrees) {
	this->plrBod.rotate(degrees);
}

// set size of player
void player::setSize(sf::Vector2f size) {
	this->plrBod.setSize(size);
}

// take damage and update healthbar
bool player::takeDamage(int damage) {
	this->hp -= damage;

	// change healthbar color depending on hp
	if ((this->hp / this->maxHp) * 100 <= 0) {
		this->hp = maxHp;
		this->healthBar.setSize(sf::Vector2f(-200, 24));
		this->healthBar.setPosition(sf::Vector2f((150 + 80 / 2) * 2, 505));
		this->healthBar.setFillColor(sf::Color(163, 255, 0));
		return true;
	}
	else if ((this->hp / this->maxHp) * 100 <= 35) {
		this->healthBar.setFillColor(sf::Color(255, 78, 0));
	}
	else if ((this->hp / this->maxHp) * 100 <= 65) {
		this->healthBar.setFillColor(sf::Color(255, 220, 0));
	}

	//this->healthBar.move(sf::Vector2f(200 - 200 * (this->hp / this->maxHp), 0));
	this->healthBar.setSize(sf::Vector2f(-200 * (this->hp / this->maxHp), this->healthBar.getSize().y));

	return false;
}

// set fill color of sprite
void player::setFill(sf::Color color) {
	this->plrBod.setFillColor(color);
}

// get rotation of player
float player::getRotation() {
	return this->plrBod.getRotation();
}

// get position of player sprite
// returns Vector2f of the position
sf::Vector2f player::getPos() {
	return this->plrBod.getPosition();
}
#include "player.hpp"

// initialize the player with given values
player::player(float posX, float posY, int money, int attack, int maxHp) {
	this->posX = posX;
	this->posY = posY;
	this->money = money;
	this->attack = attack;
	this->maxHp = maxHp;
	this->hp = maxHp;
	this->speed = 250;

	this->plrBod.setSize(sf::Vector2f(62.5, 100));
	this->plrBod.setOrigin(62.5/2, 100);
	this->plrBod.setPosition(posX, posY);
}

player::~player() {

}

// handle input logic for player
void player::update(sf::Event& event, float dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->plrBod.move(-1 * dt * this->speed, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->plrBod.move(1 * dt * this->speed, 0);
	}
}

// draw the player to the screen
void player::draw(sf::RenderWindow& window) {
	window.draw(this->plrBod);
}

// set position of player sprite
void player::setPos(sf::Vector2f pos) {
	this->plrBod.setPosition(pos.x, pos.y);
}

void player::move(sf::Vector2f offset) {
	this->plrBod.move(offset);
}

// set rotation of player sprite
// 0 to reset
void player::setRotation(float degrees) {
	this->plrBod.setRotation(degrees);
}

void player::rotate(float degrees) {
	this->plrBod.rotate(degrees);
}

void player::setSize(sf::Vector2f size) {
	this->plrBod.setSize(size);
}

bool player::takeDamage(int damage) {
	this->hp -= damage;
	cout << "Player hp: " << this->hp << endl;

	if (this->hp <= 0) {
		return true;
	}
	return false;
}

float player::getRotation() {
	return this->plrBod.getRotation();
}

// get position of player sprite
// returns Vector2f of the position
sf::Vector2f player::getPos() {
	return this->plrBod.getPosition();
}
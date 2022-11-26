#include "player.hpp"

player::player(int posX, int posY, int money, int attack, int maxHp) {
	this->posX = posX;
	this->posY = posY;
	this->money = money;
	this->attack = attack;
	this->maxHp = maxHp;
	this->hp = maxHp;
	this->speed = 250;

	this->plrBod.setSize(sf::Vector2f(125, 200));
	this->plrBod.setPosition(posX, posY);
}

player::~player() {

}

void player::update(sf::Event& event, float dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		this->plrBod.move(-1 * dt * this->speed, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		this->plrBod.move(1 * dt * this->speed, 0);
	}
}

void player::draw(sf::RenderWindow& window) {
	window.draw(this->plrBod);
}
#include "enemy.hpp"

enemy::enemy(int maxHp, int attack, sf::Texture& texture) {
	this->maxHp = maxHp;
	this->attack = attack;
	this->hp = this->maxHp;
	
	this->uvRect.width = texture.getSize().x / 2;
	this->uvRect.height = texture.getSize().y;
	this->uvRect.left = 0;
	this->uvRect.top = 0;

	this->enemyBod.setTexture(&texture);
	this->enemyBod.setTextureRect(this->uvRect);
	this->enemyBod.setSize(sf::Vector2f(99, 125));
	this->enemyBod.setOrigin(49.5, 125);
	this->enemyBod.setPosition(sf::Vector2f(1230, 354));

	this->healthBar.setOutlineThickness(5);
	this->healthBar.setOutlineColor(sf::Color::Black);
	this->healthBar.setFillColor(sf::Color(163, 255, 0));
	this->healthBar.setSize(sf::Vector2f(200, 24));
	this->healthBar.setOrigin(100, 12);
	this->healthBar.setPosition(sf::Vector2f(1065, 300));
}

// set enemy position
void enemy::setPos(sf::Vector2f pos) {
	this->enemyBod.setPosition(pos);
}

// move enemy
void enemy::move(sf::Vector2f offset) {
	this->enemyBod.move(offset);
}

// draw enemy
void enemy::draw(sf::RenderWindow& window, bool inFight) {
	window.draw(this->enemyBod);
	if (inFight) {
		window.draw(this->healthBar);
	}
}

// take damage and update healthbar
bool enemy::takeDamage(int damage) {
	this->hp -= damage;

	if ((this->hp / this->maxHp) * 100 <= 0) {
		this->hp = maxHp;
		this->healthBar.setSize(sf::Vector2f(200, 24));
		this->healthBar.setPosition(sf::Vector2f(1065, 300));
		this->healthBar.setFillColor(sf::Color(163, 255, 0));
		return true;
	}
	else if ((this->hp / this->maxHp) * 100 <= 35) {
		this->healthBar.setFillColor(sf::Color(255, 78, 0));
	}
	else if ((this->hp / this->maxHp) * 100 <= 65) {
		this->healthBar.setFillColor(sf::Color(255, 220, 0));
	}

	this->healthBar.setSize(sf::Vector2f(200 * (this->hp / this->maxHp), this->healthBar.getSize().y));


	return false;
}

// set fill of enemy sprite
void enemy::setFill(sf::Color color) {
	this->enemyBod.setFillColor(color);
}

// set rotation of enemy
void enemy::setRotation(float angle)
{
	this->enemyBod.setRotation(angle);
}

// rotate enemy
void enemy::rotate(float angle) {
	this->enemyBod.rotate(angle);
}

void enemy::setScale(float scaleX, float scaleY) {
	this->enemyBod.setScale(scaleX, scaleY);
}

// get rotation of enemy
float enemy::getRotation()
{
	return this->enemyBod.getRotation();
}

// get position of enemy
// returns Vector2f of the position
sf::Vector2f enemy::getPos() {
	return this->enemyBod.getPosition();
}
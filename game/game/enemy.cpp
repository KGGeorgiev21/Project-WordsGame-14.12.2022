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
	this->enemyBod.setSize(sf::Vector2f(90, 116));
	this->enemyBod.setOrigin(45, 116);
	this->enemyBod.setPosition(sf::Vector2f(1230, 334));

	this->healthBar.setFillColor(sf::Color(163, 255, 0));
	this->healthBar.setSize(sf::Vector2f(200, 24));
	this->healthBar.setOrigin(100, 12);
	this->healthBar.setPosition(sf::Vector2f(990, 144));
}

enemy::~enemy() {

}

void enemy::setPos(sf::Vector2f pos) {
	this->enemyBod.setPosition(pos);
}

void enemy::move(sf::Vector2f offset) {
	this->enemyBod.move(offset);
}

void enemy::draw(sf::RenderWindow& window, bool inFight) {
	window.draw(this->enemyBod);
	if (inFight) {
		window.draw(this->healthBar);
	}
}

bool enemy::takeDamage(int damage) {
	this->hp -= damage;

	cout << (this->hp / this->maxHp) * 100 << endl;

	if ((this->hp / this->maxHp) * 100 <= 0) {
		this->hp = maxHp;
		this->healthBar.setSize(sf::Vector2f(200, 24));
		this->healthBar.setPosition(sf::Vector2f(990, 144));
		this->healthBar.setFillColor(sf::Color(163, 255, 0));
		return true;
	}
	else if ((this->hp / this->maxHp) * 100 <= 35) {
		this->healthBar.setFillColor(sf::Color(255, 78, 0));
	}
	else if ((this->hp / this->maxHp) * 100 <= 65) {
		this->healthBar.setFillColor(sf::Color(255, 220, 0));
	}

	this->healthBar.move(sf::Vector2f(damage / (this->maxHp / 100), 0));
	this->healthBar.setSize(sf::Vector2f(200 * (this->hp / this->maxHp), this->healthBar.getSize().y));

	return false;
}

void enemy::setRotation(float angle)
{
	this->enemyBod.setRotation(angle);
}

void enemy::rotate(float angle) {
	this->enemyBod.rotate(angle);
}

float enemy::getRotation()
{
	return this->enemyBod.getRotation();
}

sf::Vector2f enemy::getPos() {
	return this->enemyBod.getPosition();
}

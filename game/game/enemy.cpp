#include "enemy.hpp"

enemy::enemy(int maxHp, int attack) {
	this->maxHp = maxHp;
	this->attack = attack;
	this->hp = this->maxHp;

	this->enemyBod.setFillColor(sf::Color::White);
	this->enemyBod.setSize(sf::Vector2f(100, 160));
	this->enemyBod.setOrigin(50, 160);
	this->enemyBod.setPosition(sf::Vector2f(1230, 334));

	this->healthBar.setFillColor(sf::Color(0, 252, 36));
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

void enemy::draw(sf::RenderWindow& window) {
	window.draw(this->enemyBod);
	window.draw(this->healthBar);
}

bool enemy::takeDamage(int damage) {
	this->hp -= damage;

	if (this->hp <= 0) {
		this->hp = maxHp;
		cout << "Enemy dead" << endl;
		this->healthBar.setSize(sf::Vector2f(200, 24));
		this->healthBar.setPosition(sf::Vector2f(990, 144));
		return true;
	}

	this->healthBar.setSize(sf::Vector2f(this->healthBar.getSize().x - damage * 2, this->healthBar.getSize().y));
	this->healthBar.move(sf::Vector2f(damage, 0));

	cout << "Enemy hp: " << this->hp << endl;

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

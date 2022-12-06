#include "enemy.hpp"

enemy::enemy(int maxHp, int attack) {
	this->maxHp = maxHp;
	this->attack = attack;
	this->hp = this->maxHp;

	this->enemyBod.setFillColor(sf::Color::White);
	this->enemyBod.setOrigin(50, 160);
	this->enemyBod.setSize(sf::Vector2f(100, 160));
	this->enemyBod.setPosition(sf::Vector2f(1230, 334));
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
}

bool enemy::takeDamage(int damage) {
	this->hp -= damage;

	if (this->hp <= 0) {
		this->hp = maxHp;
		cout << "Enemy dead" << endl;
		return true;
	}

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

#pragma once
#include "precompile.hpp"

class enemy {
protected:
	sf::IntRect uvRect;
	sf::RectangleShape enemyBod;
	sf::RectangleShape healthBar;

	int maxHp;

public:
	int attack;
	float hp;
	string name;

	enemy(int maxHp, int attack, sf::Texture& texture);

	void setPos(sf::Vector2f pos);
	void move(sf::Vector2f offset);
	void draw(sf::RenderWindow& window, bool inFight);
	bool takeDamage(int damage);
	void setFill(sf::Color color);
	void setRotation(float angle);
	void rotate(float angle);
	float getRotation();

	sf::Vector2f getPos();

};
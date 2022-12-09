
#pragma once
#include "precompile.hpp"

class enemy {
protected:
	sf::RectangleShape enemyBod;
	sf::RectangleShape healthBar;

	int maxHp;

public:
	int attack;
	int hp;
	string name;

	enemy(int maxHp, int attack);
	~enemy();

	void setPos(sf::Vector2f pos);
	void move(sf::Vector2f offset);
	void draw(sf::RenderWindow& window);
	bool takeDamage(int damage);
	void setRotation(float angle);
	void rotate(float angle);
	float getRotation();

	sf::Vector2f getPos();

};
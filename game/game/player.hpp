#include "precompile.hpp"

class player {
protected:
	sf::RectangleShape plrBod;
	sf::RectangleShape healthBar;

	int maxHp;
	int speed;
	float posX;
	float posY;

public:
	int money;
	int hp;
	int attack;

	player(float posX, float posY, int money, int attack, int maxHp);
	~player();

	void update(sf::Event& event, float dt);
	void draw(sf::RenderWindow& window);
	void setPos(sf::Vector2f pos);
	void move(sf::Vector2f offset);
	void setSize(sf::Vector2f size);
	void setRotation(float degrees);
	void rotate(float degrees);
	bool takeDamage(int damage);
	float getRotation();

	sf::Vector2f getPos();
};

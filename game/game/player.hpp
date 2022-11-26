#include "precompile.hpp"

class player {
protected:
	sf::RectangleShape plrBod;

	int hp;
	int maxHp;
	int attack;
	int money;
	int posX;
	int posY;
	int speed;

public:
	player(int posX, int posY, int money, int attack, int maxHp);
	~player();

	void update(sf::Event& event, float dt);
	void draw(sf::RenderWindow& window);

};
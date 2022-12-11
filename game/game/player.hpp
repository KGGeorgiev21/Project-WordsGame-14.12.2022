#include "precompile.hpp"

class player {
protected:
	sf::RectangleShape healthBar;
	sf::Texture textureLeft;
	sf::Texture textureRight;
	sf::Texture textureIdle;

	float posX;
	float posY;
	float switchTime;
	float totalTime;
	int maxHp;
	int speed;
	int imageCount;
	int currentImage;

public:
	sf::IntRect uvRect;
	sf::RectangleShape plrBod;

	int money;
	float hp;
	int attack;

	player(sf::Vector2f pos, int money, int attack, int maxHp, int imageCount, float switchTime);
	~player();

	void update(sf::Event& event, sf::Time dt);
	void draw(sf::RenderWindow& window, sf::Time dt, bool inFight);
	void setPos(sf::Vector2f pos);
	void move(sf::Vector2f offset);
	void setSize(sf::Vector2f size);
	void setRotation(float degrees);
	void rotate(float degrees);
	bool takeDamage(int damage);
	float getRotation();

	sf::Vector2f getPos();
};

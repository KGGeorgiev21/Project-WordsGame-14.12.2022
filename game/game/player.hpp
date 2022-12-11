#include "precompile.hpp"

class player {
protected:
	
	sf::RectangleShape healthBar;
	sf::Texture textureLeft;
	sf::Texture textureRight;
	sf::Texture textureIdle;

	float switchTime;
	float totalTime;
	int speed;
	int imageCount;
	int currentImage;

public:
	sf::IntRect uvRect;
	sf::RectangleShape plrBod;

	int money;
	int maxHp;
	float hp;
	int attack;
	int priceDamage;
	int priceHealth;

	player(sf::Vector2f pos, int money, int attack, int maxHp, int imageCount, float switchTime);

	void update(sf::Event& event, sf::Time dt);
	void draw(sf::RenderWindow& window, sf::Time dt, bool inFight);
	void setPos(sf::Vector2f pos);
	void move(sf::Vector2f offset);
	void setSize(sf::Vector2f size);
	void setRotation(float degrees);
	void rotate(float degrees);
	bool takeDamage(int damage);
	void setFill(sf::Color);
	float getRotation();

	sf::Vector2f getPos();
};

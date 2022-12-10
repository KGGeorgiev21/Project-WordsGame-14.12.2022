#pragma once

class npc {
protected:
	float totalTime;
	float switchTime;
	int currentImage;
	int imageCount;

public:
	sf::IntRect uvRect;
	sf::RectangleShape body;

	npc(sf::Texture& texture, int imageCount, float switchTime, sf::Vector2f pos);
	~npc();

	void update(sf::Time dt);
	void draw(sf::RenderWindow& window);
};
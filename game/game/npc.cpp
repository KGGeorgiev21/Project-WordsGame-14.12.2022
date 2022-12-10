#include "precompile.hpp"
#include "npc.hpp"

npc::npc(sf::Texture& texture, int imageCount, float switchTime, sf::Vector2f pos) {
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	this->totalTime = 0.f;
	this->currentImage = 0;
	this->uvRect.width = texture.getSize().x / float(imageCount);
	this->uvRect.height = texture.getSize().y;
	this->uvRect.top = 0;
	this->body.setSize(sf::Vector2f(90, 116));
	this->body.setOrigin(90/2, 116);
	this->body.setPosition(pos);
	this->body.setTexture(&texture);
}

npc::~npc() {

}

void npc::update(sf::Time dt) {
	this->totalTime += dt.asSeconds();

	if (this->totalTime >= this->switchTime)
	{
		this->totalTime -= this->switchTime;
		this->currentImage++;

		if (this->currentImage >= this->imageCount)
		{
			this->currentImage = 0;
		}
	}

	this->uvRect.left = this->currentImage * this->uvRect.width;
	this->uvRect.width = abs(this->uvRect.width);

	this->body.setTextureRect(this->uvRect);
}

void npc::draw(sf::RenderWindow& window) {
	window.draw(this->body);
}
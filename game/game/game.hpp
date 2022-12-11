#include "precompile.hpp"
#include "input.hpp"
#include "player.hpp"
#include "enemy.hpp"
#include "npc.hpp"

class gameClass {
private:
	
	sf::RenderWindow window;
	int windowHeight;
	int windowWidth;
	string title;
	
public:
	gameClass(int height, int width, string title);

	void initWindow();
	void mainScene();

	void fightScene(player& plr, field& inputField, sf::Time& dt, sf::Clock& clock, int npcNum, sf::Text& money, sf::Texture& texture);
	void drawShop(sf::Event &event, sf::Text &money, player &plr);
};
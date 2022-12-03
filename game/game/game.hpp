#include "precompile.hpp"
#include "input.hpp"
#include "player.hpp"

class gameClass {
private:
	
	sf::RenderWindow window;
	int windowHeight;
	int windowWidth;
	string title;
	
public:
	gameClass(int height, int width, string title);
	~gameClass();

	void initWindow();
	void updateWindow();

	void drawFight(player& plr, sf::Event& event, field& inputField);
};
#include "precompile.h"

class game {
private:
	sf::RenderWindow window;
	int windowHeight = 0;
	int windowWidth = 0;
	string title = "";
	
public:
	game(int height, int width, string title);
	~game();

	void initWindow();
	void updateWindow(sf::CircleShape& shape);
	void draw();

};
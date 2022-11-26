#include "precompile.hpp"
#include "input.hpp"

class game {
private:
	
	sf::RenderWindow window;
	int windowHeight;
	int windowWidth;
	string title;
	
public:
	game(int height, int width, string title);
	~game();

	void initWindow();
	void updateWindow();
};
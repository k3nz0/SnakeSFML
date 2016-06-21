#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "config.hpp"


#define MAX_NUMBER_OF_ITEMS 3

class Menu{
public:
	Menu();
	void processEvents(sf::RenderWindow &window);
	void render(sf::RenderWindow &window);
	void moveUp();
	void moveDown();
	int getSelectedItem() const;
	void setSelectedItem(int item);
	//~Menu();
private:
	void handlePlayerInput(sf::Keyboard::Key key);



	int mSelectedItem;
	int mCurrentItem;
	sf::Font mFont;
	sf::Text mMenu[MAX_NUMBER_OF_ITEMS];

};
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "config.hpp"

#include "Menu.hpp"
#include "Options.hpp"
#include "Game.hpp"

class GameState{
public:
	GameState();
	void run();

private:
	sf::RenderWindow mWindow;
	sf::Music mMusic;

	Menu mMenu;
	Game mGame;
	Options mOptions;

	int mLevel;

	bool mGoMenu;
	bool mGoGame;
	bool mGoOptions;
	bool mGoLost;


};



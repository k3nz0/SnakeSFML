#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Menu.hpp"
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

	bool mGoMenu;
	bool mGoGame;
	bool mGoLost;


};



#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>



struct Snake{
	int x, y;
};

struct Fruct{
	int x, y;
};

class Game{
public:
	Game();
	void reset();
	void play(sf::RenderWindow &window);
	bool getPlaying();
	void setPlaying(bool b);
private:
	void processEvents(sf::RenderWindow &window);
	void update();
	void render(sf::RenderWindow &window);
	void handlePlayerInput(sf::Keyboard::Key key);
	
	sf::Texture mTexture1;
	sf::Texture mTexture2;
	sf::Texture mTexture3;
	
	sf::Sprite mSprite1;
	sf::Sprite mSprite2;
	sf::Sprite mSprite3;

	sf::Clock timeClock;

	Snake mSnake[100];
	Fruct mFruct;
	int mDirection;
	int mSnakeLength;
		
	float timer, delay;

	bool mPlaying;
};
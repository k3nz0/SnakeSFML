#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>



struct Snake{
	int x, y;
};

struct Fruit{
	int x, y;
};

class Game{
public:
	Game();
	void reset();
	void play(sf::RenderWindow &window);
	bool getPlaying();
	void setPlaying(bool b);
	void setLevel(int level);
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

	sf::Clock mTimeClock;

	Snake mSnake[100];
	Fruit mFruit;
	int mDirection;
	int mSnakeLength;
		
	float mTimer, mDelay;

	bool mPlaying;
};
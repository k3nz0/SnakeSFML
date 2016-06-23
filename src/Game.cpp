#include "../include/Game.hpp"
#include "../include/config.hpp"
#include <iostream>

Game::Game()
{
	/*if(!mTexture1.loadFromFile("resources/images/white.png")){
		std::cout << "Error loading images/white.png" << std::endl;
	}*/

	if(!mTexture2.loadFromFile("resources/images/red.png")){
		std::cout << "Error loading resources/images/green.png" << std::endl;
	}
	if(!mTexture3.loadFromFile("resources/images/green.png")){
		std::cout << "Error loading resources/images/green.png" << std::endl;
	}
	
	mSprite1.setTexture(mTexture1);
	mSprite2.setTexture(mTexture2);
	mSprite3.setTexture(mTexture3);
	
	reset();

	mTimer = 0, mDelay = 0.1;
	mPlaying = true;

}

void Game::reset(){
	mDirection = 1;

	for(int i = 0; i < 100; i++)
		mSnake[i].x = 0, mSnake[i].y = 0;

	mSnakeLength = 4;
	
	srand(time(0));
	
	mFruit.x = rand() % N;
	mFruit.y = rand() % M;

}

void Game::play(sf::RenderWindow &window){
	float time = mTimeClock.getElapsedTime().asSeconds();
	mTimeClock.restart();
	mTimer += time;
	processEvents(window);

	if(mTimer > mDelay){
		mTimer = 0;
		update();
		render(window);
	}

}

bool Game::getPlaying(){
	return mPlaying;
}

void Game::setPlaying(bool b){
	mPlaying = b;
}

void Game::setLevel(int level){
	if(level == 0)
		mDelay = 0.15;
	else if(level == 1)
		mDelay = 0.10;
	else if(level == 2)
		mDelay = 0.05;
	else
		mDelay = 0.1;
}

// --- PRIVATE ---
void Game::processEvents(sf::RenderWindow &window){
	sf::Event event;

	while(window.pollEvent(event)){
		if(event.type == sf::Event::Closed)
			window.close();
		else if(event.type == sf::Event::KeyPressed)
			handlePlayerInput(event.key.code);
		
	}
}

void Game::update(){
	if(mSnake[0].x == mFruit.x && mSnake[0].y == mFruit.y){
		mFruit.x = rand() % N;
		mFruit.y = rand() % M;
		mSnakeLength++;
	}
	
	for(int i = mSnakeLength - 1; i > 0; i--){
		mSnake[i].x = mSnake[i - 1].x;
		mSnake[i].y = mSnake[i - 1].y;
	}

	if(mDirection == 0 && mSnake[0].y - 1 != mSnake[1].y){
	//	std::cout << mSnake[0].y - 1 << " " << mSnake[1].y << std::endl;
		mSnake[0].y -= 1;		
	}
	else if(mDirection == 1 && mSnake[0].y + 1 != mSnake[1].y){
	//	std::cout << mSnake[0].y + 1 << " " << mSnake[1].y << std::endl;
		mSnake[0].y += 1;
	}
	else if(mDirection == 2 && mSnake[0].x - 1 != mSnake[1].x){
	//	std::cout << mSnake[0].x - 1 << " " << mSnake[1].x << std::endl;
		mSnake[0].x -= 1;
	}
	else if(mDirection == 3 && mSnake[0].x + 1 != mSnake[1].x){
	//	std::cout << mSnake[0].x + 1 << " " << mSnake[1].x << std::endl;
		mSnake[0].x += 1;
	}


	if(mSnake[0].x >= N)
		mSnake[0].x = 0;
	if(mSnake[0].x < 0)
		mSnake[0].x = N - 1;	
	if(mSnake[0].y >= M)
		mSnake[0].y = 0;
	if(mSnake[0].y < 0)
		mSnake[0].y = M - 1;		


	for(int i = 1; i < mSnakeLength; i++){
		if(mSnake[0].x == mSnake[i].x && mSnake[0].y == mSnake[i].y){
			mSnakeLength = 4;
			mPlaying = false;
			break;
		}
	}
}

void Game::render(sf::RenderWindow &window){
	window.clear();
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			mSprite1.setPosition(i * size, j * size);
			window.draw(mSprite1);
		}
	}

	for(int i = 0; i < mSnakeLength; i++){
		mSprite2.setPosition(mSnake[i].x * size, mSnake[i].y * size);
		window.draw(mSprite2);
	}
	
	mSprite3.setPosition(mFruit.x * size, mFruit.y * size);
	window.draw(mSprite3);
	window.display();
}

void Game::handlePlayerInput(sf::Keyboard::Key key){
	if(key == sf::Keyboard::Up && mDirection != 1)
		mDirection = 0;
	else if(key == sf::Keyboard::Down && mDirection != 0)
		mDirection = 1;
	else if(key == sf::Keyboard::Left && mDirection != 3)
		mDirection = 2;
	else if(key == sf::Keyboard::Right && mDirection != 2)
		mDirection = 3;
}



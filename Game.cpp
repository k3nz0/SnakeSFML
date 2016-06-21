#include "Game.hpp"
#include "config.hpp"
#include <iostream>

Game::Game()
{
	if(!mTexture1.loadFromFile("images/swhite.png")){
		std::cout << "Error loading images/white.png" << std::endl;
	}
	if(!mTexture2.loadFromFile("images/red.png")){
		std::cout << "Error loading images/green.png" << std::endl;
	}
	if(!mTexture3.loadFromFile("images/green.png")){
		std::cout << "Error loading images/green.png" << std::endl;
	}
	
	mSprite1.setTexture(mTexture1);
	mSprite2.setTexture(mTexture2);
	mSprite3.setTexture(mTexture3);
	
	reset();

	timer = 0, delay = 0.1;
	mPlaying = true;

}

void Game::reset(){
	mDirection = 1;

	for(int i = 0; i < 100; i++)
		mSnake[i].x = 0, mSnake[i].y = 0;

	mSnakeLength = 4;
	
	srand(time(0));
	
	mFruct.x = rand() % N;
	mFruct.y = rand() % M;

}

void Game::play(sf::RenderWindow &window){
	float time = timeClock.getElapsedTime().asSeconds();
	timeClock.restart();
	timer += time;
	processEvents(window);

	if(timer > delay){
		timer = 0;
		update();
		render(window);
	}

}
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
	if(mSnake[0].x == mFruct.x && mSnake[0].y == mFruct.y){
		mFruct.x = rand() % N;
		mFruct.y = rand() % M;
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
	
	mSprite3.setPosition(mFruct.x * size, mFruct.y * size);
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

bool Game::getPlaying(){
	return mPlaying;
}

void Game::setPlaying(bool b){
	mPlaying = b;
}


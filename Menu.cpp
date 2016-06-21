#include "Menu.hpp"
#include <iostream>


#define sizeImg 16

Menu::Menu()
{
	if(!mFont.loadFromFile("arial.ttf")){
		std::cout << "Error loading arial.ttf" << std::endl;
	}
	
	mMenu[0].setFont(mFont);
	mMenu[0].setColor(sf::Color::Red);
	mMenu[0].setPosition((N * sizeImg) / 2, (M * sizeImg) / 4 * 1);
	mMenu[0].setString("Play");
	
	mMenu[1].setFont(mFont);
	mMenu[1].setColor(sf::Color::White);
	mMenu[1].setPosition((N * sizeImg) / 2, (M * sizeImg) / 4 * 2);
	mMenu[1].setString("Options");

	mMenu[2].setFont(mFont);
	mMenu[2].setColor(sf::Color::White);
	mMenu[2].setPosition((N * sizeImg) / 2, (M * sizeImg) / 4 * 3);
	mMenu[2].setString("Quit");
	
	mCurrentItem = 0;
	mSelectedItem = -1;
}

void Menu::processEvents(sf::RenderWindow &window){
	sf::Event event;

	while(window.pollEvent(event)){
		if(event.type == sf::Event::Closed)
			window.close();
		else if(event.type == sf::Event::KeyPressed)
			handlePlayerInput(event.key.code);
	}
}

void Menu::render(sf::RenderWindow &window){
	window.clear();
	for(int i = 0; i < MAX_NUMBER_OF_ITEMS; i++){
		window.draw(mMenu[i]);
	}
	window.display();
}


void Menu::moveUp(){
	if(mCurrentItem != 0){
		mMenu[mCurrentItem].setColor(sf::Color::White);
		mCurrentItem--;
		mMenu[mCurrentItem].setColor(sf::Color::Red);
	}
}

void Menu::moveDown(){
	if(mCurrentItem != 2){
		mMenu[mCurrentItem].setColor(sf::Color::White);
		mCurrentItem++;
		mMenu[mCurrentItem].setColor(sf::Color::Red);
	}
}

int Menu::getSelectedItem() const{
	return mSelectedItem;
}

void Menu::setSelectedItem(int item){
	mSelectedItem = -1;
}


// --- PRIVATE ---
void Menu::handlePlayerInput(sf::Keyboard::Key key){
	if(key == sf::Keyboard::Up){
		moveUp();
	}
	else if(key == sf::Keyboard::Down){
		moveDown();
	}
	else if(key == sf::Keyboard::Return){
		mSelectedItem = mCurrentItem;
	}
}

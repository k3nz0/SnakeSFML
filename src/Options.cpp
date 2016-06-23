#include "../include/Options.hpp"
#include <iostream>

Options::Options()
{
	if(!mFont.loadFromFile("resources/arial.ttf")){
		std::cout << "Error loading arial.ttf" << std::endl;
	}
	
	mMenu[0].setFont(mFont);
	mMenu[0].setColor(sf::Color::Red);
	mMenu[0].setPosition((N * size) / 2, (M * size) / 4 * 1);
	mMenu[0].setString("Easy");
	
	mMenu[1].setFont(mFont);
	mMenu[1].setColor(sf::Color::White);
	mMenu[1].setPosition((N * size) / 2, (M * size) / 4 * 2);
	mMenu[1].setString("Medium");

	mMenu[2].setFont(mFont);
	mMenu[2].setColor(sf::Color::White);
	mMenu[2].setPosition((N * size) / 2, (M * size) / 4 * 3);
	mMenu[2].setString("Hard");
	
	mCurrentItem = 0;
	mSelectedItem = -1;
}



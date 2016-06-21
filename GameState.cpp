#include "GameState.hpp"

#include "config.hpp"
#include <iostream>

GameState::GameState() :
	mMusic(), mMenu(), mGame()
{
	mWindow.create(sf::VideoMode(N * size, M * size), "Snake v0");

	if(!mMusic.openFromFile("stereo.ogg")){
		std::cout << "Error loading stereo.ogg" << std::endl;
	}
	mMusic.setLoop(true);
	mMusic.play();

	mGoMenu = true;
	mGoGame = false;
	mGoLost = false;
}


void GameState::run(){
	
	while(mWindow.isOpen()){
		if(mGoMenu){
			mMenu.render(mWindow);			
			mMenu.processEvents(mWindow);

			if(mMenu.getSelectedItem() == 0){
				mGoMenu = false;
				mGoGame = true;
				mGame.reset();
				mMenu.setSelectedItem(-1);
			}
			else if(mMenu.getSelectedItem() == 1){
				// Options
			}
			else if(mMenu.getSelectedItem() == 2){
				mMenu.setSelectedItem(-1);
				mWindow.close();
			}
		}
		else if(mGoGame){
			mGame.setPlaying(true);
			mGame.play(mWindow);
			mGoGame = mGame.getPlaying();
			if(!mGoGame){
				mGoLost = true;
			}
		}
		else if(mGoLost){
			//std::cout << "Lost the game" << std::endl;
			mGoMenu = true;	
			mGoLost = false;
		}
	}
}
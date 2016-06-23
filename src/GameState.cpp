#include "../include/GameState.hpp"
#include <iostream>


GameState::GameState() :
	mMusic(), mMenu(), mGame(), mOptions()
{
	mWindow.create(sf::VideoMode(N * size, M * size), "Snake v0");

	if(!mMusic.openFromFile("resources/stereo.ogg")){
		std::cout << "Error loading stereo.ogg" << std::endl;
	}
	mMusic.setLoop(true);
	mMusic.play();

	mGoMenu = true;
	mGoGame = false;
	mGoOptions = false;
	mGoLost = false;
	mLevel = 1;
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
				mGoMenu = false;
				mGoOptions = true;
				mMenu.setSelectedItem(-1);
			}
			else if(mMenu.getSelectedItem() == 2){
				mMenu.setSelectedItem(-1);
				mWindow.close();
			}
		}
		else if(mGoOptions){
			mOptions.render(mWindow);
			mOptions.processEvents(mWindow);

			if(mOptions.getSelectedItem() != -1){
				mLevel = mOptions.getSelectedItem();
				mOptions.setSelectedItem(-1);
				mGoMenu = true;
				mGoOptions = false;
			}

		}
		else if(mGoGame){
			mGame.setPlaying(true);
			mGame.setLevel(mLevel);
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
#include "MenuState.h"

MenuState::MenuState() {
	//startButton = new Button(ofGetWidth()/2-300, ofGetHeight()/2 - 200, 800, 800, "START");
	startButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 100, 100 , "START");
}
void MenuState::tick() {
	startButton->tick();
	if(startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);

	}
}
void MenuState::render() {
	ofImage background = getImage();
	//background.load("/Users/sebastian.estrada/Desktop/CIIC4010/OpenFrameWork/apps/myApps/pa2-pakiman/bin/data/images/intro.png");
	background.load("images/intro.png");
	background.draw(0,0,ofGetWidth(),ofGetHeight());
	startButton->render();
	//background.draw(0,0);
	ofSetBackgroundColor(0, 0, 0);
	
}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	startButton->mousePressed(x, y);
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
	
}
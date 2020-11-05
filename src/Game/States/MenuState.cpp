#include "MenuState.h"
#include "ofApp.h"
#include "ofSoundPlayer.h"



MenuState::MenuState() {
	//startButton = new Button(ofGetWidth()/2-300, ofGetHeight()/2 - 200, 1000, 1000, "START");
	//startButton = new Button(ofGetWidth()/2 -300, ofGetHeight()/2-300, ofGetWidth()-300, ofGetHeight()-400 , "START");
	startButton = new Button(ofGetWidth()/2, ofGetHeight()/2, ofGetWidth()-600, ofGetHeight()-600, "START");
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
	background.load("images/PacManMenu.png");
	background.draw(0,0,ofGetWidth(),ofGetHeight());
	startButton->render();
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
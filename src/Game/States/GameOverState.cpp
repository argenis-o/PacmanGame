#include "GameOverState.h"

GameOverState::GameOverState(){
    replayButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 20, "REPLAY");
}

void GameOverState::tick(){
	replayButton->tick();
	if(replayButton->wasPressed()){
		// setFinished(true);
		setNextState("Game");
		setFinished(true);
	}
}

void GameOverState::render(){
    YouDied.load("images/YouDied.jpg");
    YouDied.draw(0,0,ofGetWidth(),ofGetHeight());
    replayButton->render();
    ofSetBackgroundColor(0, 0, 0);
}
void GameOverState::keyPressed(int key){
	
}

void GameOverState::mousePressed(int x, int y, int button){
	replayButton->mousePressed(x, y);
}

void GameOverState::reset(){
	setFinished(false);
	setNextState("");
	replayButton->reset();
	
}
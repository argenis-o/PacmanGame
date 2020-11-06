#include "GameOverState.h"
#include "Player.h"

GameOverState::GameOverState(){
    replayButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 20, "REPLAY");
}

void GameOverState::tick(){
	replayButton->tick();
	if(replayButton->wasPressed()){
		setNextState("Game");
		setFinished(true);
	}
}

void GameOverState::render(){

    YouDied.load("images/YouDied.jpg");
    YouDied.draw(0,0,ofGetWidth(),ofGetHeight());
	ofDrawBitmapString("Score: " + to_string(score), ofGetWidth()/2, 50);
	ofDrawBitmapString("High Score: " + to_string(HighScore),ofGetWidth()/2,70);
    replayButton->render();
    ofSetBackgroundColor(255, 255, 255);
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
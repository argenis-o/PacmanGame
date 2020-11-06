#include "WinningState.h"
#include "GameState.h"


WinningState::WinningState(){
    replayButton = new Button(ofGetWidth()/2, ofGetHeight()/2, 64, 20, "PLAY AGAIN");
}

void WinningState::tick(){
	replayButton->tick();
	if(replayButton->wasPressed()){
		setNextState("Game");
		setFinished(true);
	}
}

void WinningState::render(){
    VictoryScreen.load("images/VictoryScreen.png");
	ofDrawBitmapString("Score: " + to_string(score), ofGetWidth()/2, 50);
	ofDrawBitmapString("High Score: " + to_string(HighScore),ofGetWidth()/2,70);
    VictoryScreen.draw(0,0,ofGetWidth(),ofGetHeight());
    replayButton->render();
    ofSetBackgroundColor(0, 0, 0);
}

void WinningState::keyPressed(int key){
	
}

void WinningState::mousePressed(int x, int y, int button){
	replayButton->mousePressed(x, y);
}

void WinningState::reset(){
	
	setFinished(false);
	setNextState("");
	replayButton->reset();
	
}
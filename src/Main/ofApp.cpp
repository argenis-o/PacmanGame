#include "ofApp.h"
#include "Images.h"
#include "Map.h"

//--------------------------------------------------------------
void ofApp::setup(){
	
	
		

	ofSetFrameRate(30);
	ofSetWindowTitle("PacMan"); 

	//States
	menuState = new MenuState();
	gameState = new GameState();
	gameoverState = new GameOverState();
	winningState = new WinningState();


	// Initial State
	currentState = menuState;
}

//--------------------------------------------------------------
void ofApp::update(){
	if (currentState != nullptr){
		currentState->tick();
		if(currentState->hasFinished()){
			if(currentState->getNextState() == "Menu"){
				currentState = menuState;
			}
			else if(currentState->getNextState() == "Game"){
				GhostsMovement = SoundEffects::soundManager("PacManSoundEffects/PacManBackGround.mp3"); // Start Sound
				PacManStart = SoundEffects::soundManager("PacManSoundEffects/PacManBeginning.mp3");
				GhostsMovement.setLoop(true); // makes the effect that the ghosts are moving
				currentState = gameState;

				
			}
			else if(currentState->getNextState() == "Replay" ){
				GhostsMovement.setPaused(true);
				gameoverState->setScore(gameState->getScore());
				gameoverState->setHighScore(gameState->getHighScore());
				DarthVaderVoiceline = SoundEffects::soundManager("PacManSoundEffects/DarthVaderVoiceLine2.mp3"); // Sound for when PacMan loses the game
				DarthVaderVoiceline.setVolume(1);
		 		currentState = gameoverState;
			}

			else if(currentState->getNextState() == "PLAY AGAIN"){
				GhostsMovement.setPaused(true);
				winningState->setScore(gameState->getScore());
				winningState->setHighScore(gameState->getHighScore());
				VictorySound = SoundEffects::soundManager("PacManSoundEffects/VictorySound.mp3"); // Sound when PacMan wins 
				VictorySound.setVolume(1);
				currentState = winningState;
			}
			
			currentState->reset();
		}
	}
}
		


//--------------------------------------------------------------
void ofApp::draw(){
	if (currentState != nullptr)
		currentState->render();
		
		
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (currentState != nullptr)
		
		currentState->keyPressed(key);

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (currentState != nullptr)
			currentState->keyReleased(key);
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	if (currentState != nullptr)
		currentState->mouseMoved(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseDragged(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mousePressed(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	if (currentState != nullptr)
		currentState->mouseReleased(x, y, button);
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
	if (currentState != nullptr)
			currentState->mouseEntered(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
	if (currentState != nullptr)
		currentState->mouseExited(x, y);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
	if (currentState != nullptr)
			currentState->windowResized(w, h);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
	if (currentState != nullptr)
		currentState->gotMessage(msg);
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
	if (currentState != nullptr)
		currentState->dragEvent(dragInfo);
}

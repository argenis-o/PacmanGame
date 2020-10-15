#pragma once

#include "ofMain.h"
#include "MenuState.h"
#include "GameState.h"
#include "ofSoundPlayer.h"


class ofApp : public ofBaseApp{

private:
	State *currentState;
	MenuState *menuState;
	GameState *gameState;


public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		/*void ofApp::playMusic(string word){
			song.load(word);
    		song.setVolume(0.6);
    		song.setLoop(true);
    		song.play();
		}*/

		ofSoundPlayer PacManStartUp;
		ofSoundPlayer PacManDies;
		static ofSoundPlayer PacManEatsDots;
		ofSoundPlayer PacManEatsFruit;
		ofSoundPlayer PacManEatsGhosts;
		ofSoundPlayer PacManExtraLife;
		ofSoundPlayer PacManIntermission;

		ofImage Background;

		
};

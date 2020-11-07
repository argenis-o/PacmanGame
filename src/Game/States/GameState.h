#pragma once

#include "State.h"
#include "Player.h"
#include "MapBuilder.h"

class GameState: public State{
    public: 
        GameState();
		void reset();
		void tick();
		void render();
		void keyPressed(int key);
		void mousePressed(int x, int y, int button);
		void keyReleased(int key);
		bool getGamePlaying(){return this->isPlaying;}
		void setGamePlaying(bool playing){this->isPlaying = playing;}
		void setMap(ofImage newMap){
			this->mapImage = newMap;
		}

		int getScore(){return score;}
		int getHighScore(){return HighS;}
		int HighS;
		int score;
		ofImage newMaps[2]; // array that contains maps
		
	
	private:
		bool isPlaying;
		ofImage mapImage;
		Map* map;
		ofSoundPlayer PacManStart;
		ofImage DeathStar; 
		int count = 0;
		


};
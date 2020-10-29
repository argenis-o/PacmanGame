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
	
	private:
		bool isPlaying;
		ofImage mapImage;
		Map* map;
		ofSoundPlayer PacManBackGround;
		//MapBuilder* newgame;


};
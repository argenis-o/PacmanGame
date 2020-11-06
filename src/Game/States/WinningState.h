#pragma once

#include "State.h"
#include "Button.h"
#include "GameState.h"


class WinningState : public State {
private:
	ofImage VictoryScreen;
	Button *replayButton;
	int score = 0;
	int HighScore = 0;
public:
	WinningState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
	void setScore(int score){this->score = score;}
	void setHighScore(int HighS){this->HighScore = HighS;}

};
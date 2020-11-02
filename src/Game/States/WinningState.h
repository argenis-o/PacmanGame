#pragma once

#include "State.h"
#include "Button.h"


class WinningState : public State {
private:
	ofImage VictoryScreen;
	Button *replayButton;

public:
	WinningState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();

};
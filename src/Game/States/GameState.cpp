#include "GameState.h"
#include "Entity.h"

GameState::GameState() {
	mapImage.load("images/map1.png");
	map = MapBuilder().createMap(mapImage);   //generates a new map.
	HighS = 0;
}
void GameState::tick() {
	if(HighS == 0 || map->getHighScore()>HighS){
		HighS = map->getHighScore();
	}
	map->tick();
	if(map->getHealth() == 0 || map->getDotCount()==0){
		setNextState("Replay");
		setFinished(true);
		map->setHealth();
		map = MapBuilder().createMap(mapImage);

		// newgame->createMap(mapImage);
	}
}
void GameState::render() {
	ofDrawBitmapString("High Score: " + to_string(HighS),0,95);

	map->render();
}

void GameState::keyPressed(int key){
	map->keyPressed(key);
}

void GameState::mousePressed(int x, int y, int button){
	map->mousePressed(x, y, button);
}

void GameState::keyReleased(int key){
	map->keyReleased(key);
}

void GameState::reset(){
	setFinished(false);
	setNextState("");
}
#include "GameState.h"
#include "Entity.h"
#include "WinningState.h"

GameState::GameState() {

	/*if(count == 0){
		mapImage.load("images/map1.png");
		map = MapBuilder().createMap(mapImage);   //generates a new map.
		HighS = 0;
	}*/

	mapImage.load("images/map1.png");
	DeathStar.load("images/DeathstarMap.png");
	map = MapBuilder().createMap(DeathStar);   //generates a new map.
	HighS = 0;
	newMaps[0] = mapImage;
	newMaps[1] = DeathStar;

	
}
void GameState::tick() {
	if(HighS == 0 || map->getHighScore()>HighS){
		HighS = map->getHighScore();
	}
	map->tick();
	//if(map->getHealth() == 0 || map->getDotCount()==0){
	if(map->getHealth() == 0){  
		setNextState("Replay");
		setFinished(true);
		map->setHealth();
		map = MapBuilder().createMap(newMaps[1]);

		// newgame->createMap(mapImage);
	}

	else if(map->getDotCount()==0 && map->getHealth() > 0){
		count++;
		setNextState("PLAY AGAIN");
		setFinished(true);
		map->setHealth();
		map = MapBuilder().createMap(newMaps[0]);
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
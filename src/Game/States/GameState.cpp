#include "GameState.h"
#include "Entity.h"
#include "WinningState.h"

GameState::GameState() {


	mapImage.load("images/map1.png");
	DeathStar.load("images/DeathstarMap.png");
	map = MapBuilder().createMap(mapImage);   //generates a new map.
	HighS = 0;
	newMaps[0] = mapImage;
	newMaps[1] = DeathStar;

	
}
void GameState::tick() {
	score = map->getHighScore();
	if(HighS == 0 || map->getHighScore()>HighS){
		HighS = map->getHighScore();
	}
	map->tick();

	if(map->getHealth() == 0){   // When PacMan dies with 0 lives, it resets the game back to the first map
		setNextState("Replay");
		setFinished(true);
		map->setHealth();
		map = MapBuilder().createMap(newMaps[0]);

		
	}

	else if(map->getDotCount()==0 && map->getHealth() > 0){ // if PacMan eats all the dots and has 1 life or more, change map
		count++;
		if(count>=2){ // if we get out of index, set the map back to the first one 
			count = 0;
		}
		setNextState("PLAY AGAIN");
		setFinished(true);
		map->setHealth();
		map = MapBuilder().createMap(newMaps[count]);
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
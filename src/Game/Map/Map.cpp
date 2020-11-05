#include "Map.h"
#include "Dot.h"
#include "BigDot.h"

Map::Map(EntityManager* em){
    entityManager = em;
}

void Map::tick(){
	if(dotC){
		dotCount = 0;
		for(Entity* entity:entityManager->entities){
			if(dynamic_cast<Dot*>(entity)){
			dotCount++;
			}
			else if(dynamic_cast<BigDot*>(entity)){
			dotCount++;
			}
		}
	}
	entityManager->tick();
	player->tick();
	ghost->tick();

}
void Map::render(){
	ofDrawBitmapString("Dots: "+ to_string(dotCount), 0, 155);
    ofSetBackgroundColor(0, 0, 0);
	entityManager->render();
	player->render();
	for(Entity* entity:entityManager->entities){
		if(dynamic_cast<Ghost*>(entity)){
			Ghost* DynamicGhost = dynamic_cast<Ghost*>(entity);
			// entity->render();

			if(player->ghostdie){ //if PacMan eats a Ghost, set the timer.
				if(timer<150){
					timer++;
					DynamicGhost->setIsEatable(true);

				}
			}
			else{
				timer = 0;
				DynamicGhost->setIsEatable(false);
			}

	

		}

		
	}

}

void Map::keyPressed(int key){
	player->keyPressed(key);
	ghost->keyPressed(key);
	power->keyPressed(key);

}

void Map::mousePressed(int x, int y, int button){
	player->mousePressed(x, y, button);
}

void Map::keyReleased(int key){
	player->keyReleased(key);
}
void Map::addBlockEntity(BlockEntity* e){
    entityManager->blocks.push_back(e);
}
void Map::addEntity(Entity* e){
	entityManager->entities.push_back(e);
}
void Map::setPlayer(Player* p){
    player = p;
}

void Map::setSpawner(GhostSpawner* gs){
	ghost = gs;
}

void Map::setPowerups(PowerupSpawner*PW){
	power = PW;
}


int Map::getHealth(){
	return player->getHealth();
}

void Map::setHealth(){
	player->setHealth(3);
}

void Map::EntityReset(){
	entityManager->entities.clear();
}

void Map::ResetMap(){
}



int Map::getHighScore(){
	HighScore = player->getHighScore();
	return HighScore;
}
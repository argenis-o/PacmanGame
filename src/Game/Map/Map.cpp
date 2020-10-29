#include "Map.h"

Map::Map(EntityManager* em){
    entityManager = em;
}

void Map::tick(){
	entityManager->tick();
	player->tick();
	ghost->tick();

}
void Map::render(){
    ofSetBackgroundColor(0, 0, 0);
	entityManager->render();
	player->render();
	for(Entity* entity:entityManager->entities){
		if(dynamic_cast<Ghost*>(entity)){
			entity->render();
		}
	}

}

void Map::keyPressed(int key){
	player->keyPressed(key);
	ghost->keyPressed(key);

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


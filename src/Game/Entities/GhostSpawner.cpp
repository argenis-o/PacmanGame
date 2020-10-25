#include "GhostSpawner.h"
#include "Ghost.h"
#include "Map.h"
#include "MapBuilder.h"
#include "EntityManager.h"
#include "Entity.h"



GhostSpawner::GhostSpawner(int x, int y, int width, int height, ofImage spriteSheet,EntityManager* entityManager): Entity(x, y, width, height){
    
    Ghost* ghost1 = new Ghost(x,y,width,height,spriteSheet,entityManager);
	entityManager->entities.push_back(ghost1);

    Ghost* ghost2 = new Ghost(x+5,y,width,height,spriteSheet,entityManager);
	entityManager->entities.push_back(ghost2);

    Ghost* ghost3 = new Ghost(x+10,y,width,height,spriteSheet,entityManager);
    entityManager->entities.push_back(ghost3);

    Ghost* ghost4 = new Ghost(x-5,y,width,height,spriteSheet,entityManager);
	entityManager->entities.push_back(ghost4);
    		
                    


}
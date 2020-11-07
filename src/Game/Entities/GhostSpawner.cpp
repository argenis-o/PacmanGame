#include "GhostSpawner.h"
#include "Ghost.h"
#include "Map.h"
#include "MapBuilder.h"
#include "EntityManager.h"
#include "Entity.h"



GhostSpawner::GhostSpawner(int x, int y, int width, int height, ofImage spriteSheet,EntityManager* entityManager): Entity(x, y, width, height){
    Ghost* blinky = new Ghost(x,y,width,height,spriteSheet,entityManager,Blinky);
	entityManager->entities.push_back(blinky);

    Ghost* pinky = new Ghost(x,y,width,height,spriteSheet,entityManager,Pinky);
	entityManager->entities.push_back(pinky);

    Ghost* inky = new Ghost(x,y,width,height,spriteSheet,entityManager,Inky);
    entityManager->entities.push_back(inky);

    Ghost* clyde = new Ghost(x,y,width,height,spriteSheet,entityManager,Clyde);
	entityManager->entities.push_back(clyde);
    this->entityManager = entityManager;
    this->sprite = spriteSheet;
    
                    


}

void GhostSpawner::tick(){
    if(viewGhostCount()){
        if(timer<200){
            timer++;
        }
        else{
            Ghost* clyde = new Ghost(x,y,width,height,sprite,entityManager,Clyde); // if the Ghost is killed, spawn this default one **TODO: MAKE GHOST SPAWN THE COLOR THAT WAS EATEN
            entityManager->entities.push_back(clyde);
            timer = 0;
        }
    }
}

void GhostSpawner::keyPressed(int key){
    switch(key){ //spawn a random Ghost color witg the G key
        case 'g':
            randomColor = int(ofRandom(0,4));
            if(randomColor == 0){
                Ghost* ghosts = new Ghost(x,y,width,height,sprite,entityManager,Blinky);
                entityManager->entities.push_back(ghosts);

            }

            else if(randomColor == 1){
                Ghost* ghosts = new Ghost(x,y,width,height,sprite,entityManager,Pinky);
                entityManager->entities.push_back(ghosts);
            }

            else if(randomColor == 2){
                Ghost* ghosts = new Ghost(x,y,width,height,sprite,entityManager,Inky);
                entityManager->entities.push_back(ghosts);
            }

            else{
                Ghost* ghosts = new Ghost(x,y,width,height,sprite,entityManager,Clyde);
                entityManager->entities.push_back(ghosts);
            }
    }
}

bool GhostSpawner::viewGhostCount(){
    gCount = 0;
    for(Entity* entity:entityManager->entities){
        if(dynamic_cast<Ghost*>(entity)){
            gCount++;
        }

    }
    if(gCount < 4 ){
        return true;
    }
    return false;
}
#include "PowerupSpawner.h"
#include "MapBuilder.h"
#include "EntityManager.h"
#include "Powerups.h"

PowerupSpawner::PowerupSpawner(int x, int y, int width, int height, ofImage spritesheet, EntityManager* entityManager):Entity(x,y,width,height){
    this->entityManager = entityManager;
    this->entityManager = entityManager;
    this->pow = spritesheet;

}

void PowerupSpawner::render(){
    for(Entity* entity: entityManager->entities){
        if(dynamic_cast<Powerups*>(entity)){
            poweron = false;
        }
        else{poweron = true;}
    }
    
    if(timer<5400){
        timer++;
    }
    else{
        if(poweron){
            Powerups * Cherry = new Powerups(x,y,width,height,pow,entityManager,CHERRY);
            entityManager->entities.push_back(Cherry);
        }
    }
}



void PowerupSpawner::keyPressed(int key){
    switch(key){
        case 'c':
            if(poweron){
                Powerups * Cherry = new Powerups(x,y,width,height,pow,entityManager,CHERRY);
                entityManager->entities.push_back(Cherry);
                poweron = false;
            }
    }
}
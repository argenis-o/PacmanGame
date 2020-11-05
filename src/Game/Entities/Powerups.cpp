#include "Powerups.h"
#include "Player.h"

Powerups::Powerups(int x, int y, int width, int height, ofImage spritesheet, EntityManager* em, POWER current) : Entity(x, y, width, height){
    this->em = em;
    this->power = spritesheet;
    this->current = current;
    switch(current){
        case CHERRY:
            cherry.cropFrom(spritesheet,489, 49,16,16);
    }
}





void Powerups::render(){
    cherry.draw(x,y,width,height);
}

// void Powerups::spawnCherry(){
//     Powerups *Cherry = new Powerups(x,y,width,height,power,em,CHERRY);
//     em->entities.push_back(Cherry);
// }
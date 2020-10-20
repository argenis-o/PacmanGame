#include "GhostSpawner.h"

GhostSpawner::GhostSpawner(int x, int y, int width, int height, ofImage spriteSheet): Entity(x, y, width, height){
    if(count > 3){
        count = 0;
    }
    //count++;
    if(count == 0){
      sprite.cropFrom(spriteSheet,456,64,16,16);
    }
    else if(count == 1){
        sprite.cropFrom(spriteSheet,456,80,16,16);
        //count++;
    }
    else if(count == 2){
        sprite.cropFrom(spriteSheet,456,96,16,16);
        //count++;
    }
    else if(count == 3){
        sprite.cropFrom(spriteSheet,456,112,16,16);
        //count++;
    }

}

// void GhostSpawner::sumCount(){
//     count += 1;
//     if(count == 4){
//         count = 0;
//     }
// }
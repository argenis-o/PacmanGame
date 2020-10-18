#include "GhostSpawner.h"

GhostSpawner::GhostSpawner(int x, int y, int width, int height, ofImage spriteSheet): Entity(x, y, width, height){
    sprite.cropFrom(spriteSheet,456,64,16,16);
    // sprite.cropFrom(spriteSheet,456,80,16,16);
    // sprite.cropFrom(spriteSheet,456,96,16,16);
    // sprite.cropFrom(spriteSheet,456,112,16,16);
}

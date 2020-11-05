#pragma once
#include "Entity.h"
#include "EntityManager.h"

class PowerupSpawner:public Entity{
    public:
    PowerupSpawner(int, int, int, int, ofImage, EntityManager*entityManager);
    EntityManager*entityManager; 
    void keyPressed(int);  
    ofImage pow;
    bool poweron = true;

    void render();
    int timer = 0;
};
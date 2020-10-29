#pragma once
#include "Entity.h"
#include "Ghost.h"

class GhostSpawner: public Entity{
    private:

    public:
        GhostSpawner(int, int, int, int, ofImage, EntityManager* entityManager);
        EntityManager* entityManager;
        void tick();
        void keyPressed(int);
        bool viewGhostCount();
        int randomColor;
        int gCount = 0;
        int timer = 0;

        // bool newghost = false;

        // void setSpawnRate(bool value){newghost = value;};
        //vector<Ghost*> getGhost(){};

};

